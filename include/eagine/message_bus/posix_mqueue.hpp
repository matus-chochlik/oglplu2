/**
 *  @file eagine/message_bus/posix_mqueue.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_POSIX_MQUEUE_HPP
#define EAGINE_MESSAGE_BUS_POSIX_MQUEUE_HPP

#include "../branch_predict.hpp"
#include "../random_identifier.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "../serialize/string_backend.hpp"
#include "conn_factory.hpp"
#include "connection.hpp"
#include "serialize.hpp"
#include <errno.h>
#include <fcntl.h>
#include <mqueue.h>
#include <mutex>
#include <string.h>
#include <sys/stat.h>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class posix_mqueue {
private:
    std::string _name{};

    static constexpr ::mqd_t _invalid_handle() noexcept {
        return ::mqd_t(-1);
    }

    ::mqd_t _ihandle{_invalid_handle()};
    ::mqd_t _ohandle{_invalid_handle()};
    int _last_errno{0};

public:
    constexpr posix_mqueue() noexcept = default;
    posix_mqueue(posix_mqueue&& temp) noexcept {
        using std::swap;
        swap(_name, temp._name);
        swap(_ihandle, temp._ihandle);
        swap(_ohandle, temp._ohandle);
    }
    posix_mqueue(const posix_mqueue&) = delete;
    posix_mqueue& operator=(posix_mqueue&& temp) = delete;
    posix_mqueue& operator=(const posix_mqueue&) = delete;

    ~posix_mqueue() noexcept {
        try {
            this->close();
        } catch(...) {
        }
    }

    string_view get_name() const noexcept {
        return {_name};
    }

    posix_mqueue& set_name(std::string name) {
        _name = std::move(name);
        if(!_name.empty()) {
            if(_name.front() != '/') {
                _name.insert(_name.begin(), '/');
            }
        }
        return *this;
    }

    static std::string name_from(identifier id) {
        std::string result;
        result.reserve(std_size(identifier::max_size() + 1));
        id.name().str(result);
        return result;
    }

    posix_mqueue& set_name(identifier id) {
        return set_name(name_from(id));
    }

    posix_mqueue(std::string name) {
        set_name(std::move(name));
    }

    std::string last_message() const {
        if(_last_errno) {
            char buf[128] = {'\0'};
            ::strerror_r(_last_errno, buf, sizeof(buf));
            return {buf};
        }
        return {};
    }

    bool had_error() const {
        return _last_errno != 0;
    }

    bool needs_retry() const {
        return (_last_errno == EAGAIN) || (_last_errno == ETIMEDOUT);
    }

    constexpr bool is_open() const noexcept {
        return (_ihandle >= 0) && (_ohandle >= 0);
    }

    constexpr bool is_usable() const noexcept {
        return is_open() && !(had_error() && !needs_retry());
    }

    posix_mqueue& unlink() {
        errno = 0;
        ::mq_unlink((_name + "0").c_str());
        ::mq_unlink((_name + "1").c_str());
        _last_errno = errno;
        return *this;
    }

    posix_mqueue& create() {
        errno = 0;
        _ihandle = ::mq_open(
          (_name + "1").c_str(),
          O_RDONLY | O_CREAT | O_EXCL | O_NONBLOCK,
          S_IRUSR | S_IWUSR,
          nullptr);
        _last_errno = errno;
        if(errno == 0) {
            _ohandle = ::mq_open(
              (_name + "0").c_str(),
              O_WRONLY | O_CREAT | O_EXCL | O_NONBLOCK,
              S_IRUSR | S_IWUSR,
              nullptr);
            _last_errno = errno;
        }
        return *this;
    }

    posix_mqueue& open() {
        errno = 0;
        _ihandle = ::mq_open(
          (_name + "0").c_str(),
          O_RDONLY | O_NONBLOCK,
          S_IRUSR | S_IWUSR,
          nullptr);
        _last_errno = errno;
        if(errno == 0) {
            _ohandle = ::mq_open(
              (_name + "1").c_str(),
              O_WRONLY | O_NONBLOCK,
              S_IRUSR | S_IWUSR,
              nullptr);
            _last_errno = errno;
        }
        return *this;
    }

    posix_mqueue& close() {
        if(is_open()) {
            ::mq_close(_ihandle);
            ::mq_close(_ohandle);
            _ihandle = _invalid_handle();
            _ohandle = _invalid_handle();
            _last_errno = errno;
        }
        return *this;
    }

    constexpr static span_size_t default_data_size() noexcept {
        return 8 * 1024;
    }

    valid_if_positive<span_size_t> max_data_size() {
        if(is_open()) {
            struct ::mq_attr attr {};
            errno = 0;
            ::mq_getattr(_ohandle, &attr);
            _last_errno = errno;
            return {span_size(attr.mq_msgsize)};
        }
        return {0};
    }

    span_size_t data_size() noexcept {
        return extract_or(max_data_size(), default_data_size());
    }

    posix_mqueue& send(unsigned priority, span<const char> blk) {
        if(is_open()) {
            errno = 0;
            ::mq_send(_ohandle, blk.data(), std_size(blk.size()), priority);
            _last_errno = errno;
        }
        return *this;
    }

    using receive_handler = callable_ref<void(unsigned, span<const char>)>;

    posix_mqueue& receive(memory::span<char> blk, receive_handler handler) {
        if(is_open()) {
            unsigned priority{0U};
            errno = 0;
            auto received =
              ::mq_receive(_ihandle, blk.data(), blk.size(), &priority);
            _last_errno = errno;
            if(received > 0) {
                handler(priority, head(blk, received));
            }
        }
        return *this;
    }
};
//------------------------------------------------------------------------------
template <typename Base>
class posix_mqueue_connection_info : public Base {
public:
    connection_kind kind() final {
        return connection_kind::local_interprocess;
    }

    identifier type_id() final {
        return EAGINE_ID(PosixMQue);
    }
};
//------------------------------------------------------------------------------
class posix_mqueue_connection
  : public posix_mqueue_connection_info<connection> {
    using this_class = posix_mqueue_connection;

public:
    using fetch_handler = connection::fetch_handler;

    posix_mqueue_connection() {
        _buffer.resize(_data_queue.data_size());
    }

    bool open(std::string name) {
        return !_data_queue.set_name(std::move(name)).open().had_error();
    }

    bool is_usable() final {
        return _data_queue.is_usable();
    }

    valid_if_positive<span_size_t> max_data_size() final {
        return {_buffer.size()};
    }

    void update() override {
        std::unique_lock lock{_mutex};
        _receive();
        _send();
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

    void fetch_messages(fetch_handler handler) final {
        std::unique_lock lock{_mutex};
        _incoming.fetch_all(handler);
    }

protected:
    void _checkup(posix_mqueue& connect_queue) {
        if(connect_queue.is_usable()) {
            if(!_data_queue.is_usable()) {
                _data_queue.close();
                _data_queue.unlink();
                if(!_data_queue.set_name(random_identifier(_rand_eng))
                      .create()
                      .had_error()) {

                    _buffer.resize(connect_queue.data_size());

                    block_data_sink sink(cover(_buffer));
                    string_serializer_backend backend(sink);
                    auto errors = serialize_message(
                      EAGINE_MSG_ID(eagiMsgBus, pmqConnect),
                      message_view(_data_queue.get_name()),
                      backend);
                    if(!errors) {
                        connect_queue.send(1, as_chars(sink.done()));
                        _buffer.resize(_data_queue.data_size());
                    }
                }
            }
        }
    }

    void _receive() {
        if(_data_queue.is_usable()) {
            while(!_data_queue
                     .receive(
                       as_chars(cover(_buffer)),
                       posix_mqueue::receive_handler(
                         this, EAGINE_MEM_FUNC_C(this_class, _handle_receive)))
                     .had_error()) {
            }
        }
    }

    void _send() {
        if(_data_queue.is_usable()) {
            _outgoing.fetch_all(
              {this, EAGINE_MEM_FUNC_C(this_class, _handle_send)});
        }
    }

protected:
    bool _handle_send(memory::const_block data) {
        return !_data_queue.send(1, as_chars(data)).had_error();
    }

    void _handle_receive(unsigned, memory::span<const char> data) {
        _incoming.push_if([this, data](
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
    memory::buffer _buffer;
    message_storage _incoming;
    serialized_message_storage _outgoing;
    posix_mqueue _data_queue{};
    std::default_random_engine _rand_eng{std::random_device{}()};
};
//------------------------------------------------------------------------------
class posix_mqueue_connector : public posix_mqueue_connection {
public:
    using fetch_handler = connection::fetch_handler;

    posix_mqueue_connector(std::string name) noexcept
      : _connect_queue{std::move(name)} {
    }

    posix_mqueue_connector(identifier id)
      : _connect_queue{posix_mqueue::name_from(id)} {
    }

    posix_mqueue_connector(posix_mqueue_connector&&) noexcept = default;
    posix_mqueue_connector& operator=(posix_mqueue_connector&&) = delete;
    posix_mqueue_connector(const posix_mqueue_connector&) = delete;
    posix_mqueue_connector& operator=(const posix_mqueue_connector&) = delete;

    ~posix_mqueue_connector() noexcept {
        _data_queue.unlink();
    }

    void update() final {
        std::unique_lock lock{_mutex};
        _checkup();
        _receive();
        _send();
    }

private:
    void _checkup() {
        if(!_connect_queue.is_usable()) {
            _connect_queue.close();
            _connect_queue.open();
        }
        posix_mqueue_connection::_checkup(_connect_queue);
    }

    posix_mqueue _connect_queue{};
};
//------------------------------------------------------------------------------
class posix_mqueue_acceptor : public acceptor {
    using this_class = posix_mqueue_acceptor;

public:
    using accept_handler = acceptor::accept_handler;

    posix_mqueue_acceptor(std::string name) noexcept
      : _accept_queue{std::move(name)} {
        _buffer.resize(_accept_queue.data_size());
    }

    posix_mqueue_acceptor(identifier id)
      : posix_mqueue_acceptor{posix_mqueue::name_from(id)} {
    }

    posix_mqueue_acceptor(posix_mqueue_acceptor&&) noexcept = default;
    posix_mqueue_acceptor& operator=(posix_mqueue_acceptor&&) = delete;
    posix_mqueue_acceptor(const posix_mqueue_acceptor&) = delete;
    posix_mqueue_acceptor& operator=(const posix_mqueue_acceptor&) = delete;

    ~posix_mqueue_acceptor() noexcept {
        _accept_queue.unlink();
    }

    void process_accepted(const accept_handler& handler) final {
        _checkup();
        _receive();
        _process(handler);
    }

private:
    void _checkup() {
        if(!_accept_queue.is_usable()) {
            _accept_queue.close();
            _accept_queue.unlink();
            if(!_accept_queue.create().had_error()) {
                _buffer.resize(_accept_queue.data_size());
            }
        }
    }

    void _receive() {
        if(_accept_queue.is_usable()) {
            while(!_accept_queue
                     .receive(
                       as_chars(cover(_buffer)),
                       posix_mqueue::receive_handler(
                         this, EAGINE_MEM_FUNC_C(this_class, _handle_receive)))
                     .had_error()) {
            }
        }
    }

    void _handle_receive(unsigned, memory::span<const char> data) {
        _requests.push_if([data](
                            identifier_t& class_id,
                            identifier_t& method_id,
                            stored_message& message) {
            block_data_source source(as_bytes(data));
            string_deserializer_backend backend(source);
            const auto errors =
              deserialize_message(class_id, method_id, message, backend);
            if(EAGINE_LIKELY(EAGINE_ID(eagiMsgBus).matches(class_id))) {
                if(EAGINE_LIKELY(EAGINE_ID(pmqConnect).matches(method_id))) {
                    return !errors;
                }
            }
            return false;
        });
    }

    void _process(const accept_handler& handler) {
        auto fetch_handler = [this, &handler](
                               identifier_t class_id,
                               identifier_t method_id,
                               const message_view& message) -> bool {
            EAGINE_ASSERT((EAGINE_MSG_ID(eagiMsgBus, pmqConnect)
                             .matches(class_id, method_id)));

            if(auto conn = std::make_unique<posix_mqueue_connection>()) {
                if(conn->open(to_string(as_chars(message.data)))) {
                    handler(std::move(conn));
                }
            }
            return true;
        };
        _requests.fetch_all(message_storage::fetch_handler{fetch_handler});
    }

    memory::buffer _buffer;
    message_storage _requests;
    posix_mqueue _accept_queue{};
};
//------------------------------------------------------------------------------
struct posix_mqueue_connection_factory
  : posix_mqueue_connection_info<connection_factory> {
    using connection_factory::make_acceptor;
    using connection_factory::make_connector;

    std::unique_ptr<acceptor> make_acceptor(string_view address) final {
        return std::make_unique<posix_mqueue_acceptor>(to_string(address));
    }

    std::unique_ptr<connection> make_connector(string_view address) {
        return std::make_unique<posix_mqueue_connector>(to_string(address));
    }
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_POSIX_MQUEUE_HPP

