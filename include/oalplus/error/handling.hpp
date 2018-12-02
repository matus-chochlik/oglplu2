/**
 *  @file oalplus/error/handling.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ERROR_HANDLING_1509260923_HPP
#define OALPLUS_ERROR_HANDLING_1509260923_HPP

#include "../utils/deferred_handler.hpp"
#include "error.hpp"

namespace oalplus {

template <typename ErrorInfo>
static inline void handle_al_error(ErrorInfo& info) {
    if(!std::uncaught_exception()) {
        throw error(std::move(info));
    }
}

static inline constexpr bool is_al_error(ALenum ec) noexcept {
    return ec != AL_NO_ERROR;
}

struct al_error_handling_policy {
    static bool is_valid(const error_info& info) noexcept {
        return is_al_error(info.al_error_code());
    }

    static void invoke(error_info& info) {
        handle_al_error(info);
    }

    static void cancel(error_info& info) noexcept {
        info.al_error_code(AL_NO_ERROR);
    }
};

using deferred_error_handler =
  deferred_handler<error_info, al_error_handling_policy>;

} // namespace oalplus

#ifndef OALPLUS_AL_GET_ERROR
#define OALPLUS_AL_GET_ERROR() ::alGetError()
#endif

#define OALPLUS_RETURN_HANDLER_IF(CONDITION, ERROR_CODE, ERROR_INFO, SEVERITY) \
    {                                                                          \
        ALenum oalplus_error_code##__LINE__ = ERROR_CODE;                      \
        if(CONDITION(oalplus_error_code##__LINE__)) {                          \
            return oalplus::deferred_error_handler(                            \
              std::move(oalplus::error_info(oalplus_error_code##__LINE__)      \
                          .ERROR_INFO.source_file(__FILE__)                    \
                          .source_line(__LINE__)));                            \
        }                                                                      \
    }

#define OALPLUS_RETURN_HANDLER_IF_AL_ERROR(ERROR_CODE, ERROR_INFO, SEVERITY) \
    OALPLUS_RETURN_HANDLER_IF(                                               \
      oalplus::is_al_error, ERROR_CODE, ERROR_INFO, SEVERITY)

#define OALPLUS_VERIFY(ALFUNC, ERROR_INFO, SEVERITY) \
    OALPLUS_RETURN_HANDLER_IF_AL_ERROR(              \
      OALPLUS_AL_GET_ERROR(), ERROR_INFO.al_function_name(#ALFUNC), SEVERITY)

#define OALPLUS_VERIFY_SIMPLE(ALFUNC, SEVERITY) \
    OALPLUS_VERIFY(ALFUNC, no_info(), SEVERITY)

#endif // include guard
