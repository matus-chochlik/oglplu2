/**
 *  @file eagine/ssl_api/object_handle.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_OBJECT_HANDLE_HPP
#define EAGINE_SSL_API_OBJECT_HANDLE_HPP

#include "config.hpp"
#include <eagine/handle.hpp>
#include <eagine/message_id.hpp>

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
using basic_io_tag = EAGINE_MSG_TYPE(ssl, BIO);
//------------------------------------------------------------------------------
using basic_io = basic_handle<basic_io_tag, ssl_types::bio_type*, nullptr>;
using owned_basic_io =
  basic_owned_handle<basic_io_tag, ssl_types::bio_type*, nullptr>;
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_OBJECT_HANDLE_HPP
