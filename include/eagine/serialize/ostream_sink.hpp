/**
 *  @file eagine/serialize/ostream_sink.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_OSTREAM_SINK_HPP
#define EAGINE_SERIALIZE_OSTREAM_SINK_HPP

#include "data_sink.hpp"
#include <ostream>

namespace eagine {
//------------------------------------------------------------------------------
class ostream_data_sink : public serializer_data_sink {
public:
    ostream_data_sink(std::ostream& out) noexcept
      : _out{out} {
    }

    void write(memory::const_block blk) {
        _out.write(
          reinterpret_cast<const char*>(blk.data()),
          static_cast<std::streamsize>(blk.size()));
    }

private:
    std::ostream& _out;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_OSTREAM_SINK_HPP

