/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/math/matrix_inverse.hpp>
#include <oglplus/math/coordinates.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
auto orbiting_camera::target_to_camera_direction() const noexcept -> vec3 {
    return to_cartesian(unit_spherical_coordinates(azimuth(), elevation()));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
auto orbiting_camera::target_plane_point(float ndcx, float ndcy, float aspect)
  const noexcept -> optionally_valid<vec3> {
    using math::inverse_matrix;
    using math::multiply;

    const auto mat = matrix(aspect);

    if(auto inv = inverse_matrix(mat)) {
        auto ndct = multiply(mat, vec4(target(), 1.F));
        auto ndc = vec4{ndcx * ndct.w(), ndcy * ndct.w(), ndct.z(), ndct.w()};
        return {vec3(math::multiply(inv.value(), ndc)), true};
    }
    return {};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
auto orbiting_camera::pointer_ray(float ndcx, float ndcy, float aspect)
  const noexcept -> optionally_valid<line> {
    if(const auto ptr{target_plane_point(ndcx, ndcy, aspect)}) {
        return {line(position(), ptr.value_anyway() - position()), true};
    }
    return {};
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
auto orbiting_camera::grab_sphere_radius() const noexcept -> float {
    const auto orb = orbit();
    return math::minimum(orb * tan(fov() * 0.5F), orb * 0.75F);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
auto orbiting_camera::grab_sphere() const noexcept -> sphere {
    return sphere(target(), grab_sphere_radius());
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp
