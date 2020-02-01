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
        return EAGINE_ID(AsioTcpLcl);
    }
};
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
template <asio_connection_addr_kind, asio_connection_protocol>
struct asio_connection_socket;

template <asio_connection_addr_kind K, asio_connection_protocol P>
using asio_connection_socket_t = typename asio_connection_socket<K, P>::type;
//------------------------------------------------------------------------------
template <>
struct asio_connection_socket<
  asio_connection_addr_kind::ipv4,
  asio_connection_protocol::stream> : identity<asio::ip::tcp::socket> {};
//------------------------------------------------------------------------------
template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
class asio_connection
  : public std::enable_shared_from_this<asio_connection<Kind, Proto>>
  , public asio_connection_info<connection, Kind, Proto> {

    using socket_t = asio_connection_socket_t<Kind, Proto>;

protected:
    std::mutex _mutex;
    std::shared_ptr<asio_common_state> _asio_state;
    socket_t _socket;

private:
    memory::buffer _buffer;
    message_storage _incoming;
    serialized_message_storage _outgoing;

    void _send() {
        if(auto blk = _outgoing.top()) {
            asio::async_write(
              _socket,
              asio::buffer(blk.data(), blk.size()),
              [this, self{this->shared_from_this()}](
                std::error_code error, std::size_t length) {
                  if(!error) {
                      this->_handle_sent(span_size(length));
                  }
              });
        }
    }

    void _handle_sent(span_size_t) {
        this->_outgoing.pop();
        this->_send();
    }

    void _receive() {
        asio::async_read(
          _socket,
          asio::buffer(_buffer.data(), _buffer.size()),
          [this, self{this->shared_from_this()}](
            std::error_code error, std::size_t length) {
              if(!error) {
                  this->_handle_received(
                    head(view(_buffer), span_size(length)));
              }
          });
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
    asio_connection(
      std::shared_ptr<asio_common_state> asio_state, socket_t socket) noexcept
      : _asio_state{std::move(asio_state)}
      , _socket{std::move(socket)} {
        EAGINE_ASSERT(_asio_state);
        _buffer.resize(8 * 1024);
    }

    bool is_usable() final {
        if(EAGINE_LIKELY(_asio_state)) {
            return _socket.is_open();
        }
        return false;
    }

    void update() final {
        if(EAGINE_LIKELY(_asio_state)) {
            _receive();
            _send();
            _asio_state->context.poll();
        }
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
template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
class asio_connector : public asio_connection<Kind, Proto> {
    using base = asio_connection<Kind, Proto>;
    using socket_t = asio_connection_socket_t<Kind, Proto>;

    std::string _addr_str;

public:
    asio_connector(
      std::shared_ptr<asio_common_state>& asio_state, string_view addr_str)
      : base{asio_state, socket_t{asio_state->context}}
      , _addr_str{to_string(addr_str)} {
    }
};
//------------------------------------------------------------------------------
template <asio_connection_addr_kind, asio_connection_protocol>
class asio_acceptor : public acceptor {
private:
    std::shared_ptr<asio_common_state> _asio_state;

public:
    asio_acceptor(
      std::shared_ptr<asio_common_state> asio_state, string_view) noexcept
      : _asio_state{std::move(asio_state)} {
    }

    void process_accepted(const accept_handler& handler) final {
        EAGINE_MAYBE_UNUSED(handler);
    }
};
//------------------------------------------------------------------------------
template <asio_connection_addr_kind, asio_connection_protocol>
class asio_connection_factory;
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
