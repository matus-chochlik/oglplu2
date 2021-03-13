/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_TRANSLATED_HPP
#define EAGINE_SHAPES_TRANSLATED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <array>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Generator modifier translating the generated vertices by specifed amount.
/// @ingroup shapes
/// @see translate
class translated_gen : public delegated_gen {
public:
    translated_gen(
      std::unique_ptr<generator>&& gen,
      std::array<float, 3> d) noexcept
      : delegated_gen(std::move(gen))
      , _d{d} {}

    void attrib_values(vertex_attrib_variant, span<float>) override;

    auto bounding_sphere() -> math::sphere<float, true> override;

private:
    std::array<float, 3> _d;
};
//------------------------------------------------------------------------------
/// @brief Constructs instances of translated_gen modifier.
/// @ingroup shapes
static inline auto
translate(std::unique_ptr<generator>&& gen, std::array<float, 3> d) noexcept {
    return std::make_unique<translated_gen>(std::move(gen), d);
}
//------------------------------------------------------------------------------

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/translated.inl>
#endif

#endif // EAGINE_SHAPES_TRANSLATED_HPP
