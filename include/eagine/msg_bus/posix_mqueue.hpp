/**
 *  @file eagine/msg_bus/posix_mqueue.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MSG_BUS_POSIX_MQUEUE_HPP
#define EAGINE_MSG_BUS_POSIX_MQUEUE_HPP

#include "../branch_predict.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "../serialize/string_backend.hpp"
#include "connection.hpp"
#include "serialize.hpp"
#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <mutex>
#include <string.h>
#include <sys/stat.h>

namespace eagine {
//------------------------------------------------------------------------------
class message_bus_posix_mqueue {
private:
    std::string _name{};

    static constexpr ::mqd_t _invalid_handle() noexcept {
        return -1;
    }

    ::mqd_t _handle{_invalid_handle()};
    int _last_errno{0};

public:
    bool needs_retry() const {
        return (_last_errno == EAGAIN) || (_last_errno == ETIMEDOUT);
    }

    std::string last_message() const {
        if(_last_errno) {
            char buf[64] = {'\0'};
            ::strerror_r(_last_errno, buf, sizeof(buf));
            return {buf};
        }
        return {};
    }

    constexpr message_bus_posix_mqueue() noexcept = default;
    message_bus_posix_mqueue(message_bus_posix_mqueue&& temp) noexcept {
        using std::swap;
        swap(_name, temp._name);
        swap(_handle, temp._handle);
    }
    message_bus_posix_mqueue(const message_bus_posix_mqueue&) = delete;
    message_bus_posix_mqueue& operator=(
      message_bus_posix_mqueue&& temp) noexcept {
        using std::swap;
        swap(_handle, temp._handle);
        return *this;
    }
    message_bus_posix_mqueue& operator=(const message_bus_posix_mqueue&) =
      delete;

    ~message_bus_posix_mqueue() noexcept {
        try {
            this->close();
        } catch(...) {
        }
    }

    message_bus_posix_mqueue& set_name(std::string name) {
        _name = std::move(name);
        if(!_name.empty()) {
            if(_name.front() != '/') {
                _name.insert(_name.begin(), '/');
            }
            if(_name.back() != ';') {
                _name.insert(_name.begin(), ';');
            }
        }
        return *this;
    }

    message_bus_posix_mqueue(std::string name) {
        set_name(std::move(name));
    }

    constexpr bool is_open() const noexcept {
        return _handle >= 0;
    }

    constexpr explicit operator bool() const noexcept {
        return is_open();
    }

    constexpr bool operator!() const noexcept {
        return !bool(*this);
    }

    message_bus_posix_mqueue& unlink() {
        errno = 0;
        ::mq_unlink(_name.c_str());
        _last_errno = errno;
        return *this;
    }

    message_bus_posix_mqueue& create() {
        errno = 0;
        _handle = ::mq_open(
          _name.c_str(),
          O_RDWR | O_CREAT | O_EXCL | O_NONBLOCK,
          S_IRUSR | S_IWUSR,
          nullptr);
        _last_errno = errno;
        return *this;
    }

    message_bus_posix_mqueue& open() {
        errno = 0;
        _handle = ::mq_open(
          _name.c_str(), O_RDWR | O_NONBLOCK, S_IRUSR | S_IWUSR, nullptr);
        _last_errno = errno;
        return *this;
    }

    message_bus_posix_mqueue& close() {
        if(is_open()) {
            ::mq_close(_handle);
            _handle = _invalid_handle();
            _last_errno = errno;
        }
        return *this;
    }

    auto max_data_size() {
        struct ::mq_attr attr {};
        errno = 0;
        ::mq_getattr(_handle, &attr);
        _last_errno = errno;
        return attr.mq_msgsize;
    }

    message_bus_posix_mqueue& send(unsigned priority, span<const char> blk) {
        errno = 0;
        ::mq_send(_handle, blk.data(), std_size(blk.size()), priority);
        _last_errno = errno;
        return *this;
    }

    message_bus_posix_mqueue& send(memory::const_block blk) {
        return send(0, as_chars(blk));
    }

    using receive_handler = callable_ref<void(unsigned, span<const char>)>;

    message_bus_posix_mqueue& receive(
      memory::span<char> blk, receive_handler handler) {
        unsigned priority{0U};
        errno = 0;
        auto received =
          ::mq_receive(_handle, blk.data(), span_size(blk.size()), &priority);
        _last_errno = errno;
        if(received > 0) {
            handler(priority, head(blk, received));
        }
        return *this;
    }
};
//------------------------------------------------------------------------------
class message_bus_posix_mqueue_connection : public message_bus_connection {
    using this_class = message_bus_posix_mqueue_connection;

public:
    using fetch_handler = message_bus_connection::fetch_handler;

    identifier type_id() final {
        return EAGINE_ID(PosixMQue);
    }

    bool is_usable() final {
        return bool(_data_queue);
    }

    valid_if_positive<span_size_t> max_data_size() final {
        return {span_size(_buffer.size())};
    }

    void update() override {
        std::unique_lock lock{_mutex};
        _do_update();
    }

    bool send(
      identifier_t class_id,
      identifier_t method_id,
      const message_view& message) final {
        std::unique_lock lock{_mutex};
        block_data_sink sink(as_bytes(cover(_buffer)));
        string_serializer_backend backend(sink);
        auto errors = serialize_message(class_id, method_id, message, backend);
        if(!errors) {
            _outgoing.push(as_bytes(view(_buffer)));
            return true;
        }
        return false;
    }

    void fetch_messages(fetch_handler handler) final {
        std::unique_lock lock{_mutex};
        _incoming.fetch_all(handler);
    }

protected:
    void _do_update() {
        // receive
        while(_data_queue.receive(
          cover(_buffer),
          message_bus_posix_mqueue::receive_handler(
            this, EAGINE_MEM_FUNC_C(this_class, _handle_receive)))) {
        }
        // send
        _outgoing.fetch_all(
          {this, EAGINE_MEM_FUNC_C(this_class, _handle_send)});
    }

private:
    bool _handle_send(memory::const_block blk) {
        return bool(_data_queue.send(blk));
    }

    void _handle_receive(unsigned, memory::span<const char> data) {
        _incoming.push_if([data](
                            identifier_t& class_id,
                            identifier_t& method_id,
                            stored_message& message) {
            block_data_source source(as_bytes(data));
            string_deserializer_backend backend(source);
            const auto errors =
              deserialize_message(class_id, method_id, message, backend);
            return !errors;
        });
    }

    std::mutex _mutex;
    message_storage _incoming;
    serialized_message_storage _outgoing;
    std::vector<char> _buffer;
    message_bus_posix_mqueue _data_queue{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MSG_BUS_POSIX_MQUEUE_HPP

