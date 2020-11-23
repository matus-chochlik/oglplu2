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
class Object {
private:
    ObjectType* _pimpl{nullptr};
    Deleter* _deleter{nullptr};

protected:
    Object(ObjectType* pimpl, Deleter* deleter, const char* error_message)
      : _pimpl(pimpl)
      , _deleter(deleter) {
        EAGINE_ASSERT(_deleter);
        if(!_pimpl) {
            throw std::runtime_error(error_message);
        }
    }

public:
    Object(Object&& temp) noexcept
      : _pimpl(std::exchange(temp._pimpl, nullptr))
      , _deleter(std::exchange(temp._deleter, nullptr)) {}

    Object(const Object&) = delete;
    auto operator=(Object&&) = delete;
    auto operator=(const Object&) = delete;

    ~Object() {
        if(_pimpl) {
            _deleter(_pimpl);
        }
    }

    auto Get() const noexcept -> ObjectType* {
        EAGINE_ASSERT(_pimpl);
        return _pimpl;
    }

    operator ObjectType*() const noexcept {
        return Get();
    }

    auto operator->() const noexcept -> ObjectType* {
        return Get();
    }
};

class Display : public Object<::Display> {
private:
    static auto _any_event(::Display*, ::XEvent*, ::XPointer) -> Bool {
        return True;
    }

public:
    Display(const char* name = nullptr)
      : Object<::Display>(
          ::XOpenDisplay(name),
          ::XCloseDisplay,
          "Error opening X Display") {}

    auto NextEvent(XEvent& event) const -> bool {
        return ::XCheckIfEvent(
                 this->Get(), &event, &_any_event, ::XPointer()) == True;
    }
};

class ScreenNames : public std::vector<std::string> {
public:
    ScreenNames() {
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
class DisplayObject {
private:
    const Display& _display;
    HandleType _handle;

    Deleter* _deleter{nullptr};

protected:
    auto DisplayRef() const -> auto& {
        return _display;
    }

    DisplayObject(
      const Display& display,
      HandleType handle,
      Deleter* deleter,
      const char* error_message)
      : _display(display)
      , _handle(handle)
      , _deleter(deleter) {
        EAGINE_ASSERT(_deleter);
        if(!_handle) {
            throw std::runtime_error(error_message);
        }
    }

public:
    DisplayObject(DisplayObject&& temp) noexcept
      : _display(temp._display)
      , _handle(std::exchange(temp._handle, 0))
      , _deleter(std::exchange(temp._deleter, nullptr)) {}

    DisplayObject(const DisplayObject&) = delete;
    auto operator=(DisplayObject&&) = delete;
    auto operator=(const DisplayObject&) = delete;

    ~DisplayObject() {
        if(_handle) {
            _deleter(_display, _handle);
        }
    }

    auto Handle() const -> HandleType {
        return _handle;
    }

    operator HandleType() const {
        return Handle();
    }
};

template <typename HandleType>
class BaseDisplayObject {
private:
    HandleType _handle;

public:
    template <typename Derived, typename Deleter>
    BaseDisplayObject(const DisplayObject<Derived, Deleter>& derived)
      : _handle(derived.Handle()) {}

    auto Handle() const -> HandleType {
        return _handle;
    }

    operator HandleType() const {
        return Handle();
    }
};

} // namespace eagine::x11

#endif
