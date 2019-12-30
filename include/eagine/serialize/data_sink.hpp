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

namespace eagine {
//------------------------------------------------------------------------------
struct serializer_data_sink {
    serializer_data_sink() noexcept = default;
    serializer_data_sink(serializer_data_sink&&) noexcept = default;
    serializer_data_sink(const serializer_data_sink&) = delete;
    serializer_data_sink& operator=(serializer_data_sink&&) = delete;
    serializer_data_sink& operator=(const serializer_data_sink&) = delete;
    virtual ~serializer_data_sink() noexcept = default;

    virtual void write(memory::const_block data) = 0;

    inline void write(char chr) {
        this->write(as_bytes(view_one(chr)));
    }

    inline void write(string_view str) {
        this->write(as_bytes(str));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_DATA_SINK_HPP

