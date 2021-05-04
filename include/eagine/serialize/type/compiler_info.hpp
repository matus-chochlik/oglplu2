/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_TYPE_COMPILER_INFO_HPP
#define EAGINE_SERIALIZE_TYPE_COMPILER_INFO_HPP

#include "../../compiler_info.hpp"
#include "../read.hpp"
#include "../write.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <>
struct serializer<compiler_info> : common_serializer<compiler_info> {
    template <typename Backend>
    auto write(const compiler_info& value, Backend& backend) const {
        return _serializer.write(value._data, backend);
    }

private:
    serializer<typename compiler_info::_data_tuple> _serializer{};
};
//------------------------------------------------------------------------------
template <>
struct deserializer<compiler_info> : common_deserializer<compiler_info> {
    template <typename Backend>
    auto read(compiler_info& value, Backend& backend) const {
        typename compiler_info::_data_tuple temp{};
        const auto errors{_deserializer.read(temp, backend)};
        if(EAGINE_LIKELY(!errors)) {
            value = {std::move(temp)};
        }
        return errors;
    }

private:
    deserializer<typename compiler_info::_data_tuple> _deserializer{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif

