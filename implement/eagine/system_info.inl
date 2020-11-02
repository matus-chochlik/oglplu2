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
#include <eagine/types.hpp>
#include <array>
#include <unistd.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
#if EAGINE_LINUX
static inline auto system_info_linux_sysinfo() noexcept -> struct ::sysinfo& {
    using si_t = struct sysinfo;
    static timeout refresh{std::chrono::milliseconds(10), nothing};
    static si_t _si{};
    if(refresh) {
        ::sysinfo(&_si);
        refresh.reset();
    }
    return _si;
}

static inline auto system_info_linux_load_avg(std::size_t which) noexcept
  -> float {
    return static_cast<float>(system_info_linux_sysinfo().loads[which]) /
           static_cast<float>(
             (1U << static_cast<unsigned>(SI_LOAD_SHIFT)) *
             (std::thread::hardware_concurrency()));
}
//------------------------------------------------------------------------------
class system_info_impl {
public:
    auto cpu_temperature() const noexcept
      -> valid_if_positive<kelvins_t<float>> {
        // TODO read from sysfs
        return {kelvins_(0.F)};
    }

    auto gpu_temperature() const noexcept
      -> valid_if_positive<kelvins_t<float>> {
        // TODO read from sysfs
        return {kelvins_(0.F)};
    }

private:
};
//------------------------------------------------------------------------------
#else
#endif
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::_impl() noexcept -> system_info_impl* {
#if EAGINE_LINUX
    if(EAGINE_UNLIKELY(!_pimpl)) {
        try {
            _pimpl = std::make_shared<system_info_impl>();
        } catch(...) {
        }
    }
    return _pimpl.get();
#endif
    return nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::hostname() const -> valid_if_not_empty<std::string> {
#if EAGINE_POSIX
    std::array<char, 1024> hname{};
    if(::gethostname(hname.data(), std_size(hname.size())) == 0) {
        return {std::string(hname.data())};
    }
#endif
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::memory_page_size() const noexcept
  -> valid_if_positive<span_size_t> {
#if EAGINE_POSIX
#if defined(_SC_PAGESIZE)
    return {span_size(::sysconf(_SC_PAGESIZE))};
#endif
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::current_processes() const noexcept
  -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    return {span_size(system_info_linux_sysinfo().procs)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::short_average_load() const noexcept
  -> valid_if_nonnegative<float> {
#if EAGINE_LINUX
    return {system_info_linux_load_avg(0)};
#endif
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::long_average_load() const noexcept
  -> valid_if_nonnegative<float> {
#if EAGINE_LINUX
    return {system_info_linux_load_avg(1)};
#endif
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::uptime() const noexcept -> std::chrono::duration<float> {
    using r_t = std::chrono::duration<float>;
#if EAGINE_LINUX
    return r_t{system_info_linux_sysinfo().uptime};
#endif
    return r_t{0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::free_ram_size() const noexcept
  -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.freeram * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::total_ram_size() const noexcept
  -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.totalram * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::free_swap_size() const noexcept
  -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.freeswap * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::total_swap_size() const noexcept
  -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.totalswap * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::cpu_temperature() noexcept
  -> valid_if_positive<kelvins_t<float>> {
#if EAGINE_LINUX
    if(const auto impl{_impl()}) {
        return extract(impl).cpu_temperature();
    }
#endif
    return {kelvins_(0.F)};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::gpu_temperature() noexcept
  -> valid_if_positive<kelvins_t<float>> {
#if EAGINE_LINUX
    if(const auto impl{_impl()}) {
        return extract(impl).gpu_temperature();
    }
#endif
    return {kelvins_(0.F)};
}
//------------------------------------------------------------------------------
} // namespace eagine
