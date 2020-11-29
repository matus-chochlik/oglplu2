/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_INTEROP_X11_DISPLAY_HPP
#define EAGINE_INTEROP_X11_DISPLAY_HPP

#include <eagine/array_size.hpp>
#include <eagine/assert.hpp>
#include <X11/Xlib.h>
#include <cassert>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace eagine::x11 {

template <typename ObjectType, typename Deleter = int(ObjectType*)>
class object {
private:
    ObjectType* _pimpl{nullptr};
    Deleter* _deleter{nullptr};

protected:
    object(ObjectType* pimpl, Deleter* deleter, const char* error_message)
      : _pimpl(pimpl)
      , _deleter(deleter) {
        EAGINE_ASSERT(_deleter);
        if(!_pimpl) {
            throw std::runtime_error(error_message);
        }
    }

public:
    object(object&& temp) noexcept
      : _pimpl(std::exchange(temp._pimpl, nullptr))
      , _deleter(std::exchange(temp._deleter, nullptr)) {}

    object(const object&) = delete;
    auto operator=(object&&) = delete;
    auto operator=(const object&) = delete;

    ~object() {
        if(_pimpl) {
            _deleter(_pimpl);
        }
    }

    auto get() const noexcept -> ObjectType* {
        EAGINE_ASSERT(_pimpl);
        return _pimpl;
    }

    operator ObjectType*() const noexcept {
        return get();
    }

    auto operator->() const noexcept -> ObjectType* {
        return get();
    }
};

class display : public object<::Display> {
private:
    static auto _any_event(::Display*, ::XEvent*, ::XPointer) -> Bool {
        return True;
    }

public:
    display(const char* name = nullptr)
      : object<::Display>(
          ::XOpenDisplay(name),
          ::XCloseDisplay,
          "Error opening X Display") {}

    auto next_event(XEvent& event) const -> bool {
        return ::XCheckIfEvent(
                 this->get(), &event, &_any_event, ::XPointer()) == True;
    }
};

class screen_names : public std::vector<std::string> {
public:
    screen_names() {
        char namebuf[16];
        auto name = static_cast<char*>(namebuf);
        int display = 0;
        while(true) {
            int screen = 0;
            while(true) {
                std::snprintf( // NOLINT(hicpp-vararg)
                  name,
                  array_size(namebuf),
                  ":%d.%d",
                  display,
                  screen);

                if(auto tmp{::XOpenDisplay(name)}) {
                    push_back(name);
                    ::XCloseDisplay(tmp);
                } else if(screen != 0) {
                    break;
                } else {
                    return;
                }
                ++screen;
            }
            ++display;
        }
    }
};

template <typename HandleType, typename Deleter = int(::Display*, HandleType)>
class display_object {
private:
    const display& _display;
    HandleType _handle;

    Deleter* _deleter{nullptr};

protected:
    auto display_ref() const -> auto& {
        return _display;
    }

    display_object(
      const display& dpy,
      HandleType handle,
      Deleter* deleter,
      const char* error_message)
      : _display(dpy)
      , _handle(handle)
      , _deleter(deleter) {
        EAGINE_ASSERT(_deleter);
        if(!_handle) {
            throw std::runtime_error(error_message);
        }
    }

public:
    display_object(display_object&& temp) noexcept
      : _display(temp._display)
      , _handle(std::exchange(temp._handle, 0))
      , _deleter(std::exchange(temp._deleter, nullptr)) {}

    display_object(const display_object&) = delete;
    auto operator=(display_object&&) = delete;
    auto operator=(const display_object&) = delete;

    ~display_object() {
        if(_handle) {
            _deleter(_display, _handle);
        }
    }

    auto handle() const -> HandleType {
        return _handle;
    }

    operator HandleType() const {
        return handle();
    }
};

template <typename HandleType>
class base_display_object {
private:
    HandleType _handle;

public:
    template <typename Derived, typename Deleter>
    base_display_object(const display_object<Derived, Deleter>& derived)
      : _handle(derived.handle()) {}

    auto handle() const -> HandleType {
        return _handle;
    }

    operator HandleType() const {
        return handle();
    }
};

} // namespace eagine::x11

#endif
