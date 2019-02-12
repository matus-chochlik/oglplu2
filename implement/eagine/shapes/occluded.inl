/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/functions.hpp>
#include <eagine/memory/span_algo.hpp>
#include <cassert>
#include <vector>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void occluded_gen::attrib_values(vertex_attrib_kind attr, span<float> dest) {

    if(attr == vertex_attrib_kind::occlusion) {
        const auto vc = delegated_gen::vertex_count();
        const auto pva = vertex_attrib_kind::position;
        const auto nva = vertex_attrib_kind::normal;
        const auto pvpv = delegated_gen::values_per_vertex(pva);
        const auto nvpv = delegated_gen::values_per_vertex(nva);
        const auto ns = _samples;

        if((pvpv == 3) && (nvpv == 3)) {
            assert(dest.size() >= vc * delegated_gen::values_per_vertex(attr));

            std::vector<float> positions(std_size(vc * pvpv));
            std::vector<float> normals(std_size(vc * nvpv));

            delegated_gen::attrib_values(pva, cover(positions));
            delegated_gen::attrib_values(nva, cover(normals));

            std::vector<math::line<float, true>> rays(std_size(vc * ns));
            std::vector<float> weights(rays.size());

            for(span_size_t v = 0; v < vc; ++v) {
                const auto k = std_size(v * 3);
                const math::tvec<float, 3, true> pos{
                  positions[k + 0], positions[k + 1], positions[k + 2]};
                const math::tvec<float, 3, true> nml{
                  normals[k + 0], normals[k + 1], normals[k + 2]};

                rays[std_size(v * ns)] = math::line<float, true>{pos, nml};
                weights[std_size(v * ns)] = 1.f;

                for(span_size_t s = 1; s < ns; ++s) {
                    // TODO: generate random vectors
                    rays[std_size(v * ns + s)] =
                      math::line<float, true>{pos, nml};
                    weights[std_size(v * ns + s)] = 1.f;
                }
            }
            std::vector<optionally_valid<float>> params(rays.size());

            delegated_gen::ray_intersections(view(rays), cover(params));

            for(span_size_t v = 0; v < vc; ++v) {
                float occl = 0.f;
                float wght = 0.f;
                for(span_size_t s = 0; s < ns; ++s) {
                    const auto l = std_size(v * ns + s);
                    if(params[l] > 0.0f) {
                        using std::exp;
                        occl += exp(1.f - params[l].value_anyway());
                    }
                    wght += weights[l];
                }
                dest[v] = occl / wght;
            }
        } else {
            fill(dest, 0.f);
        }
    } else {
        delegated_gen::attrib_values(attr, dest);
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
