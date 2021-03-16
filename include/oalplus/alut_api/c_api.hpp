/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALUT_API_C_API_HPP
#define OALPLUS_ALUT_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef OALPLUS_ALUT_STATIC_FUNC
#if OALPLUS_HAS_AL
#define OALPLUS_ALUT_STATIC_FUNC(NAME) &EAGINE_JOIN(::alut, NAME)
#else
#define OALPLUS_ALUT_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine::oalp {
//------------------------------------------------------------------------------
/// @brief Class wrapping the C-functions from the ALUT API.
/// @ingroup al_api_wrap
/// @see basic_alut_constants
/// @see basic_alut_operations
template <typename ApiTraits>
class basic_alut_c_api {
public:
    using this_api = basic_alut_c_api;

    /// @brief Alias for the API traits policy type passed as template argument.
    using api_traits = ApiTraits;

    static constexpr bool has_api = alut_types::has_api;

    /// @brief Alias for enumeration type.
    using enum_type = typename alut_types::enum_type;

    /// @brief Alias for string character type.
    using char_type = typename alut_types::char_type;

    /// @brief Alias for boolean type.
    using bool_type = typename alut_types::bool_type;

    /// @brief Alias for signed integer type.
    using int_type = typename alut_types::int_type;

    /// @brief Alias for unsigned integer type.
    using uint_type = typename alut_types::uint_type;

    /// @brief Alias for object handle type.
    using name_type = typename alut_types::name_type;

    /// @brief Alias for integer type used to store sizes and counts.
    using size_type = typename alut_types::size_type;

    /// @brief Alias for floating-point type.
    using float_type = typename alut_types::float_type;

    /// @brief Untyped non-const pointer type.
    using void_ptr_type = typename alut_types::void_ptr_type;

    /// @brief Untyped const pointer type.
    using const_void_ptr_type = typename alut_types::const_void_ptr_type;

#ifdef __GNUC__
    EAGINE_DIAG_PUSH()
    EAGINE_DIAG_OFF(address)
#endif

    /// @brief Alias for ALUT C-API function wrapper template.
    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using alut_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      has_api,
      bool(Function)>;
#ifdef __GNUC__
    EAGINE_DIAG_POP()
#endif

    /// @var GetError
    /// @alutfuncwrap{GetError}
    alut_api_function<enum_type(), OALPLUS_ALUT_STATIC_FUNC(GetError)> GetError;

    /// @var GetErrorString
    /// @alutfuncwrap{GetErrorString}
    alut_api_function<
      const char_type*(enum_type),
      OALPLUS_ALUT_STATIC_FUNC(GetErrorString)>
      GetErrorString;

    /// @var Init
    /// @alutfuncwrap{Init}
    alut_api_function<bool_type(int*, char**), OALPLUS_ALUT_STATIC_FUNC(Init)>
      Init;

    /// @var InitWithoutContext
    /// @alutfuncwrap{InitWithoutContext}
    alut_api_function<bool_type(int*, char**), OALPLUS_ALUT_STATIC_FUNC(Init)>
      InitWithoutContext;

    /// @var CreateBufferFromFile
    /// @alutfuncwrap{CreateBufferFromFile}
    alut_api_function<
      name_type(const char*),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferFromFile)>
      CreateBufferFromFile;

    /// @var CreateBufferFromFileImage
    /// @alutfuncwrap{GetErroteBufferFromFileImager}
    alut_api_function<
      name_type(const_void_ptr_type, size_type),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferFromFileImage)>
      CreateBufferFromFileImage;

    /// @var CreateBufferHelloWorld
    /// @alutfuncwrap{CreateBufferHelloWorld}
    alut_api_function<
      name_type(),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferHelloWorld)>
      CreateBufferHelloWorld;

    /// @var CreateBufferWaveform
    /// @alutfuncwrap{CreateBufferWaveform}
    alut_api_function<
      name_type(enum_type, float_type, float_type, float_type),
      OALPLUS_ALUT_STATIC_FUNC(CreateBufferWaveform)>
      CreateBufferWaveform;

    /// @var Exit
    /// @alutfuncwrap{Exit}
    alut_api_function<bool_type(), OALPLUS_ALUT_STATIC_FUNC(Exit)> Exit;

    basic_alut_c_api(api_traits& traits);
};
//------------------------------------------------------------------------------
/// @brief Alias for the default ALUT operations wrapper instantiation.
/// @ingroup al_api_wrap
using alut_c_api = basic_alut_c_api<alut_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_ALUT_API_C_API_HPP
