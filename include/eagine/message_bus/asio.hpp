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
#include "conn_factory.hpp"
#include "serialize.hpp"
#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
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

template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
class asio_connection;

template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
class asio_connector;

template <asio_connection_addr_kind K, asio_connection_protocol P>
class asio_acceptor;
//------------------------------------------------------------------------------
template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
class asio_connection_base
  : public std::enable_shared_from_this<asio_connection_base<Kind, Proto>>
  , public asio_connection_info<connection, Kind, Proto> {

protected:
    std::mutex _mutex;
    std::shared_ptr<asio_common_state> _asio_state;

    memory::buffer _buffer;
    message_storage _incoming;
    serialized_message_storage _outgoing;

    void _handle_sent(span_size_t) {
        this->_outgoing.pop();
    }

    void _handle_received(memory::const_block data) {
        _incoming.push_if([data](
                            identifier_t& class_id,
                            identifier_t& method_id,
                            stored_message& message) {
            block_data_source source(data);
            string_deserializer_backend backend(source);
            const auto errors =
              deserialize_message(class_id, method_id, message, backend);
            return !errors;
        });
    }

public:
    asio_connection_base(std::shared_ptr<asio_common_state> asio_state)
      : _asio_state{std::move(asio_state)} {
        EAGINE_ASSERT(_asio_state);
        _buffer.resize(8 * 1024);
    }

    valid_if_positive<span_size_t> max_data_size() final {
        return {_buffer.size()};
    }

    bool send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) final {
        std::unique_lock lock{_mutex};
        block_data_sink sink(cover(_buffer));
        string_serializer_backend backend(sink);
        auto errors = serialize_message(class_id, method_id, message, backend);
        if(!errors) {
            _outgoing.push(sink.done());
            return true;
        }
        return false;
    }

    void fetch_messages(connection::fetch_handler handler) final {
        std::unique_lock lock{_mutex};
        _incoming.fetch_all(handler);
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
      asio_connection_protocol::stream> {

    using base = asio_connection_base<
      asio_connection_addr_kind::ipv4,
      asio_connection_protocol::stream>;

protected:
    asio::ip::tcp::socket _socket;

    void _send() {
        if(auto blk = _outgoing.top()) {
            asio::async_write(
              _socket,
              asio::buffer(blk.data(), blk.size()),
              [this, self{this->shared_from_this()}](
                std::error_code error, std::size_t length) {
                  if(!error) {
                      this->_handle_sent(span_size(length));
                      this->_send();
                  }
              });
        }
    }

    void _receive() {
        auto blk = cover(this->_buffer);
        asio::async_read(
          _socket,
          asio::buffer(blk.data(), blk.size()),
          [this, self{this->shared_from_this()}, blk](
            std::error_code error, std::size_t length) {
              if(!error) {
                  this->_handle_received(head(blk, span_size(length)));
              }
          });
    }

    asio_connection(const std::shared_ptr<asio_common_state>& asio_state)
      : base{asio_state}
      , _socket{asio_state->context} {
    }

public:
    asio_connection(
      const std::shared_ptr<asio_common_state>& asio_state,
      asio::ip::tcp::socket socket)
      : base{asio_state}
      , _socket{std::move(socket)} {
    }

    bool is_usable() final {
        if(EAGINE_LIKELY(this->_asio_state)) {
            return _socket.is_open();
        }
        return false;
    }

    void update() override {
        EAGINE_ASSERT(this->_asio_state);
        if(_socket.is_open()) {
            _receive();
            _send();
        }
        this->_asio_state->context.poll();
    }
};
//------------------------------------------------------------------------------
template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
class asio_connector : public asio_connection<Kind, Proto> {
    using base = asio_connection<Kind, Proto>;

    std::string _addr_str;

public:
    asio_connector(
      std::shared_ptr<asio_common_state>& asio_state, string_view addr_str)
      : base{asio_state}
      , _addr_str{to_string(addr_str)} {
    }

    void update() final {
        EAGINE_ASSERT(this->_asio_state);
        if(!this->_socket.is_open()) {
        }
        if(this->_socket.is_open()) {
            this->_receive();
            this->_send();
        }
        this->_asio_state->context.poll();
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
        _socket = asio::ip::tcp::socket(
          this->_asio_state->context, asio::ip::tcp::v4());
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
            asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 3491);
            _acceptor.open(endpoint.protocol());
            _acceptor.bind(endpoint);
            _acceptor.listen();
            _start_accept();
        }
        this->_asio_state->context.poll();
    }

    void process_accepted(const accept_handler& handler) final {
        for(auto& socket : _accepted) {
            handler(std::make_unique<asio_connection<
                      asio_connection_addr_kind::ipv4,
                      asio_connection_protocol::stream>>(
              this->_asio_state, std::move(socket)));
        }
        _accepted.clear();
    }
};
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
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_ASIO_HPP
