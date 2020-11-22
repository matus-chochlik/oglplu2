/**
 *  @file eagine/serialize/type/build_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_TYPE_BUILD_INFO_HPP
#define EAGINE_SERIALIZE_TYPE_BUILD_INFO_HPP

#include "../../build_info.hpp"
#include "../read.hpp"
#include "../write.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <>
struct serializer<build_info> : common_serializer<build_info> {
    template <typename Backend>
    auto write(const build_info& value, Backend& backend) const {
        return _serializer.write(value._data, backend);
    }

private:
    serializer<typename build_info::_data_tuple> _serializer{};
};
//------------------------------------------------------------------------------
template <>
struct deserializer<build_info> : common_deserializer<build_info> {
    template <typename Backend>
    auto read(build_info& value, Backend& backend) const {
        typename build_info::_data_tuple temp{};
        const auto errors{_deserializer.read(temp, backend)};
        if(EAGINE_LIKELY(!errors)) {
            value = {std::move(temp)};
        }
        return errors;
    }

private:
    deserializer<typename build_info::_data_tuple> _deserializer{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif

