/**
 *  @file eagine/message_bus/skeleton.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SKELETON_HPP
#define EAGINE_MESSAGE_BUS_SKELETON_HPP

#include "../callable_ref.hpp"
#include "../flat_map.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "endpoint.hpp"
#include "serialize.hpp"
#include <array>
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class skeleton;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class skeleton<Result(Params...), Serializer, Deserializer, MaxDataSize> {
public:
    bool call(
      endpoint& bus,
      const stored_message& msg_in,
      message_id msg_id,
      memory::block buffer,
      callable_ref<Result(Params...)> func) {
        std::tuple<std::remove_cv_t<std::remove_reference_t<Params>>...> tupl{};

        block_data_source source(msg_in.content());
        Deserializer read_backend(source);

        if(msg_in.has_serializer_id(read_backend.type_id())) {
            const auto read_errors = deserialize(tupl, read_backend);
            if(!read_errors) {
                const auto result{std::apply(func, tupl)};
                block_data_sink sink(buffer);
                Serializer write_backend(sink);

                const auto errors = serialize(result, write_backend);
                EAGINE_ASSERT(!errors);
                message_view msg_out{sink.done()};
                msg_out.set_serializer_id(write_backend.type_id());
                bus.respond_to(msg_in, msg_id, msg_out);
                return true;
            }
        }
        return false;
    }

    bool call(
      endpoint& bus,
      const stored_message& msg_in,
      message_id msg_id,
      callable_ref<Result(Params...)> func) {
        std::array<byte, MaxDataSize> buffer{};
        return call(bus, msg_in, msg_id, cover(buffer), func);
    }
};
//------------------------------------------------------------------------------
template <
  typename Signature,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class lazy_skeleton;
//------------------------------------------------------------------------------
template <
  typename Result,
  typename... Params,
  typename Serializer,
  typename Deserializer,
  std::size_t MaxDataSize>
class lazy_skeleton<Result(Params...), Serializer, Deserializer, MaxDataSize> {
public:
    using id_t = message_sequence_t;

    lazy_skeleton() noexcept = default;

    template <typename R, typename P>
    lazy_skeleton(std::chrono::duration<R, P> default_timeout) noexcept
      : _default_timeout{default_timeout} {
    }

    bool enqueue(const stored_message& msg_in) {
        auto [pos, emplaced] = _pending.try_emplace(msg_in.sequence_no);

        if(emplaced) {
            block_data_source source(msg_in.content());
            Deserializer read_backend(source);

            if(msg_in.has_serializer_id(read_backend.type_id())) {
                auto& [source_id, too_late, args] = pos->second;
                const auto read_errors = deserialize(args, read_backend);
                if(!read_errors) {
                    source_id = msg_in.source_id;
                    too_late.reset(_default_timeout);
                    return true;
                }
            }
        }
        return false;
    }

    bool handle_one(
      endpoint& bus,
      message_id msg_id,
      memory::block buffer,
      callable_ref<Result(Params...)> handler) {
        const auto bgn = _pending.begin();
        auto pos = bgn;
        while(pos != _pending.end()) {
            const auto invocation_id = pos->first;
            const auto& [target_id, too_late, args] = pos->second;
            ++pos;
            if(!too_late) {
                const auto result{std::apply(handler, args)};
                block_data_sink sink(cover(buffer));
                Serializer write_backend(sink);

                const auto errors = serialize(result, write_backend);
                EAGINE_ASSERT(!errors);
                message_view msg_out{sink.done()};
                msg_out.set_serializer_id(write_backend.type_id());
                msg_out.set_target_id(target_id);
                msg_out.set_sequence_no(invocation_id);
                bus.send(msg_id, msg_out);
                break;
            }
        }
        if(bgn != pos) {
            _pending.erase(bgn, pos);
            return true;
        }
        return false;
    }

    bool handle_one(
      endpoint& bus,
      message_id msg_id,
      callable_ref<Result(Params...)> handler) {
        std::array<byte, MaxDataSize> buffer{};
        return handle_one(bus, msg_id, cover(buffer), handler);
    }

    bool handle_one(
      endpoint& bus,
      message_id msg_id,
      memory::block buffer,
      callable_ref<bool(callable_ref<void(Result)>, Params...)> handler) {
        const auto pos = _pending.begin();
        if(pos != _pending.end()) {
            const auto invocation_id = pos->first;
            const auto& [target_id, too_late, args] = pos->second;
            if(!too_late) {
                auto do_send =
                  [this, &bus, msg_id, buffer, invocation_id, target_id](
                    Result result) {
                      block_data_sink sink(buffer);
                      Serializer write_backend(sink);

                      const auto errors = serialize(result, write_backend);
                      if(!errors) {
                          message_view msg_out{sink.done()};
                          msg_out.set_serializer_id(write_backend.type_id());
                          msg_out.set_target_id(target_id);
                          msg_out.set_sequence_no(invocation_id);
                          bus.send(msg_id, msg_out);
                      }
                  };
                if(std::apply(
                     handler,
                     std::tuple_cat(
                       std::make_tuple(callable_ref<void(Result)>(do_send)),
                       std::move(args)))) {
                    _pending.erase(pos);
                    return true;
                }
            }
        }
        return false;
    }

    bool handle_one(
      endpoint& bus,
      message_id msg_id,
      callable_ref<bool(callable_ref<void(Result)>, Params...)> handler) {
        std::array<byte, MaxDataSize> buffer{};
        return handle_one(bus, msg_id, cover(buffer), handler);
    }

private:
    std::chrono::milliseconds _default_timeout{1000};
    flat_map<
      id_t,
      std::tuple<
        identifier_t,
        timeout,
        std::tuple<std::remove_cv_t<std::remove_reference_t<Params>>...>>>
      _pending{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SKELETON_HPP

