/// @file
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

/// @brief Wrapper for a handle to dynamically linkable executable module.
/// @see shared_executable_module
/// @ingroup dyn_lib
/// @note Do not use directly, consider using shared executable module.
class executable_module {
public:
    /// @brief Default constructor.
    executable_module() noexcept = default;

    /// @brief Not move constructible.
    executable_module(const executable_module&) = delete;

    /// @brief Not copy constructible.
    executable_module(executable_module&&) = delete;

    /// @brief Not move assignable.
    executable_module& operator=(const executable_module&) = delete;

    /// @brief Not copy assignable.
    executable_module& operator=(executable_module&&) = delete;

    /// @brief Alias for the handle type.
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

    /// @brief Closes the handle.
    ~executable_module() noexcept {
        if(_handle) {
            ::dlclose(_handle);
        }
    }

    /// @brief Checks if the module is open.
    /// @see find_symbol
    bool is_open() const noexcept {
        return bool(_handle);
    }

    /// @brief Returns a pointer to the exported symbol with the specifed name.
    /// @see is_open
    /// @see error_message
    optionally_valid<void*> find_symbol(string_view name) {
        ::dlerror();
        void* result = ::dlsym(_handle, c_str(name));
        if(auto error = ::dlerror()) {
            _message.assign(error);
            return {};
        }
        return {result, true};
    }

    /// @brief Returns the user-readable error message from the last failed operation.
    string_view error_message() const noexcept {
        return {_message};
    }

private:
    handle_type _handle{nullptr};
    std::string _message{};
};

/// @brief Reference counting handle to dynamically linkable executable module.
/// @ingroup dyn_lib
class shared_executable_module {
public:
    /// @brief Default constructor.
    /// @post !is_open()
    shared_executable_module() noexcept = default;

    /// @brief Constructor which opens the current executable as a module.
    /// @see open_self
    shared_executable_module(nothing_t)
      : _module{_do_open(nothing)} {}

    /// @brief Construction which tries to open executable module with specified filename.
    /// @see open
    shared_executable_module(string_view filename)
      : _module{_do_open(filename)} {}

    /// @brief Opens the current executable module. Closes the previous one, if any.
    /// @see open
    /// @see is_open
    shared_executable_module& open_self() {
        _module = _do_open(nothing);
        return *this;
    }

    /// @brief Opens the specified executable module. Closes the previous one, if any.
    /// @see open_self
    /// @see is_open
    shared_executable_module& open(string_view filename) {
        _module = _do_open(filename);
        return *this;
    }

    /// @brief Indicates if this executable module is open.
    /// @see open
    /// @see open_self
    bool is_open() const noexcept {
        return bool(_module) && _module->is_open();
    }

    /// @brief Indicates if this executable module is open.
    /// @see is_open
    explicit operator bool() const noexcept {
        return is_open();
    }

    /// @brief Returns a human-readable error message from the last failed operation.
    string_view error_message() const noexcept {
        return bool(_module) ? _module->error_message() : string_view();
    }

    /// @brief Finds and returns pointer to exported function with the specified name.
    /// @see is_open
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
