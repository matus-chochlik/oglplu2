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

#include "../bool_aggregate.hpp"
#include "../branch_predict.hpp"
#include "../main_ctx_object.hpp"
#include "../random_identifier.hpp"
#include "../serialize/block_sink.hpp"
#include "../serialize/block_source.hpp"
#include "../serialize/string_backend.hpp"
#include "conn_factory.hpp"
#include "serialize.hpp"
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <mqueue.h>
#include <mutex>
#include <random>
#include <sys/stat.h>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
class posix_mqueue {
private:
    std::string _name{};

    static constexpr auto _invalid_handle() noexcept -> ::mqd_t {
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
    auto operator=(posix_mqueue&& temp) = delete;
    auto operator=(const posix_mqueue&) = delete;

    ~posix_mqueue() noexcept {
        try {
            this->close();
        } catch(...) {
        }
    }

    auto get_name() const noexcept -> string_view {
        return {_name};
    }

    auto set_name(std::string name) -> auto& {
        _name = std::move(name);
        if(!_name.empty()) {
            if(_name.front() != '/') {
                _name.insert(_name.begin(), '/');
            }
        }
        return *this;
    }

    static auto name_from(identifier id) -> std::string {
        std::string result;
        result.reserve(std_size(identifier::max_size() + 1));
        id.name().str(result);
        return result;
    }

    auto set_name(identifier id) -> auto& {
        return set_name(name_from(id));
    }

    posix_mqueue(std::string name) {
        set_name(std::move(name));
    }

    auto last_message() const -> std::string {
        if(_last_errno) {
            char buf[128] = {'\0'};
            ::strerror_r(_last_errno, static_cast<char*>(buf), sizeof(buf));
            return {static_cast<const char*>(buf)};
        }
        return {};
    }

    auto had_error() const -> bool {
        return _last_errno != 0;
    }

    auto needs_retry() const -> bool {
        return (_last_errno == EAGAIN) || (_last_errno == ETIMEDOUT);
    }

    constexpr auto is_open() const noexcept -> bool {
        return (_ihandle >= 0) && (_ohandle >= 0);
    }

    constexpr auto is_usable() const noexcept -> bool {
        return is_open() && !(had_error() && !needs_retry());
    }

    auto unlink() -> auto& {
        errno = 0;
        ::mq_unlink((_name + "0").c_str());
        ::mq_unlink((_name + "1").c_str());
        _last_errno = errno;
        return *this;
    }

    auto create() -> auto& {
        errno = 0;
        // NOLINTNEXTLINE(hicpp-vararg)
        _ihandle = ::mq_open(
          (_name + "1").c_str(),
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          O_RDONLY | O_CREAT | O_EXCL | O_NONBLOCK,
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          S_IRUSR | S_IWUSR,
          nullptr);
        _last_errno = errno;
        if(errno == 0) {
            // NOLINTNEXTLINE(hicpp-vararg)
            _ohandle = ::mq_open(
              (_name + "0").c_str(),
              // NOLINTNEXTLINE(hicpp-signed-bitwise)
              O_WRONLY | O_CREAT | O_EXCL | O_NONBLOCK,
              // NOLINTNEXTLINE(hicpp-signed-bitwise)
              S_IRUSR | S_IWUSR,
              nullptr);
            _last_errno = errno;
        }
        return *this;
    }

    auto open() -> auto& {
        errno = 0;
        // NOLINTNEXTLINE(hicpp-vararg)
        _ihandle = ::mq_open(
          (_name + "0").c_str(),
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          O_RDONLY | O_NONBLOCK,
          // NOLINTNEXTLINE(hicpp-signed-bitwise)
          S_IRUSR | S_IWUSR,
          nullptr);
        _last_errno = errno;
        if(errno == 0) {
            // NOLINTNEXTLINE(hicpp-vararg)
            _ohandle = ::mq_open(
              (_name + "1").c_str(),
              // NOLINTNEXTLINE(hicpp-signed-bitwise)
              O_WRONLY | O_NONBLOCK,
              // NOLINTNEXTLINE(hicpp-signed-bitwise)
              S_IRUSR | S_IWUSR,
              nullptr);
            _last_errno = errno;
        }
        return *this;
    }

    auto close() -> posix_mqueue& {
        if(is_open()) {
            ::mq_close(_ihandle);
            ::mq_close(_ohandle);
            _ihandle = _invalid_handle();
            _ohandle = _invalid_handle();
            _last_errno = errno;
        }
        return *this;
    }

    constexpr static auto default_data_size() noexcept -> span_size_t {
        return 8 * 1024;
    }

    auto max_data_size() -> valid_if_positive<span_size_t> {
        if(is_open()) {
            struct ::mq_attr attr {};
            errno = 0;
            ::mq_getattr(_ohandle, &attr);
            _last_errno = errno;
            return {span_size(attr.mq_msgsize)};
        }
        return {0};
    }

    auto data_size() noexcept -> span_size_t {
        return extract_or(max_data_size(), default_data_size());
    }

    auto send(unsigned priority, span<const char> blk) -> auto& {
        if(is_open()) {
            errno = 0;
            ::mq_send(_ohandle, blk.data(), std_size(blk.size()), priority);
            _last_errno = errno;
        }
        return *this;
    }

    using receive_handler = callable_ref<void(unsigned, span<const char>)>;

    auto receive(memory::span<char> blk, receive_handler handler) -> auto& {
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
    using Base::Base;

    auto kind() -> connection_kind final {
        return connection_kind::local_interprocess;
    }

    auto addr_kind() -> connection_addr_kind final {
        return connection_addr_kind::filepath;
    }

    auto type_id() -> identifier final {
        return EAGINE_ID(PosixMQue);
    }
};
//------------------------------------------------------------------------------
class posix_mqueue_connection
  : public posix_mqueue_connection_info<connection>
  , public main_ctx_object {

public:
    using fetch_handler = connection::fetch_handler;

    posix_mqueue_connection(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(MQueConn), parent} {
        _buffer.resize(_data_queue.data_size());
    }

    auto open(std::string name) -> bool {
        return !_data_queue.set_name(std::move(name)).open().had_error();
    }

    auto is_usable() -> bool final {
        return _data_queue.is_usable();
    }

    auto max_data_size() -> valid_if_positive<span_size_t> final {
        return {_buffer.size()};
    }

    auto update() -> bool override {
        std::unique_lock lock{_mutex};
        some_true something_done{};
        something_done(_receive());
        something_done(_send());
        return something_done;
    }

    auto send(message_id msg_id, const message_view& message) -> bool final {
        std::unique_lock lock{_mutex};
        block_data_sink sink(cover(_buffer));
        string_serializer_backend backend(sink);
        auto errors = serialize_message(msg_id, message, backend);
        if(!errors) {
            _outgoing.push(sink.done());
            return true;
        }
        return false;
    }

    auto fetch_messages(fetch_handler handler) -> bool final {
        std::unique_lock lock{_mutex};
        return _incoming.fetch_all(handler);
    }

protected:
    auto _checkup(posix_mqueue& connect_queue) -> bool {
        some_true something_done{};
        if(connect_queue.is_usable()) {
            if(!_data_queue.is_usable()) {
                _data_queue.close();
                _data_queue.unlink();
                if(!_data_queue
                      .set_name(random_identifier(any_random_engine(_rand_eng)))
                      .create()
                      .had_error()) {

                    _buffer.resize(connect_queue.data_size());

                    block_data_sink sink(cover(_buffer));
                    string_serializer_backend backend(sink);
                    auto errors = serialize_message(
                      EAGINE_MSGBUS_ID(pmqConnect),
                      message_view(_data_queue.get_name()),
                      backend);
                    if(!errors) {
                        connect_queue.send(1, as_chars(sink.done()));
                        _buffer.resize(_data_queue.data_size());
                    }
                }
                something_done();
            }
        }
        return something_done;
    }

    auto _receive() -> bool {
        some_true something_done{};
        if(_data_queue.is_usable()) {
            while(!_data_queue
                     .receive(
                       as_chars(cover(_buffer)),
                       posix_mqueue::receive_handler(
                         this, EAGINE_THIS_MEM_FUNC_C(_handle_receive)))
                     .had_error()) {
                something_done();
            }
        }
        return something_done;
    }

    auto _send() -> bool {
        if(_data_queue.is_usable()) {
            return _outgoing.fetch_all(
              {this, EAGINE_THIS_MEM_FUNC_C(_handle_send)});
        }
        return false;
    }

protected:
    auto _handle_send(memory::const_block data) -> bool {
        return !_data_queue.send(1, as_chars(data)).had_error();
    }

    void _handle_receive(unsigned, memory::span<const char> data) {
        _incoming.push_if([data](message_id& msg_id, stored_message& message) {
            block_data_source source(as_bytes(data));
            string_deserializer_backend backend(source);
            const auto errors = deserialize_message(msg_id, message, backend);
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
    using base = posix_mqueue_connection;

public:
    using fetch_handler = connection::fetch_handler;

    posix_mqueue_connector(main_ctx_parent parent, std::string name) noexcept
      : base{parent}
      , _connect_queue{std::move(name)} {}

    posix_mqueue_connector(main_ctx_parent parent, identifier id)
      : base{parent}
      , _connect_queue{posix_mqueue::name_from(id)} {}

    posix_mqueue_connector(posix_mqueue_connector&&) = delete;
    posix_mqueue_connector(const posix_mqueue_connector&) = delete;
    auto operator=(posix_mqueue_connector&&) = delete;
    auto operator=(const posix_mqueue_connector&) = delete;

    ~posix_mqueue_connector() noexcept final {
        _data_queue.unlink();
    }

    auto update() -> bool final {
        std::unique_lock lock{_mutex};
        some_true something_done{};
        something_done(_checkup());
        something_done(_receive());
        something_done(_send());
        return something_done;
    }

private:
    auto _checkup() -> bool {
        some_true something_done{};
        if(!_connect_queue.is_usable()) {
            _connect_queue.close();
            _connect_queue.open();
            something_done();
        }
        return posix_mqueue_connection::_checkup(_connect_queue) &&
               something_done;
    }

    posix_mqueue _connect_queue{};
};
//------------------------------------------------------------------------------
class posix_mqueue_acceptor
  : public posix_mqueue_connection_info<acceptor>
  , public main_ctx_object {

public:
    using accept_handler = acceptor::accept_handler;

    posix_mqueue_acceptor(main_ctx_parent parent, std::string name) noexcept
      : main_ctx_object{EAGINE_ID(MQueConnAc), parent}
      , _accept_queue{std::move(name)} {
        _buffer.resize(_accept_queue.data_size());
    }

    posix_mqueue_acceptor(main_ctx_parent parent, identifier id)
      : posix_mqueue_acceptor{parent, posix_mqueue::name_from(id)} {}

    posix_mqueue_acceptor(posix_mqueue_acceptor&&) noexcept = default;
    posix_mqueue_acceptor(const posix_mqueue_acceptor&) = delete;
    auto operator=(posix_mqueue_acceptor&&) = delete;
    auto operator=(const posix_mqueue_acceptor&) = delete;

    ~posix_mqueue_acceptor() noexcept final {
        _accept_queue.unlink();
    }

    auto update() -> bool final {
        some_true something_done{};
        something_done(_checkup());
        something_done(_receive());
        return something_done;
    }

    auto process_accepted(const accept_handler& handler) -> bool final {
        return _process(handler);
    }

private:
    auto _checkup() -> bool {
        some_true something_done{};
        if(!_accept_queue.is_usable()) {
            _accept_queue.close();
            _accept_queue.unlink();
            if(!_accept_queue.create().had_error()) {
                _buffer.resize(_accept_queue.data_size());
            }
            something_done();
        }
        return something_done;
    }

    auto _receive() -> bool {
        some_true something_done{};
        if(_accept_queue.is_usable()) {
            while(!_accept_queue
                     .receive(
                       as_chars(cover(_buffer)),
                       posix_mqueue::receive_handler(
                         this, EAGINE_THIS_MEM_FUNC_C(_handle_receive)))
                     .had_error()) {
                something_done();
            }
        }
        return something_done;
    }

    void _handle_receive(unsigned, memory::span<const char> data) {
        _requests.push_if([data](message_id& msg_id, stored_message& message) {
            block_data_source source(as_bytes(data));
            string_deserializer_backend backend(source);
            const auto errors = deserialize_message(msg_id, message, backend);
            if(EAGINE_LIKELY(is_special_message(msg_id))) {
                if(EAGINE_LIKELY(msg_id.has_method(EAGINE_ID(pmqConnect)))) {
                    return !errors;
                }
            }
            return false;
        });
    }

    auto _process(const accept_handler& handler) -> bool {
        auto fetch_handler = [this, &handler](
                               message_id msg_id,
                               message_age,
                               const message_view& message) -> bool {
            EAGINE_ASSERT((msg_id == EAGINE_MSGBUS_ID(pmqConnect)));
            EAGINE_MAYBE_UNUSED(msg_id);

            if(auto conn = std::make_unique<posix_mqueue_connection>(*this)) {
                if(conn->open(to_string(as_chars(message.data)))) {
                    handler(std::move(conn));
                }
            }
            return true;
        };
        return _requests.fetch_all({construct_from, fetch_handler});
    }

    memory::buffer _buffer{};
    message_storage _requests{};
    posix_mqueue _accept_queue{};
};
//------------------------------------------------------------------------------
class posix_mqueue_connection_factory
  : public posix_mqueue_connection_info<connection_factory>
  , public main_ctx_object {
public:
    posix_mqueue_connection_factory(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(MQueConnFc), parent} {}

    using connection_factory::make_acceptor;
    using connection_factory::make_connector;

    auto make_acceptor(string_view address) -> std::unique_ptr<acceptor> final {
        return std::make_unique<posix_mqueue_acceptor>(
          *this, to_string(address));
    }

    auto make_connector(string_view address)
      -> std::unique_ptr<connection> final {
        return std::make_unique<posix_mqueue_connector>(
          *this, to_string(address));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_POSIX_MQUEUE_HPP
