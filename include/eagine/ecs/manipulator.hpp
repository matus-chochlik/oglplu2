/**
 *  @file eagine/ecs/manipulator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_ECS_MANIPULATOR_HPP
#define EAGINE_ECS_MANIPULATOR_HPP

#include "../assert.hpp"
#include "../optional_ref.hpp"
#include <type_traits>
#include <utility>

namespace eagine::ecs {

template <typename Component, bool Const>
class basic_manipulator;

template <typename Component>
class basic_manipulator<Component, false> {
private:
    Component* _ptr{nullptr};

protected:
    void _reset_cmp(Component& cmp) noexcept {
        _ptr = &cmp;
    }

public:
    basic_manipulator() noexcept = default;

    basic_manipulator(Component& cmp) noexcept
      : _ptr{&cmp} {}

    auto is_valid() const noexcept -> bool {
        return _ptr != nullptr;
    }

    auto read() const -> const Component& {
        EAGINE_ASSERT(is_valid());
        return *_ptr;
    }

    template <typename T>
    auto read(T Component::*member) const
      -> optional_reference_wrapper<const T> {
        if(_ptr != nullptr) {
            return {*_ptr.*member};
        }
        return {nothing};
    }

    auto write() -> Component& {
        EAGINE_ASSERT(is_valid());
        return *_ptr;
    }

    auto operator->() -> Component* {
        EAGINE_ASSERT(is_valid());
        return _ptr;
    }
};

template <typename Component>
class basic_manipulator<Component, true> {
private:
    const Component* _ptr{nullptr};

protected:
    void _reset_cmp(const Component& cmp) noexcept {
        _ptr = &cmp;
    }

public:
    basic_manipulator() noexcept = default;

    basic_manipulator(const Component& cmp) noexcept
      : _ptr{&cmp} {}

    auto is_valid() const noexcept -> bool {
        return _ptr != nullptr;
    }

    auto read() const -> const Component& {
        EAGINE_ASSERT(is_valid());
        return *_ptr;
    }

    template <typename T>
    auto read(T Component::*member) const
      -> optional_reference_wrapper<const T> {
        if(_ptr != nullptr) {
            return {*_ptr.*member};
        }
        return {nothing};
    }

    auto operator->() -> const Component* {
        EAGINE_ASSERT(is_valid());
        return _ptr;
    }
};

template <typename Component, bool Const>
struct get_manipulator {
    using type = basic_manipulator<Component, Const>;
};

template <typename Component, bool Const>
using get_manipulator_t = typename get_manipulator<Component, Const>::type;

template <typename Component>
class manipulator
  : public get_manipulator_t<
      std::remove_const_t<Component>,
      std::is_const_v<Component>> {
private:
    using _base = get_manipulator_t<
      std::remove_const_t<Component>,
      std::is_const_v<Component>>;

    using _nonconstC = std::remove_const_t<Component>;
    _nonconstC* _add_place{nullptr};

protected:
    const bool _can_rem{false};
    bool _removed{false};
    bool _added{false};

public:
    manipulator() = default;

    manipulator(bool can_rem)
      : _can_rem{can_rem} {}

    manipulator(Component& cmp, bool can_rem)
      : _base{cmp}
      , _can_rem{can_rem} {}

    manipulator(Component& cmp, _nonconstC& add, bool can_rem)
      : _base(cmp)
      , _add_place{&add}
      , _can_rem(can_rem) {}

    manipulator(std::nullptr_t, _nonconstC& add, bool can_rem)
      : _add_place{&add}
      , _can_rem{can_rem} {}

    auto can_add() const noexcept -> bool {
        return _add_place != nullptr;
    }

    void add(std::remove_const_t<Component>&& cmp) {
        EAGINE_ASSERT(can_add());
        EAGINE_ASSERT(_add_place);
        *_add_place = std::move(cmp);
        this->_reset_cmp(*_add_place);
        _added = true;
    }

    auto can_remove() const noexcept -> bool {
        return _can_rem && this->is_valid();
    }

    void remove() {
        _removed = true;
    }
};

template <typename Component>
class concrete_manipulator : public manipulator<Component> {
public:
    using manipulator<Component>::manipulator;

    void reset(Component& cmp) noexcept {
        this->_reset_cmp(cmp);
        this->_added = false;
        this->_removed = false;
    }

    auto add_requested() const noexcept -> bool {
        return this->_added;
    }

    auto remove_requested() const noexcept -> bool {
        return this->_removed;
    }
};

} // namespace eagine::ecs

#endif // EAGINE_ECS_MANIPULATOR_HPP
