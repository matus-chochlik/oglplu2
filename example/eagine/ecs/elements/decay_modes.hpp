/**
 *  @example eagine/ecs/elements/decay_modes.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_EXAMPLE_ECS_DECAY_MODES_HPP // NOLINT(llvm-header-guard)
#define EAGINE_EXAMPLE_ECS_DECAY_MODES_HPP

#include "entity.hpp"
#include <eagine/flat_map.hpp>
#include <eagine/identifier.hpp>
#include <tuple>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
enum class decay_mode {
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
template <decay_mode... M>
using decay_mode_t = std::integer_sequence<decay_mode, M...>;
//------------------------------------------------------------------------------
template <decay_mode... M>
constexpr inline auto is_fission_v =
  std::disjunction_v<(M == decay_mode::fission)...>;
//------------------------------------------------------------------------------
template <typename T>
struct decay_mode_traits;
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_mode::alpha>> {
    static constexpr auto symbol() noexcept -> string_view {
        return {"α"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -2;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -2;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_mode::beta_p>> {
    static constexpr auto symbol() noexcept -> string_view {
        return {"β⁺"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 1;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_mode::beta_m>> {
    static constexpr auto symbol() noexcept -> string_view {
        return {"β⁻"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -1;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_mode::proton_emi>> {
    static constexpr auto symbol() noexcept -> string_view {
        return {"p⁺"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 0;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_mode::neutron_emi>> {
    static constexpr auto symbol() noexcept -> string_view {
        return {"n⁰"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 0;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -1;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_mode::electron_cap>> {
    static constexpr auto symbol() noexcept -> string_view {
        return {"+e⁻"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 1;
    }
};
//------------------------------------------------------------------------------
template <>
struct decay_mode_traits<decay_mode_t<decay_mode::fission>> {
    static constexpr auto symbol() noexcept -> string_view {
        return {"≺"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 0;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 0;
    }
};
//------------------------------------------------------------------------------
template <decay_mode... P>
struct decay_mode_traits<decay_mode_t<P...>> {
private:
    template <decay_mode H>
    static void _append_symbol(decay_mode_t<H>, std::string& s) {
        s.append(to_string(decay_mode_traits<decay_mode_t<H>>::symbol()));
    }

    template <decay_mode H, decay_mode N, decay_mode... T>
    static void _append_symbol(decay_mode_t<H, N, T...>, std::string& s) {
        s.append(",");
        s.append(to_string(decay_mode_traits<decay_mode_t<H>>::symbol()));
        _append_symbol(decay_mode_t<N, T...>{}, s);
    }

    static auto _make_symbol() noexcept {
        std::string s;
        _append_symbol(decay_mode_t<P...>{}, s);
        return s;
    }

public:
    static auto symbol() noexcept -> string_view {
        const static auto s{_make_symbol()};
        return {s};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return (
          0 + ... + decay_mode_traits<decay_mode_t<P>>::proton_count_diff());
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return (
          0 + ... + decay_mode_traits<decay_mode_t<P>>::neutron_count_diff());
    }
};
//------------------------------------------------------------------------------
template <typename DecayMode>
struct decay_mode_id;

template <>
struct decay_mode_id<decay_mode_t<decay_mode::alpha>>
  : selector<EAGINE_ID_V(AlphaDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::proton_emi>>
  : selector<EAGINE_ID_V(PrtnEmissn)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::neutron_emi>>
  : selector<EAGINE_ID_V(NtrnEmissn)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::electron_cap>>
  : selector<EAGINE_ID_V(ElnCapDcy)> {};

template <>
struct decay_mode_id<
  decay_mode_t<decay_mode::electron_cap, decay_mode::electron_cap>>
  : selector<EAGINE_ID_V(2ElnCapDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::beta_m>>
  : selector<EAGINE_ID_V(BetaMDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::beta_m, decay_mode::beta_m>>
  : selector<EAGINE_ID_V(BetaM2Dcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::beta_m, decay_mode::alpha>>
  : selector<EAGINE_ID_V(BtaMAlpDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::beta_m, decay_mode::neutron_emi>>
  : selector<EAGINE_ID_V(BetaMNDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<
  decay_mode::beta_m,
  decay_mode::neutron_emi,
  decay_mode::neutron_emi>> : selector<EAGINE_ID_V(BetaMN2Dcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::beta_p>>
  : selector<EAGINE_ID_V(BetaPDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::beta_p, decay_mode::beta_p>>
  : selector<EAGINE_ID_V(BetaP2Dcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::beta_p, decay_mode::alpha>>
  : selector<EAGINE_ID_V(BtaPAlpDcy)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::fission>>
  : selector<EAGINE_ID_V(Fission)> {};

template <>
struct decay_mode_id<decay_mode_t<decay_mode::transition>>
  : selector<EAGINE_ID_V(Transition)> {};
//------------------------------------------------------------------------------
using known_decay_modes = std::tuple<
  decay_mode_t<decay_mode::alpha>,
  decay_mode_t<decay_mode::proton_emi>,
  decay_mode_t<decay_mode::neutron_emi>,
  decay_mode_t<decay_mode::electron_cap>,
  decay_mode_t<decay_mode::electron_cap, decay_mode::electron_cap>,
  decay_mode_t<decay_mode::beta_m>,
  decay_mode_t<decay_mode::beta_m, decay_mode::beta_m>,
  decay_mode_t<decay_mode::beta_m, decay_mode::alpha>,
  decay_mode_t<decay_mode::beta_m, decay_mode::neutron_emi>,
  decay_mode_t<decay_mode::beta_m, decay_mode::neutron_emi, decay_mode::neutron_emi>,
  decay_mode_t<decay_mode::beta_p>,
  decay_mode_t<decay_mode::beta_p, decay_mode::beta_p>,
  decay_mode_t<decay_mode::beta_p, decay_mode::alpha>,
  decay_mode_t<decay_mode::fission>,
  decay_mode_t<decay_mode::transition>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif
