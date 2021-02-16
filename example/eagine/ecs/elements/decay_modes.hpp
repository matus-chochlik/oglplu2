/// @example eagine/ecs/elements/decay_modes.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_EXAMPLE_ECS_DECAY_MODES_HPP // NOLINT(llvm-header-guard)
#define EAGINE_EXAMPLE_ECS_DECAY_MODES_HPP

#include "entity.hpp"
#include <eagine/flat_map.hpp>
#include <eagine/identifier.hpp>
#include <eagine/mp_list.hpp>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
enum class decay_part {
    alpha,
    beta_p,
    beta_m,
    proton_emi,
    neutron_emi,
    electron_cap,
    fission,
    transition
};
//------------------------------------------------------------------------------
template <decay_part... M>
using decay_mode_t = std::integer_sequence<decay_part, M...>;
//------------------------------------------------------------------------------
template <decay_part... M>
constexpr auto is_fission_v = (false || ... || (M == decay_part::fission));
//------------------------------------------------------------------------------
struct decay_mode_info {
    std::string symbol;
    int proton_count_diff{0};
    int neutron_count_diff{0};
    bool is_fission{false};
};
//------------------------------------------------------------------------------
template <typename T>
struct decay_mode_traits;
//------------------------------------------------------------------------------
template <decay_part... M>
static inline auto mode_info(decay_mode_t<M...> = {})
  -> const decay_mode_info& {
    return decay_mode_traits<decay_mode_t<M...>>::info();
}
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::alpha>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"α", -2, -2, false};
        return i;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::beta_p>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"β⁺", -1, 1, false};
        return i;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::beta_m>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"β⁻", 1, -1, false};
        return i;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::proton_emi>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"p⁺", -1, 0, false};
        return i;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::neutron_emi>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"n⁰", 0, -1, false};
        return i;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::electron_cap>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"+e⁻", -1, 1, false};
        return i;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::fission>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"≺", 0, 0, true};
        return i;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_part::transition>> {
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{"IT", 0, 0, false};
        return i;
    }
};
//------------------------------------------------------------------------------
template <decay_part... P>
struct decay_mode_traits<decay_mode_t<P...>> {
private:
    template <decay_part H>
    static void _append_symbol(decay_mode_t<H> m, std::string& s) {
        s.append(mode_info(m).symbol);
    }

    template <decay_part H, decay_part N, decay_part... T>
    static void _append_symbol(decay_mode_t<H, N, T...>, std::string& s) {
        s.append(mode_info(decay_mode_t<H>{}).symbol);
        s.append(",");
        _append_symbol(decay_mode_t<N, T...>{}, s);
    }

    static auto _make_symbol() noexcept {
        std::string s;
        _append_symbol(decay_mode_t<P...>{}, s);
        return s;
    }

public:
    static auto info() noexcept -> const auto& {
        static const decay_mode_info i{
          _make_symbol(),
          (0 + ... + mode_info(decay_mode_t<P>{}).proton_count_diff),
          (0 + ... + mode_info(decay_mode_t<P>{}).neutron_count_diff),
          is_fission_v<P...>};
        return i;
    }
};
//------------------------------------------------------------------------------
template <typename DecayMode>
struct decay_mode_id;

template <>
struct decay_mode_id<decay_mode_t<decay_part::alpha>>
  : selector<EAGINE_ID_V(AlphaDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::proton_emi>>
  : selector<EAGINE_ID_V(PrtnEmissn)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::neutron_emi>>
  : selector<EAGINE_ID_V(NtrnEmissn)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::electron_cap>>
  : selector<EAGINE_ID_V(ElnCapDcy)> {};

template <>
struct decay_mode_id<
  decay_mode_t<decay_part::electron_cap, decay_part::electron_cap>>
  : selector<EAGINE_ID_V(2ElnCapDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::electron_cap, decay_part::fission>>
  : selector<EAGINE_ID_V(ElnCapFisn)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::beta_m>>
  : selector<EAGINE_ID_V(BetaMDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::beta_m, decay_part::beta_m>>
  : selector<EAGINE_ID_V(BetaM2Dcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::beta_m, decay_part::alpha>>
  : selector<EAGINE_ID_V(BtaMAlpDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::beta_m, decay_part::neutron_emi>>
  : selector<EAGINE_ID_V(BetaMNDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<
  decay_part::beta_m,
  decay_part::neutron_emi,
  decay_part::neutron_emi>> : selector<EAGINE_ID_V(BetaMN2Dcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::beta_p>>
  : selector<EAGINE_ID_V(BetaPDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::beta_p, decay_part::beta_p>>
  : selector<EAGINE_ID_V(BetaP2Dcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::beta_p, decay_part::alpha>>
  : selector<EAGINE_ID_V(BtaPAlpDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::fission>>
  : selector<EAGINE_ID_V(Fission)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_part::transition>>
  : selector<EAGINE_ID_V(Transition)> {};
//------------------------------------------------------------------------------
struct known_decay_modes {
    using m = decay_part;
    using list = mp_list<
      decay_mode_t<m::alpha>,
      decay_mode_t<m::proton_emi>,
      decay_mode_t<m::neutron_emi>,
      decay_mode_t<m::electron_cap>,
      decay_mode_t<m::electron_cap, m::electron_cap>,
      decay_mode_t<m::electron_cap, m::fission>,
      decay_mode_t<m::beta_m>,
      decay_mode_t<m::beta_m, m::beta_m>,
      decay_mode_t<m::beta_m, m::alpha>,
      decay_mode_t<m::beta_m, m::neutron_emi>,
      decay_mode_t<m::beta_m, m::neutron_emi, m::neutron_emi>,
      decay_mode_t<m::beta_p>,
      decay_mode_t<m::beta_p, m::beta_p>,
      decay_mode_t<m::beta_p, m::alpha>,
      decay_mode_t<m::fission>,
      decay_mode_t<m::transition>>;

    template <decay_part... M>
    static auto get_id(decay_mode_t<M...> = {}) noexcept {
        return decay_mode_id<decay_mode_t<M...>>::value;
    }

    static auto get_id(string_view symbol) -> identifier_t {
        return _get_id(symbol, list{});
    }

    static auto get_info(identifier_t mode_id) -> const decay_mode_info* {
        return _get_info(mode_id, list{});
    }

    static auto proton_count_diff(identifier_t mode_id) noexcept -> int {
        if(auto i{get_info(mode_id)}) {
            return extract(i).proton_count_diff;
        }
        return 0;
    }

    static auto neutron_count_diff(identifier_t mode_id) noexcept -> int {
        if(auto i{get_info(mode_id)}) {
            return extract(i).neutron_count_diff;
        }
        return 0;
    }

private:
    static auto _get_info(identifier_t, mp_list<>) noexcept
      -> const decay_mode_info* {
        return nullptr;
    }

    template <typename H, typename... T>
    static auto _get_info(identifier_t id, mp_list<H, T...>)
      -> const decay_mode_info* {
        if(decay_mode_id<H>::value == id) {
            return &mode_info(H{});
        }
        return _get_info(id, mp_list<T...>{});
    }

    static auto _get_id(string_view, mp_list<>) noexcept -> identifier_t {
        return 0;
    }

    template <typename H, typename... T>
    static auto _get_id(string_view symbol, mp_list<H, T...>) -> identifier_t {
        if(are_equal(string_view(mode_info(H{}).symbol), symbol)) {
            return get_id(H{});
        }
        return _get_id(symbol, mp_list<T...>{});
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
