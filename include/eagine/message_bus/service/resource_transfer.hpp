/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_RESOURCE_TRANSFER_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_RESOURCE_TRANSFER_HPP

#include "../../flat_map.hpp"
#include "../../flat_set.hpp"
#include "../../from_string.hpp"
#include "../../main_ctx.hpp"
#include "../../math/functions.hpp"
#include "../../memory/span_algo.hpp"
#include "../../random_bytes.hpp"
#include "../../string_span.hpp"
#include "../../timeout.hpp"
#include "../../url.hpp"
#include "../../valid_if/decl.hpp"
#include "../blobs.hpp"
#include "../service.hpp"
#include "../service_requirements.hpp"
#include "../signal.hpp"
#include "discovery.hpp"
#include "host_info.hpp"
#include <filesystem>
#include <fstream>
#include <random>
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
class random_byte_blob_io : public blob_io {
public:
    random_byte_blob_io(span_size_t size) noexcept
      : _size{size}
      , _re{std::random_device{}()} {}

    auto total_size() -> span_size_t final {
        return _size;
    }

    auto fetch_fragment(span_size_t offs, memory::block dst)
      -> span_size_t final {
        return fill_with_random_bytes(
                 head(dst, _size - offs), any_random_engine(_re))
          .size();
    }

private:
    span_size_t _size;
    std::default_random_engine _re;
};
//------------------------------------------------------------------------------
class file_blob_io : public blob_io {
public:
    file_blob_io(
      std::fstream file,
      optionally_valid<span_size_t> offs,
      optionally_valid<span_size_t> size)
      : _file{std::move(file)} {
        _file.seekg(0, std::ios::end);
        _size = limit_cast<span_size_t>(_file.tellg());
        if(size) {
            _size = _size ? math::minimum(_size, extract(size)) : extract(size);
        }
        if(offs) {
            _offs = math::minimum(_size, extract(offs));
        }
    }

    auto is_at_eod(span_size_t offs) -> bool final {
        return offs >= total_size();
    }

    auto total_size() -> span_size_t final {
        return _size - _offs;
    }

    auto fetch_fragment(span_size_t offs, memory::block dst)
      -> span_size_t final {
        _file.seekg(_offs + offs, std::ios::beg);
        return limit_cast<span_size_t>(
          read_from_stream(_file, head(dst, _size - _offs - offs)).gcount());
    }

    auto store_fragment(span_size_t offs, memory::const_block src)
      -> bool final {
        _file.seekg(_offs + offs, std::ios::beg);
        return write_to_stream(_file, head(src, _size - _offs - offs)).good();
    }

    auto check_stored(span_size_t, memory::const_block) -> bool final {
        return true;
    }

    void handle_finished(message_id, message_age, const message_info&) final {
        _file.close();
    }

private:
    std::fstream _file;
    span_size_t _offs{0};
    span_size_t _size{0};
};
//------------------------------------------------------------------------------
/// @brief Service providing access to files over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see resource_manipulator
template <typename Base = subscriber>
class resource_server : public Base {
    using This = resource_server;

public:
    void set_file_root(const std::filesystem::path& root_path) {
        _root_path = std::filesystem::canonical(root_path);
    }

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

        something_done(_blobs.update(this->bus_node().post_callable()));
        const auto opt_max_size = this->bus_node().max_data_size();
        if(EAGINE_LIKELY(opt_max_size)) {
            something_done(_blobs.process_outgoing(
              this->bus_node().post_callable(), extract(opt_max_size)));
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
    auto _get_file_path(const url& locator) const -> std::filesystem::path {
        try {
            if(auto loc_path_str{locator.path_str()}) {
                std::filesystem::path loc_path{
                  std::string_view{extract(loc_path_str)}};
                if(_root_path.empty()) {
                    if(loc_path.is_absolute()) {
                        return loc_path;
                    }
                    return std::filesystem::current_path().root_path() /
                           loc_path;
                }
                if(loc_path.is_absolute()) {
                    return std::filesystem::canonical(
                      _root_path / loc_path.relative_path());
                }
                return std::filesystem::canonical(_root_path / loc_path);
            }
        } catch(const std::runtime_error&) {
        }
        return {};
    }

    auto _get_resource(
      const message_context& ctx,
      const url& locator,
      identifier_t endpoint_id,
      message_priority priority) -> std::
      tuple<std::unique_ptr<blob_io>, std::chrono::seconds, message_priority> {
        auto read_io = get_resource_io(endpoint_id, locator);
        if(!read_io) {
            if(locator.has_scheme("eagires")) {
                if(auto count{locator.argument("count")}) {
                    if(auto bytes{from_string<span_size_t>(extract(count))}) {
                        if(locator.has_path("/random")) {
                            read_io = std::make_unique<random_byte_blob_io>(
                              extract(bytes));
                        } else if(locator.has_path("/zeroes")) {
                            read_io = std::make_unique<single_byte_blob_io>(
                              extract(bytes), 0x0U);
                        } else if(locator.has_path("/ones")) {
                            read_io = std::make_unique<single_byte_blob_io>(
                              extract(bytes), 0x1U);
                        }
                    }
                }
            } else if(locator.has_scheme("file")) {
                const auto file_path = _get_file_path(locator);
                const bool is_contained =
                  starts_with(string_view(file_path), string_view(_root_path));
                ctx.bus_node()
                  .log_info("sending file ${filePath} to ${target}")
                  .arg(EAGINE_ID(target), endpoint_id)
                  .arg(EAGINE_ID(filePath), EAGINE_ID(FsPath), file_path);
                if(is_contained) {
                    std::fstream file{
                      file_path, std::ios::in | std::ios::binary};
                    if(file.is_open()) {
                        read_io = std::make_unique<file_blob_io>(
                          std::move(file),
                          from_string<span_size_t>(extract_or(
                            locator.argument("offs"), string_view{})),
                          from_string<span_size_t>(extract_or(
                            locator.argument("size"), string_view{})));
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
              _get_resource(ctx, locator, message.source_id, message.priority);
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
    std::filesystem::path _root_path{};
};
//------------------------------------------------------------------------------
/// @brief Service manipulating files over the message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see resource_manipulator
template <typename Base = subscriber>
class resource_manipulator
  : public require_services<Base, host_info_consumer, subscriber_discovery> {

    using This = resource_manipulator;
    using base =
      require_services<Base, host_info_consumer, subscriber_discovery>;

public:
    /// @brief Triggered when a resource server appears on the bus.
    signal<void(identifier_t)> resource_server_appeared;

    /// @brief Triggered when a resource server dissapears from the bus.
    signal<void(identifier_t)> resource_server_lost;

    /// @brief Returns the best-guess of server endpoint id for a URL.
    /// @see query_resource_content
    auto server_endpoint_id(const url& locator) -> identifier_t {
        if(locator.has_scheme("eagimbe")) {
            if(const auto opt_id{from_string<identifier_t>(
                 extract_or(locator.host(), string_view{}))}) {
                const auto endpoint_id = extract(opt_id);
                const auto spos = _server_endpoints.find(endpoint_id);
                if(spos != _server_endpoints.end()) {
                    return endpoint_id;
                }
            }
        } else if(locator.has_scheme("eagimbh")) {
            if(const auto hostname{locator.host()}) {
                const auto hpos = _hostname_to_endpoint.find(extract(hostname));
                if(hpos != _hostname_to_endpoint.end()) {
                    for(const auto endpoint_id : std::get<1>(*hpos)) {
                        const auto spos = _server_endpoints.find(endpoint_id);
                        if(spos != _server_endpoints.end()) {
                            return endpoint_id;
                        }
                    }
                }
            }
        }
        return broadcast_endpoint_id();
    }

    /// @brief Requests the contents of the file with the specified URL.
    auto query_resource_content(
      identifier_t endpoint_id,
      const url& locator,
      std::shared_ptr<blob_io> write_io,
      message_priority priority,
      std::chrono::seconds max_time) -> optionally_valid<message_sequence_t> {
        const auto request = std::make_tuple(locator.str());
        auto buffer = default_serialize_buffer_for(request);

        if(endpoint_id == broadcast_endpoint_id()) {
            endpoint_id = server_endpoint_id(locator);
        }

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

    /// @brief Requests the contents of the file with the specified URL.
    /// @see server_endpoint_id
    auto query_resource_content(
      const url& locator,
      std::shared_ptr<blob_io> write_io,
      message_priority priority,
      std::chrono::seconds max_time) -> optionally_valid<message_sequence_t> {
        return query_resource_content(
          server_endpoint_id(locator),
          locator,
          std::move(write_io),
          priority,
          max_time);
    }

protected:
    using base::base;

    void init() {
        base::init();

        this->reported_alive.connect(EAGINE_THIS_MEM_FUNC_REF(_handle_alive));
        this->subscribed.connect(EAGINE_THIS_MEM_FUNC_REF(_handle_subscribed));
        this->unsubscribed.connect(
          EAGINE_THIS_MEM_FUNC_REF(_handle_unsubscribed));
        this->not_subscribed.connect(
          EAGINE_THIS_MEM_FUNC_REF(_handle_unsubscribed));
        this->host_id_received.connect(
          EAGINE_THIS_MEM_FUNC_REF(_handle_host_id_received));
        this->hostname_received.connect(
          EAGINE_THIS_MEM_FUNC_REF(_handle_hostname_received));
    }

    void add_methods() {
        base::add_methods();

        base::add_method(
          this,
          EAGINE_MSG_MAP(
            eagiRsrces, fragment, This, _handle_resource_fragment));
        base::add_method(
          this,
          EAGINE_MSG_MAP(
            eagiRsrces, fragResend, This, _handle_resource_resend_request));
    }

    auto update() -> bool {
        some_true something_done;

        something_done(base::update());
        something_done(_blobs.handle_complete() > 0);

        if(_search_servers) {
            this->bus_node().query_subscribers_of(
              EAGINE_MSG_ID(eagiRsrces, getContent));
            something_done();
        }

        return something_done;
    }

private:
    void _handle_alive(const subscriber_info& sub_info) {
        const auto pos = _server_endpoints.find(sub_info.endpoint_id);
        if(pos != _server_endpoints.end()) {
            auto& svr_info = std::get<1>(*pos);
            svr_info.last_report_time = std::chrono::steady_clock::now();
        }
    }

    void _handle_subscribed(const subscriber_info& sub_info, message_id msg_id) {
        if(msg_id == EAGINE_MSG_ID(eagiRsrces, getContent)) {
            auto spos = _server_endpoints.find(sub_info.endpoint_id);
            if(spos == _server_endpoints.end()) {
                spos = _server_endpoints.emplace(sub_info.endpoint_id).first;
                resource_server_appeared(sub_info.endpoint_id);
            }
            auto& svr_info = std::get<1>(*spos);
            svr_info.last_report_time = std::chrono::steady_clock::now();
        }
    }

    void _remove_server(identifier_t endpoint_id) {
        const auto spos = _server_endpoints.find(endpoint_id);
        if(spos != _server_endpoints.end()) {
            resource_server_lost(endpoint_id);
            _server_endpoints.erase(spos);
        }
        for(auto& entry : _host_id_to_endpoint) {
            std::get<1>(entry).erase(endpoint_id);
        }
        _host_id_to_endpoint.erase(
          std::remove_if(
            _host_id_to_endpoint.begin(),
            _host_id_to_endpoint.end(),
            [](const auto& entry) { return std::get<1>(entry).empty(); }),
          _host_id_to_endpoint.end());
        for(auto& entry : _hostname_to_endpoint) {
            std::get<1>(entry).erase(endpoint_id);
        }
        _hostname_to_endpoint.erase(
          std::remove_if(
            _hostname_to_endpoint.begin(),
            _hostname_to_endpoint.end(),
            [](const auto& entry) { return std::get<1>(entry).empty(); }),
          _hostname_to_endpoint.end());
    }

    void
    _handle_unsubscribed(const subscriber_info& sub_info, message_id msg_id) {
        if(msg_id == EAGINE_MSG_ID(eagiRsrces, getContent)) {
            _remove_server(sub_info.endpoint_id);
        }
    }

    void _handle_host_id_received(
      const result_context& ctx,
      const valid_if_positive<host_id_t>& host_id) {
        if(host_id) {
            _host_id_to_endpoint[extract(host_id)].insert(ctx.source_id());
        }
    }

    void _handle_hostname_received(
      const result_context& ctx,
      const valid_if_not_empty<std::string>& hostname) {
        if(hostname) {
            _hostname_to_endpoint[extract(hostname)].insert(ctx.source_id());
        }
    }
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

    resetting_timeout _search_servers{std::chrono::seconds{5}, nothing};

    flat_map<std::string, flat_set<identifier_t>, str_view_less>
      _hostname_to_endpoint;
    flat_map<identifier_t, flat_set<identifier_t>> _host_id_to_endpoint;

    struct _server_info {
        std::chrono::steady_clock::time_point last_report_time{};
    };

    flat_map<identifier_t, _server_info> _server_endpoints;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_RESOURCE_TRANSFER_HPP
