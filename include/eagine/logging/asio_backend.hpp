/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_LOGGING_ASIO_BACKEND_HPP
#define EAGINE_LOGGING_ASIO_BACKEND_HPP

#include "../config/platform.hpp"
#include "ostream_backend.hpp"
#include <iostream>

#ifdef __clang__
EAGINE_DIAG_PUSH()
EAGINE_DIAG_OFF(disabled-macro-expansion)
EAGINE_DIAG_OFF(covered-switch-default)
EAGINE_DIAG_OFF(zero-as-null-pointer-constant)
EAGINE_DIAG_OFF(shorten-64-to-32)
EAGINE_DIAG_OFF(deprecated)
#endif

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#if EAGINE_POSIX
#include <asio/local/stream_protocol.hpp>
#endif
#include <asio/streambuf.hpp>
#include <asio/write.hpp>

#ifdef __clang__
EAGINE_DIAG_POP()
#endif

namespace eagine {
//------------------------------------------------------------------------------
#if EAGINE_POSIX
class asio_local_ostream_log_connection {
    static auto _fix_addr(string_view addr_str) noexcept {
        return addr_str ? addr_str : string_view{"/tmp/eagine-xmllog"};
    }

public:
    asio_local_ostream_log_connection(string_view addr_str)
      : _endpoint{c_str(_fix_addr(addr_str))}
      , _socket{_context}
      , _out{&_buffer} {
        _socket.connect(_endpoint);
    }

    auto out() noexcept -> std::ostream& {
        if(_socket.is_open()) {
            return _out;
        }
        return std::clog;
    }

protected:
    void _flush() {
        try {
            if(_socket.is_open()) {
                const auto done = asio::write(_socket, _buffer);
                _buffer.consume(done);
            }
        } catch(...) {
        }
    }

private:
    asio::io_context _context{};
    asio::local::stream_protocol::endpoint _endpoint{};
    asio::local::stream_protocol::socket _socket;
    asio::streambuf _buffer{};
    std::ostream _out;
};
#endif
//------------------------------------------------------------------------------
class asio_tcpipv4_ostream_log_connection {
public:
    asio_tcpipv4_ostream_log_connection(string_view addr_str)
      : _addr{_fix_addr(addr_str)}
      , _resolver{_context}
      , _socket{_context}
      , _out{&_buffer} {
        for(auto& endpt :
            _resolver.resolve(std::get<0>(_addr), std::get<1>(_addr))) {
            _socket.connect(endpt);
            break;
        }
    }

    auto out() noexcept -> std::ostream& {
        if(_socket.is_open()) {
            return _out;
        }
        return std::clog;
    }

protected:
    void _flush() {
        try {
            if(_socket.is_open()) {
                const auto done = asio::write(_socket, _buffer);
                _buffer.consume(done);
            }
        } catch(...) {
        }
    }

private:
    static auto _fix_addr(string_view addr_str)
      -> std::tuple<std::string, std::string> {
        auto [hostname, port_str] = split_by_last(addr_str, string_view(":"));
        return {
          hostname ? to_string(hostname) : std::string("localhost"),
          port_str ? to_string(port_str) : std::string("34917")};
    }
    std::tuple<std::string, std::string> _addr;

    asio::io_context _context{};
    asio::ip::tcp::resolver _resolver;
    asio::ip::tcp::socket _socket;
    asio::streambuf _buffer{};
    std::ostream _out;
};
//------------------------------------------------------------------------------
template <typename Connection, typename Lockable>
class asio_ostream_log_backend
  : public Connection
  , public ostream_log_backend<Lockable> {

    using base = ostream_log_backend<Lockable>;

    void flush() noexcept final {
        Connection::_flush();
    }

public:
    asio_ostream_log_backend(
      string_view addr_str,
      log_event_severity min_severity)
      : Connection(addr_str)
      , ostream_log_backend<Lockable>(Connection::out(), min_severity) {}

    asio_ostream_log_backend(log_event_severity min_severity)
      : asio_ostream_log_backend(string_view{}, min_severity) {}

    asio_ostream_log_backend(asio_ostream_log_backend&&) = delete;
    asio_ostream_log_backend(const asio_ostream_log_backend&) = delete;
    auto operator=(asio_ostream_log_backend&&) = delete;
    auto operator=(const asio_ostream_log_backend&) = delete;

    ~asio_ostream_log_backend() noexcept override {
        this->finish_log();
    }
};
//------------------------------------------------------------------------------
#if EAGINE_POSIX
template <typename Lockable = std::mutex>
using asio_local_ostream_log_backend =
  asio_ostream_log_backend<asio_local_ostream_log_connection, Lockable>;
#define EAGINE_HAS_ASIO_LOCAL_LOG_BACKEND 1
#else
#define EAGINE_HAS_ASIO_LOCAL_LOG_BACKEND 0
#endif // EAGINE_POSIX

template <typename Lockable = std::mutex>
using asio_tcpipv4_ostream_log_backend =
  asio_ostream_log_backend<asio_tcpipv4_ostream_log_connection, Lockable>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_ASIO_BACKEND_HPP
