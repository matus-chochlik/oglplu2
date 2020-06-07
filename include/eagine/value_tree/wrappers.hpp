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

#include "interface.hpp"

namespace eagine {
namespace valtree {
//------------------------------------------------------------------------------
class compound;
class attribute {
public:
    attribute() noexcept = default;

    explicit operator bool() const {
        return bool(_pimpl);
    }

    bool operator!() const {
        return !_pimpl;
    }

    string_view name() const {
        if(_pimpl) {
            return _pimpl->name();
        }
        return {};
    }

    span_size_t nested_count() const {
        if(_pimpl) {
            return _pimpl->nested_count();
        }
        return 0;
    }

    attribute nested(span_size_t index) const {
        if(_pimpl) {
            return {_pimpl->nested(index)};
        }
        return {};
    }

    attribute find(const basic_string_path& path) const {
        if(_pimpl) {
            return {_pimpl->find(path)};
        }
        return {};
    }

    attribute find(string_view str_path) const {
        return find(basic_string_path{str_path, EAGINE_TAG(split_by), "/"});
    }

private:
    friend class compound;

    attribute(std::shared_ptr<attribute_interface> pimpl) noexcept
      : _pimpl{std::move(pimpl)} {
    }

    std::shared_ptr<attribute_interface> _pimpl{};
};
//------------------------------------------------------------------------------
class compound {
public:
    compound() noexcept = default;

    template <typename Compound, typename... Args>
    static std::
      enable_if_t<std::is_base_of_v<compound_interface, Compound>, compound>
      make(Args&&... args) {
        return {std::make_shared<Compound>(std::forward<Args>(args)...)};
    }

    explicit operator bool() const {
        return bool(_pimpl);
    }

    bool operator!() const {
        return !_pimpl;
    }

    attribute structure() {
        if(_pimpl) {
            return {_pimpl->structure()};
        }
        return {};
    }

    span_size_t value_count(const attribute& attrib) {
        if(_pimpl) {
            return _pimpl->value_count(attrib._pimpl);
        }
        return 0;
    }

    using fetch_strings_handler =
      callable_ref<void(span_size_t, span<const string_view>)>;

    span_size_t fetch_strings(
      const attribute& attrib,
      span_size_t offset,
      span_size_t size,
      fetch_strings_handler handler) {
        if(_pimpl) {
            return _pimpl->fetch_strings(attrib._pimpl, offset, size, handler);
        }
        return 0;
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

