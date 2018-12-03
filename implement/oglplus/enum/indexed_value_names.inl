/**
 *  @file oglplus/enum/indexed_value_names.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/maybe_unused.hpp>

namespace oglplus {

OGLPLUS_LIB_FUNC
string_view
get_enum_value_name_cstr(const any_indexed_enum_value& aiev) noexcept {
    switch(aiev._base_id) {
#ifdef GL_TEXTURE0
        case GL_TEXTURE0:
            return {"TEXTURE", 7};
#endif

#ifdef GL_DRAW_BUFFER0
        case GL_DRAW_BUFFER0:
            return {"DRAW_BUFFER", 11};
#endif

#ifdef GL_CLIP_DISTANCE0
        case GL_CLIP_DISTANCE0:
            return {"CLIP_DISTANCE", 13};
#endif

#ifdef GL_COLOR_ATTACHMENT0
        case GL_COLOR_ATTACHMENT0:
            return {"COLOR_ATTACHMENT", 16};
#endif
        default:;
    }

    EAGINE_MAYBE_UNUSED(aiev);
    return {};
}

OGLPLUS_LIB_FUNC
std::string get_enum_value_name(const any_indexed_enum_value& aiev) noexcept {
    auto str = get_enum_value_name_cstr(aiev);
    return std::string(str.begin(), str.end()) + std::to_string(aiev.index());
}

} // namespace oglplus
