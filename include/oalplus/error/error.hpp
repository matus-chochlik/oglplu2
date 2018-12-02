/**
 *  @file oalplus/error/error.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ERROR_ERROR_1509260923_HPP
#define OALPLUS_ERROR_ERROR_1509260923_HPP

#include "info.hpp"
#include <stdexcept>

namespace oalplus {

class error : public std::runtime_error {
private:
    error_info _info;

    static std::string _make_msg(error_info& info);

public:
    error(error_info&& info);

    const error_info& info() const noexcept {
        return _info;
    }
};

} // namespace oalplus

#include <oalplus/error/error.inl>

#endif // include guard
