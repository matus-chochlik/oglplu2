/**
 *  @file eagine/system_info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/timeout.hpp>

#if EAGINE_LINUX
#include <sys/sysinfo.h>
#endif

#if EAGINE_POSIX
#include <unistd.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
#if EAGINE_LINUX
static inline struct ::sysinfo& system_info_linux_sysinfo() noexcept {
    using si_t = struct sysinfo;
    static timeout refresh{std::chrono::milliseconds(10), nothing};
    static si_t _si{};
    if(refresh) {
        ::sysinfo(&_si);
        refresh.reset();
    }
    return _si;
}

static inline float system_info_linux_load_avg(std::size_t which) noexcept {
    return static_cast<float>(system_info_linux_sysinfo().loads[which]) /
           static_cast<float>(
             (1U << static_cast<unsigned>(SI_LOAD_SHIFT)) *
             (std::thread::hardware_concurrency()));
}
#endif
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_positive<span_size_t> system_info::memory_page_size() const noexcept {
#if EAGINE_POSIX
#if defined(_SC_PAGESIZE)
    return {span_size(::sysconf(_SC_PAGESIZE))};
#endif
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_nonnegative<float> system_info::short_average_load() const noexcept {
#if EAGINE_LINUX
    return system_info_linux_load_avg(0);
#endif
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_nonnegative<float> system_info::long_average_load() const noexcept {
#if EAGINE_LINUX
    return system_info_linux_load_avg(1);
#endif
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::chrono::duration<float> system_info::uptime() const noexcept {
    using r_t = std::chrono::duration<float>;
#if EAGINE_LINUX
    return r_t{system_info_linux_sysinfo().uptime};
#endif
    return r_t{0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_positive<span_size_t> system_info::free_ram_size() const noexcept {
#if EAGINE_LINUX
    return {span_size(system_info_linux_sysinfo().freeram)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
valid_if_positive<span_size_t> system_info::total_ram_size() const noexcept {
#if EAGINE_LINUX
    return {span_size(system_info_linux_sysinfo().totalram)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
} // namespace eagine
