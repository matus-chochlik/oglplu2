/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_RESOURCE_TRANSFER_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_RESOURCE_TRANSFER_HPP

#include "../../from_string.hpp"
#include "../../main_ctx.hpp"
#include "../../memory/span_algo.hpp"
#include "../../url.hpp"
#include "../../valid_if/decl.hpp"
#include "../blobs.hpp"
#include "../service.hpp"
#include "../signal.hpp"
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class single_byte_blob_io : public blob_io {
public:
    single_byte_blob_io(span_size_t size, byte value) noexcept
      : _size{size}
      , _value{value} {}

    auto total_size() -> span_size_t final {
        return _size;
    }

    auto fetch_fragment(span_size_t offs, memory::block dst)
      -> span_size_t final {
        return fill(head(dst, _size - offs), _value).size();
    }

private:
    span_size_t _size;
    byte _value;
};
//------------------------------------------------------------------------------
/// @brief Service providing access to files over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see resource_manipulator
template <typename Base = subscriber>
class resource_server : public Base {
    using This = resource_server;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(
          this,
          EAGINE_MSG_MAP(
            eagiRsrces, getContent, This, _handle_resource_content_request));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(
            eagiRsrces, fragResend, This, _handle_resource_resend_request));
    }

    auto update() -> bool {
        some_true something_done;
        something_done(Base::update());

        something_done(_blobs.cleanup());
        const auto opt_max_size = this->bus_node().max_data_size();
        if(EAGINE_LIKELY(opt_max_size)) {
            something_done(_blobs.process_outgoing(
              EAGINE_THIS_MEM_FUNC_REF(_call_post), extract(opt_max_size)));
        }

        return something_done;
    }

    virtual auto get_resource_io(identifier_t, const url&)
      -> std::unique_ptr<blob_io> {
        return {};
    }

    virtual auto get_blob_timeout(identifier_t, span_size_t size)
      -> std::chrono::seconds {
        return std::chrono::seconds{size / 1024};
    }

    virtual auto get_blob_priority(identifier_t, message_priority priority)
      -> message_priority {
        return priority;
    }

private:
    auto _call_post(message_id msg_id, const message_view& message) -> bool {
        return this->bus_node().post(msg_id, message);
    }

    auto _get_resource(
      const url& locator,
      identifier_t endpoint_id,
      message_priority priority) -> std::
      tuple<std::unique_ptr<blob_io>, std::chrono::seconds, message_priority> {
        auto read_io = get_resource_io(endpoint_id, locator);
        if(!read_io) {
            if(locator.has_scheme("eagires")) {
                if(auto count{locator.argument("count")}) {
                    if(auto bytes{from_string<span_size_t>(extract(count))}) {
                        if(locator.has_path("/zeroes")) {
                            read_io = std::make_unique<single_byte_blob_io>(
                              extract(bytes), 0x0U);
                        } else if(locator.has_path("/ones")) {
                            read_io = std::make_unique<single_byte_blob_io>(
                              extract(bytes), 0x1U);
                        }
                    }
                }
            }
        }

        const auto max_time =
          read_io ? get_blob_timeout(endpoint_id, read_io->total_size())
                  : std::chrono::seconds{};

        return {
          std::move(read_io),
          max_time,
          get_blob_priority(endpoint_id, priority)};
    }

    auto _handle_resource_content_request(
      const message_context& ctx,
      stored_message& message) -> bool {
        std::string url_str;
        auto request = std::tie(url_str);
        if(EAGINE_LIKELY(default_deserialize(request, message.content()))) {
            ctx.bus_node()
              .log_info("received content request for ${url}")
              .arg(EAGINE_ID(url), EAGINE_ID(URL), url_str);
            const url locator{std::move(url_str)};

            auto [read_io, max_time, priority] =
              _get_resource(locator, message.source_id, message.priority);
            if(read_io) {
                _blobs.push_outgoing(
                  EAGINE_MSG_ID(eagiRsrces, content),
                  message.target_id,
                  message.source_id,
                  message.sequence_no,
                  std::move(read_io),
                  max_time,
                  priority);
            }
        } else {
            ctx.bus_node()
              .log_error("failed to deserialize resource content request")
              .arg(EAGINE_ID(content), message.const_content());
        }
        return true;
    }

    auto _handle_resource_resend_request(
      const message_context&,
      stored_message& message) -> bool {
        _blobs.process_resend(message);
        return true;
    }

    blob_manipulator _blobs{
      *this,
      EAGINE_MSG_ID(eagiRsrces, fragment),
      EAGINE_MSG_ID(eagiRsrces, fragResend)};
};
//------------------------------------------------------------------------------
/// @brief Service manipulating files over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see resource_manipulator
template <typename Base = subscriber>
class resource_manipulator : public Base {

    using This = resource_manipulator;

public:
    /// @brief Requests the contents of the file with the specified URL.
    auto query_resource_content(
      identifier_t endpoint_id,
      const url& locator,
      std::shared_ptr<blob_io> write_io,
      message_priority priority,
      std::chrono::seconds max_time) -> optionally_valid<message_sequence_t> {
        const auto request = std::make_tuple(locator.str());
        auto buffer = default_serialize_buffer_for(request);
        if(auto serialized{default_serialize(request, cover(buffer))}) {
            const auto msg_id{EAGINE_MSG_ID(eagiRsrces, getContent)};
            message_view message{extract(serialized)};
            message.set_target_id(endpoint_id);
            message.set_priority(priority);
            this->bus_node().set_next_sequence_id(msg_id, message);
            this->bus_node().post(msg_id, message);
            _blobs.expect_incoming(
              EAGINE_MSG_ID(eagiRsrces, content),
              endpoint_id,
              message.sequence_no,
              std::move(write_io),
              max_time);
            return {message.sequence_no, true};
        }
        return {};
    }

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(
          this,
          EAGINE_MSG_MAP(
            eagiRsrces, fragment, This, _handle_resource_fragment));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(
            eagiRsrces, fragResend, This, _handle_resource_resend_request));
    }

    auto update() -> bool {
        some_true something_done;

        something_done(Base::update());
        something_done(_blobs.handle_complete() > 0);

        return something_done;
    }

private:
    auto _handle_resource_fragment(
      const message_context& ctx,
      stored_message& message) -> bool {
        EAGINE_MAYBE_UNUSED(ctx);
        _blobs.process_incoming(message);
        return true;
    }

    auto _handle_resource_resend_request(
      const message_context&,
      stored_message& message) -> bool {
        _blobs.process_resend(message);
        return true;
    }

    blob_manipulator _blobs{
      *this,
      EAGINE_MSG_ID(eagiRsrces, fragment),
      EAGINE_MSG_ID(eagiRsrces, fragResend)};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_RESOURCE_TRANSFER_HPP
