/**
 *  @file eagine/from_string.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#if EAGINE_USE_BOOST_SPIRIT
#if __has_include(<boost/spirit/home/x3.hpp>)
#include <eagine/assert.hpp>
#include <eagine/math/constants.hpp>
#include <boost/spirit/home/x3.hpp>
#include <complex>
#include <limits>
#include <memory>
#include <tuple>
#include <utility>
#else
#undef EAGINE_USE_BOOST_SPIRIT
#endif
#endif

#ifndef EAGINE_USE_BOOST_SPIRIT
#define EAGINE_USE_BOOST_SPIRIT 0
#endif

namespace eagine {
#if EAGINE_USE_BOOST_SPIRIT
namespace numexpr {
//------------------------------------------------------------------------------
namespace bs = boost::spirit::x3;
namespace bf = boost::fusion;
using bf::at_c;
using bs::_attr;
using bs::_val;
using parsed_number_t = std::complex<long double>;
//------------------------------------------------------------------------------
struct symbolic_constants : bs::symbols<parsed_number_t> {
    symbolic_constants() noexcept {
        add("pi", parsed_number_t(math::pi))("i", parsed_number_t(0, 1));
    }
};
//------------------------------------------------------------------------------
const symbolic_constants symbolic_constant{};

struct numeric_expression_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<numeric_expression_tag, parsed_number_t> numeric_expression =
  "numeric-expression";

struct function_call_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<function_call_tag, parsed_number_t> function_call =
  "function-call";

struct numeric_literal_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<numeric_literal_tag, parsed_number_t> numeric_literal =
  "numeric-literal";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto numeric_literal_def = bs::double_ | bs::int_;

//------------------------------------------------------------------------------
struct juxtaposition_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<juxtaposition_tag, parsed_number_t> juxtaposition =
  "juxtaposition";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto juxtaposition_def = (numeric_literal >> symbolic_constant)[(
  [](auto& c) { _val(c) = at_c<0>(_attr(c)) * at_c<1>(_attr(c)); })];
//------------------------------------------------------------------------------
struct conversion_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<conversion_tag, parsed_number_t> conversion = "conversion";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto conversion_def =
  (numeric_literal >> "deg")[([](auto& c) {
      _val(c) = ((parsed_number_t(math::pi) * _attr(c)) / parsed_number_t(180));
  })] |
  (numeric_literal >> "turn")[(
    [](auto& c) { _val(c) = (parsed_number_t(2 * math::pi) * _attr(c)); })];
//------------------------------------------------------------------------------
struct numeric_constant_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<numeric_constant_tag, parsed_number_t> numeric_constant =
  "numeric-constant";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto numeric_constant_def =
  (juxtaposition | conversion | numeric_literal | symbolic_constant);
//------------------------------------------------------------------------------
struct coersion_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<coersion_tag, parsed_number_t> coersion = "coersion";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto coersion_def =
  (numeric_constant)[([](auto& c) { _val(c) = _attr(c); })] |
  ("-" >> numeric_constant)[([](auto& c) { _val(c) = -_attr(c); })] |
  (function_call)[([](auto& c) { _val(c) = _attr(c); })] |
  ("-" >> function_call)[([](auto& c) { _val(c) = -_attr(c); })] |
  ("(" >> numeric_expression >> ")")[([](auto& c) { _val(c) = _attr(c); })] |
  ("-(" >> numeric_expression >> ")")[([](auto& c) { _val(c) = -_attr(c); })];
//------------------------------------------------------------------------------
struct numeric_factor_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<numeric_factor_tag, parsed_number_t> numeric_factor =
  "numeric-factor";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto numeric_factor_def = (coersion >> *('^' >> coersion))[([](auto& c) {
    auto l{at_c<0>(_attr(c))};
    const auto& ve{at_c<1>(_attr(c))};
    if(ve.empty()) {
        _val(c) = l;
    } else {
        parsed_number_t e{1};
        for(auto i = ve.rbegin(); i != ve.rend(); ++i) {
            e = std::pow(*i, e);
        }
        _val(c) = std::pow(l, e);
    }
})];
//------------------------------------------------------------------------------
struct numeric_term_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<numeric_term_tag, parsed_number_t> numeric_term = "numeric-term";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto numeric_term_def =
  (numeric_factor >> *(bs::char_("*/") >> numeric_factor))[([](auto& c) {
      auto l{at_c<0>(_attr(c))};
      for(const auto& p : at_c<1>(_attr(c))) {
          const auto o{at_c<0>(p)};
          const auto r{at_c<1>(p)};
          l = (o == '*') ? (l * r) : (l / r);
      }
      _val(c) = l;
  })];
//------------------------------------------------------------------------------
struct arith_expression_tag;
// NOLINTNEXTLINE(cert-err58-cpp)
const bs::rule<arith_expression_tag, parsed_number_t> arith_expression =
  "arithmetic-expression";
// NOLINTNEXTLINE(cert-err58-cpp)
const auto arith_expression_def =
  (numeric_term >> *(bs::char_("+-") >> numeric_term))[([](auto& c) {
      auto l{at_c<0>(_attr(c))};
      for(const auto& p : at_c<1>(_attr(c))) {
          const auto o{at_c<0>(p)};
          const auto r{at_c<1>(p)};
          l = (o == '+') ? (l + r) : (l - r);
      }
      _val(c) = l;
  })];
//------------------------------------------------------------------------------
// NOLINTNEXTLINE(cert-err58-cpp)
const auto function_call_def =
  (bs::lit("sqrt") >> "(" >> numeric_expression >>
   ")")[([](auto& c) { _val(c) = std::sqrt(_attr(c)); })] |
  (bs::lit("sin") >> "(" >> numeric_expression >>
   ")")[([](auto& c) { _val(c) = std::sin(_attr(c)); })] |
  (bs::lit("cos") >> "(" >> numeric_expression >>
   ")")[([](auto& c) { _val(c) = std::cos(_attr(c)); })] |
  (bs::lit("tg") >> "(" >> numeric_expression >>
   ")")[([](auto& c) { _val(c) = std::tan(_attr(c)); })] |
  (bs::lit("ln") >> "(" >> numeric_expression >>
   ")")[([](auto& c) { _val(c) = std::log(_attr(c)); })] |
  (bs::lit("exp") >> "(" >> numeric_expression >>
   ")")[([](auto& c) { _val(c) = std::exp(_attr(c)); })] |
  (bs::lit("e") >> "^" >>
   numeric_term)[([](auto& c) { _val(c) = std::exp(_attr(c)); })];
//------------------------------------------------------------------------------
// NOLINTNEXTLINE(cert-err58-cpp)
const auto numeric_expression_def = arith_expression | function_call;

// NOLINTNEXTLINE(modernize-use-trailing-return-type)
BOOST_SPIRIT_DEFINE(
  numeric_literal,
  juxtaposition,
  numeric_constant,
  conversion,
  coersion,
  numeric_factor,
  numeric_term,
  arith_expression,
  function_call,
  numeric_expression)
//------------------------------------------------------------------------------
template <typename Iter>
static inline auto do_parse(Iter i, Iter e, parsed_number_t& n) {
    if(bs::phrase_parse(i, e, numeric_expression, bs::ascii::space, n)) {
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
} // namespace numexpr
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto _parse_from_string(string_view src, long double& parsed) noexcept -> bool {
    numexpr::parsed_number_t temp{};
    if(numexpr::do_parse(src.begin(), src.end(), temp)) {
        parsed = temp.real();
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto _parse_from_string(string_view src, long long int& parsed) noexcept
  -> bool {
    long double temp{};
    if(_parse_from_string(src, temp)) {
        const auto rnd{std::round(temp)};
        const auto eps{std::numeric_limits<long double>::epsilon()};
        if(std::abs(temp - rnd) <= eps) {
            parsed = static_cast<long long int>(rnd);
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------
#else
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto _parse_from_string(string_view, long double&) noexcept -> bool {
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto _parse_from_string(string_view, long long int&) noexcept -> bool {
    return false;
}
//------------------------------------------------------------------------------
#endif
} // namespace eagine
