/// @file eagine/cleanup_group.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_CLEANUP_GROUP_HPP
#define EAGINE_CLEANUP_GROUP_HPP

#include <eagine/memory/object_storage.hpp>
#include <eagine/scope_exit.hpp>

namespace eagine {
//------------------------------------------------------------------------------
class cleanup_group {
private:
    memory::object_storage _storage;

public:
    template <
      typename Func,
      typename = std::enable_if_t<std::is_invocable_v<Func>>,
      typename = std::enable_if_t<std::is_void_v<std::invoke_result_t<Func>>>>
    auto add(Func func) -> auto& {
        return _storage.template emplace<func_on_scope_exit<Func>>(
          std::move(func));
    }

    template <
      typename Func,
      typename = std::enable_if_t<std::is_invocable_v<Func>>>
    auto add_ret(Func func) -> auto& {
        return add([func{std::move(func)}]() { func(); });
    }

    void reserve(span_size_t n) {
        _storage.reserve(n);
    }

    auto is_empty() const noexcept {
        return _storage.is_empty();
    }

    void clear() noexcept {
        _storage.clear();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_CLEANUP_GROUP_HPP
