/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_TEST_MAIN_CTX_HPP
#define EAGINE_TEST_MAIN_CTX_HPP

#include <eagine/main_ctx_object.hpp>
#include <eagine/main_ctx_storage.hpp>
#include <eagine/protected_member.hpp>

namespace eagine {
//------------------------------------------------------------------------------
struct test_args {
    const int argc = 2;
    const char* arg0 = "test";
    const char* arg1 = "--use-null-log";
    const char* arga[3] = {arg0, arg1, nullptr};
    const char** argv = static_cast<const char**>(arga);
};
//------------------------------------------------------------------------------
class test_main_ctx
  : protected_member<test_args>
  , protected_member<main_ctx_options>
  , protected_member<main_ctx_storage>
  , public main_ctx {

public:
    test_main_ctx()
      : protected_member<main_ctx_storage>{
		  static_cast<protected_member<test_args>&>(*this).get_the_member().argc,
		  static_cast<protected_member<test_args>&>(*this).get_the_member().argv,
		  static_cast<protected_member<main_ctx_options>&>(*this).get_the_member()}
      , main_ctx{static_cast<protected_member<main_ctx_storage>&>(*this).get_the_member()} {}
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
