/**
 *  @file eagine/system_info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/timeout.hpp>
#include <vector>

#if EAGINE_LINUX
#include <eagine/value_tree/filesystem.hpp>
#include <eagine/value_tree/wrappers.hpp>
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
    system_info_impl(logger& parent)
      : _sysfs{valtree::from_filesystem_path("/sys/devices", parent)} {
        auto sysfs_scanner = [this](
                               valtree::compound& c,
                               const valtree::attribute& a,
                               const basic_string_path&) {
            if(!c.is_link(a)) {
                if(auto temp_a{c.nested(a, "temp")}) {
                    if(auto type_a{c.nested(a, "type")}) {
                        if(!_cpu_temp_i) {
                            if(c.has_value(type_a, "cpu-thermal")) {
                                _cpu_temp_i = tz_count();
                            } else if(c.has_value(type_a, "acpitz")) {
                                _cpu_temp_i = tz_count();
                            }
                        }
                        _tz_temp_a.push_back(temp_a);
                    }
                }
                return true;
            }
            return false;
        };
        _sysfs.traverse(valtree::compound::visit_handler(sysfs_scanner));
    }

    auto tz_count() noexcept -> span_size_t {
        return span_size(_tz_temp_a.size());
    }

    auto tz_temperature(span_size_t index) noexcept
      -> valid_if_positive<kelvins_t<float>> {
        EAGINE_ASSERT((index >= 0) && (index < tz_count()));
        auto& temp_a = _tz_temp_a[std_size(index)];
        if(temp_a) {
            float millicelsius{0.F};
            if(_sysfs.fetch_value(temp_a, millicelsius)) {
                return kelvins_(millicelsius * 0.001F + 273.15F);
            }
        }
        return {kelvins_(0.F)};
    }

    auto cpu_temperature() noexcept -> valid_if_positive<kelvins_t<float>> {
        if(_cpu_temp_i) {
            return tz_temperature(extract(_cpu_temp_i));
        }
        return {kelvins_(0.F)};
    }

    auto gpu_temperature() noexcept -> valid_if_positive<kelvins_t<float>> {
        if(_gpu_temp_i) {
            return tz_temperature(extract(_gpu_temp_i));
        }
        return {kelvins_(0.F)};
    }

private:
    valtree::compound _sysfs;
    std::vector<valtree::attribute> _tz_temp_a;
    valid_if_nonnegative<span_size_t> _cpu_temp_i{-1};
    valid_if_nonnegative<span_size_t> _gpu_temp_i{-1};
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
            _pimpl = std::make_shared<system_info_impl>(_log);
        } catch(...) {
        }
    }
    return _pimpl.get();
#endif
    return nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::hostname() noexcept -> valid_if_not_empty<std::string> {
#if EAGINE_POSIX
    try {
        std::array<char, 1024> hname{};
        if(::gethostname(hname.data(), std_size(hname.size())) == 0) {
            return {std::string(hname.data())};
        }
    } catch(...) {
    }
#endif
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::memory_page_size() noexcept
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
auto system_info::current_processes() noexcept
  -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    return {span_size(system_info_linux_sysinfo().procs)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::short_average_load() noexcept -> valid_if_nonnegative<float> {
#if EAGINE_LINUX
    return {system_info_linux_load_avg(0)};
#endif
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::long_average_load() noexcept -> valid_if_nonnegative<float> {
#if EAGINE_LINUX
    return {system_info_linux_load_avg(1)};
#endif
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::uptime() noexcept -> std::chrono::duration<float> {
    using r_t = std::chrono::duration<float>;
#if EAGINE_LINUX
    return r_t{system_info_linux_sysinfo().uptime};
#endif
    return r_t{0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::free_ram_size() noexcept -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.freeram * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::total_ram_size() noexcept -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.totalram * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::free_swap_size() noexcept -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.freeswap * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::total_swap_size() noexcept -> valid_if_positive<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.totalswap * si.mem_unit)};
#endif
    return {0};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::thermal_sensor_count() noexcept -> span_size_t {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).tz_count();
    }
#endif
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::sensor_temperature(span_size_t index) noexcept
  -> valid_if_positive<kelvins_t<float>> {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).tz_temperature(index);
    }
#endif
    EAGINE_MAYBE_UNUSED(index);
    return {kelvins_(0.F)};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::cpu_temperature() noexcept
  -> valid_if_positive<kelvins_t<float>> {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
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
    if(auto impl{_impl()}) {
        return extract(impl).gpu_temperature();
    }
#endif
    return {kelvins_(0.F)};
}
//------------------------------------------------------------------------------
} // namespace eagine
