/**
 *  @file eagine/serialize/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_FWD_HPP
#define EAGINE_SERIALIZE_FWD_HPP

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
class fragment_serialize_wrapper;

template <typename T>
class fragment_deserialize_wrapper;

template <typename T>
struct serializer;

template <typename T>
struct deserializer;
//------------------------------------------------------------------------------
} // namespace eagine

#endif
