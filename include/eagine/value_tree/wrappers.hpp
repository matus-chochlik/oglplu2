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
#include "../memory/span_algo.hpp"
#include "interface.hpp"
#include <utility>

namespace eagine {
namespace valtree {
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
        if(this != &temp) {
            using std::swap;
            swap(_owner, temp._owner);
            swap(_pimpl, temp._pimpl);
        }
        return *this;
    }

    attribute& operator=(const attribute& that) {
        if(this != &that) {
            using std::swap;
            attribute temp{};
            swap(_owner, temp._owner);
            swap(_pimpl, temp._pimpl);
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

    string_view name() const {
        if(_owner && _pimpl) {
            return _pimpl->name(*_owner);
        }
        return {};
    }

    span_size_t nested_count() const {
        if(_owner && _pimpl) {
            return _pimpl->nested_count(*_owner);
        }
        return 0;
    }

    attribute nested(span_size_t index) const {
        if(_owner && _pimpl) {
            return {_owner, _pimpl->nested(*_owner, index)};
        }
        return {};
    }

    attribute find(const basic_string_path& path) const {
        if(_owner && _pimpl) {
            return {_owner, _pimpl->find(*_owner, path)};
        }
        return {};
    }

    attribute find(string_view str_path) const {
        return find(basic_string_path{str_path, EAGINE_TAG(split_by), "/"});
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

    explicit operator bool() const {
        return bool(_pimpl);
    }

    bool operator!() const {
        return !_pimpl;
    }

    attribute structure() const {
        if(_pimpl) {
            return {_pimpl, _pimpl->structure()};
        }
        return {};
    }

    attribute find(const basic_string_path& path) const {
        return structure().find(path);
    }

    attribute find(string_view path_str) const {
        return structure().find(path_str);
    }

    bool has(const basic_string_path& path) const {
        return bool(find(path));
    }

    bool has(string_view path_str) const {
        return bool(find(path_str));
    }

    span_size_t value_count(const attribute& attrib) {
        if(_pimpl && attrib._pimpl) {
            return _pimpl->value_count(*attrib._pimpl);
        }
        return 0;
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
      string_view path_str, span_size_t offset, span<T> dest) {
        return fetch_values(find(path_str), offset, dest);
    }

    template <typename T>
    span<T> fetch_values(const attribute& attrib, span<T> dest) {
        return fetch_values(attrib, 0, dest);
    }

    template <typename T>
    span<T> fetch_values(string_view path_str, span<T> dest) {
        return fetch_values(path_str, 0, dest);
    }

    template <typename T>
    bool fetch_value(const attribute& attrib, span_size_t offset, T& dest) {
        return !fetch_values(attrib, offset, cover_one(dest)).empty();
    }

    template <typename T>
    bool fetch_value(const attribute& attrib, T& dest) {
        return fetch_value(attrib, 0, dest);
    }

    template <typename T>
    bool fetch_value(string_view path_str, span_size_t offset, T& dest) {
        return fetch_value(find(path_str), offset, dest);
    }

    template <typename T>
    bool fetch_value(string_view path_str, T& dest) {
        return fetch_value(find(path_str), dest);
    }

private:
    compound(std::shared_ptr<compound_interface> pimpl) noexcept
      : _pimpl{std::move(pimpl)} {
    }

    std::shared_ptr<compound_interface> _pimpl{};
};
//------------------------------------------------------------------------------
} // namespace valtree
} // namespace eagine

#endif // EAGINE_VALUE_TREE_WRAPPERS_HPP

