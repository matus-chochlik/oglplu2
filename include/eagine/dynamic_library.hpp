/// @file eagine/dynamic_library.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_DYNAMIC_LIBRARY_HPP
#define EAGINE_DYNAMIC_LIBRARY_HPP

#include "config/platform.hpp"
#include "nothing.hpp"
#include "string_span.hpp"
#include <dlfcn.h>
#include <string>
#include <type_traits>

namespace eagine {

class executable_module {
public:
    executable_module() noexcept = default;
    executable_module(const executable_module&) = delete;
    executable_module(executable_module&&) = delete;
    executable_module& operator=(const executable_module&) = delete;
    executable_module& operator=(executable_module&&) = delete;

    using handle_type = void*;

    executable_module(string_view filename, int flags)
      : _handle(::dlopen(c_str(filename), flags)) {
        if(!_handle) {
            _message.assign(::dlerror());
        }
    }

    executable_module(nothing_t, int flags)
      : _handle(::dlopen(nullptr, flags)) {
        if(!_handle) {
            _message.assign(::dlerror());
        }
    }

    ~executable_module() noexcept {
        if(_handle) {
            ::dlclose(_handle);
        }
    }

    bool is_open() const noexcept {
        return bool(_handle);
    }

    optionally_valid<void*> find_symbol(string_view name) {
        ::dlerror();
        void* result = ::dlsym(_handle, c_str(name));
        if(auto error = ::dlerror()) {
            _message.assign(error);
            return {};
        }
        return {result, true};
    }

    string_view error_message() const noexcept {
        return {_message};
    }

private:
    handle_type _handle{nullptr};
    std::string _message{};
};

class shared_executable_module {
public:
    shared_executable_module() noexcept = default;

    shared_executable_module(nothing_t)
      : _module{_do_open(nothing)} {}

    shared_executable_module(string_view filename)
      : _module{_do_open(filename)} {}

    shared_executable_module& open_self() {
        _module = _do_open(nothing);
        return *this;
    }

    shared_executable_module& open(string_view filename) {
        _module = _do_open(filename);
        return *this;
    }

    bool is_open() const noexcept {
        return bool(_module) && _module->is_open();
    }

    explicit operator bool() const noexcept {
        return is_open();
    }

    string_view error_message() const noexcept {
        return bool(_module) ? _module->error_message() : string_view();
    }

    template <typename Signature>
    std::enable_if_t<
      std::is_function_v<std::remove_pointer_t<Signature>>,
      optionally_valid<std::remove_pointer_t<Signature>*>>
    find(string_view name) const noexcept {
        if(is_open()) {
            if(auto found = _module->find_symbol(name)) {
                return {
                  reinterpret_cast<std::remove_pointer_t<Signature>*>(
                    extract(found)),
                  true};
            }
        }
        return {};
    }

private:
    std::shared_ptr<executable_module> _module{};

    static std::shared_ptr<executable_module> _do_open(string_view filename) {
        return std::make_shared<executable_module>(filename, RTLD_LAZY);
    }

    static std::shared_ptr<executable_module> _do_open(nothing_t) {
        return std::make_shared<executable_module>(nothing, RTLD_LAZY);
    }
};

} // namespace eagine

#endif // EAGINE_DYNAMIC_LIBRARY_HPP
