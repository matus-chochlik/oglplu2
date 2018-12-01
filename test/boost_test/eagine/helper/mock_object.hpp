/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_EAGINE_HELPER_MOCK_OBJECT_HPP
#define TEST_EAGINE_HELPER_MOCK_OBJECT_HPP

#include <set>
#include <stdexcept>
#include <eagine/deferred_handler.hpp>
#include <eagine/nothing.hpp>
#include <eagine/object/name.hpp>
#include <eagine/object/owner.hpp>
#include <eagine/outcome.hpp>

namespace eagine {
namespace tag {

struct mock_object {};

} // namespace tag

struct mock_error_info {
    const char* op_name;
};

[[noreturn]] static inline void
mock_handle_error(mock_error_info& mei) {
    throw std::runtime_error(mei.op_name);
}

struct mock_obj_gen_del_ops {
    static std::set<unsigned>& _assigned(void) noexcept {
        static std::set<unsigned> _ns;
        return _ns;
    }

    static deferred_handler<mock_error_info> _gen(
      span<unsigned> names) noexcept {
        unsigned next = 1;

        for(unsigned& name : names) {
            while(_assigned().find(next) != _assigned().end()) {
                ++next;
            }
            _assigned().insert(next);
            name = next;
        }
        return {};
    }

    static deferred_handler<mock_error_info> _delete(
      span<unsigned> names) noexcept {
        for(unsigned name : names) {
            if(_assigned().find(name) == _assigned().end()) {
                return {mock_handle_error, mock_error_info{"delete"}};
            }
            _assigned().erase(name);
        }
        return {};
    }

    static basic_outcome<bool, mock_error_info> _is_a(unsigned name) noexcept {
        return {_assigned().find(name) != _assigned().end()};
    }
};

template <>
struct object_traits<tag::mock_object> {
    typedef unsigned name_type;

    typedef mock_obj_gen_del_ops gen_del_ops;

    template <typename ObjTag>
    using dsa_zero_ops_t = object_name<ObjTag>;

    template <typename ObjTag>
    using dsa_ops_t = object_name<ObjTag>;

    static constexpr inline unsigned invalid_name(void) noexcept {
        return ~unsigned(0);
    }

    static constexpr inline unsigned get_type(void) noexcept {
        return 12345u;
    }
};

using mock_object_name = object_name<tag::mock_object>;
using mock_object = object_owner<tag::mock_object>;

} // namespace eagine

#endif // include guard
