/**
 *  @file eagine/serialize/type/sudoku.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_TYPE_SUDOKU_HPP
#define EAGINE_SERIALIZE_TYPE_SUDOKU_HPP

#include "../../sudoku.hpp"
#include "../read.hpp"
#include "../write.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <unsigned S, bool T>
struct serializer<basic_sudoku_board<S, T>>
  : common_serializer<basic_sudoku_board<S, T>> {
    template <typename Backend>
    auto write(const basic_sudoku_board<S, T>& value, Backend& backend) const {
        return _serializer.write(value._blocks, backend);
    }

private:
    serializer<typename basic_sudoku_board<S, T>::blocks_type> _serializer{};
};
//------------------------------------------------------------------------------
template <unsigned S, bool T>
struct deserializer<basic_sudoku_board<S, T>>
  : common_deserializer<basic_sudoku_board<S, T>> {
    template <typename Backend>
    auto read(basic_sudoku_board<S, T>& value, Backend& backend) const {
        const auto errors{_deserializer.read(value._blocks, backend)};
        return errors;
    }

private:
    deserializer<typename basic_sudoku_board<S, T>::blocks_type> _deserializer{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif

