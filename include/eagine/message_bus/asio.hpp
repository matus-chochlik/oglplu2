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

#include "../bool_aggregate.hpp"
#include "../branch_predict.hpp"
#include "../config/platform.hpp"
#include "../from_string.hpp"
#include "../logging/exception.hpp"
#include "../logging/logger.hpp"
#include "../maybe_unused.hpp"
#include "../serialize/size_and_data.hpp"
#include "../timeout.hpp"
#include "conn_factory.hpp"
#include "serialize.hpp"
#include <mutex>
#include <thread>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wdeprecated"
#endif

#include <asio/connect.hpp>
#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <asio/ip/udp.hpp>
#if EAGINE_POSIX
#include <asio/local/stream_protocol.hpp>
#endif
#include <asio/read.hpp>
#include <asio/write.hpp>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

namespace eagine::msgbus {
//------------------------------------------------------------------------------
enum class connection_addr_kind { local, ipv4 };
enum class connection_protocol { stream, datagram };

template <connection_protocol Proto>
using connection_protocol_tag =
  std::integral_constant<connection_protocol, Proto>;

using stream_protocol_tag =
  connection_protocol_tag<connection_protocol::stream>;
using datagram_protocol_tag =
  connection_protocol_tag<connection_protocol::datagram>;
//------------------------------------------------------------------------------
template <typename Socket>
class flushing_sockets {
public:
    void adopt(Socket& sckt) {
        _waiting.emplace_back(std::chrono::seconds(10), std::move(sckt));
    }

    bool empty() const noexcept {
        return _waiting.empty();
    }

    void update() noexcept {
        _waiting.erase(
          std::remove_if(
            _waiting.begin(),
            _waiting.end(),
            [](auto& waiting) { return bool(std::get<0>(waiting)); }),
          _waiting.end());
    }

private:
    std::vector<std::tuple<timeout, Socket>> _waiting;
};
//------------------------------------------------------------------------------
struct asio_common_state {
    asio::io_context context;

    asio_common_state() = default;
    asio_common_state(asio_common_state&&) = delete;
    asio_common_state(const asio_common_state&) = delete;
    asio_common_state& operator=(asio_common_state&&) = delete;
    asio_common_state& operator=(const asio_common_state&) = delete;

    ~asio_common_state() noexcept {
        while(has_flushing()) {
            update();
            std::this_thread::yield();
        }
    }

    template <typename Socket>
    void adopt_flushing(Socket& sckt) {
        std::get<flushing_sockets<Socket>>(_flushing).adopt(sckt);
    }

    void update() noexcept {
        _update_flushing(_flushing);
    }

    bool has_flushing() const noexcept {
        return _has_flushing(_flushing);
    }

private:
    template <typename Tup, std::size_t... I>
    static void _do_update_flushing(
      Tup& flushing, std::index_sequence<I...>) noexcept {
        (..., std::get<I>(flushing).update());
    }

    template <typename Tup>
    static void _update_flushing(Tup& flushing) noexcept {
        _do_update_flushing(
          flushing, std::make_index_sequence<std::tuple_size_v<Tup>>());
    }

    template <typename Tup, std::size_t... I>
    static bool _does_have_flushing(
      Tup& flushing, std::index_sequence<I...>) noexcept {
        return (false || ... || !std::get<I>(flushing).empty());
    }

    template <typename Tup>
    static bool _has_flushing(Tup& flushing) noexcept {
        return _does_have_flushing(
          flushing, std::make_index_sequence<std::tuple_size_v<Tup>>());
    }

    std::tuple<
#if EAGINE_POSIX
      flushing_sockets<asio::local::stream_protocol::socket>,
#endif
      flushing_sockets<asio::ip::tcp::socket>,
      flushing_sockets<asio::ip::udp::socket>>
      _flushing;
};
//------------------------------------------------------------------------------
template <connection_addr_kind, connection_protocol>
struct asio_types;

template <typename Base, connection_addr_kind, connection_protocol>
class asio_connection_info;

template <connection_addr_kind, connection_protocol>
class asio_connection;

template <connection_addr_kind, connection_protocol>
class asio_connector;

template <connection_addr_kind, connection_protocol>
class asio_acceptor;
//------------------------------------------------------------------------------
template <typename Endpoint>
struct connection_sink {
    connection_sink() noexcept = default;
    connection_sink(connection_sink&&) = delete;
    connection_sink(const connection_sink&) = delete;
    connection_sink& operator=(connection_sink&&) = delete;
    connection_sink& operator=(const connection_sink&) = delete;
    virtual ~connection_sink() noexcept = default;

    virtual void on_received(const Endpoint& source, memory::const_block) = 0;
};
//------------------------------------------------------------------------------
template <typename Socket, connection_protocol Proto, span_size_t Batch>
struct connection_state
  : std::enable_shared_from_this<connection_state<Socket, Proto, Batch>> {

    logger _log{};
    std::mutex mutex;
    std::shared_ptr<asio_common_state> common;
    Socket socket;
    typename Socket::endpoint_type endpoint;
    connection_sink<typename Socket::endpoint_type>* conn_sink{nullptr};

    memory::buffer push_buffer;
    memory::buffer read_buffer;
    memory::buffer write_buffer;
    serialized_message_storage incoming;
    serialized_message_storage outgoing;
    message_storage unpacked;
    bool is_sending{false};
    bool is_recving{false};
    bool has_recved{false};

    connection_state(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      Socket sock)
      : _log{EAGINE_ID(AsioConnSt), parent}
      , common{std::move(asio_state)}
      , socket{std::move(sock)} {
        EAGINE_ASSERT(common);
        common->update();
        push_buffer.resize(8 * 1024);
        zero(cover(push_buffer));
        read_buffer.resize(push_buffer.size());
        zero(cover(read_buffer));
        write_buffer.resize(push_buffer.size());
        zero(cover(write_buffer));

        _log.debug("allocating write buffer of ${size}")
          .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), write_buffer.size());
        _log.debug("allocating read buffer of ${size}")
          .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), read_buffer.size());
    }

    connection_state(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state) noexcept
      : connection_state{parent, asio_state, Socket{asio_state->context}} {
    }

    auto weak_ref() noexcept {
        return std::weak_ptr(this->shared_from_this());
    }

    bool is_usable() const {
        if(EAGINE_LIKELY(common)) {
            return socket.is_open();
        }
        return false;
    }

    bool enqueue(message_id msg_id, const message_view& message) {
        std::unique_lock lock{mutex};
        block_data_sink sink(cover(push_buffer));
        string_serializer_backend backend(sink);
        auto errors = serialize_message(msg_id, message, backend);
        if(!errors) {
            _log.trace("enqueuing message ${message} to be sent")
              .arg(EAGINE_ID(message), msg_id);
            outgoing.push(sink.done());
            return true;
        }
        _log.error("failed to serialize message ${message}")
          .arg(EAGINE_ID(message), msg_id);
        return false;
    }

    bool fetch_messages(connection::fetch_handler handler) {
        std::unique_lock lock{mutex};
        unpacked.fetch_all(handler);
        auto unpacker = [this, &handler](memory::const_block data) {
            for_each_data_with_size(data, [this](memory::const_block blk) {
                unpacked.push_if(
                  [this, blk](message_id& msg_id, stored_message& message) {
                      block_data_source source(blk);
                      string_deserializer_backend backend(source);
                      const auto errors =
                        deserialize_message(msg_id, message, backend);
                      if(!errors) {
                          this->_log.trace("received message ${message}")
                            .arg(EAGINE_ID(message), msg_id);
                          return true;
                      } else {
                          _log.error("failed to deserialize message)")
                            .arg(EAGINE_ID(errorBits), errors.bits())
                            .arg(EAGINE_ID(block), blk);
                          return false;
                      }
                  });
            });
            unpacked.fetch_all(handler);
            return true;
        };

        return incoming.fetch_some(
          serialized_message_storage::fetch_handler(unpacker), Batch);
    }

    void handle_sent(serialized_message_storage::bit_set to_be_removed) {
        outgoing.cleanup(to_be_removed);
        is_sending = false;
    }

    template <typename Handler>
    void do_start_send(
      stream_protocol_tag, memory::const_block blk, Handler handler) {
        asio::async_write(
          socket, asio::buffer(blk.data(), blk.size()), handler);
    }

    template <typename Handler>
    void do_start_send(
      datagram_protocol_tag, memory::const_block blk, Handler handler) {
        socket.async_send_to(
          asio::buffer(blk.data(), blk.size()), endpoint, handler);
    }

    bool start_send() {
        std::unique_lock lock{mutex};
        if(!is_sending) {
            if(auto packed_messages = outgoing.pack_into(cover(write_buffer))) {
                is_sending = true;
                const auto blk = view(write_buffer);

                _log.trace("writing data (size: ${size})")
                  .arg(EAGINE_ID(packed), EAGINE_ID(bits), packed_messages)
                  .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), blk.size())
                  .arg(EAGINE_ID(block), blk);

                do_start_send(
                  connection_protocol_tag<Proto>{},
                  blk,
                  [this, packed_messages, selfref{weak_ref()}](
                    std::error_code error, std::size_t length) {
                      if(const auto self{selfref.lock()}) {
                          if(!error) {
                              _log.trace("sent data (size: ${size})")
                                .arg(
                                  EAGINE_ID(size), EAGINE_ID(ByteSize), length);

                              this->handle_sent(packed_messages);
                              self->start_send();
                          } else {
                              _log.error("failed to send data: ${error}")
                                .arg(EAGINE_ID(error), error);
                              this->is_sending = false;
                          }
                      }
                  });
            }
        }
        return is_sending;
    }

    void do_handle_received(stream_protocol_tag, memory::const_block data) {
        incoming.push(data);
    }

    void do_handle_received(datagram_protocol_tag, memory::const_block data) {
        if(conn_sink) {
            conn_sink->on_received(endpoint, data);
        } else {
            incoming.push(data);
        }
    }

    void handle_received(memory::const_block data) {
        do_handle_received(connection_protocol_tag<Proto>{}, data);
        is_recving = false;
        has_recved = true;
    }

    template <typename Handler>
    void do_start_receive(
      stream_protocol_tag, memory::block blk, Handler handler) {
        asio::async_read(socket, asio::buffer(blk.data(), blk.size()), handler);
    }

    template <typename Handler>
    void do_start_receive(
      datagram_protocol_tag, memory::block blk, Handler handler) {
        socket.async_receive_from(
          asio::buffer(blk.data(), blk.size()), endpoint, handler);
    }

    bool start_receive() {
        std::unique_lock lock{mutex};
        if(!is_recving) {
            is_recving = true;
            has_recved = false;
            auto blk = cover(read_buffer);

            _log.trace("reading data (size: ${size})")
              .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), blk.size());

            do_start_receive(
              connection_protocol_tag<Proto>{},
              blk,
              [this, selfref{weak_ref()}, blk](
                std::error_code error, std::size_t length) {
                  if(const auto self{selfref.lock()}) {
                      memory::const_block rcvd = head(blk, span_size(length));
                      if(!error) {
                          _log.trace("received data (size: ${size})")
                            .arg(EAGINE_ID(block), rcvd)
                            .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), length);

                          this->handle_received(rcvd);
                          self->start_receive();
                      } else {
                          if(rcvd) {
                              _log.warning("failed receiving data: ${error}")
                                .arg(EAGINE_ID(error), error);
                              this->handle_received(rcvd);
                          } else {
                              _log.error("failed to receive data: ${error}")
                                .arg(EAGINE_ID(error), error);
                          }
                          this->is_recving = false;
                          this->socket.close();
                      }
                  }
              });
        }
        return has_recved;
    }

    bool update() {
        some_true something_done{};
        if(auto count = common->context.poll()) {
            _log.trace("called ready handlers (count: ${count})")
              .arg(EAGINE_ID(count), count);
            something_done();
        } else {
            common->context.reset();
        }
        return something_done;
    }

    void cleanup() {
        while(start_send()) {
            _log.debug("flushing connection outbox (count: ${count})")
              .arg(EAGINE_ID(count), outgoing.size());
            update();
        }
        common->adopt_flushing(socket);
        common->update();
    }
};
//------------------------------------------------------------------------------
template <
  connection_addr_kind Kind,
  connection_protocol Proto,
  typename Socket,
  span_size_t Batch>
class asio_connection_base
  : public asio_connection_info<connection, Kind, Proto> {

protected:
    logger _log{};
    std::shared_ptr<connection_state<Socket, Proto, Batch>> _state;

public:
    asio_connection_base(
      logger& parent, std::shared_ptr<asio_common_state> asio_state)
      : _log{EAGINE_ID(AsioConnBs), parent}
      , _state{std::make_shared<connection_state<Socket, Proto, Batch>>(
          _log, std::move(asio_state))} {
        EAGINE_ASSERT(_state);
    }

    asio_connection_base(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      Socket socket)
      : _log{EAGINE_ID(AsioConnBs), parent}
      , _state{std::make_shared<connection_state<Socket, Proto, Batch>>(
          _log, std::move(asio_state), std::move(socket))} {
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

    bool send(message_id msg_id, const message_view& message) final {
        EAGINE_ASSERT(_state);
        return _state->enqueue(msg_id, message);
    }

    bool fetch_messages(connection::fetch_handler handler) final {
        EAGINE_ASSERT(_state);
        return _state->fetch_messages(handler);
    }
};
//------------------------------------------------------------------------------
template <connection_addr_kind Kind, connection_protocol Proto>
class asio_connection
  : public asio_connection_base<
      Kind,
      Proto,
      typename asio_types<Kind, Proto>::socket_type,
      64> {

    using base = asio_connection_base<
      Kind,
      Proto,
      typename asio_types<Kind, Proto>::socket_type,
      64>;

public:
    using base::base;

    bool update() override {
        EAGINE_ASSERT(this->_state);
        some_true something_done{};
        if(this->_state->socket.is_open()) {
            something_done(this->_state->start_receive());
            something_done(this->_state->start_send());
        }
        something_done(this->_state->update());
        return something_done;
    }

    void cleanup() final {
        this->_state->cleanup();
    }
};
//------------------------------------------------------------------------------
// IPv4
//------------------------------------------------------------------------------
using ipv4_port = unsigned short int;
static inline std::tuple<std::string, ipv4_port> parse_ipv4_addr(
  string_view addr_str) {
    auto [hostname, port_str] = split_by_last(
      addr_str ? addr_str : string_view{"localhost"}, string_view(":"));
    return {
      to_string(hostname),
      extract_or(from_string<ipv4_port>(port_str), ipv4_port{34912U})};
}
//------------------------------------------------------------------------------
// TCP/IPv4
//------------------------------------------------------------------------------
template <typename Base>
class asio_connection_info<
  Base,
  connection_addr_kind::ipv4,
  connection_protocol::stream> : public Base {
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
struct asio_types<connection_addr_kind::ipv4, connection_protocol::stream> {
    using socket_type = asio::ip::tcp::socket;
};
//------------------------------------------------------------------------------
template <>
class asio_connector<connection_addr_kind::ipv4, connection_protocol::stream>
  : public asio_connection<
      connection_addr_kind::ipv4,
      connection_protocol::stream> {
    using base =
      asio_connection<connection_addr_kind::ipv4, connection_protocol::stream>;

    asio::ip::tcp::resolver _resolver;
    std::tuple<std::string, ipv4_port> _addr;
    timeout _should_reconnect{std::chrono::seconds{1}, nothing};
    bool _connecting{false};

    void _start_connect(
      asio::ip::tcp::resolver::iterator resolved, ipv4_port port) {
        this->_state->endpoint = *resolved;
        this->_state->endpoint.port(port);

        this->_log.debug("connecting to ${host}:${port}")
          .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));

        this->_state->socket.async_connect(
          this->_state->endpoint,
          [this, resolved, port](std::error_code error) mutable {
              if(!error) {
                  this->_log.debug("connected on address ${host}:${port}")
                    .arg(
                      EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
                    .arg(
                      EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));
                  this->_connecting = false;
              } else {
                  if(++resolved != asio::ip::tcp::resolver::iterator{}) {
                      this->_start_connect(resolved, port);
                  } else {
                      this->_log
                        .error(
                          "failed to connect on address "
                          "${address}:${port}: "
                          "${error}")
                        .arg(EAGINE_ID(error), error)
                        .arg(
                          EAGINE_ID(host),
                          EAGINE_ID(IpV4Host),
                          std::get<0>(_addr))
                        .arg(
                          EAGINE_ID(port),
                          EAGINE_ID(IpV4Port),
                          std::get<1>(_addr));
                      this->_connecting = false;
                  }
              }
          });
    }

    void _start_resolve() {
        _connecting = true;
        auto& [host, port] = _addr;
        _resolver.async_resolve(
          asio::string_view(host.data(), std_size(host.size())),
          {},
          [this, port](std::error_code error, auto resolved) {
              if(!error) {
                  this->_start_connect(resolved, port);
              } else {
                  _log.error("failed to resolve address: ${error}")
                    .arg(EAGINE_ID(error), error);
                  this->_connecting = false;
              }
          });
    }

public:
    asio_connector(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str)
      : base{parent, asio_state}
      , _resolver{asio_state->context}
      , _addr{parse_ipv4_addr(addr_str)} {
    }

    bool update() final {
        EAGINE_ASSERT(this->_state);
        some_true something_done{};
        if(this->_state->socket.is_open()) {
            something_done(this->_state->start_receive());
            something_done(this->_state->start_send());
        } else if(!_connecting) {
            if(_should_reconnect) {
                _should_reconnect.reset();
                _start_resolve();
                something_done();
            }
        }
        something_done(this->_state->update());
        return something_done;
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<connection_addr_kind::ipv4, connection_protocol::stream>
  : public acceptor {
private:
    logger _log{};
    std::shared_ptr<asio_common_state> _asio_state;
    std::tuple<std::string, ipv4_port> _addr;
    asio::ip::tcp::acceptor _acceptor;
    asio::ip::tcp::socket _socket;

    std::vector<asio::ip::tcp::socket> _accepted;

    void _start_accept() {
        this->_log.debug("accepting connection on address ${host}:${port}")
          .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));

        _socket = asio::ip::tcp::socket(this->_asio_state->context);
        _acceptor.async_accept(_socket, [this](std::error_code error) {
            if(!error) {
                this->_log
                  .debug("accepted connection on address ${host}:${port}")
                  .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
                  .arg(
                    EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));
                this->_accepted.emplace_back(std::move(this->_socket));
            } else {
                this->_log
                  .error(
                    "failed to accept connection on address "
                    "${host}:${port}: "
                    "${error}")
                  .arg(EAGINE_ID(error), error)
                  .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
                  .arg(
                    EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));
            }
            _start_accept();
        });
    }

public:
    asio_acceptor(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      string_view addr_str) noexcept
      : _log{EAGINE_ID(AsioAccptr), parent}
      , _asio_state{std::move(asio_state)}
      , _addr{parse_ipv4_addr(addr_str)}
      , _acceptor{_asio_state->context}
      , _socket{_asio_state->context} {
    }

    bool update() final {
        EAGINE_ASSERT(this->_asio_state);
        some_true something_done{};
        if(!_acceptor.is_open()) {
            asio::ip::tcp::endpoint endpoint(
              asio::ip::tcp::v4(), std::get<1>(_addr));
            _acceptor.open(endpoint.protocol());
            _acceptor.bind(endpoint);
            _acceptor.listen();
            _start_accept();
            something_done();
        }
        if(this->_asio_state->context.poll()) {
            something_done();
        } else {
            this->_asio_state->context.reset();
        }
        return something_done;
    }

    bool process_accepted(const accept_handler& handler) final {
        some_true something_done{};
        for(auto& socket : _accepted) {
            auto conn = std::make_unique<asio_connection<
              connection_addr_kind::ipv4,
              connection_protocol::stream>>(
              _log, _asio_state, std::move(socket));
            handler(std::move(conn));
            something_done();
        }
        _accepted.clear();
        return something_done;
    }
};
//------------------------------------------------------------------------------
// UDP/IPv4
//------------------------------------------------------------------------------
template <typename Base>
class asio_connection_info<
  Base,
  connection_addr_kind::ipv4,
  connection_protocol::datagram> : public Base {
public:
    connection_kind kind() final {
        return connection_kind::remote_interprocess;
    }

    identifier type_id() final {
        return EAGINE_ID(AsioUdpIp4);
    }
};
//------------------------------------------------------------------------------
template <>
struct asio_types<connection_addr_kind::ipv4, connection_protocol::datagram> {
    using socket_type = asio::ip::udp::socket;
};
//------------------------------------------------------------------------------
template <>
class asio_connector<connection_addr_kind::ipv4, connection_protocol::datagram>
  : public asio_connection<
      connection_addr_kind::ipv4,
      connection_protocol::datagram> {
    using base = asio_connection<
      connection_addr_kind::ipv4,
      connection_protocol::datagram>;

    asio::ip::udp::resolver _resolver;
    std::tuple<std::string, ipv4_port> _addr;
    timeout _should_reconnect{std::chrono::seconds{1}, nothing};
    bool _connecting{false};

    void _on_resolve(
      asio::ip::udp::resolver::iterator resolved, ipv4_port port) {
        this->_state->endpoint = *resolved;
        this->_state->endpoint.port(port);
        this->_state->socket.open(asio::ip::udp::v4());
        this->_connecting = false;

        this->_log.debug("resolved address ${host}:${port}")
          .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));
    }

    void _start_resolve() {
        _connecting = true;
        const auto& [host, port] = _addr;
        _resolver.async_resolve(
          host, {}, [this, port](std::error_code error, auto resolved) {
              if(!error) {
                  this->_on_resolve(resolved, port);
              } else {
                  _log.error("failed to resolve address: ${error}")
                    .arg(EAGINE_ID(error), error);
                  this->_connecting = false;
              }
          });
    }

public:
    asio_connector(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str)
      : base{parent, asio_state}
      , _resolver{asio_state->context}
      , _addr{parse_ipv4_addr(addr_str)} {
    }

    bool update() final {
        EAGINE_ASSERT(this->_state);
        some_true something_done{};
        if(this->_state->socket.is_open()) {
            something_done(this->_state->start_receive());
            something_done(this->_state->start_send());
        } else if(!_connecting) {
            if(_should_reconnect) {
                _should_reconnect.reset();
                _start_resolve();
                something_done();
            }
        }
        something_done(this->_state->update());
        return something_done;
    }
};
//------------------------------------------------------------------------------
class asio_udp_ipv4_server_connection
  : public asio_connection<
      connection_addr_kind::ipv4,
      connection_protocol::datagram>
  , public connection_sink<asio::ip::udp::endpoint> {
    using base = asio_connection<
      connection_addr_kind::ipv4,
      connection_protocol::datagram>;

public:
    asio_udp_ipv4_server_connection(
      logger& parent,
      const std::shared_ptr<asio_common_state>& state,
      ipv4_port port)
      : base{parent, state} {
        this->_state->endpoint = {asio::ip::udp::v4(), port};
    }

    void on_received(
      const asio::ip::udp::endpoint&, memory::const_block) final {
    }

    bool process_accepted(const acceptor::accept_handler&) {
        return false;
    }

private:
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<connection_addr_kind::ipv4, connection_protocol::datagram>
  : public acceptor {
private:
    logger _log{};
    std::shared_ptr<asio_common_state> _asio_state;
    std::tuple<std::string, ipv4_port> _addr;

    asio_udp_ipv4_server_connection _conn;

public:
    asio_acceptor(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      string_view addr_str) noexcept
      : _log{EAGINE_ID(AsioAccptr), parent}
      , _asio_state{std::move(asio_state)}
      , _addr{parse_ipv4_addr(addr_str)}
      , _conn{_log, _asio_state, std::get<1>(_addr)} {
    }

    bool update() final {
        return _conn.update();
    }

    bool process_accepted(const accept_handler& handler) final {
        return _conn.process_accepted(handler);
    }
};
//------------------------------------------------------------------------------
// Local/Stream
#if EAGINE_POSIX
//------------------------------------------------------------------------------
template <typename Base>
class asio_connection_info<
  Base,
  connection_addr_kind::local,
  connection_protocol::stream> : public Base {
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
struct asio_types<connection_addr_kind::local, connection_protocol::stream> {
    using socket_type = asio::local::stream_protocol::socket;
};
//------------------------------------------------------------------------------
template <>
class asio_connector<connection_addr_kind::local, connection_protocol::stream>
  : public asio_connection<
      connection_addr_kind::local,
      connection_protocol::stream> {
    using base =
      asio_connection<connection_addr_kind::local, connection_protocol::stream>;

    std::string _addr_str;
    timeout _should_reconnect{std::chrono::seconds{1}, nothing};
    bool _connecting{false};

    void _start_connect() {
        _connecting = true;
        this->_log.debug("connecting to ${address}")
          .arg(EAGINE_ID(address), EAGINE_ID(FsPath), this->_addr_str);

        this->_state->socket.async_connect(
          this->_state->endpoint, [this](std::error_code error) mutable {
              if(!error) {
                  this->_log.debug("connected on address ${address}")
                    .arg(EAGINE_ID(address), EAGINE_ID(FsPath), _addr_str);
                  this->_connecting = false;
              } else {
                  this->_log.error("failed to connect: ${error}")
                    .arg(EAGINE_ID(error), error);
                  this->_connecting = false;
              }
          });
    }

    static inline auto _fix_addr(string_view addr_str) noexcept {
        return addr_str ? addr_str : string_view{"/tmp/eagine-msgbus.socket"};
    }

public:
    asio_connector(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str)
      : base{parent, asio_state}
      , _addr_str{_fix_addr(addr_str)} {
        this->_state->endpoint = {_addr_str.c_str()};
    }

    bool update() final {
        EAGINE_ASSERT(this->_state);
        some_true something_done{};
        if(this->_state->socket.is_open()) {
            something_done(this->_state->start_receive());
            something_done(this->_state->start_send());
        } else if(!_connecting) {
            if(_should_reconnect) {
                _should_reconnect.reset();
                _start_connect();
                something_done();
            }
        }
        something_done(this->_state->update());
        return something_done;
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<connection_addr_kind::local, connection_protocol::stream>
  : public acceptor {
private:
    logger _log{};
    std::shared_ptr<asio_common_state> _asio_state;
    std::string _addr_str;
    asio::local::stream_protocol::acceptor _acceptor;
    bool _accepting{false};

    std::vector<asio::local::stream_protocol::socket> _accepted;

    void _start_accept() {
        this->_log.debug("accepting connection on address ${address}")
          .arg(EAGINE_ID(address), EAGINE_ID(FsPath), _addr_str);

        _accepting = true;
        _acceptor.async_accept([this](
                                 std::error_code error,
                                 asio::local::stream_protocol::socket socket) {
            if(error) {
                this->_accepting = false;
                this->_log
                  .error(
                    "failed to accept connection on address ${address}: "
                    "${error}")
                  .arg(EAGINE_ID(error), error)
                  .arg(EAGINE_ID(address), EAGINE_ID(FsPath), _addr_str);
            } else {
                this->_log.debug("accepted connection on address ${address}")
                  .arg(EAGINE_ID(address), EAGINE_ID(FsPath), _addr_str);
                this->_accepted.emplace_back(std::move(socket));
            }
            _start_accept();
        });
    }

    static inline auto _fix_addr(string_view addr_str) noexcept {
        return addr_str ? addr_str : string_view{"/tmp/eagine-msgbus.socket"};
    }

    static inline std::shared_ptr<asio_common_state> _prepare(
      std::shared_ptr<asio_common_state> asio_state, string_view addr_str) {
        std::remove(c_str(addr_str));
        return asio_state;
    }

public:
    asio_acceptor(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      string_view addr_str) noexcept
      : _log{EAGINE_ID(AsioAccptr), parent}
      , _asio_state{_prepare(std::move(asio_state), _fix_addr(addr_str))}
      , _addr_str{to_string(_fix_addr(addr_str))}
      , _acceptor{
          _asio_state->context,
          asio::local::stream_protocol::endpoint(_addr_str.c_str())} {
    }

    ~asio_acceptor() noexcept override {
        try {
            std::remove(_addr_str.c_str());
        } catch(...) {
        }
    }

    asio_acceptor(asio_acceptor&&) = delete;
    asio_acceptor(const asio_acceptor&) = delete;
    asio_acceptor& operator=(asio_acceptor&&) = delete;
    asio_acceptor& operator=(const asio_acceptor&) = delete;

    bool update() final {
        EAGINE_ASSERT(this->_asio_state);
        some_true something_done{};
        if(EAGINE_UNLIKELY(!_acceptor.is_open())) {
            _acceptor = {
              _asio_state->context,
              asio::local::stream_protocol::endpoint(_addr_str.c_str())};
            something_done();
        }
        if(_acceptor.is_open() && !_accepting) {
            _start_accept();
            something_done();
        }
        if(this->_asio_state->context.poll()) {
            something_done();
        } else {
            this->_asio_state->context.reset();
        }
        return something_done;
    }

    bool process_accepted(const accept_handler& handler) final {
        some_true something_done{};
        for(auto& socket : _accepted) {
            auto conn = std::make_unique<asio_connection<
              connection_addr_kind::local,
              connection_protocol::stream>>(
              _log, _asio_state, std::move(socket));
            handler(std::move(conn));
            something_done();
        }
        _accepted.clear();
        return something_done;
    }
};
//------------------------------------------------------------------------------
#endif // EAGINE_POSIX
//------------------------------------------------------------------------------
// Factory
//------------------------------------------------------------------------------
template <connection_addr_kind Kind, connection_protocol Proto>
class asio_connection_factory
  : public asio_connection_info<connection_factory, Kind, Proto> {
private:
    logger _log{};
    std::shared_ptr<asio_common_state> _asio_state;

public:
    using connection_factory::make_acceptor;
    using connection_factory::make_connector;

    asio_connection_factory(
      logger& parent, std::shared_ptr<asio_common_state> asio_state) noexcept
      : _log{EAGINE_ID(AsioConnFc), parent}
      , _asio_state{std::move(asio_state)} {
    }

    asio_connection_factory(logger& parent)
      : asio_connection_factory{parent, std::make_shared<asio_common_state>()} {
    }

    std::unique_ptr<acceptor> make_acceptor(string_view addr_str) final {
        return std::make_unique<asio_acceptor<Kind, Proto>>(
          _log, _asio_state, addr_str);
    }

    std::unique_ptr<connection> make_connector(string_view addr_str) final {
        return std::make_unique<asio_connector<Kind, Proto>>(
          _log, _asio_state, addr_str);
    }
};
//------------------------------------------------------------------------------
using asio_tcp_ipv4_connection_factory = asio_connection_factory<
  connection_addr_kind::ipv4,
  connection_protocol::stream>;
//------------------------------------------------------------------------------
using asio_udp_v4_connection_factory = asio_connection_factory<
  connection_addr_kind::ipv4,
  connection_protocol::datagram>;
//------------------------------------------------------------------------------
#if EAGINE_POSIX
using asio_local_stream_connection_factory = asio_connection_factory<
  connection_addr_kind::local,
  connection_protocol::stream>;
#endif // EAGINE_POSIX
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ASIO_HPP
