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
using engine_tag = EAGINE_MSG_TYPE(ssl, Engine);
using basic_io_tag = EAGINE_MSG_TYPE(ssl, BIO);
using basic_io_method_tag = EAGINE_MSG_TYPE(ssl, BIOMethod);
using message_digest_type_tag = EAGINE_MSG_TYPE(ssl, MsgDgstTyp);
using message_digest_tag = EAGINE_MSG_TYPE(ssl, MsgDigest);
using pkey_tag = EAGINE_MSG_TYPE(ssl, PKey);
//------------------------------------------------------------------------------
using engine = basic_handle<engine_tag, ssl_types::engine_type*, nullptr>;
using basic_io = basic_handle<basic_io_tag, ssl_types::bio_type*, nullptr>;
using basic_io_method =
  basic_handle<basic_io_method_tag, const ssl_types::bio_method_type*, nullptr>;
using message_digest_type =
  basic_handle<message_digest_type_tag, const ssl_types::evp_md_type*, nullptr>;
using message_digest =
  basic_handle<message_digest_tag, ssl_types::evp_md_ctx_type*, nullptr>;
using pkey = basic_handle<pkey_tag, ssl_types::evp_pkey_type*, nullptr>;
//------------------------------------------------------------------------------
using owned_basic_io =
  basic_owned_handle<basic_io_tag, ssl_types::bio_type*, nullptr>;
using owned_message_digest =
  basic_owned_handle<message_digest_tag, ssl_types::evp_md_ctx_type*, nullptr>;
using owned_pkey =
  basic_owned_handle<pkey_tag, ssl_types::evp_pkey_type*, nullptr>;
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_OBJECT_HANDLE_HPP
