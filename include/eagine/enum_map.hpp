/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_ENUM_MAP_HPP
#define EAGINE_ENUM_MAP_HPP

#include "bitfield.hpp"
#include "types.hpp"
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Enum, template <Enum> class Unit, Enum Key>
struct static_enum_map_unit : Unit<Key> {

    template <typename Visitor>
    auto _accept(Enum key, Visitor& visitor) -> bool {
        if(Key == key) {
            visitor(Key, *static_cast<Unit<Key>*>(this));
            return true;
        }
        return false;
    }

    template <typename Visitor>
    auto _accept(Enum key, Visitor& visitor) const -> bool {
        if(Key == key) {
            visitor(Key, *static_cast<const Unit<Key>*>(this));
            return true;
        }
        return false;
    }

    template <typename Visitor>
    auto _accept(bitfield<Enum> keys, Visitor& visitor) -> span_size_t {
        if(keys.has(Key)) {
            visitor(Key, *static_cast<Unit<Key>*>(this));
            return 1;
        }
        return 0;
    }

    template <typename Visitor>
    auto _accept(bitfield<Enum> keys, Visitor& visitor) const -> span_size_t {
        if(keys.has(Key)) {
            visitor(Key, *static_cast<const Unit<Key>*>(this));
            return 1;
        }
        return 0;
    }

    template <typename Visitor>
    auto _accept(Visitor& visitor) -> bool {
        visitor(Key, *static_cast<Unit<Key>*>(this));
        return true;
    }

    template <typename Visitor>
    auto _accept(Visitor& visitor) const -> bool {
        visitor(Key, *static_cast<const Unit<Key>*>(this));
        return true;
    }
};
//------------------------------------------------------------------------------
template <typename Enum, template <Enum> class Unit, Enum... Keys>
class static_enum_map : private static_enum_map_unit<Enum, Unit, Keys>... {

    template <Enum Key>
    auto _base() noexcept -> static_enum_map_unit<Enum, Unit, Key>& {
        return *this;
    }

    template <Enum Key>
    auto _base() const noexcept
      -> const static_enum_map_unit<Enum, Unit, Key>& {
        return *this;
    }

public:
    static_enum_map() = default;

    template <
      typename Arg,
      typename = std::enable_if_t<!std::is_same_v<Arg, static_enum_map>>>
    explicit static_enum_map(const Arg& arg)
      : static_enum_map_unit<Enum, Unit, Keys>{arg}... {}

    template <
      typename... Args,
      typename = std::enable_if_t<(sizeof...(Args) > 1)>>
    explicit static_enum_map(const Args&... args)
      : static_enum_map_unit<Enum, Unit, Keys>{args...}... {}

    template <Enum Key>
    auto get() noexcept -> Unit<Key>& {
        return _base<Key>();
    }

    template <Enum Key>
    auto get() const noexcept -> const Unit<Key>& {
        return _base<Key>();
    }

    template <typename Visitor>
    auto visit(Enum key, Visitor visitor) noexcept -> bool {
        return (false || ... || _base<Keys>()._accept(key, visitor));
    }

    template <typename Visitor>
    auto visit(Enum key, Visitor visitor) const noexcept -> bool {
        return (false || ... || _base<Keys>()._accept(key, visitor));
    }

    template <typename Visitor>
    auto visit(bitfield<Enum> keys, Visitor visitor) noexcept -> span_size_t {
        return (0 + ... + _base<Keys>()._accept(keys, visitor));
    }

    template <typename Visitor>
    auto visit(bitfield<Enum> keys, Visitor visitor) const noexcept
      -> span_size_t {
        return (0 + ... + _base<Keys>()._accept(keys, visitor));
    }

    template <typename Visitor>
    auto visit_all(Visitor visitor) noexcept -> bool {
        return (true && ... && _base<Keys>()._accept(visitor));
    }

    template <typename Visitor>
    auto visit_all(Visitor visitor) const noexcept -> bool {
        return (true && ... && _base<Keys>()._accept(visitor));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ENUM_MAP_HPP
