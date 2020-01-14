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
#include "connection.hpp"
#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <string.h>
#include <sys/stat.h>

namespace eagine {
//------------------------------------------------------------------------------
class msg_queue_posix_mqueue {
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

    constexpr msg_queue_posix_mqueue() noexcept = default;
    msg_queue_posix_mqueue(msg_queue_posix_mqueue&& temp) noexcept {
        using std::swap;
        swap(_name, temp._name);
        swap(_handle, temp._handle);
    }
    msg_queue_posix_mqueue(const msg_queue_posix_mqueue&) = delete;
    msg_queue_posix_mqueue& operator=(msg_queue_posix_mqueue&& temp) noexcept {
        using std::swap;
        swap(_handle, temp._handle);
        return *this;
    }
    msg_queue_posix_mqueue& operator=(const msg_queue_posix_mqueue&) = delete;

    ~msg_queue_posix_mqueue() noexcept {
        try {
            this->close();
        } catch(...) {
        }
    }

    msg_queue_posix_mqueue& set_name(std::string name) {
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

    msg_queue_posix_mqueue(std::string name) {
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

    msg_queue_posix_mqueue& unlink() {
        errno = 0;
        ::mq_unlink(_name.c_str());
        _last_errno = errno;
        return *this;
    }

    msg_queue_posix_mqueue& create() {
        errno = 0;
        _handle = ::mq_open(
          _name.c_str(),
          O_RDWR | O_CREAT | O_EXCL | O_NONBLOCK,
          S_IRUSR | S_IWUSR,
          nullptr);
        _last_errno = errno;
        return *this;
    }

    msg_queue_posix_mqueue& open() {
        errno = 0;
        _handle = ::mq_open(
          _name.c_str(), O_RDWR | O_NONBLOCK, S_IRUSR | S_IWUSR, nullptr);
        _last_errno = errno;
        return *this;
    }

    msg_queue_posix_mqueue& close() {
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

    msg_queue_posix_mqueue& send(unsigned priority, span<const char> blk) {
        errno = 0;
        ::mq_send(_handle, blk.data(), std_size(blk.size()), priority);
        _last_errno = errno;
        return *this;
    }

    using receive_handler = callable_ref<void(unsigned, span<const char>)>;

    msg_queue_posix_mqueue& receive(
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
} // namespace eagine

#endif // EAGINE_MSG_BUS_POSIX_MQUEUE_HPP

