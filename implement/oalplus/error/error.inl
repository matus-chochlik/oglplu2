/**
 *  @file oalplus/error/error.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oalplus {
//------------------------------------------------------------------------------
#if !OALPLUS_LINK_LIBRARY || defined(OALPLUS_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
OALPLUS_LIB_FUNC
std::string error::_make_msg(error_info& info) {
    return ::alGetString(info.al_error_code());
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
inline error::error(error_info&& info)
  : std::runtime_error(_make_msg(info))
  , _info(info) {
}
//------------------------------------------------------------------------------
} // namespace oalplus
