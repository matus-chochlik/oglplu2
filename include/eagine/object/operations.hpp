/**
 *  @file eagine/object/operations.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_OPERATIONS_1509260923_HPP
#define EAGINE_OBJECT_OPERATIONS_1509260923_HPP

#include "name.hpp"

namespace eagine {

template <typename ObjTag>
class object_zero_and_ops
  : public object_traits<ObjTag>::template zero_dsa_ops_t<ObjTag> {
private:
    using _base =
      typename object_traits<ObjTag>::template zero_dsa_ops_t<ObjTag>;

public:
    object_zero_and_ops() = default;
};

template <typename ObjTag>
class object_name_and_ops
  : public object_traits<ObjTag>::template dsa_ops_t<ObjTag> {
private:
    using _base = typename object_traits<ObjTag>::template dsa_ops_t<ObjTag>;

public:
    using _base::_base;
};

} // namespace eagine

#endif // include guard
