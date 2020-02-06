/**
 *  @file eagine/message_bus/asio.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ASIO_HPP
#define EAGINE_MESSAGE_BUS_ASIO_HPP

#include "../branch_predict.hpp"
#include "../config/platform.hpp"
#include "../serialize/size_and_data.hpp"
#include "conn_factory.hpp"
#include "serialize.hpp"
#include <asio/connect.hpp>
#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#if EAGINE_POSIX
#include <asio/local/stream_protocol.hpp>
#endif
#include <asio/read.hpp>
#include <asio/write.hpp>
#include <mutex>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
enum class asio_connection_addr_kind { local, ipv4 };
enum class asio_connection_protocol { stream, datagram };
//------------------------------------------------------------------------------
struct asio_common_state {
    asio::io_context context;
};
//------------------------------------------------------------------------------
template <typename Base, asio_connection_addr_kind, asio_connection_protocol>
class asio_connection_info;

template <asio_connection_addr_kind, asio_connection_protocol>
class asio_connection;

template <asio_connection_addr_kind, asio_connection_protocol>
class asio_connector;

template <asio_connection_addr_kind, asio_connection_protocol>
class asio_acceptor;
//------------------------------------------------------------------------------
template <typename Socket>
struct asio_connection_state
  : std::enable_shared_from_this<asio_connection_state<Socket>> {

    std::mutex mutex;
    std::shared_ptr<asio_common_state> common;
    Socket socket;

    memory::buffer read_buffer;
    memory::buffer write_buffer;
    message_storage incoming;
    serialized_message_storage outgoing;
    bool is_sending{false};
    bool is_recving{false};

    asio_connection_state(
      std::shared_ptr<asio_common_state> asio_state, Socket sock)
      : common{std::move(asio_state)}
      , socket{std::move(sock)} {
        EAGINE_ASSERT(common);
        read_buffer.resize(8 * 1024);
        zero(cover(read_buffer));
        write_buffer.resize(read_buffer.size());
        zero(cover(write_buffer));
    }

    asio_connection_state(
      const std::shared_ptr<asio_common_state>& asio_state) noexcept
      : asio_connection_state{asio_state, Socket{asio_state->context}} {
    }

    bool is_usable() const {
        if(EAGINE_LIKELY(common)) {
            return socket.is_open();
        }
        return false;
    }

    bool enqueue(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        std::unique_lock lock{mutex};
        block_data_sink sink(cover(write_buffer));
        string_serializer_backend backend(sink);
        auto errors = serialize_message(class_id, method_id, message, backend);
        if(!errors) {
            outgoing.push(sink.done());
            return true;
        }
        return false;
    }

    void fetch_messages(connection::fetch_handler handler) {
        std::unique_lock lock{mutex};
        incoming.fetch_all(handler);
    }

    void handle_sent(span_size_t) {
        outgoing.pop();
        is_sending = false;
    }

    void start_send() {
        if(auto to_be_sent = outgoing.top()) {
            if(!is_sending) {
                if(store_data_with_size(to_be_sent, cover(write_buffer))) {
                    is_sending = true;
                    asio::async_write(
                      socket,
                      asio::buffer(write_buffer.data(), write_buffer.size()),
                      [this, self{this->shared_from_this()}](
                        std::error_code error, std::size_t length) {
                          if(!error) {
                              this->handle_sent(span_size(length));
                              this->start_send();
                          } else {
                              this->is_sending = false;
                          }
                      });
                }
            }
        }
    }

    void handle_received(memory::const_block data) {
        if(const auto blk = get_data_with_size(data)) {
            incoming.push_if([blk](
                               identifier_t& class_id,
                               identifier_t& method_id,
                               stored_message& message) {
                block_data_source source(blk);
                string_deserializer_backend backend(source);
                const auto errors =
                  deserialize_message(class_id, method_id, message, backend);
                return !errors;
            });
        }
        is_recving = false;
    }

    void start_receive() {
        if(!is_recving) {
            is_recving = true;
            auto blk = cover(read_buffer);
            asio::async_read(
              socket,
              asio::buffer(blk.data(), blk.size()),
              [this, self{this->shared_from_this()}, blk](
                std::error_code error, std::size_t length) {
                  if(!error) {
                      this->handle_received(head(blk, span_size(length)));
                      this->start_receive();
                  } else {
                      this->is_recving = false;
                  }
              });
        }
    }

    void update() {
        common->context.poll();
    }
};
//------------------------------------------------------------------------------
template <
  asio_connection_addr_kind Kind,
  asio_connection_protocol Proto,
  typename Socket>
class asio_connection_base
  : public asio_connection_info<connection, Kind, Proto> {

protected:
    std::shared_ptr<asio_connection_state<Socket>> _state;

public:
    asio_connection_base(std::shared_ptr<asio_common_state> asio_state)
      : _state{std::make_shared<asio_connection_state<Socket>>(
          std::move(asio_state))} {
        EAGINE_ASSERT(_state);
    }

    asio_connection_base(
      std::shared_ptr<asio_common_state> asio_state, Socket socket)
      : _state{std::make_shared<asio_connection_state<Socket>>(
          std::move(asio_state), std::move(socket))} {
        EAGINE_ASSERT(_state);
    }

    valid_if_positive<span_size_t> max_data_size() final {
        EAGINE_ASSERT(_state);
        return {_state->write_buffer.size()};
    }

    bool is_usable() final {
        EAGINE_ASSERT(_state);
        return _state->is_usable();
    }

    bool send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) final {
        EAGINE_ASSERT(_state);
        return _state->enqueue(class_id, method_id, message);
    }

    void fetch_messages(connection::fetch_handler handler) final {
        EAGINE_ASSERT(_state);
        _state->fetch_messages(handler);
    }
};
//------------------------------------------------------------------------------
// TCP/IPv4
//------------------------------------------------------------------------------
template <typename Base>
class asio_connection_info<
  Base,
  asio_connection_addr_kind::ipv4,
  asio_connection_protocol::stream> : public Base {
public:
    connection_kind kind() final {
        return connection_kind::remote_interprocess;
    }

    identifier type_id() final {
        return EAGINE_ID(AsioTcpIp4);
    }
};
//------------------------------------------------------------------------------
template <>
class asio_connection<
  asio_connection_addr_kind::ipv4,
  asio_connection_protocol::stream>
  : public asio_connection_base<
      asio_connection_addr_kind::ipv4,
      asio_connection_protocol::stream,
      asio::ip::tcp::socket> {

    using base = asio_connection_base<
      asio_connection_addr_kind::ipv4,
      asio_connection_protocol::stream,
      asio::ip::tcp::socket>;

public:
    using base::base;

    void update() override {
        EAGINE_ASSERT(this->_state);
        this->_state->start_receive();
        this->_state->start_send();
        this->_state->update();
    }
};
//------------------------------------------------------------------------------
template <>
class asio_connector<
  asio_connection_addr_kind::ipv4,
  asio_connection_protocol::stream>
  : public asio_connection<
      asio_connection_addr_kind::ipv4,
      asio_connection_protocol::stream> {
    using base = asio_connection<
      asio_connection_addr_kind::ipv4,
      asio_connection_protocol::stream>;

    asio::ip::tcp::resolver _resolver;
    std::string _addr_str;
    bool _connecting{false};

    void _start_connect(asio::ip::tcp::resolver::iterator resolved) {
        asio::ip::tcp::endpoint ep = *resolved;
        ep.port(34912);
        this->_state->socket.async_connect(
          ep, [this, resolved](std::error_code error) mutable {
              if(!error) {
                  this->_connecting = false;
              } else {
                  if(++resolved != asio::ip::tcp::resolver::iterator{}) {
                      this->_start_connect(resolved);
                  } else {
                      this->_connecting = false;
                  }
              }
          });
    }

    void _start_resolve() {
        auto host = _addr_str.empty() ? asio::string_view("localhost")
                                      : asio::string_view(_addr_str);
        _resolver.async_resolve(
          host, {}, [this](std::error_code error, auto resolved) {
              if(!error) {
                  this->_start_connect(resolved);
              } else {
                  this->_connecting = false;
              }
          });
    }

public:
    asio_connector(
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str)
      : base{asio_state}
      , _resolver{asio_state->context}
      , _addr_str{to_string(addr_str)} {
    }

    void update() final {
        EAGINE_ASSERT(this->_state);
        if(this->_state->socket.is_open()) {
            this->_state->start_receive();
            this->_state->start_send();
        } else if(!_connecting) {
            _connecting = true;
            _start_resolve();
        }
        this->_state->update();
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<
  asio_connection_addr_kind::ipv4,
  asio_connection_protocol::stream> : public acceptor {
private:
    std::shared_ptr<asio_common_state> _asio_state;
    std::string _addr_str;
    asio::ip::tcp::acceptor _acceptor;
    asio::ip::tcp::socket _socket;

    std::vector<asio::ip::tcp::socket> _accepted;

    void _start_accept() {
        _socket = asio::ip::tcp::socket(this->_asio_state->context);
        _acceptor.async_accept(_socket, [this](std::error_code error) {
            if(!error) {
                this->_accepted.emplace_back(std::move(this->_socket));
            }
            _start_accept();
        });
    }

public:
    asio_acceptor(
      std::shared_ptr<asio_common_state> asio_state,
      string_view addr_str) noexcept
      : _asio_state{std::move(asio_state)}
      , _addr_str{to_string(addr_str)}
      , _acceptor{_asio_state->context}
      , _socket{_asio_state->context} {
    }

    void update() final {
        EAGINE_ASSERT(this->_asio_state);
        if(!_acceptor.is_open()) {
            // TODO: addr string
            asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 34912);
            _acceptor.open(endpoint.protocol());
            _acceptor.bind(endpoint);
            _acceptor.listen();
            _start_accept();
        }
        this->_asio_state->context.poll();
    }

    void process_accepted(const accept_handler& handler) final {
        for(auto& socket : _accepted) {
            auto conn = std::make_unique<asio_connection<
              asio_connection_addr_kind::ipv4,
              asio_connection_protocol::stream>>(
              _asio_state, std::move(socket));
            handler(std::move(conn));
        }
        _accepted.clear();
    }
};
//------------------------------------------------------------------------------
// Local/Stream
#if EAGINE_POSIX
//------------------------------------------------------------------------------
template <typename Base>
class asio_connection_info<
  Base,
  asio_connection_addr_kind::local,
  asio_connection_protocol::stream> : public Base {
public:
    connection_kind kind() final {
        return connection_kind::local_interprocess;
    }

    identifier type_id() final {
        return EAGINE_ID(AsioLclStr);
    }
};
//------------------------------------------------------------------------------
template <>
class asio_connection<
  asio_connection_addr_kind::local,
  asio_connection_protocol::stream>
  : public asio_connection_base<
      asio_connection_addr_kind::local,
      asio_connection_protocol::stream,
      asio::local::stream_protocol::socket> {

    using base = asio_connection_base<
      asio_connection_addr_kind::local,
      asio_connection_protocol::stream,
      asio::local::stream_protocol::socket>;

public:
    using base::base;

    void update() override {
        EAGINE_ASSERT(this->_state);
        this->_state->start_receive();
        this->_state->start_send();
        this->_state->update();
    }
};
//------------------------------------------------------------------------------
template <>
class asio_connector<
  asio_connection_addr_kind::local,
  asio_connection_protocol::stream>
  : public asio_connection<
      asio_connection_addr_kind::local,
      asio_connection_protocol::stream> {
    using base = asio_connection<
      asio_connection_addr_kind::local,
      asio_connection_protocol::stream>;

    asio::local::stream_protocol::endpoint _endpoint;
    bool _connecting{false};

    void _start_connect() {
        this->_state->socket.async_connect(
          _endpoint,
          [this](std::error_code) mutable { this->_connecting = false; });
    }

public:
    asio_connector(
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str)
      : base{asio_state}
      , _endpoint{c_str(addr_str)} {
    }

    void update() final {
        EAGINE_ASSERT(this->_state);
        if(this->_state->socket.is_open()) {
            this->_state->start_receive();
            this->_state->start_send();
        } else if(!_connecting) {
            _connecting = true;
            _start_connect();
        }
        this->_state->update();
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<
  asio_connection_addr_kind::local,
  asio_connection_protocol::stream> : public acceptor {
private:
    std::shared_ptr<asio_common_state> _asio_state;
    std::string _addr_str;
    asio::local::stream_protocol::acceptor _acceptor;
    bool _accepting{false};

    std::vector<asio::local::stream_protocol::socket> _accepted;

    void _start_accept() {
        _accepting = true;
        _acceptor.async_accept([this](
                                 std::error_code error,
                                 asio::local::stream_protocol::socket socket) {
            if(error) {
                this->_accepting = false;
            } else {
                this->_accepted.emplace_back(std::move(socket));
            }
            _start_accept();
        });
    }

    static inline std::shared_ptr<asio_common_state> _prepare(
      std::shared_ptr<asio_common_state> asio_state, string_view addr_str) {
        std::remove(c_str(addr_str));
        return asio_state;
    }

public:
    asio_acceptor(
      std::shared_ptr<asio_common_state> asio_state,
      string_view addr_str) noexcept
      : _asio_state{_prepare(std::move(asio_state), addr_str)}
      , _addr_str{to_string(addr_str)}
      , _acceptor{_asio_state->context,
                  asio::local::stream_protocol::endpoint(_addr_str.c_str())} {
    }

    ~asio_acceptor() noexcept {
        try {
            std::remove(_addr_str.c_str());
        } catch(...) {
        }
    }

    asio_acceptor(asio_acceptor&&) = delete;
    asio_acceptor(const asio_acceptor&) = delete;
    asio_acceptor& operator=(asio_acceptor&&) = delete;
    asio_acceptor& operator=(const asio_acceptor&) = delete;

    void update() final {
        EAGINE_ASSERT(this->_asio_state);
        if(EAGINE_UNLIKELY(!_acceptor.is_open())) {
            _acceptor = {
              _asio_state->context,
              asio::local::stream_protocol::endpoint(_addr_str.c_str())};
        }
        if(_acceptor.is_open() && !_accepting) {
            _start_accept();
        }
        this->_asio_state->context.poll();
    }

    void process_accepted(const accept_handler& handler) final {
        for(auto& socket : _accepted) {
            auto conn = std::make_unique<asio_connection<
              asio_connection_addr_kind::local,
              asio_connection_protocol::stream>>(
              _asio_state, std::move(socket));
            handler(std::move(conn));
        }
        _accepted.clear();
    }
};
//------------------------------------------------------------------------------
#endif // EAGINE_POSIX
//------------------------------------------------------------------------------
// Factory
//------------------------------------------------------------------------------
template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
class asio_connection_factory
  : public asio_connection_info<connection_factory, Kind, Proto> {
private:
    std::shared_ptr<asio_common_state> _asio_state;

public:
    using connection_factory::make_acceptor;
    using connection_factory::make_connector;

    asio_connection_factory(
      std::shared_ptr<asio_common_state> asio_state) noexcept
      : _asio_state{std::move(asio_state)} {
    }

    asio_connection_factory()
      : asio_connection_factory{std::make_shared<asio_common_state>()} {
    }

    std::unique_ptr<acceptor> make_acceptor(string_view addr_str) final {
        return std::make_unique<asio_acceptor<Kind, Proto>>(
          _asio_state, addr_str);
    }

    std::unique_ptr<connection> make_connector(string_view addr_str) final {
        return std::make_unique<asio_connector<Kind, Proto>>(
          _asio_state, addr_str);
    }
};
//------------------------------------------------------------------------------
using asio_tcp_ipv4_connection_factory = asio_connection_factory<
  asio_connection_addr_kind::ipv4,
  asio_connection_protocol::stream>;
//------------------------------------------------------------------------------
#if EAGINE_POSIX
using asio_local_stream_connection_factory = asio_connection_factory<
  asio_connection_addr_kind::local,
  asio_connection_protocol::stream>;
#endif // EAGINE_POSIX
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_ASIO_HPP
