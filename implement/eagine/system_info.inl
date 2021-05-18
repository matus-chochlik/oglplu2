/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/main_ctx.hpp>
#include <eagine/timeout.hpp>
#include <vector>

#if EAGINE_LINUX
#include <eagine/file_contents.hpp>
#include <eagine/from_string.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/value_tree/filesystem.hpp>
#include <eagine/value_tree/wrappers.hpp>
#include <limits>
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
    system_info_impl(main_ctx_parent parent)
      : _sysfs{valtree::from_filesystem_path("/sys/devices", parent)} {
        auto sysfs_scanner = [this](
                               valtree::compound& c,
                               const valtree::attribute& a,
                               const basic_string_path& p) {
            if(!c.is_link(a)) {
                bool is_tz{false};
                bool is_cd{false};
                bool is_ps{false};
                for(auto& entry : p) {
                    if(starts_with(entry, string_view("thermal_zone"))) {
                        is_tz = true;
                        break;
                    }
                    if(starts_with(entry, string_view("cooling_device"))) {
                        is_cd = true;
                        break;
                    }
                    if(starts_with(entry, string_view("power_supply"))) {
                        is_ps = true;
                        break;
                    }
                }
                if(is_tz) {
                    if(auto temp_a{c.nested(a, "temp")}) {
                        if(auto type_a{c.nested(a, "type")}) {
                            if(!_cpu_temp_i) {
                                if(c.has_value(type_a, "cpu-thermal")) {
                                    _cpu_temp_i = tz_count();
                                } else if(c.has_value(type_a, "acpitz")) {
                                    _cpu_temp_i = tz_count();
                                }
                            }
                            _tz_temp_a.emplace_back(temp_a);
                        }
                    }
                }
                if(is_cd) {
                    if(auto cur_a{c.nested(a, "cur_state")}) {
                        if(auto max_a{c.nested(a, "max_state")}) {
                            _cd_cm_a.emplace_back(cur_a, max_a);
                        }
                    }
                }
                if(is_ps) {
                    if(auto type_a{c.nested(a, "type")}) {
                        if(c.has_value(type_a, "Battery")) {
                            if(auto cap_a{c.nested(a, "capacity")}) {
                                _bat_cap_a.emplace_back(cap_a);
                            }
                        } else if(c.has_value(type_a, "Mains")) {
                            if(auto onl_a{c.nested(a, "online")}) {
                                _ac_online_a.emplace_back(onl_a);
                            }
                        }
                    }
                }
                return true;
            }
            return false;
        };
        _sysfs.traverse(
          valtree::compound::visit_handler{construct_from, sysfs_scanner});

        if(file_contents machine_id{"/etc/machine-id"}) {
            memory::for_each_chunk(
              as_chars(machine_id.block()),
              span_size_of<host_id_t>() * 2,
              [this](auto hexstr) {
                  if(const auto mi{from_string(
                       hexstr,
                       type_identity<host_id_t>(),
                       default_selector,
                       16)}) {
                      _host_id ^= extract(mi);
                  }
              });
        }
    }

    auto host_id() noexcept {
        return _host_id;
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

    auto tz_min_max() noexcept -> std::tuple<
      valid_if_positive<kelvins_t<float>>,
      valid_if_positive<kelvins_t<float>>> {
        auto min{std::numeric_limits<float>::max()};
        auto max{std::numeric_limits<float>::min()};
        for(auto& temp_a : _tz_temp_a) {
            float millicelsius{0.F};
            if(_sysfs.fetch_value(temp_a, millicelsius)) {
                min = std::min(min, millicelsius);
                max = std::max(max, millicelsius);
            }
        }
        if(min <= max) {
            return {
              kelvins_(min * 0.001F + 273.15F),
              kelvins_(max * 0.001F + 273.15F)};
        }
        return {{kelvins_(0.F)}, {kelvins_(0.F)}};
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

    auto cd_count() noexcept -> span_size_t {
        return span_size(_cd_cm_a.size());
    }

    auto cd_state(span_size_t index) noexcept -> valid_if_between_0_1<float> {
        EAGINE_ASSERT((index >= 0) && (index < cd_count()));
        auto& [cur_a, max_a] = _cd_cm_a[index];
        if(cur_a && max_a) {
            float cur_s{-1.F};
            float max_s{-1.F};
            if(
              _sysfs.fetch_value(cur_a, cur_s) &&
              _sysfs.fetch_value(max_a, max_s)) {
                if(max_s > 0.F) {
                    return {cur_s / max_s};
                }
            }
        }
        return {-1.F};
    }

    auto bat_count() noexcept -> span_size_t {
        return span_size(_bat_cap_a.size());
    }

    auto bat_capacity(span_size_t index) noexcept
      -> valid_if_between_0_1<float> {
        EAGINE_ASSERT((index >= 0) && (index < bat_count()));
        auto& cap_a = _bat_cap_a[index];
        if(cap_a) {
            float capacity{-1.F};
            if(_sysfs.fetch_value(cap_a, capacity)) {
                return {capacity * 0.01F};
            }
        }
        return {-1.F};
    }

    auto acps_count() noexcept -> span_size_t {
        return span_size(_ac_online_a.size());
    }

    auto acps_online(span_size_t index) noexcept -> tribool {
        EAGINE_ASSERT((index >= 0) && (index < acps_count()));
        auto& onl_a = _ac_online_a[index];
        if(onl_a) {
            int online{0};
            if(_sysfs.fetch_value(onl_a, online)) {
                return {online != 0};
            }
        }
        return indeterminate;
    }

private:
    host_id_t _host_id{0};
    valtree::compound _sysfs;
    std::vector<valtree::attribute> _tz_temp_a;
    valid_if_nonnegative<span_size_t> _cpu_temp_i{-1};
    valid_if_nonnegative<span_size_t> _gpu_temp_i{-1};

    std::vector<std::tuple<valtree::attribute, valtree::attribute>> _cd_cm_a;

    std::vector<valtree::attribute> _bat_cap_a;
    std::vector<valtree::attribute> _ac_online_a;
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
            _pimpl = std::make_shared<system_info_impl>(*this);
        } catch(...) {
        }
    }
    return _pimpl.get();
#endif
    return nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::preinitialize() noexcept -> system_info& {
    _impl();
    return *this;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::host_id() noexcept -> valid_if_positive<host_id_type> {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return {extract(impl).host_id()};
    }
#endif
#if EAGINE_POSIX
    return {static_cast<host_id_type>(::gethostid())};
#endif
    return {};
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
auto system_info::free_swap_size() noexcept
  -> valid_if_nonnegative<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.freeswap * si.mem_unit)};
#endif
    return {-1};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::total_swap_size() noexcept
  -> valid_if_nonnegative<span_size_t> {
#if EAGINE_LINUX
    const auto& si = system_info_linux_sysinfo();
    return {span_size(si.totalswap * si.mem_unit)};
#endif
    return {-1};
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
auto system_info::temperature_min_max() noexcept -> std::tuple<
  valid_if_positive<kelvins_t<float>>,
  valid_if_positive<kelvins_t<float>>> {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).tz_min_max();
    }
#endif
    return {{kelvins_(0.F)}, {kelvins_(0.F)}};
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
EAGINE_LIB_FUNC
auto system_info::cooling_device_count() noexcept -> span_size_t {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).cd_count();
    }
#endif
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::cooling_device_state(span_size_t index) noexcept
  -> valid_if_between_0_1<float> {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).cd_state(index);
    }
#endif
    EAGINE_MAYBE_UNUSED(index);
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::battery_count() noexcept -> span_size_t {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).bat_count();
    }
#endif
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::battery_capacity(span_size_t index) noexcept
  -> valid_if_between_0_1<float> {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).bat_capacity(index);
    }
#endif
    EAGINE_MAYBE_UNUSED(index);
    return {-1.F};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::ac_supply_count() noexcept -> span_size_t {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).acps_count();
    }
#endif
    return 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto system_info::ac_supply_online(span_size_t index) noexcept -> tribool {
#if EAGINE_LINUX
    if(auto impl{_impl()}) {
        return extract(impl).acps_online(index);
    }
#endif
    EAGINE_MAYBE_UNUSED(index);
    return indeterminate;
}
//------------------------------------------------------------------------------
} // namespace eagine
