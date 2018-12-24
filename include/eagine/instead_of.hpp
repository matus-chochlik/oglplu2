/**
 *  @file eagine/instead_of.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_INSTEAD_OF_HPP
#define EAGINE_INSTEAD_OF_HPP

namespace eagine {

template <typename Src, typename Dst>
struct instead_of {
    using type = Dst;

    static constexpr inline Dst value(Dst val) noexcept {
        return val;
    }
};

template <typename Src, typename Dst>
using instead_of_t = typename instead_of<Src, Dst>::type;

} // namespace eagine

#endif // EAGINE_INSTEAD_OF_HPP
