/**
 *  @file eagine/compiler_info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_name() noexcept -> valid_if_not_empty<string_view> {
#if defined(__clang__)
    return {{"Clang"}};
#elif defined(__INTEL_COMPILER)
    return {{"Intel C/C++"}};
#elif defined(__DMC__)
    return {{"Digital Mars"}};
#elif defined(__EDG__)
    return {{"EDG C++ frontend"}};
#elif defined(__CWCC__)
    return {{"Metrowerks CodeWarrior"}};
#elif defined(_MSC_VER)
    return {{"Microsoft Visual C++"}};
#elif defined(__COMO__)
    return {{"Comeau C++"}};
#elif defined(__FCC_VERSION)
    return {{"Fujitsu C++"}};
#elif defined(__MINGW64__)
    return {{"MinGW 64bit"}};
#elif defined(__MINGW32__)
    return {{"MinGW 32bit"}};
#elif defined(_ACC_)
    return {{"ACC"}};
#elif defined(__CC_ARM)
    return {{"ARM Compiler"}};
#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
    return {{"Borland C++"}};
#elif defined(__DECCXX)
    return {{"Compaq C++"}};
#elif defined(__DJGPP__)
    return {{"DJGPP"}};
#elif defined(__IBMCPP__)
    return {{"IBM z/OS XL C++"}};
#elif defined(__IBMCPP__)
    return {{"IBM z/OS XL C++"}};
#elif defined(__WATCOMC__)
    return {{"Watcom C++"}};
#elif defined(__ZTC__)
    return {{"Zortech C++"}};
#elif defined(__GNUC__)
    return {{"GCC"}};
#endif
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_version_major() noexcept -> valid_if_nonnegative<int> {
#if defined(__clang_major__)
    return {__clang_major__};
#elif defined(__INTEL_COMPILER)
    return {(__INTEL_COMPILER % 1000) / 100};
#elif defined(__DMC__)
    return {(__DMC__ >> 8U) & 0xFU};
#elif defined(__EDG_VERSION__)
    return {(__EDG_VERSION__ % 1000) / 100};
#elif defined(__CWCC__)
    return {(__CWCC__ % 10000) / 1000};
#elif defined(_MSC_VER)
    return {(_MSC_VER % 10000) / 100};
#elif defined(__COMO_VERSION__)
    return {(__COMO_VERSION__ % 1000) / 100};
#elif defined(__MINGW64_VERSION_MAJOR)
    return {__MINGW64_VERSION_MAJOR};
#elif defined(__MINGW32_VERSION_MAJOR)
    return {__MINGW32_VERSION_MAJOR};
#elif defined(__GNUC__)
    return {__GNUC__};
#endif
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_version_minor() noexcept -> valid_if_nonnegative<int> {
#if defined(__clang_minor__)
    return {__clang_minor__};
#elif defined(__INTEL_COMPILER)
    return {(__INTEL_COMPILER % 100) / 10};
#elif defined(__DMC__)
    return {(__DMC__ >> 4U) & 0xFU};
#elif defined(__EDG_VERSION__)
    return {(__EDG_VERSION__ % 100) / 1};
#elif defined(__CWCC__)
    return {(__CWCC__ % 1000) / 100};
#elif defined(_MSC_VER)
    return {(_MSC_VER % 100) / 1};
#elif defined(__COMO_VERSION__)
    return {(__COMO_VERSION__ % 100) / 10};
#elif defined(__MINGW64_VERSION_MINOR)
    return {__MINGW64_VERSION_MINOR};
#elif defined(__MINGW32_VERSION_MINOR)
    return {__MINGW32_VERSION_MINOR};
#elif defined(__GNUC_MINOR__)
    return {__GNUC_MINOR__};
#endif
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto compiler_version_patch() noexcept -> valid_if_nonnegative<int> {
#if defined(__clang_patchlevel__)
    return {__clang_patchlevel__};
#elif defined(__INTEL_COMPILER)
    return {(__INTEL_COMPILER % 10) / 1};
#elif defined(__DMC__)
    return {(__DMC__ >> 0U) & 0xFU};
#elif defined(__CWCC__)
    return {(__CWCC__ % 100) / 1};
#elif defined(__GNUC_PATCHLEVEL__)
    return {__GNUC_PATCHLEVEL__};
#endif
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto architecture_name() noexcept -> valid_if_not_empty<string_view> {
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_AMD64) || \
  defined(_M_X64)
    return {"AMD64/x86-64"};
#elif defined(__i386__) || defined(__i386) || defined(__i486__) || \
  defined(__i586__) || defined(__i686__) || defined(__X86__) || defined(_X86_)
    return {"Intel x86"};
#elif defined(__ia64__) || defined(__ia64) || defined(_M_IA64) || \
  defined(__itanium__)
    return {"Intel IA-64"};
#elif defined(__aarch64__)
    return {"ARM64"};
#elif defined(__arm__) || defined(__thumb__) || defined(_M_ARM) || \
  defined(_M_ARMT)
    return {"ARM"};
#elif defined(__powerpc64__) || defined(__powerpc__) || defined(__powerpc) || \
  defined(_M_PPC) || defined(_ARCH_PPC)
    return {"PowerPC"};
#elif defined(__sparc__) || defined(__sparc)
    return {"SPARC"};
#elif defined(__mips__) || defined(__mips) || defined(__MIPS__)
    return {"MIPS"};
#elif defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
    return {"Alpha"};
#endif
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine
