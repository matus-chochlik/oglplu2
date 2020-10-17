/**
 *  @file eagine/value_tree/implementation.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALUE_TREE_IMPLEMENTATION_HPP
#define EAGINE_VALUE_TREE_IMPLEMENTATION_HPP

#include "interface.hpp"
#include <memory>
#include <vector>

namespace eagine::valtree {
//------------------------------------------------------------------------------
template <typename Derived>
class compound_implementation : public compound_interface {
private:
    auto derived() noexcept -> Derived& {
        return *static_cast<Derived*>(this);
    }

public:
    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<bool> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<byte> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int16_t> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int32_t> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int64_t> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::uint16_t> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::uint32_t> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::uint64_t> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<float> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::chrono::duration<float>> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    auto fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::string> dest) -> span_size_t final {
        return derived().do_fetch_values(attrib, offset, dest);
    }
};
//------------------------------------------------------------------------------
template <typename Derived, typename Node>
class compound_with_refcounted_node : public compound_implementation<Derived> {
private:
    std::vector<std::tuple<span_size_t, std::unique_ptr<Node>>> _nodes{};

    auto _do_make_new(Node&& temp) -> Node* {
        for(auto& [ref_count, node_ptr] : _nodes) {
            if(temp == *node_ptr) {
                ++ref_count;
                return node_ptr.get();
            }
        }
        _nodes.emplace_back(1, std::make_unique<Node>(std::move(temp)));
        return std::get<1>(_nodes.back()).get();
    }

protected:
    inline auto _unwrap(attribute_interface& attrib) const noexcept -> auto& {
        EAGINE_ASSERT(attrib.type_id() == this->type_id());
        EAGINE_ASSERT(dynamic_cast<Node*>(&attrib));
        return static_cast<Node&>(attrib);
    }

public:
    template <typename... Args>
    auto make_node(Args&&... args) {
        return _do_make_new(Node{std::forward<Args>(args)...});
    }

    void add_ref(attribute_interface& attrib) noexcept final {
        auto& that = _unwrap(attrib);
        for(auto& [ref_count, node_ptr] : _nodes) {
            if(&that == node_ptr.get()) {
                ++ref_count;
            }
        }
    }

    void release(attribute_interface& attrib) noexcept final {
        auto& that = _unwrap(attrib);
        for(auto pos = _nodes.begin(); pos != _nodes.end(); ++pos) {
            auto& [ref_count, node_ptr] = *pos;
            if(&that == node_ptr.get()) {
                if(--ref_count <= 0) {
                    _nodes.erase(pos);
                    break;
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#endif // EAGINE_VALUE_TREE_IMPLEMENTATION_HPP
