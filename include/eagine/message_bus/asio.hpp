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
#include "../logging/exception.hpp"
#include "../logging/logger.hpp"
#include "../maybe_unused.hpp"
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
#if EAGINE_POSIX
#include <asio/local/stream_protocol.hpp>
#endif
#include <asio/read.hpp>
#include <asio/write.hpp>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
enum class asio_connection_addr_kind { local, ipv4 };
enum class asio_connection_protocol { stream, datagram };
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
      flushing_sockets<asio::ip::tcp::socket>>
      _flushing;
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
template <typename Socket, span_size_t Batch>
struct asio_connection_state
  : std::enable_shared_from_this<asio_connection_state<Socket, Batch>> {

    logger _log{};
    std::mutex mutex;
    std::shared_ptr<asio_common_state> common;
    Socket socket;

    memory::buffer push_buffer;
    memory::buffer read_buffer;
    memory::buffer write_buffer;
    serialized_message_storage incoming;
    serialized_message_storage outgoing;
    message_storage unpacked;
    bool is_sending{false};
    bool is_recving{false};
    bool has_recved{false};

    asio_connection_state(
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

    asio_connection_state(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state) noexcept
      : asio_connection_state{parent, asio_state, Socket{asio_state->context}} {
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

    bool enqueue(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) {
        std::unique_lock lock{mutex};
        block_data_sink sink(cover(push_buffer));
        string_serializer_backend backend(sink);
        auto errors = serialize_message(class_id, method_id, message, backend);
        if(!errors) {
            _log.trace("enqueuing message ${message} to be sent")
              .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
            outgoing.push(sink.done());
            return true;
        }
        _log.error("failed to serialize message ${message}")
          .arg(EAGINE_ID(message), message_id_tuple(class_id, method_id));
        return false;
    }

    bool fetch_messages(connection::fetch_handler handler) {
        std::unique_lock lock{mutex};
        auto unpacker = [this, &handler](memory::const_block data) {
            for_each_data_with_size(data, [this](memory::const_block blk) {
                unpacked.push_if([this, blk](
                                   identifier_t& class_id,
                                   identifier_t& method_id,
                                   stored_message& message) {
                    block_data_source source(blk);
                    string_deserializer_backend backend(source);
                    const auto errors = deserialize_message(
                      class_id, method_id, message, backend);
                    if(!errors) {
                        this->_log.trace("received message ${message}")
                          .arg(
                            EAGINE_ID(message),
                            message_id_tuple(class_id, method_id));
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

    bool start_send() {
        std::unique_lock lock{mutex};
        if(!is_sending) {
            if(auto packed_messages = outgoing.pack_into(cover(write_buffer))) {
                is_sending = true;
                const auto blk = view(write_buffer);

                _log.trace("writing data (size: ${size})")
                  .arg(EAGINE_ID(block), blk)
                  .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), blk.size());

                asio::async_write(
                  socket,
                  asio::buffer(blk.data(), blk.size()),
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

    void handle_received(memory::const_block data) {
        incoming.push(data);
        is_recving = false;
        has_recved = true;
    }

    bool start_receive() {
        std::unique_lock lock{mutex};
        if(!is_recving) {
            is_recving = true;
            has_recved = false;
            auto blk = cover(read_buffer);

            _log.trace("reading data (size: ${size})")
              .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), blk.size());

            asio::async_read(
              socket,
              asio::buffer(blk.data(), blk.size()),
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
  asio_connection_addr_kind Kind,
  asio_connection_protocol Proto,
  typename Socket,
  span_size_t Batch>
class asio_connection_base
  : public asio_connection_info<connection, Kind, Proto> {

protected:
    logger _log{};
    std::shared_ptr<asio_connection_state<Socket, Batch>> _state;

public:
    asio_connection_base(
      logger& parent, std::shared_ptr<asio_common_state> asio_state)
      : _log{EAGINE_ID(AsioConnBs), parent}
      , _state{std::make_shared<asio_connection_state<Socket, Batch>>(
          _log, std::move(asio_state))} {
        EAGINE_ASSERT(_state);
    }

    asio_connection_base(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      Socket socket)
      : _log{EAGINE_ID(AsioConnBs), parent}
      , _state{std::make_shared<asio_connection_state<Socket, Batch>>(
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

    bool send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) final {
        EAGINE_ASSERT(_state);
        return _state->enqueue(class_id, method_id, message);
    }

    bool fetch_messages(connection::fetch_handler handler) final {
        EAGINE_ASSERT(_state);
        return _state->fetch_messages(handler);
    }
};
//------------------------------------------------------------------------------
// TCP/IPv4
//------------------------------------------------------------------------------
static constexpr inline auto asio_connection_port() noexcept {
    return 34912;
}
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
      asio::ip::tcp::socket,
      64> {

    using base = asio_connection_base<
      asio_connection_addr_kind::ipv4,
      asio_connection_protocol::stream,
      asio::ip::tcp::socket,
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
        ep.port(asio_connection_port());

        this->_log.debug("connecting to ${address}:${port}")
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), asio_connection_port())
          .arg(EAGINE_ID(address), EAGINE_ID(IpV4Addr), _addr_str);

        this->_state->socket.async_connect(
          ep, [this, resolved](std::error_code error) mutable {
              if(!error) {
                  this->_log.debug("connected on address ${address}:${port}")
                    .arg(
                      EAGINE_ID(port),
                      EAGINE_ID(IpV4Port),
                      asio_connection_port())
                    .arg(EAGINE_ID(address), EAGINE_ID(IpV4Addr), _addr_str);
                  this->_connecting = false;
              } else {
                  if(++resolved != asio::ip::tcp::resolver::iterator{}) {
                      this->_start_connect(resolved);
                  } else {
                      this->_log
                        .error(
                          "failed to connect on address "
                          "${address}:${port}: "
                          "${error}")
                        .arg(EAGINE_ID(error), error)
                        .arg(
                          EAGINE_ID(port),
                          EAGINE_ID(IpV4Port),
                          asio_connection_port())
                        .arg(
                          EAGINE_ID(address), EAGINE_ID(IpV4Addr), _addr_str);
                      this->_connecting = false;
                  }
              }
          });
    }

    void _start_resolve() {
        auto host = asio::string_view(_addr_str);
        _resolver.async_resolve(
          host, {}, [this](std::error_code error, auto resolved) {
              if(!error) {
                  this->_start_connect(resolved);
              } else {
                  _log.error("failed to resolve address: ${error}")
                    .arg(EAGINE_ID(error), error);
                  this->_connecting = false;
              }
          });
    }

    static inline auto _fix_addr(string_view addr_str) noexcept {
        return addr_str ? addr_str : string_view{"localhost"};
    }

public:
    asio_connector(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str)
      : base{parent, asio_state}
      , _resolver{asio_state->context}
      , _addr_str{to_string(_fix_addr(addr_str))} {
    }

    bool update() final {
        EAGINE_ASSERT(this->_state);
        some_true something_done{};
        if(this->_state->socket.is_open()) {
            something_done(this->_state->start_receive());
            something_done(this->_state->start_send());
        } else if(!_connecting) {
            _connecting = true;
            _start_resolve();
            something_done();
        }
        something_done(this->_state->update());
        return something_done;
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<
  asio_connection_addr_kind::ipv4,
  asio_connection_protocol::stream> : public acceptor {
private:
    logger _log{};
    std::shared_ptr<asio_common_state> _asio_state;
    std::string _addr_str;
    asio::ip::tcp::acceptor _acceptor;
    asio::ip::tcp::socket _socket;

    std::vector<asio::ip::tcp::socket> _accepted;

    void _start_accept() {
        this->_log.debug("accepting connection on address ${address}:${port}")
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), asio_connection_port())
          .arg(EAGINE_ID(address), EAGINE_ID(IpV4Addr), _addr_str);

        _socket = asio::ip::tcp::socket(this->_asio_state->context);
        _acceptor.async_accept(_socket, [this](std::error_code error) {
            if(!error) {
                this->_log
                  .debug("accepted connection on address ${address}:${port}")
                  .arg(
                    EAGINE_ID(port),
                    EAGINE_ID(IpV4Port),
                    asio_connection_port())
                  .arg(EAGINE_ID(address), EAGINE_ID(IpV4Addr), _addr_str);
                this->_accepted.emplace_back(std::move(this->_socket));
            } else {
                this->_log
                  .error(
                    "failed to accept connection on address "
                    "${address}:${port}: "
                    "${error}")
                  .arg(EAGINE_ID(error), error)
                  .arg(
                    EAGINE_ID(port),
                    EAGINE_ID(IpV4Port),
                    asio_connection_port())
                  .arg(EAGINE_ID(address), EAGINE_ID(IpV4Addr), _addr_str);
            }
            _start_accept();
        });
    }

    static inline auto _fix_addr(string_view addr_str) noexcept {
        return addr_str ? addr_str : string_view{"localhost"};
    }

public:
    asio_acceptor(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      string_view addr_str) noexcept
      : _log{EAGINE_ID(AsioAccptr), parent}
      , _asio_state{std::move(asio_state)}
      , _addr_str{to_string(_fix_addr(addr_str))}
      , _acceptor{_asio_state->context}
      , _socket{_asio_state->context} {
    }

    bool update() final {
        EAGINE_ASSERT(this->_asio_state);
        some_true something_done{};
        if(!_acceptor.is_open()) {
            // TODO: address string
            asio::ip::tcp::endpoint endpoint(
              asio::ip::tcp::v4(), asio_connection_port());
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
              asio_connection_addr_kind::ipv4,
              asio_connection_protocol::stream>>(
              _log, _asio_state, std::move(socket));
            handler(std::move(conn));
            something_done();
        }
        _accepted.clear();
        return something_done;
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
      asio::local::stream_protocol::socket,
      8> {

    using base = asio_connection_base<
      asio_connection_addr_kind::local,
      asio_connection_protocol::stream,
      asio::local::stream_protocol::socket,
      8>;

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

    std::string _addr_str;
    asio::local::stream_protocol::endpoint _endpoint;
    bool _connecting{false};

    void _start_connect() {
        _connecting = true;
        this->_log.debug("connecting to ${address}")
          .arg(EAGINE_ID(address), EAGINE_ID(FsPath), this->_addr_str);

        this->_state->socket.async_connect(
          _endpoint, [this](std::error_code error) mutable {
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
      , _addr_str{_fix_addr(addr_str)}
      , _endpoint{_addr_str.c_str()} {
    }

    bool update() final {
        EAGINE_ASSERT(this->_state);
        some_true something_done{};
        if(this->_state->socket.is_open()) {
            something_done(this->_state->start_receive());
            something_done(this->_state->start_send());
        } else if(!_connecting) {
            _start_connect();
            something_done();
        }
        something_done(this->_state->update());
        return something_done;
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<
  asio_connection_addr_kind::local,
  asio_connection_protocol::stream> : public acceptor {
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
      , _acceptor{_asio_state->context,
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
              asio_connection_addr_kind::local,
              asio_connection_protocol::stream>>(
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
template <asio_connection_addr_kind Kind, asio_connection_protocol Proto>
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
