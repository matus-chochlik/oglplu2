/**
 *  @file eagine/serialize/data_sink.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_DATA_SINK_HPP
#define EAGINE_SERIALIZE_DATA_SINK_HPP

#include "../memory/block.hpp"
#include "../span.hpp"
#include "../string_span.hpp"
#include "result.hpp"

namespace eagine {
//------------------------------------------------------------------------------
struct serializer_data_sink {
    serializer_data_sink() noexcept = default;
    serializer_data_sink(serializer_data_sink&&) noexcept = default;
    serializer_data_sink(const serializer_data_sink&) = delete;
    serializer_data_sink& operator=(serializer_data_sink&&) noexcept = default;
    serializer_data_sink& operator=(const serializer_data_sink&) = delete;
    virtual ~serializer_data_sink() noexcept = default;

    using result = serialization_result;

    virtual span_size_t remaining_size() = 0;

    virtual result write(memory::const_block data) = 0;

    inline result write(char chr) {
        return this->write(as_bytes(view_one(chr)));
    }

    inline result write(string_view str) {
        return this->write(as_bytes(str));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_DATA_SINK_HPP

