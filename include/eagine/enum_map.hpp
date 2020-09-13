/**
 *  @file eagine/enum_map.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

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
    bool _accept(Enum key, Visitor& visitor) {
        if(Key == key) {
            visitor(Key, *static_cast<Unit<Key>*>(this));
            return true;
        }
        return false;
    }

    template <typename Visitor>
    bool _accept(Enum key, Visitor& visitor) const {
        if(Key == key) {
            visitor(Key, *static_cast<const Unit<Key>*>(this));
            return true;
        }
        return false;
    }

    template <typename Visitor>
    span_size_t _accept(bitfield<Enum> keys, Visitor& visitor) {
        if(keys.has(Key)) {
            visitor(Key, *static_cast<Unit<Key>*>(this));
            return 1;
        }
        return 0;
    }

    template <typename Visitor>
    span_size_t _accept(bitfield<Enum> keys, Visitor& visitor) const {
        if(keys.has(Key)) {
            visitor(Key, *static_cast<const Unit<Key>*>(this));
            return 1;
        }
        return 0;
    }

    template <typename Visitor>
    bool _accept(Visitor& visitor) {
        visitor(Key, *static_cast<Unit<Key>*>(this));
        return true;
    }

    template <typename Visitor>
    bool _accept(Visitor& visitor) const {
        visitor(Key, *static_cast<const Unit<Key>*>(this));
        return true;
    }
};
//------------------------------------------------------------------------------
template <typename Enum, template <Enum> class Unit, Enum... Keys>
class static_enum_map : private static_enum_map_unit<Enum, Unit, Keys>... {

    template <Enum Key>
    static_enum_map_unit<Enum, Unit, Key>& _base() noexcept {
        return *this;
    }

    template <Enum Key>
    const static_enum_map_unit<Enum, Unit, Key>& _base() const noexcept {
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
    Unit<Key>& get() noexcept {
        return _base<Key>();
    }

    template <Enum Key>
    const Unit<Key>& get() const noexcept {
        return _base<Key>();
    }

    template <typename Visitor>
    bool visit(Enum key, Visitor visitor) noexcept {
        return (false || ... || _base<Keys>()._accept(key, visitor));
    }

    template <typename Visitor>
    bool visit(Enum key, Visitor visitor) const noexcept {
        return (false || ... || _base<Keys>()._accept(key, visitor));
    }

    template <typename Visitor>
    span_size_t visit(bitfield<Enum> keys, Visitor visitor) noexcept {
        return (0 + ... + _base<Keys>()._accept(keys, visitor));
    }

    template <typename Visitor>
    span_size_t visit(bitfield<Enum> keys, Visitor visitor) const noexcept {
        return (0 + ... + _base<Keys>()._accept(keys, visitor));
    }

    template <typename Visitor>
    bool visit_all(Visitor visitor) noexcept {
        return (true && ... && _base<Keys>()._accept(visitor));
    }

    template <typename Visitor>
    bool visit_all(Visitor visitor) const noexcept {
        return (true && ... && _base<Keys>()._accept(visitor));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ENUM_MAP_HPP
