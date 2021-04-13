/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_INSTEAD_OF_HPP
#define EAGINE_INSTEAD_OF_HPP

namespace eagine {

/// @see Helper meta-function "returning" @c Dst type instead of @c Src type.
/// @ingroup metaprogramming
/// @see instead_of_t
template <typename Src, typename Dst>
struct instead_of {
    /// @brief The result type.
    using type = Dst;

    static constexpr Dst value(Dst val) noexcept {
        return val;
    }
};

/// @see Trait "returning" @c Dst type instead of @c Src type.
/// @ingroup metaprogramming
template <typename Src, typename Dst>
using instead_of_t = typename instead_of<Src, Dst>::type;

} // namespace eagine

#endif // EAGINE_INSTEAD_OF_HPP
