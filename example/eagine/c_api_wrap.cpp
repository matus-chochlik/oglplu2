/**
 *  @example eagine/c_api_wrap.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>
#include <eagine/c_api_wrap.hpp>
#include <iostream>

#if EAGINE_POSIX
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#define EXAMPLE_API_STATIC_FUNC(NAME) &::NAME
#else
#define EXAMPLE_API_STATIC_FUNC(NAME) nullptr
#endif

namespace eagine {
//------------------------------------------------------------------------------
struct example_sets_errno {};
//------------------------------------------------------------------------------
struct example_api_traits {

    template <typename Tag, typename Signature>
    using function_pointer = std::add_pointer<Signature>;

    template <typename Tag, typename Signature>
    std::add_pointer_t<Signature> load_function(
      Tag, string_view, identity<Signature>) {
        return nullptr;
    }

    template <typename Tag, typename T>
    using transform_return_value = identity<T>;

    template <typename Tag, typename T>
    using transform_parameter = identity<T>;

    template <typename Tag, typename RV>
    static constexpr RV fallback(Tag, identity<RV>) {
        return {};
    }

    template <typename RV, typename... Params, typename... Args>
    static constexpr auto call(
      example_sets_errno, RV (*function)(Params...), Args&&... args) {
        return function(std::forward<Args>(args)...);
    }
};
//------------------------------------------------------------------------------
template <typename Traits>
struct example_file_api {

    opt_c_api_function<
      Traits,
      example_sets_errno,
      int(int[2]),
      EXAMPLE_API_STATIC_FUNC(pipe),
      EAGINE_POSIX>
      make_pipe;

    opt_c_api_function<
      Traits,
      example_sets_errno,
      ssize_t(int, void*, size_t),
      EXAMPLE_API_STATIC_FUNC(read),
      EAGINE_POSIX>
      read_file;

    opt_c_api_function<
      Traits,
      example_sets_errno,
      ssize_t(int, const void*, size_t),
      EXAMPLE_API_STATIC_FUNC(write),
      EAGINE_POSIX>
      write_file;

    opt_c_api_function<
      Traits,
      example_sets_errno,
      int(int),
      EXAMPLE_API_STATIC_FUNC(close),
      EAGINE_POSIX>
      close_file;

    example_file_api(Traits& traits)
      : make_pipe{"pipe", traits}
      , read_file{"read", traits}
      , write_file{"write", traits}
      , close_file{"close", traits} {
    }
};
//------------------------------------------------------------------------------
template <typename Traits>
example_file_api<Traits> wrap_example_file_api(Traits& traits) {
    return {traits};
}
//------------------------------------------------------------------------------
} // namespace eagine

int main() {
    using namespace eagine;
    example_api_traits traits;
    auto api(wrap_example_file_api(traits));

    if(api.make_pipe && api.write_file && api.read_file && api.close_file) {
        int pfd[2] = {-1, -1};
        char buffer[64];

        api.make_pipe(pfd);
        api.write_file(pfd[1], static_cast<const void*>("test data"), 10);
        api.read_file(pfd[0], static_cast<void*>(buffer), 64);

        std::cout << buffer << std::endl;

        api.close_file(pfd[0]);
        api.close_file(pfd[1]);
    } else {
        std::cerr << "required API is not available" << std::endl;
    }

    return 0;
}
