/**
 *  @file eagine/serialize/fast_backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_FAST_BACKEND_HPP
#define EAGINE_SERIALIZE_FAST_BACKEND_HPP

#include "write_backend.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class fast_serializer_backend
  : public common_serializer_backend<fast_serializer_backend> {
    using base = common_serializer_backend<fast_serializer_backend>;

public:
    using base::base;
    using base::sink;

    template <typename T>
    void do_write(span<const T> values) {
        sink(as_bytes(values));
    }

    void do_write(span<const string_view> values) {
        for(auto& str : values) {
            do_write(view_one(str.size()));
            sink(str);
        }
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_FAST_BACKEND_HPP

