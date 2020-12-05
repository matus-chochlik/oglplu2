/**
 *  @file eagine/sudoku.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SUDOKU_HPP
#define EAGINE_SUDOKU_HPP

#include "assert.hpp"
#include <array>
#include <cstdint>
#include <ostream>
#include <random>

namespace eagine {
//------------------------------------------------------------------------------
template <unsigned S>
class basic_sudoku_board;
//------------------------------------------------------------------------------
template <unsigned S>
class basic_sudoku_board_type {
public:
    static constexpr const unsigned glyph_count = S * S;
    static constexpr const unsigned cell_count = S * S * S * S;

    using This = basic_sudoku_board_type;
    using cell_type = std::conditional_t<
      (glyph_count > 32U),
      std::int64_t,
      std::conditional_t<
        (glyph_count > 16),
        std::uint32_t,
        std::conditional_t<(glyph_count > 8), std::uint16_t, std::uint8_t>>>;

    basic_sudoku_board_type(
      std::array<std::string, glyph_count> glyphs,
      std::string empty_glyph,
      std::string multi_glyph) noexcept
      : _glyphs{std::move(glyphs)}
      , _empty_glyph{std::move(empty_glyph)}
      , _multi_glyph{std::move(multi_glyph)} {}

    auto print(std::ostream&, const basic_sudoku_board<S>& board) const
      -> std::ostream&;

    auto print_tight(std::ostream&, const basic_sudoku_board<S>& board) const
      -> std::ostream&;

private:
    std::array<std::string, glyph_count> _glyphs;
    std::string _empty_glyph;
    std::string _multi_glyph;
};
//------------------------------------------------------------------------------
template <unsigned S>
class basic_sudoku_value {
public:
    struct from_cell_value_tag {};
    using board_type = basic_sudoku_board_type<S>;
    using value_type = unsigned;
    using cell_type = typename board_type::cell_type;
    static constexpr const unsigned glyph_count = board_type::glyph_count;

    static constexpr auto to_cell_type(value_type value) noexcept {
        return cell_type(1U << value);
    }

    constexpr basic_sudoku_value() noexcept = default;
    constexpr basic_sudoku_value(value_type value) noexcept
      : _cel_val{to_cell_type(value)} {}

    constexpr auto is_empty() const noexcept {
        return _cel_val == 0U;
    }

    constexpr auto is_single() const noexcept {
        return _is_pot(_cel_val);
    }

    constexpr auto is_unsolved() const noexcept {
        return !is_empty() && !is_single();
    }

    auto cell_value() const noexcept -> cell_type {
        return _cel_val;
    }

    auto get() const noexcept -> value_type {
        value_type result = 0U;
        while(result < glyph_count) {
            if(_cel_val == to_cell_type(result)) {
                break;
            }
            ++result;
        }
        EAGINE_ASSERT(result < glyph_count);
        return result;
    }

    constexpr auto set(value_type value) noexcept -> auto& {
        EAGINE_ASSERT(value < glyph_count);
        _cel_val = to_cell_type(value);
        return *this;
    }

    constexpr auto add(value_type value) noexcept -> auto& {
        EAGINE_ASSERT(value < glyph_count);
        _cel_val |= to_cell_type(value);
        return *this;
    }

    template <typename Function>
    void for_each_alternative(Function func) const noexcept {

        for(value_type value = 0; value < glyph_count; ++value) {
            const auto mask = to_cell_type(value);
            if((_cel_val & mask) == mask) {
                func(value);
            }
        }
    }

private:
    friend class basic_sudoku_board<S>;

    constexpr basic_sudoku_value(cell_type cel_val, from_cell_value_tag) noexcept
      : _cel_val{cel_val} {}

    static constexpr auto _is_pot(cell_type v) noexcept {
        return (v > 0U) && ((v & (v - 1U)) == 0U);
    }

    cell_type _cel_val{0U};
};
//------------------------------------------------------------------------------
template <unsigned S>
class basic_sudoku_board {
public:
    using This = basic_sudoku_board;
    using board_type = basic_sudoku_board_type<S>;
    using value_type = basic_sudoku_value<S>;
    using cell_type = typename board_type::cell_type;
    using coord_type = std::array<unsigned, 4>;
    static constexpr const unsigned glyph_count = board_type::glyph_count;

    static constexpr auto invalid_coord() noexcept -> coord_type {
        return {{S, S, S, S}};
    }

    template <typename Function>
    void for_each_coord(Function func) const noexcept {
        for(unsigned by = 0; by < S; ++by) {
            for(unsigned bx = 0; bx < S; ++bx) {
                for(unsigned cy = 0; cy < S; ++cy) {
                    for(unsigned cx = 0; cx < S; ++cx) {
                        if(!func(coord_type{{bx, by, cx, cy}})) {
                            return;
                        }
                    }
                }
            }
        }
    }

    basic_sudoku_board(const board_type& type) noexcept
      : _type{type} {
        for_each_coord([&](const auto& coord) {
            set(coord, value_type());
            return true;
        });
    }

    auto type() const noexcept -> auto& {
        return _type;
    }

    friend auto operator<<(std::ostream& out, const This& that)
      -> std::ostream& {
        return that._type.get().print(out, that);
    }

    auto print_tight(std::ostream& out) const -> std::ostream& {
        return _type.get().print_tight(out, *this);
    }

    auto is_possible(const coord_type& coord, value_type value) const noexcept {
        const auto [cbx, cby, ccx, ccy] = coord;
        const auto cel_val = value.cell_value();

        for(unsigned cy = 0; cy < S; ++cy) {
            for(unsigned cx = 0; cx < S; ++cx) {
                if((cx != ccx) || (cy != ccy)) {
                    if(_cell_val({cbx, cby, cx, cy}) == cel_val) {
                        return false;
                    }
                }
            }
        }

        for(unsigned bx = 0; bx < S; ++bx) {
            for(unsigned cx = 0; cx < S; ++cx) {
                if((bx != cbx) || (cx != ccx)) {
                    if(_cell_val({bx, cby, cx, ccy}) == cel_val) {
                        return false;
                    }
                }
            }
        }

        for(unsigned by = 0; by < S; ++by) {
            for(unsigned cy = 0; cy < S; ++cy) {
                if((by != cby) || (cy != ccy)) {
                    if(_cell_val({cbx, by, ccx, cy}) == cel_val) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    auto is_solved() noexcept {
        bool result = true;
        for_each_coord([&](const auto& coord) {
            const auto value = get(coord);
            if(!value.is_single()) {
                result = false;
                return false;
            } else {
                EAGINE_ASSERT(is_possible(coord, value));
            }
            return true;
        });
        return result;
    }

    auto has_empty() noexcept {
        bool result = false;
        for_each_coord([&](const auto& coord) {
            if(get(coord).is_empty()) {
                result = true;
                return false;
            }
            return true;
        });
        return result;
    }

    auto get(const coord_type& coord) const noexcept -> value_type {
        return {_cell_val(coord), typename value_type::from_cell_value_tag{}};
    }

    auto set(const coord_type& coord, value_type value) noexcept -> auto& {
        _cell_ref(coord) = value.cell_value();
        return *this;
    }

    auto set_available_alternatives(const coord_type& coord) noexcept -> auto& {
        value_type alternatives;
        for(unsigned value = 0; value < glyph_count; ++value) {
            if(is_possible(coord, value)) {
                alternatives.add(value);
            }
        }
        return set(coord, alternatives);
    }

    auto calculate_alternatives() noexcept -> auto& {
        for_each_coord([&](const auto& coord) {
            if(!get(coord).is_single()) {
                set_available_alternatives(coord);
            }
            return true;
        });
        return *this;
    }

    auto find_unsolved() const noexcept -> coord_type {
        auto result = invalid_coord();
        for_each_coord([&](const auto& coord) {
            if(!get(coord).is_single()) {
                result = coord;
                return false;
            }
            return true;
        });
        return result;
    }

    template <typename Function>
    void for_each_alternative(const coord_type& coord, Function func) const {
        if(coord != invalid_coord()) {
            get(coord).for_each_alternative([&](value_type alt) {
                auto candidate = This(*this).set(coord, alt);
                if(candidate.is_possible(coord, alt)) {
                    if(!candidate.calculate_alternatives().has_empty()) {
                        func(candidate);
                    }
                }
            });
        }
    }

private:
    auto _cell_val(const coord_type& coord) const noexcept {
        const auto [bx, by, cx, cy] = coord;
        return _cell(_block(_blocks, bx, by), cx, cy);
    }

    auto _cell_ref(const coord_type& coord) noexcept -> auto& {
        const auto [bx, by, cx, cy] = coord;
        return _cell(_block(_blocks, bx, by), cx, cy);
    }

    template <typename B>
    static auto _cell(B& block, unsigned x, unsigned y) noexcept -> auto& {
        return block[y * S + x];
    }

    template <typename B>
    static auto _block(B& blocks, unsigned x, unsigned y) noexcept -> auto& {
        return blocks[y * S + x];
    }

    std::reference_wrapper<const board_type> _type;
    std::array<std::array<cell_type, glyph_count>, glyph_count> _blocks{};
};
//------------------------------------------------------------------------------
template <unsigned S>
auto basic_sudoku_board_type<S>::print(
  std::ostream& out,
  const basic_sudoku_board<S>& board) const -> std::ostream& {
    for(unsigned by = 0; by < S; ++by) {
        for(unsigned cy = 0; cy < S; ++cy) {
            for(unsigned bx = 0; bx < S; ++bx) {
                for(unsigned cx = 0; cx < S; ++cx) {
                    const auto v = board.get({{bx, by, cx, cy}});
                    if(v.is_single()) {
                        out << ' ' << _glyphs[v.get()];
                    } else if(v.is_empty()) {
                        out << ' ' << _empty_glyph;
                    } else {
                        out << ' ' << _multi_glyph;
                    }
                }
                if(bx + 1 < S) {
                    out << " |";
                }
            }
            out << '\n';
        }
        if(by + 1 < S) {
            for(unsigned s1 = 0; s1 < S; ++s1) {
                for(unsigned s2 = 0; s2 < S; ++s2) {
                    if(s1 == 0 && s2 == 0) {
                        out << " -";
                    } else {
                        out << "--";
                    }
                }
                if(s1 + 1 < S) {
                    out << "-+";
                }
            }
            out << '\n';
        }
    }
    return out;
}
//------------------------------------------------------------------------------
template <unsigned S>
auto basic_sudoku_board_type<S>::print_tight(
  std::ostream& out,
  const basic_sudoku_board<S>& board) const -> std::ostream& {
    for(unsigned by = 0; by < S; ++by) {
        for(unsigned cy = 0; cy < S; ++cy) {
            for(unsigned bx = 0; bx < S; ++bx) {
                for(unsigned cx = 0; cx < S; ++cx) {
                    const auto v = board.get({{bx, by, cx, cy}});
                    if(v.is_single()) {
                        out << _glyphs[v.get()];
                    } else if(v.is_empty()) {
                        out << _empty_glyph;
                    } else {
                        out << _multi_glyph;
                    }
                }
            }
            out << '\n';
        }
    }
    return out;
}
//------------------------------------------------------------------------------
template <unsigned S>
class basic_sudoku_board_generator {
public:
    using board_type = basic_sudoku_board_type<S>;

    auto generate(const board_type& type, std::size_t count)
      -> basic_sudoku_board<S> {
        basic_sudoku_board<S> result{type};
        result.calculate_alternatives();

        while(count) {
            const typename basic_sudoku_board<S>::coord_type coord{
              _coord_dist(_rd),
              _coord_dist(_rd),
              _coord_dist(_rd),
              _coord_dist(_rd)};

            if(!result.get(coord).is_single()) {
                while(true) {
                    auto temp = result;
                    const auto value{_glyph_dist(_rd)};
                    if(temp.is_possible(coord, value)) {
                        result =
                          temp.set(coord, value).calculate_alternatives();
                        --count;
                        break;
                    }
                }
            }
        }

        return result;
    }

    auto generate_few(const board_type& type) {
        return generate(type, S + S);
    }

    auto generate_medium(const board_type& type) {
        return generate(type, S * S + S + S);
    }

    auto generate_many(const board_type& type) {
        return generate(type, S * S * S + S + S + S);
    }

private:
    std::random_device _rd;
    std::uniform_int_distribution<unsigned> _coord_dist{0, S - 1};
    std::uniform_int_distribution<unsigned> _glyph_dist{0, S* S - 1};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SUDOKU_HPP
