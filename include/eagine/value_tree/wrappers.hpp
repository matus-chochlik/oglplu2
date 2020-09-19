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

    auto attribute_name(const attribute& attrib) const -> string_view {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->attribute_name(*attrib._pimpl);
        }
        return {};
    }

    auto nested_count(const attribute& attrib) const -> span_size_t {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->nested_count(*attrib._pimpl);
        }
        return 0;
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

    auto value_count(const attribute& attrib) -> span_size_t {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->value_count(*attrib._pimpl);
        }
        return 0;
    }

    auto value_count(const basic_string_path& path) -> span_size_t {
        return value_count(find(path));
    }

    auto value_count(string_view name) -> span_size_t {
        return value_count(nested(name));
    }

    template <typename T>
    auto fetch_values(const attribute& attrib, span_size_t offset, span<T> dest)
      -> span<T> {
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
      span<T> dest) -> span<T> {
        return fetch_values(find(path), offset, dest);
    }

    template <typename T>
    auto fetch_values(string_view name, span_size_t offset, span<T> dest)
      -> span<T> {
        return fetch_values(nested(name), offset, dest);
    }

    template <typename T>
    auto fetch_values(const attribute& attrib, span<T> dest) -> span<T> {
        return fetch_values(attrib, 0, dest);
    }

    template <typename T>
    auto fetch_values(const basic_string_path& path, span<T> dest) -> span<T> {
        return fetch_values(path, 0, dest);
    }

    template <typename T>
    auto fetch_values(string_view name, span<T> dest) -> span<T> {
        return fetch_values(name, 0, dest);
    }

    template <typename T>
    auto fetch_value(const attribute& attrib, span_size_t offset, T& dest)
      -> bool {
        return !fetch_values(attrib, offset, cover_one(dest)).empty();
    }

    template <typename T>
    auto fetch_value(string_view name, span_size_t offset, T& dest) -> bool {
        return fetch_value(nested(name), offset, dest);
    }

    template <typename T>
    auto fetch_value(const basic_string_path& path, span_size_t offset, T& dest)
      -> bool {
        return fetch_value(find(path), offset, dest);
    }

    template <typename T>
    auto fetch_value(string_view name, T& dest) -> bool {
        return fetch_value(name, 0, dest);
    }

    template <typename T>
    auto fetch_value(const attribute& attrib, T& dest) -> bool {
        return fetch_value(attrib, 0, dest);
    }

    template <typename T>
    auto fetch_value(const basic_string_path& path, T& dest) -> bool {
        return fetch_value(path, 0, dest);
    }

    template <typename T>
    auto get(const attribute& attrib, span_size_t offset, identity<T> = {})
      -> optionally_valid<T> {
        T temp{};
        if(fetch_value(attrib, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    auto get(const basic_string_path& path, span_size_t offset, identity<T> = {})
      -> optionally_valid<T> {
        T temp{};
        if(fetch_value(path, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    auto get(string_view name, span_size_t offset, identity<T> = {})
      -> optionally_valid<T> {
        T temp{};
        if(fetch_value(name, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    auto get(const attribute& attrib, identity<T> tid = {})
      -> optionally_valid<T> {
        return get<T>(attrib, 0, tid);
    }

    template <typename T>
    auto get(const basic_string_path& path, identity<T> tid = {})
      -> optionally_valid<T> {
        return get<T>(path, 0, tid);
    }

    template <typename T>
    auto get(string_view name, identity<T> tid = {}) -> optionally_valid<T> {
        return get<T>(name, 0, tid);
    }

    using visit_handler =
      callable_ref<bool(compound&, const attribute&, const basic_string_path&)>;

    void traverse(visit_handler visitor);

private:
    compound(std::shared_ptr<compound_interface> pimpl) noexcept
      : _pimpl{std::move(pimpl)} {}

    std::shared_ptr<compound_interface> _pimpl{};
};
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/value_tree/wrappers.inl>
#endif

#endif // EAGINE_VALUE_TREE_WRAPPERS_HPP
