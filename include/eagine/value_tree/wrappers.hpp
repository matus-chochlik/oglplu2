/**
 *  @file eagine/value_tree/wrappers.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALUE_TREE_WRAPPERS_HPP
#define EAGINE_VALUE_TREE_WRAPPERS_HPP

#include "../assert.hpp"
#include "../callable_ref.hpp"
#include "../identity.hpp"
#include "../memory/span_algo.hpp"
#include "../valid_if/decl.hpp"
#include "interface.hpp"
#include <utility>

namespace eagine::valtree {
//------------------------------------------------------------------------------
class compound;
class attribute {
public:
    attribute() noexcept = default;
    attribute(attribute&& temp) noexcept
      : _owner{std::move(temp._owner)}
      , _pimpl{temp._pimpl} {
        temp._pimpl = nullptr;
    }

    attribute(const attribute& that)
      : _owner{that._owner}
      , _pimpl{that._pimpl} {
        if(_owner && _pimpl) {
            _owner->add_ref(*_pimpl);
        }
    }

    auto operator=(attribute&& temp) noexcept -> attribute& {
        if(this != std::addressof(temp)) {
            using std::swap;
            swap(_owner, temp._owner);
            swap(_pimpl, temp._pimpl);
        }
        return *this;
    }

    auto operator=(const attribute& that) -> attribute& {
        if(this != std::addressof(that)) {
            using std::swap;
            attribute temp{std::move(*this)};
            _owner = that._owner;
            _pimpl = that._pimpl;
            if(_owner && _pimpl) {
                _owner->add_ref(*_pimpl);
            }
        }
        return *this;
    }

    ~attribute() noexcept {
        if(_pimpl) {
            EAGINE_ASSERT(_owner);
            _owner->release(*_pimpl);
        }
    }

    explicit operator bool() const {
        return _owner && _pimpl;
    }

    auto type_id() const noexcept -> identifier_t {
        if(_pimpl) {
            return _pimpl->type_id();
        }
        return 0;
    }

    auto name() const -> string_view {
        if(_owner && _pimpl) {
            return _owner->attribute_name(*_pimpl);
        }
        return {};
    }

private:
    friend class compound;

    attribute(
      std::shared_ptr<compound_interface> owner,
      attribute_interface* pimpl) noexcept
      : _owner{std::move(owner)}
      , _pimpl{pimpl} {}

    std::shared_ptr<compound_interface> _owner{};
    attribute_interface* _pimpl{nullptr};
};
//------------------------------------------------------------------------------
class compound_attribute;
//------------------------------------------------------------------------------
template <typename T>
struct not_converted_value {
    constexpr not_converted_value(T& dest) noexcept
      : _dest{dest} {}

    constexpr auto dest() noexcept -> auto& {
        return _dest;
    }

    constexpr auto apply() const noexcept {
        return true;
    }

private:
    T& _dest;
};
//------------------------------------------------------------------------------
template <typename T>
struct converted_value : not_converted_value<T> {
    using base = not_converted_value<T>;
    using base::base;
};
//------------------------------------------------------------------------------
template <>
struct converted_value<std::chrono::duration<float>>
  : not_converted_value<std::chrono::duration<float>> {
    using base = not_converted_value<std::chrono::duration<float>>;
    using base::base;
};
//------------------------------------------------------------------------------
template <typename R, typename P>
class converted_value<std::chrono::duration<R, P>> {
    using T = std::chrono::duration<R, P>;

public:
    constexpr converted_value(T& dest) noexcept
      : _dest{dest} {}

    constexpr auto dest() noexcept -> auto& {
        return _temp;
    }

    auto apply() const {
        _dest = std::chrono::duration_cast<T>(_temp);
        return true;
    }

private:
    std::chrono::duration<float> _temp{};
    T& _dest;
};
//------------------------------------------------------------------------------
class compound {
public:
    compound() noexcept = default;

    template <typename Compound, typename... Args>
    static auto make(Args&&... args) -> std::
      enable_if_t<std::is_base_of_v<compound_interface, Compound>, compound> {
        return {Compound::make_shared(std::forward<Args>(args)...)};
    }

    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    auto type_id() const noexcept -> identifier_t {
        if(_pimpl) {
            return _pimpl->type_id();
        }
        return 0;
    }

    auto structure() const -> attribute {
        if(_pimpl) {
            return {_pimpl, _pimpl->structure()};
        }
        return {};
    }

    auto root() const -> compound_attribute;

    auto attribute_name(const attribute& attrib) const -> string_view {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->attribute_name(*attrib._pimpl);
        }
        return {};
    }

    auto canonical_type(const attribute& attrib) const -> value_type {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->canonical_type(*attrib._pimpl);
        }
        return value_type::unknown;
    }

    auto is_link(const attribute& attrib) const -> bool {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->is_link(*attrib._pimpl);
        }
        return false;
    }

    auto nested_count(const attribute& attrib) const -> span_size_t {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->nested_count(*attrib._pimpl);
        }
        return 0;
    }

    auto has_nested(const attribute& attrib) const -> bool {
        return nested_count(attrib) != 0;
    }

    auto nested(const attribute& attrib, span_size_t index) const -> attribute {
        if(_pimpl && attrib._pimpl) {
            return {_pimpl, _pimpl->nested(*attrib._pimpl, index)};
        }
        return {};
    }

    auto nested(const attribute& attrib, string_view name) const -> attribute {
        if(_pimpl && attrib._pimpl) {
            return {_pimpl, _pimpl->nested(*attrib._pimpl, name)};
        }
        return {};
    }

    auto nested(string_view name) const -> attribute {
        return nested(structure(), name);
    }

    auto find(const attribute& attrib, const basic_string_path& path) const
      -> attribute {
        if(_pimpl && attrib._pimpl) {
            return {_pimpl, _pimpl->find(*attrib._pimpl, path)};
        }
        return {};
    }

    auto find(const basic_string_path& path) const -> attribute {
        return find(structure(), path);
    }

    auto value_count(const attribute& attrib) const -> span_size_t {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->value_count(*attrib._pimpl);
        }
        return 0;
    }

    auto value_count(const basic_string_path& path) const -> span_size_t {
        return value_count(find(path));
    }

    auto value_count(string_view name) -> span_size_t {
        return value_count(nested(name));
    }

    template <typename T>
    auto fetch_values(const attribute& attrib, span_size_t offset, span<T> dest)
      const -> span<T> {
        if(_pimpl && attrib._pimpl) {
            return head(
              dest, _pimpl->fetch_values(*attrib._pimpl, offset, dest));
        }
        return {};
    }

    template <typename T>
    auto fetch_values(
      const basic_string_path& path,
      span_size_t offset,
      span<T> dest) const -> span<T> {
        return fetch_values(find(path), offset, dest);
    }

    template <typename T>
    auto fetch_values(string_view name, span_size_t offset, span<T> dest) const
      -> span<T> {
        return fetch_values(nested(name), offset, dest);
    }

    template <typename T>
    auto fetch_values(const attribute& attrib, span<T> dest) const -> span<T> {
        return fetch_values(attrib, 0, dest);
    }

    template <typename T>
    auto fetch_values(const basic_string_path& path, span<T> dest) const
      -> span<T> {
        return fetch_values(path, 0, dest);
    }

    template <typename T>
    auto fetch_values(string_view name, span<T> dest) const -> span<T> {
        return fetch_values(name, 0, dest);
    }

    auto fetch_blob(const attribute& attrib, memory::block dest) const
      -> memory::block {
        return fetch_values(attrib, dest);
    }

    auto fetch_blob(const basic_string_path& path, memory::block dest) const
      -> memory::block {
        return fetch_values(path, dest);
    }

    auto fetch_blob(string_view name, memory::block dest) const
      -> memory::block {
        return fetch_values(name, dest);
    }

    template <typename T>
    auto fetch_value(const attribute& attrib, span_size_t offset, T& dest) const
      -> bool {
        converted_value<T> conv{dest};
        if(!fetch_values(attrib, offset, cover_one(conv.dest())).empty()) {
            return conv.apply();
        }
        return false;
    }

    template <typename T>
    auto fetch_value(string_view name, span_size_t offset, T& dest) const
      -> bool {
        return fetch_value(nested(name), offset, dest);
    }

    template <typename T>
    auto fetch_value(const basic_string_path& path, span_size_t offset, T& dest)
      const -> bool {
        return fetch_value(find(path), offset, dest);
    }

    template <typename T>
    auto fetch_value(string_view name, T& dest) const -> bool {
        return fetch_value(name, 0, dest);
    }

    template <typename T>
    auto fetch_value(const attribute& attrib, T& dest) const -> bool {
        return fetch_value(attrib, 0, dest);
    }

    template <typename T>
    auto fetch_value(const basic_string_path& path, T& dest) const -> bool {
        return fetch_value(path, 0, dest);
    }

    template <std::size_t L>
    auto has_value(const attribute& attrib, const char (&what)[L]) const
      -> bool {
        char temp[L]{};
        if(fetch_values(attrib, 0, cover(temp))) {
            return starts_with(string_view(temp), string_view(what));
        }
        return false;
    }

    template <typename T>
    auto get(const attribute& attrib, span_size_t offset, identity<T> = {}) const
      -> optionally_valid<T> {
        T temp{};
        if(fetch_value(attrib, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    auto get(
      const basic_string_path& path,
      span_size_t offset,
      identity<T> = {}) const -> optionally_valid<T> {
        T temp{};
        if(fetch_value(path, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    auto get(string_view name, span_size_t offset, identity<T> = {}) const
      -> optionally_valid<T> {
        T temp{};
        if(fetch_value(name, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    auto get(const attribute& attrib, identity<T> tid = {}) const
      -> optionally_valid<T> {
        return get<T>(attrib, 0, tid);
    }

    template <typename T>
    auto get(const basic_string_path& path, identity<T> tid = {}) const
      -> optionally_valid<T> {
        return get<T>(path, 0, tid);
    }

    template <typename T>
    auto get(string_view name, identity<T> tid = {}) const
      -> optionally_valid<T> {
        return get<T>(name, 0, tid);
    }

    using visit_handler =
      callable_ref<bool(compound&, const attribute&, const basic_string_path&)>;

    void traverse(visit_handler visitor);

    using stack_visit_handler = callable_ref<bool(
      compound&,
      const attribute&,
      const basic_string_path&,
      span<const attribute>)>;

    void traverse(stack_visit_handler visitor);

private:
    compound(std::shared_ptr<compound_interface> pimpl) noexcept
      : _pimpl{std::move(pimpl)} {}

    std::shared_ptr<compound_interface> _pimpl{};
};
//------------------------------------------------------------------------------
class compound_attribute {
public:
    compound_attribute() noexcept = default;

    compound_attribute(compound c, attribute a) noexcept
      : _c{std::move(c)}
      , _a{std::move(a)} {
        EAGINE_ASSERT(_c.type_id() == _a.type_id());
    }

    explicit operator bool() const noexcept {
        return _c && _a;
    }

    auto type_id() const noexcept {
        return _c.type_id();
    }

    auto name() const noexcept -> string_view {
        return _c.attribute_name(_a);
    }

    auto is_link() const noexcept -> bool {
        return _c.is_link(_a);
    }

    auto canonical_type() const -> value_type {
        return _c.canonical_type(_a);
    }

    auto nested_count() const -> span_size_t {
        return _c.nested_count(_a);
    }

    auto has_nested() const -> span_size_t {
        return _c.has_nested(_a);
    }

    auto nested(span_size_t index) const -> compound_attribute {
        return {_c, _c.nested(_a, index)};
    }

    auto nested(string_view name) const -> compound_attribute {
        return {_c, _c.nested(_a, name)};
    }

    auto find(const basic_string_path& path) const -> compound_attribute {
        return {_c, _c.find(_a, path)};
    }

    auto value_count() const -> span_size_t {
        return _c.value_count(_a);
    }

    template <typename T>
    auto fetch_values(span_size_t offset, span<T> dest) const {
        return _c.fetch_values(_a, offset, dest);
    }

    template <typename T>
    auto fetch_values(span<T> dest) const {
        return _c.fetch_values(_a, dest);
    }

    auto fetch_blob(memory::block dest) const {
        return _c.fetch_blob(_a, dest);
    }

    template <typename T>
    auto fetch_value(span_size_t offset, T& dest) const -> bool {
        return _c.fetch_value(_a, offset, dest);
    }

    template <typename T>
    auto fetch_value(T& dest) const -> bool {
        return _c.fetch_value(_a, dest);
    }

    template <typename T>
    auto get(span_size_t offset, identity<T> tid = {}) const {
        return _c.get(_a, offset, tid);
    }

    template <typename T>
    auto get(identity<T> tid = {}) const {
        return _c.get(_a, tid);
    }

private:
    compound _c;
    attribute _a;
};
//------------------------------------------------------------------------------
inline auto compound::root() const -> compound_attribute {
    return {*this, structure()};
}
//------------------------------------------------------------------------------
static inline auto operator/(compound c, attribute a) noexcept
  -> compound_attribute {
    return {std::move(c), std::move(a)};
}
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/value_tree/wrappers.inl>
#endif

#endif // EAGINE_VALUE_TREE_WRAPPERS_HPP
