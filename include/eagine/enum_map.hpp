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

#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Enum, template <Enum> class Unit, Enum Key>
struct static_enum_map_unit : Unit<Key> {

    template <typename Visitor>
    bool _accept(Enum key, Visitor& visitor) {
        if(Key == key) {
            visitor(*static_cast<Unit<Key>*>(this));
            return true;
        }
        return false;
    }

    template <typename Visitor>
    bool _accept(Enum key, Visitor& visitor) const {
        if(Key == key) {
            visitor(*static_cast<const Unit<Key>*>(this));
            return true;
        }
        return false;
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
      typename... Args,
      typename = std::enable_if_t<(sizeof...(Args) > 1)>>
    explicit static_enum_map(const Args&... args)
      : static_enum_map_unit<Enum, Unit, Keys>{args}... {
    }

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
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ENUM_MAP_HPP
