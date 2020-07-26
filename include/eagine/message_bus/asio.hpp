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
#include "../flat_map.hpp"
#include "../logging/exception.hpp"
#include "../logging/logger.hpp"
#include "../maybe_unused.hpp"
#include "../serialize/size_and_data.hpp"
#include "../timeout.hpp"
#include "conn_factory.hpp"
#include "network.hpp"
#include "serialize.hpp"
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
template <connection_addr_kind, connection_protocol>
struct asio_types;

template <connection_addr_kind Kind, connection_protocol Proto>
using asio_socket_type = typename asio_types<Kind, Proto>::socket_type;

template <connection_addr_kind Kind, connection_protocol Proto>
using asio_endpoint_type =
  typename asio_socket_type<Kind, Proto>::endpoint_type;

template <typename Base, connection_addr_kind, connection_protocol>
class asio_connection_info;

template <connection_addr_kind, connection_protocol>
class asio_connection;

template <connection_addr_kind, connection_protocol>
class asio_connector;

template <connection_addr_kind, connection_protocol>
class asio_acceptor;
//------------------------------------------------------------------------------
template <typename Socket>
class asio_flushing_sockets {
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
        std::get<asio_flushing_sockets<Socket>>(_flushing).adopt(sckt);
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
      asio_flushing_sockets<asio::local::stream_protocol::socket>,
#endif
      asio_flushing_sockets<asio::ip::tcp::socket>,
      asio_flushing_sockets<asio::ip::udp::socket>>
      _flushing;
};
//------------------------------------------------------------------------------
template <connection_addr_kind Kind, connection_protocol Proto>
struct asio_connection_group {
    asio_connection_group() noexcept = default;
    asio_connection_group(asio_connection_group&&) = delete;
    asio_connection_group(const asio_connection_group&) = delete;
    asio_connection_group& operator=(asio_connection_group&&) = delete;
    asio_connection_group& operator=(const asio_connection_group&) = delete;
    virtual ~asio_connection_group() noexcept = default;

    using bit_set = typename serialized_message_storage::bit_set;
    using endpoint_type = asio_endpoint_type<Kind, Proto>;

    virtual bit_set pack_into(endpoint_type&, memory::block) = 0;

    virtual void on_sent(const endpoint_type&, bit_set to_be_removed) = 0;

    virtual void on_received(const endpoint_type&, memory::const_block) = 0;

    virtual bool has_received() = 0;
};
//------------------------------------------------------------------------------
template <connection_addr_kind Kind, connection_protocol Proto>
struct asio_connection_state
  : std::enable_shared_from_this<asio_connection_state<Kind, Proto>> {
    using endpoint_type = asio_endpoint_type<Kind, Proto>;

    logger _log{};
    std::shared_ptr<asio_common_state> common;
    asio_socket_type<Kind, Proto> socket;
    endpoint_type conn_endpoint{};

    memory::buffer push_buffer{};
    memory::buffer read_buffer{};
    memory::buffer write_buffer{};
    bool is_sending{false};
    bool is_recving{false};

    asio_connection_state(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      asio_socket_type<Kind, Proto> sock,
      span_size_t block_size)
      : _log{EAGINE_ID(AsioConnSt), parent}
      , common{std::move(asio_state)}
      , socket{std::move(sock)} {
        EAGINE_ASSERT(common);
        common->update();

        EAGINE_ASSERT(block_size >= min_connection_data_size);
        push_buffer.resize(block_size);
        zero(cover(push_buffer));
        read_buffer.resize(block_size);
        zero(cover(read_buffer));
        write_buffer.resize(block_size);
        zero(cover(write_buffer));

        _log.debug("allocating write buffer of ${size}")
          .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), write_buffer.size());
        _log.debug("allocating read buffer of ${size}")
          .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), read_buffer.size());
    }

    asio_connection_state(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state,
      span_size_t block_size) noexcept
      : asio_connection_state{
          parent,
          asio_state,
          asio_socket_type<Kind, Proto>{asio_state->context},
          block_size} {
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

    template <typename Handler>
    void do_start_send(
      stream_protocol_tag,
      const endpoint_type&,
      memory::const_block blk,
      Handler handler) {
        asio::async_write(
          socket, asio::buffer(blk.data(), blk.size()), handler);
    }

    template <typename Handler>
    void do_start_send(
      datagram_protocol_tag,
      const endpoint_type& target_endpoint,
      memory::const_block blk,
      Handler handler) {
        socket.async_send_to(
          asio::buffer(blk.data(), blk.size()), target_endpoint, handler);
    }

    void do_start_send(asio_connection_group<Kind, Proto>& group) {

        endpoint_type target_endpoint{conn_endpoint};
        if(const auto packed_messages{
             group.pack_into(target_endpoint, cover(write_buffer))}) {
            is_sending = true;
            const auto blk = view(write_buffer);

            _log.trace("sending data (size: ${size})")
              .arg(EAGINE_ID(packed), EAGINE_ID(bits), packed_messages)
              .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), blk.size())
              .arg(EAGINE_ID(block), blk);

            do_start_send(
              connection_protocol_tag<Proto>{},
              target_endpoint,
              blk,
              [this,
               &group,
               target_endpoint,
               packed_messages,
               selfref{weak_ref()}](std::error_code error, std::size_t length) {
                  if(const auto self{selfref.lock()}) {
                      if(!error) {
                          _log.trace("sent data (size: ${size})")
                            .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), length);

                          this->handle_sent(
                            group, target_endpoint, packed_messages);
                      } else {
                          _log.error("failed to send data: ${error}")
                            .arg(EAGINE_ID(error), error);
                          this->is_sending = false;
                      }
                  }
              });
        } else {
            is_sending = false;
        }
    }

    bool start_send(asio_connection_group<Kind, Proto>& group) {
        if(!is_sending) {
            do_start_send(group);
        }
        return is_sending;
    }

    void handle_sent(
      asio_connection_group<Kind, Proto>& group,
      const endpoint_type& target_endpoint,
      serialized_message_storage::bit_set to_be_removed) {
        group.on_sent(target_endpoint, to_be_removed);
        do_start_send(group);
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
          asio::buffer(blk.data(), blk.size()), conn_endpoint, handler);
    }

    void do_start_receive(asio_connection_group<Kind, Proto>& group) {
        auto blk = cover(read_buffer);

        _log.trace("receiving data (size: ${size})")
          .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), blk.size());

        is_recving = true;
        do_start_receive(
          connection_protocol_tag<Proto>{},
          blk,
          [this, &group, selfref{weak_ref()}, blk](
            std::error_code error, std::size_t length) {
              if(const auto self{selfref.lock()}) {
                  memory::const_block rcvd = head(blk, span_size(length));
                  if(!error) {
                      _log.trace("received data (size: ${size})")
                        .arg(EAGINE_ID(block), rcvd)
                        .arg(EAGINE_ID(size), EAGINE_ID(ByteSize), length);

                      this->handle_received(rcvd, group);
                  } else {
                      if(rcvd) {
                          _log.warning("failed receiving data: ${error}")
                            .arg(EAGINE_ID(error), error);
                          this->handle_received(rcvd, group);
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

    bool start_receive(asio_connection_group<Kind, Proto>& group) {
        if(!is_recving) {
            do_start_receive(group);
        }
        return group.has_received();
    }

    void handle_received(
      memory::const_block data, asio_connection_group<Kind, Proto>& group) {
        group.on_received(conn_endpoint, data);
        do_start_receive(group);
    }

    bool update() {
        some_true something_done{};
        if(const auto count{common->context.poll()}) {
            _log.trace("called ready handlers (count: ${count})")
              .arg(EAGINE_ID(count), count);
            something_done();
        } else {
            common->context.reset();
        }
        return something_done;
    }

    void cleanup(asio_connection_group<Kind, Proto>& group) {
        while(start_send(group)) {
            _log.debug("flushing connection outbox");
            update();
        }
        common->adopt_flushing(socket);
        common->update();
    }
};
//------------------------------------------------------------------------------
template <connection_addr_kind Kind, connection_protocol Proto>
class asio_connection_base
  : public asio_connection_info<connection, Kind, Proto> {

    logger _log{};

    using bit_set = typename connection_outgoing_messages::bit_set;

protected:
    std::shared_ptr<asio_connection_state<Kind, Proto>> _state;

    asio_connection_base(
      logger& parent, std::shared_ptr<asio_connection_state<Kind, Proto>> state)
      : _log{EAGINE_ID(AsioConnBs), parent}
      , _state{std::move(state)} {
    }

public:
    asio_connection_base(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      span_size_t block_size)
      : _log{EAGINE_ID(AsioConnBs), parent}
      , _state{std::make_shared<asio_connection_state<Kind, Proto>>(
          _log, std::move(asio_state), block_size)} {
        EAGINE_ASSERT(_state);
    }

    asio_connection_base(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      asio_socket_type<Kind, Proto> socket,
      span_size_t block_size)
      : _log{EAGINE_ID(AsioConnBs), parent}
      , _state{std::make_shared<asio_connection_state<Kind, Proto>>(
          _log, std::move(asio_state), std::move(socket), block_size)} {
        EAGINE_ASSERT(_state);
    }

    inline auto& log() noexcept {
        return _log;
    }

    inline auto& conn_state() noexcept {
        EAGINE_ASSERT(_state);
        return *_state;
    }

    valid_if_positive<span_size_t> max_data_size() final {
        return {conn_state().write_buffer.size()};
    }

    bool is_usable() final {
        return conn_state().is_usable();
    }
};
//------------------------------------------------------------------------------
template <connection_addr_kind Kind, connection_protocol Proto>
class asio_connection
  : public asio_connection_base<Kind, Proto>
  , public asio_connection_group<Kind, Proto> {

    using base = asio_connection_base<Kind, Proto>;
    using endpoint_type = asio_endpoint_type<Kind, Proto>;

public:
    using base::base;
    using base::conn_state;
    using base::log;

    bool update() override {
        some_true something_done{};
        if(conn_state().socket.is_open()) {
            something_done(conn_state().start_receive(*this));
            something_done(conn_state().start_send(*this));
        }
        something_done(conn_state().update());
        return something_done;
    }

    using bit_set = typename connection_outgoing_messages::bit_set;

    bit_set pack_into(endpoint_type&, memory::block data) final {
        return _outgoing.pack_into(data);
    }

    void on_sent(const endpoint_type&, bit_set to_be_removed) final {
        return _outgoing.cleanup(to_be_removed);
    }

    void on_received(const endpoint_type&, memory::const_block data) final {
        return _incoming.push(data);
    }

    bool has_received() final {
        return !_incoming.empty();
    }

    bool send(message_id msg_id, const message_view& message) final {
        return _outgoing.enqueue(
          log(), msg_id, message, cover(conn_state().push_buffer));
    }

    bool fetch_messages(connection::fetch_handler handler) final {
        return _incoming.fetch_messages(log(), handler);
    }

    void cleanup() final {
        conn_state().cleanup(*this);
    }

private:
    connection_outgoing_messages _outgoing{};
    connection_incoming_messages _incoming{};
};
//------------------------------------------------------------------------------
template <connection_addr_kind Kind>
class asio_datagram_client_connection
  : public asio_connection_base<Kind, connection_protocol::datagram> {

    using base = asio_connection_base<Kind, connection_protocol::datagram>;

public:
    using base::conn_state;
    using base::log;

    asio_datagram_client_connection(
      logger& parent,
      std::shared_ptr<
        asio_connection_state<Kind, connection_protocol::datagram>> state,
      std::shared_ptr<connection_outgoing_messages> outgoing,
      std::shared_ptr<connection_incoming_messages> incoming)
      : base(parent, std::move(state))
      , _outgoing{std::move(outgoing)}
      , _incoming{std::move(incoming)} {
    }

    using bit_set = typename connection_outgoing_messages::bit_set;

    bit_set pack_into(memory::block data) {
        EAGINE_ASSERT(_outgoing);
        return _outgoing->pack_into(data);
    }

    void on_sent(bit_set to_be_removed) {
        EAGINE_ASSERT(_outgoing);
        return _outgoing->cleanup(to_be_removed);
    }

    void on_received(memory::const_block data) {
        EAGINE_ASSERT(_incoming);
        _incoming->push(data);
    }

    bool send(message_id msg_id, const message_view& message) final {
        EAGINE_ASSERT(_outgoing);
        return _outgoing->enqueue(
          log(), msg_id, message, cover(conn_state().push_buffer));
    }

    bool fetch_messages(connection::fetch_handler handler) final {
        EAGINE_ASSERT(_incoming);
        return _incoming->fetch_messages(log(), handler);
    }

    bool update() final {
        some_true something_done{};
        something_done(conn_state().update());
        return something_done;
    }

private:
    std::shared_ptr<connection_outgoing_messages> _outgoing;
    std::shared_ptr<connection_incoming_messages> _incoming;
};
//------------------------------------------------------------------------------
template <connection_addr_kind Kind>
class asio_datagram_server_connection
  : public asio_connection_base<Kind, connection_protocol::datagram>
  , public asio_connection_group<Kind, connection_protocol::datagram> {

    using base = asio_connection_base<Kind, connection_protocol::datagram>;
    using endpoint_type =
      asio_endpoint_type<Kind, connection_protocol::datagram>;

public:
    using base::base;
    using base::conn_state;
    using base::log;

    using bit_set = typename connection_outgoing_messages::bit_set;

    bit_set pack_into(endpoint_type& target, memory::block dest) final {
        EAGINE_ASSERT(_index >= 0);
        const auto prev_idx{_index};
        do {
            if(_index < span_size(_current.size())) {
                auto pos = _current.begin();
                std::advance(pos, _index);
                ++_index;
                auto& [ep, out_in] = *pos;
                auto& outgoing = std::get<0>(out_in);
                EAGINE_ASSERT(outgoing);
                if(const auto packed{outgoing->pack_into(dest)}) {
                    target = ep;
                    return packed;
                }
            } else {
                _index = 0;
            }
        } while(_index != prev_idx);
        return bit_set(0);
    }

    void on_sent(const endpoint_type& ep, bit_set to_be_removed) final {
        _outgoing(ep).cleanup(to_be_removed);
    }

    void on_received(const endpoint_type& ep, memory::const_block data) final {
        _incoming(ep).push(data);
    }

    bool has_received() final {
        for(auto m : {&_current, &_pending}) {
            for(const auto& p : *m) {
                const auto& incoming = std::get<1>(std::get<1>(p));
                EAGINE_ASSERT(incoming);
                if(!incoming->empty()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool send(message_id, const message_view&) final {
        EAGINE_UNREACHABLE();
        return false;
    }

    bool fetch_messages(connection::fetch_handler) final {
        EAGINE_UNREACHABLE();
        return false;
    }

    bool process_accepted(const acceptor::accept_handler& handler) {
        some_true something_done;
        for(auto& p : _pending) {
            handler(std::make_unique<asio_datagram_client_connection<Kind>>(
              log(),
              this->_state,
              std::get<0>(std::get<1>(p)),
              std::get<1>(std::get<1>(p))));
            _current.insert(p);
            something_done();
        }
        _pending.clear();
        if(something_done) {
            log()
              .debug("accepted datagram endpoints")
              .arg(EAGINE_ID(current), _current.size());
        }
        return something_done;
    }

    bool update() final {
        some_true something_done{};
        if(conn_state().socket.is_open()) {
            something_done(conn_state().start_receive(*this));
            something_done(conn_state().start_send(*this));
        } else {
            log().warning("datagram socket is not open");
        }
        something_done(conn_state().update());
        return something_done;
    }

    void cleanup() final {
        conn_state().cleanup(*this);
    }

private:
    auto& _get(const endpoint_type& ep) {
        auto pos = _current.find(ep);
        if(pos == _current.end()) {
            pos = _pending.find(ep);
            if(pos == _pending.end()) {
                pos = _pending
                        .try_emplace(
                          ep,
                          std::make_shared<connection_outgoing_messages>(),
                          std::make_shared<connection_incoming_messages>())
                        .first;
                log()
                  .debug("added pending datagram endpoint")
                  .arg(EAGINE_ID(pending), _pending.size())
                  .arg(EAGINE_ID(current), _current.size());
            }
        }
        return std::get<1>(*pos);
    }

    connection_outgoing_messages& _outgoing(const endpoint_type& ep) {
        auto& outgoing = std::get<0>(_get(ep));
        EAGINE_ASSERT(outgoing);
        return *outgoing;
    }

    connection_incoming_messages& _incoming(const endpoint_type& ep) {
        auto& incoming = std::get<1>(_get(ep));
        EAGINE_ASSERT(incoming);
        return *incoming;
    }

    flat_map<
      endpoint_type,
      std::tuple<
        std::shared_ptr<connection_outgoing_messages>,
        std::shared_ptr<connection_incoming_messages>>>
      _current{}, _pending{};
    span_size_t _index{0};
};
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

    connection_addr_kind addr_kind() final {
        return connection_addr_kind::ipv4;
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
    using base::conn_state;
    using base::log;

    asio::ip::tcp::resolver _resolver;
    std::tuple<std::string, ipv4_port> _addr;
    timeout _should_reconnect{std::chrono::seconds{1}, nothing};
    bool _connecting{false};

    void _start_connect(
      asio::ip::tcp::resolver::iterator resolved, ipv4_port port) {
        auto& ep = conn_state().conn_endpoint = *resolved;
        ep.port(port);

        log()
          .debug("connecting to ${host}:${port}")
          .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));

        conn_state().socket.async_connect(
          ep, [this, resolved, port](std::error_code error) mutable {
              if(!error) {
                  log()
                    .debug("connected on address ${host}:${port}")
                    .arg(
                      EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
                    .arg(
                      EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));
                  this->_connecting = false;
              } else {
                  if(++resolved != asio::ip::tcp::resolver::iterator{}) {
                      this->_start_connect(resolved, port);
                  } else {
                      log()
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
          [this, port{port}](std::error_code error, auto resolved) {
              if(!error) {
                  this->_start_connect(resolved, port);
              } else {
                  log()
                    .error("failed to resolve address: ${error}")
                    .arg(EAGINE_ID(error), error);
                  this->_connecting = false;
              }
          });
    }

public:
    asio_connector(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str,
      span_size_t block_size)
      : base{parent, asio_state, block_size}
      , _resolver{asio_state->context}
      , _addr{parse_ipv4_addr(addr_str)} {
    }

    bool update() final {
        some_true something_done{};
        if(conn_state().socket.is_open()) {
            something_done(conn_state().start_receive(*this));
            something_done(conn_state().start_send(*this));
        } else if(!_connecting) {
            if(_should_reconnect) {
                _should_reconnect.reset();
                _start_resolve();
                something_done();
            }
        }
        something_done(conn_state().update());
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
    span_size_t _block_size;

    std::vector<asio::ip::tcp::socket> _accepted;

    void _start_accept() {
        _log.debug("accepting connection on address ${host}:${port}")
          .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));

        _socket = asio::ip::tcp::socket(this->_asio_state->context);
        _acceptor.async_accept(_socket, [this](std::error_code error) {
            if(!error) {
                _log.debug("accepted connection on address ${host}:${port}")
                  .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
                  .arg(
                    EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));
                this->_accepted.emplace_back(std::move(this->_socket));
            } else {
                _log
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
      string_view addr_str,
      span_size_t block_size) noexcept
      : _log{EAGINE_ID(AsioAccptr), parent}
      , _asio_state{std::move(asio_state)}
      , _addr{parse_ipv4_addr(addr_str)}
      , _acceptor{_asio_state->context}
      , _socket{_asio_state->context}
      , _block_size{block_size} {
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
              _log, _asio_state, std::move(socket), _block_size);
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

    connection_addr_kind addr_kind() final {
        return connection_addr_kind::ipv4;
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
    using base::conn_state;
    using base::log;

    asio::ip::udp::resolver _resolver;
    std::tuple<std::string, ipv4_port> _addr;
    timeout _should_reconnect{std::chrono::seconds{1}, nothing};
    bool _establishing{false};

    void _on_resolve(
      const asio::ip::udp::resolver::iterator& resolved, ipv4_port port) {
        auto& ep = conn_state().conn_endpoint = *resolved;
        ep.port(port);
        conn_state().socket.open(ep.protocol());
        this->_establishing = false;

        log()
          .debug("resolved address ${host}:${port}")
          .arg(EAGINE_ID(host), EAGINE_ID(IpV4Host), std::get<0>(_addr))
          .arg(EAGINE_ID(port), EAGINE_ID(IpV4Port), std::get<1>(_addr));
    }

    void _start_resolve() {
        _establishing = true;
        const auto& [host, port] = _addr;
        _resolver.async_resolve(
          host, {}, [this, port{port}](std::error_code error, auto resolved) {
              if(!error) {
                  this->_on_resolve(resolved, port);
              } else {
                  log()
                    .error("failed to resolve address: ${error}")
                    .arg(EAGINE_ID(error), error);
                  this->_establishing = false;
              }
          });
    }

public:
    asio_connector(
      logger& parent,
      const std::shared_ptr<asio_common_state>& asio_state,
      string_view addr_str,
      span_size_t block_size)
      : base{parent, asio_state, block_size}
      , _resolver{asio_state->context}
      , _addr{parse_ipv4_addr(addr_str)} {
    }

    bool update() final {
        some_true something_done{};
        if(conn_state().socket.is_open()) {
            something_done(conn_state().start_receive(*this));
            something_done(conn_state().start_send(*this));
        } else if(!_establishing) {
            if(_should_reconnect) {
                _should_reconnect.reset();
                _start_resolve();
                something_done();
            }
        }
        something_done(conn_state().update());
        return something_done;
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<connection_addr_kind::ipv4, connection_protocol::datagram>
  : public acceptor {
private:
    logger _log{};
    std::shared_ptr<asio_common_state> _asio_state;
    std::tuple<std::string, ipv4_port> _addr;

    asio_datagram_server_connection<connection_addr_kind::ipv4> _conn;

public:
    asio_acceptor(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      string_view addr_str,
      span_size_t block_size) noexcept
      : _log{EAGINE_ID(AsioAccptr), parent}
      , _asio_state{std::move(asio_state)}
      , _addr{parse_ipv4_addr(addr_str)}
      , _conn{
          _log,
          _asio_state,
          asio::ip::udp::socket{
            _asio_state->context,
            asio::ip::udp::endpoint{asio::ip::udp::v4(), std::get<1>(_addr)}},
          block_size} {
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
  connection_addr_kind::filepath,
  connection_protocol::stream> : public Base {
public:
    connection_kind kind() final {
        return connection_kind::local_interprocess;
    }

    connection_addr_kind addr_kind() final {
        return connection_addr_kind::filepath;
    }

    identifier type_id() final {
        return EAGINE_ID(AsioLclStr);
    }
};
//------------------------------------------------------------------------------
template <>
struct asio_types<connection_addr_kind::filepath, connection_protocol::stream> {
    using socket_type = asio::local::stream_protocol::socket;
};
//------------------------------------------------------------------------------
template <>
class asio_connector<
  connection_addr_kind::filepath,
  connection_protocol::stream>
  : public asio_connection<
      connection_addr_kind::filepath,
      connection_protocol::stream> {
    using base = asio_connection<
      connection_addr_kind::filepath,
      connection_protocol::stream>;

    std::string _addr_str;
    timeout _should_reconnect{std::chrono::seconds{1}, nothing};
    bool _connecting{false};

    void _start_connect() {
        _connecting = true;
        log()
          .debug("connecting to ${address}")
          .arg(EAGINE_ID(address), EAGINE_ID(FsPath), this->_addr_str);

        conn_state().socket.async_connect(
          conn_state().conn_endpoint, [this](std::error_code error) mutable {
              if(!error) {
                  log()
                    .debug("connected on address ${address}")
                    .arg(EAGINE_ID(address), EAGINE_ID(FsPath), _addr_str);
                  _connecting = false;
              } else {
                  log()
                    .error("failed to connect: ${error}")
                    .arg(EAGINE_ID(error), error);
                  _connecting = false;
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
      string_view addr_str,
      span_size_t block_size)
      : base{parent, asio_state, block_size}
      , _addr_str{_fix_addr(addr_str)} {
        conn_state().conn_endpoint = {_addr_str.c_str()};
    }

    bool update() final {
        some_true something_done{};
        if(conn_state().socket.is_open()) {
            something_done(conn_state().start_receive(*this));
            something_done(conn_state().start_send(*this));
        } else if(!_connecting) {
            if(_should_reconnect) {
                _should_reconnect.reset();
                _start_connect();
                something_done();
            }
        }
        something_done(conn_state().update());
        return something_done;
    }
};
//------------------------------------------------------------------------------
template <>
class asio_acceptor<connection_addr_kind::filepath, connection_protocol::stream>
  : public acceptor {
private:
    logger _log{};
    std::shared_ptr<asio_common_state> _asio_state;
    std::string _addr_str;
    asio::local::stream_protocol::acceptor _acceptor;
    span_size_t _block_size;
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
      string_view addr_str, span_size_t block_size) noexcept
      : _log{EAGINE_ID(AsioAccptr), parent}
      , _asio_state{_prepare(std::move(asio_state), _fix_addr(addr_str))}
      , _addr_str{to_string(_fix_addr(addr_str))}
      , _acceptor{
          _asio_state->context,
          asio::local::stream_protocol::endpoint(_addr_str.c_str())}
	  , _block_size{block_size} {
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
              connection_addr_kind::filepath,
              connection_protocol::stream>>(
              _log, _asio_state, std::move(socket), _block_size);
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

    template <connection_addr_kind K, connection_protocol P>
    static constexpr span_size_t _default_block_size(
      connection_addr_kind_tag<K>, connection_protocol_tag<P>) noexcept {
        return 2 * 1024;
    }

    template <connection_addr_kind K>
    static constexpr span_size_t _default_block_size(
      connection_addr_kind_tag<K>, datagram_protocol_tag) noexcept {
        return min_connection_data_size;
    }

    span_size_t _block_size{default_block_size()};

public:
    using connection_factory::make_acceptor;
    using connection_factory::make_connector;

    static constexpr span_size_t default_block_size() noexcept {
        return _default_block_size(
          connection_addr_kind_tag<Kind>{}, connection_protocol_tag<Proto>{});
    }

    asio_connection_factory(
      logger& parent,
      std::shared_ptr<asio_common_state> asio_state,
      span_size_t block_size) noexcept
      : _log{EAGINE_ID(AsioConnFc), parent}
      , _asio_state{std::move(asio_state)}
      , _block_size{block_size} {
    }

    asio_connection_factory(logger& parent, span_size_t block_size)
      : asio_connection_factory{
          parent, std::make_shared<asio_common_state>(), block_size} {
    }

    asio_connection_factory(logger& parent)
      : asio_connection_factory{parent, default_block_size()} {
    }

    std::unique_ptr<acceptor> make_acceptor(string_view addr_str) final {
        return std::make_unique<asio_acceptor<Kind, Proto>>(
          _log, _asio_state, addr_str, _block_size);
    }

    std::unique_ptr<connection> make_connector(string_view addr_str) final {
        return std::make_unique<asio_connector<Kind, Proto>>(
          _log, _asio_state, addr_str, _block_size);
    }
};
//------------------------------------------------------------------------------
using asio_tcp_ipv4_connection_factory = asio_connection_factory<
  connection_addr_kind::ipv4,
  connection_protocol::stream>;
//------------------------------------------------------------------------------
using asio_udp_ipv4_connection_factory = asio_connection_factory<
  connection_addr_kind::ipv4,
  connection_protocol::datagram>;
//------------------------------------------------------------------------------
#if EAGINE_POSIX
using asio_local_stream_connection_factory = asio_connection_factory<
  connection_addr_kind::filepath,
  connection_protocol::stream>;
#endif // EAGINE_POSIX
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ASIO_HPP
