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

    attribute& operator=(attribute&& temp) noexcept {
        if(this != std::addressof(temp)) {
            using std::swap;
            swap(_owner, temp._owner);
            swap(_pimpl, temp._pimpl);
        }
        return *this;
    }

    attribute& operator=(const attribute& that) {
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

    identifier_t type_id() const noexcept {
        if(_pimpl) {
            return _pimpl->type_id();
        }
        return 0;
    }

    string_view name() const {
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
      , _pimpl{pimpl} {
    }

    std::shared_ptr<compound_interface> _owner{};
    attribute_interface* _pimpl{nullptr};
};
//------------------------------------------------------------------------------
class compound {
public:
    compound() noexcept = default;

    template <typename Compound, typename... Args>
    static std::
      enable_if_t<std::is_base_of_v<compound_interface, Compound>, compound>
      make(Args&&... args) {
        return {Compound::make_shared(std::forward<Args>(args)...)};
    }

    explicit operator bool() const noexcept {
        return bool(_pimpl);
    }

    bool operator!() const noexcept {
        return !_pimpl;
    }

    identifier_t type_id() const noexcept {
        if(_pimpl) {
            return _pimpl->type_id();
        }
        return 0;
    }

    attribute structure() const {
        if(_pimpl) {
            return {_pimpl, _pimpl->structure()};
        }
        return {};
    }

    string_view attribute_name(const attribute& attrib) const {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->attribute_name(*attrib._pimpl);
        }
        return {};
    }

    span_size_t nested_count(const attribute& attrib) const {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->nested_count(*attrib._pimpl);
        }
        return 0;
    }

    attribute nested(const attribute& attrib, span_size_t index) const {
        if(_pimpl && attrib._pimpl) {
            return {_pimpl, _pimpl->nested(*attrib._pimpl, index)};
        }
        return {};
    }

    attribute nested(const attribute& attrib, string_view name) const {
        if(_pimpl && attrib._pimpl) {
            return {_pimpl, _pimpl->nested(*attrib._pimpl, name)};
        }
        return {};
    }

    attribute nested(string_view name) const {
        return nested(structure(), name);
    }

    attribute find(
      const attribute& attrib, const basic_string_path& path) const {
        if(_pimpl && attrib._pimpl) {
            return {_pimpl, _pimpl->find(*attrib._pimpl, path)};
        }
        return {};
    }

    attribute find(const basic_string_path& path) const {
        return find(structure(), path);
    }

    span_size_t value_count(const attribute& attrib) {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->value_count(*attrib._pimpl);
        }
        return 0;
    }

    span_size_t value_count(const basic_string_path& path) {
        return value_count(find(path));
    }

    span_size_t value_count(string_view name) {
        return value_count(nested(name));
    }

    template <typename T>
    span<T> fetch_values(
      const attribute& attrib, span_size_t offset, span<T> dest) {
        if(_pimpl && attrib._pimpl) {
            return head(
              dest, _pimpl->fetch_values(*attrib._pimpl, offset, dest));
        }
        return {};
    }

    template <typename T>
    span<T> fetch_values(
      const basic_string_path& path, span_size_t offset, span<T> dest) {
        return fetch_values(find(path), offset, dest);
    }

    template <typename T>
    span<T> fetch_values(string_view name, span_size_t offset, span<T> dest) {
        return fetch_values(nested(name), offset, dest);
    }

    template <typename T>
    span<T> fetch_values(const attribute& attrib, span<T> dest) {
        return fetch_values(attrib, 0, dest);
    }

    template <typename T>
    span<T> fetch_values(const basic_string_path& path, span<T> dest) {
        return fetch_values(path, 0, dest);
    }

    template <typename T>
    span<T> fetch_values(string_view name, span<T> dest) {
        return fetch_values(name, 0, dest);
    }

    template <typename T>
    bool fetch_value(const attribute& attrib, span_size_t offset, T& dest) {
        return !fetch_values(attrib, offset, cover_one(dest)).empty();
    }

    template <typename T>
    bool fetch_value(string_view name, span_size_t offset, T& dest) {
        return fetch_value(nested(name), offset, dest);
    }

    template <typename T>
    bool fetch_value(
      const basic_string_path& path, span_size_t offset, T& dest) {
        return fetch_value(find(path), offset, dest);
    }

    template <typename T>
    bool fetch_value(string_view name, T& dest) {
        return fetch_value(name, 0, dest);
    }

    template <typename T>
    bool fetch_value(const attribute& attrib, T& dest) {
        return fetch_value(attrib, 0, dest);
    }

    template <typename T>
    bool fetch_value(const basic_string_path& path, T& dest) {
        return fetch_value(path, 0, dest);
    }

    template <typename T>
    optionally_valid<T> get(
      const attribute& attrib, span_size_t offset, identity<T> = {}) {
        T temp{};
        if(fetch_value(attrib, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    optionally_valid<T> get(
      const basic_string_path& path, span_size_t offset, identity<T> = {}) {
        T temp{};
        if(fetch_value(path, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    optionally_valid<T> get(
      string_view name, span_size_t offset, identity<T> = {}) {
        T temp{};
        if(fetch_value(name, offset, temp)) {
            return {std::move(temp), true};
        }
        return {};
    }

    template <typename T>
    optionally_valid<T> get(const attribute& attrib, identity<T> tid = {}) {
        return get<T>(attrib, 0, tid);
    }

    template <typename T>
    optionally_valid<T> get(
      const basic_string_path& path, identity<T> tid = {}) {
        return get<T>(path, 0, tid);
    }

    template <typename T>
    optionally_valid<T> get(string_view name, identity<T> tid = {}) {
        return get<T>(name, 0, tid);
    }

    using visit_handler =
      callable_ref<bool(compound&, const attribute&, const basic_string_path&)>;

    void traverse(visit_handler visitor);

private:
    compound(std::shared_ptr<compound_interface> pimpl) noexcept
      : _pimpl{std::move(pimpl)} {
    }

    std::shared_ptr<compound_interface> _pimpl{};
};
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/value_tree/wrappers.inl>
#endif

#endif // EAGINE_VALUE_TREE_WRAPPERS_HPP

