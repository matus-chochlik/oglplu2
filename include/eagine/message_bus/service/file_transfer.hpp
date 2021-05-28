/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_FILE_TRANSFER_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_FILE_TRANSFER_HPP

#include "../../main_ctx.hpp"
#include "../../url.hpp"
#include "../../valid_if/decl.hpp"
#include "../blobs.hpp"
#include "../service.hpp"
#include "../signal.hpp"
#include <tuple>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Service providing access to files over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see file_transfer_consumer
template <typename Base = subscriber>
class file_server : public Base {
    using This = file_server;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(
          this,
          EAGINE_MSG_MAP(
            eagiFiles, rqFileCont, This, _handle_file_content_request));
    }

    auto update() -> bool {
        some_true something_done;
        something_done(Base::update());

        something_done(_blobs.cleanup());
        const auto opt_max_size = this->bus_node().max_data_size();
        if(EAGINE_LIKELY(opt_max_size)) {
            something_done(_blobs.process_outgoing(
              EAGINE_THIS_MEM_FUNC_REF(_handle_post), extract(opt_max_size)));
        }

        return something_done;
    }

    virtual auto get_io(string_view)
      -> std::tuple<std::unique_ptr<blob_io>, std::chrono::seconds> {
        // TODO
        return {_blobs.make_io(1024), std::chrono::seconds{60}};
    }

private:
    auto _handle_post(message_id msg_id, const message_view& message) -> bool {
        return this->bus_node().post(msg_id, message);
    }

    auto _handle_file_content_request(
      const message_context&,
      stored_message& message) -> bool {
        std::string url_str;
        auto request = std::tie(url_str);
        if(default_deserialize(request, message.data())) {
            auto [read_io, max_time] = get_io(url_str);
            _blobs.push_outgoing(
              EAGINE_MSG_ID(eagiFiles, content),
              message.target_id,
              message.source_id,
              message.sequence_no,
              std::move(read_io),
              max_time,
              message_priority::normal);
        }
        return true;
    }

    blob_manipulator _blobs{*this, EAGINE_MSG_ID(eagiFiles, fragment)};
};
//------------------------------------------------------------------------------
/// @brief Service manipulating files over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see file_manipulator
template <typename Base = subscriber>
class file_manipulator : public Base {

    using This = file_manipulator;

public:
    /// @brief Requests the contents of the file with the specified URL.
    /// @see file_content_received
    auto query_file_content(identifier_t endpoint_id, const url& file_url)
      -> optionally_valid<message_sequence_t> {
        auto request = std::make_tuple(to_string(file_url.str()));
        auto buffer = default_serialize_buffer_for(request);
        if(default_serialize(request, cover(buffer))) {
            const auto msg_id{EAGINE_MSG_ID(eagiFiles, rqFileCont)};
            message_view message{};
            message.set_target_id(endpoint_id);
            this->bus_node().set_next_sequence_id(msg_id, message);
            this->bus_node().post(msg_id, message);
            return {message.sequence_no, true};
        }
        return {};
    }

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        // TODO
    }

private:
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_FILE_TRANSFER_HPP
