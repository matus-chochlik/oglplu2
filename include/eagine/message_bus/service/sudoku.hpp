/**
 *  @file eagine/message_bus/service/sudoku.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_SUDOKU_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_SUDOKU_HPP

#include "../../bool_aggregate.hpp"
#include "../../flat_set.hpp"
#include "../../int_constant.hpp"
#include "../../math/functions.hpp"
#include "../../maybe_unused.hpp"
#include "../../serialize/type/sudoku.hpp"
#include "../../sudoku.hpp"
#include "../serialize.hpp"
#include "../subscriber.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <random>
#include <tuple>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <template <unsigned> class U>
struct sudoku_rank_tuple
  : std::tuple<nothing_t, nothing_t, nothing_t, U<3>, U<4>, U<5>, U<6>> {
    using base =
      std::tuple<nothing_t, nothing_t, nothing_t, U<3>, U<4>, U<5>, U<6>>;

    sudoku_rank_tuple() = default;

    template <typename... Args>
    sudoku_rank_tuple(const Args&... args)
      : base{
          nothing,
          nothing,
          nothing,
          {args...},
          {args...},
          {args...},
          {args...}} {}

    template <unsigned S>
    auto get(unsigned_constant<S>) noexcept -> auto& {
        return std::get<S>(*this);
    }

    template <unsigned S>
    auto get(unsigned_constant<S>) const noexcept -> const auto& {
        return std::get<S>(*this);
    }
};
//------------------------------------------------------------------------------
template <typename Function, typename... RankTuple>
static inline void for_each_sudoku_rank_unit(Function func, RankTuple&... t) {
    func(std::get<3>(t)...);
    func(std::get<4>(t)...);
    func(std::get<5>(t)...);
    func(std::get<6>(t)...);
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_search_msg(unsigned_constant<S>) noexcept {
    if constexpr(S == 3) {
        return EAGINE_MSG_ID(eagiSudoku, search3);
    }
    if constexpr(S == 4) {
        return EAGINE_MSG_ID(eagiSudoku, search4);
    }
    if constexpr(S == 5) {
        return EAGINE_MSG_ID(eagiSudoku, search5);
    }
    if constexpr(S == 6) {
        return EAGINE_MSG_ID(eagiSudoku, search6);
    }
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_alive_msg(unsigned_constant<S>) noexcept {
    if constexpr(S == 3) {
        return EAGINE_MSG_ID(eagiSudoku, alive3);
    }
    if constexpr(S == 4) {
        return EAGINE_MSG_ID(eagiSudoku, alive4);
    }
    if constexpr(S == 5) {
        return EAGINE_MSG_ID(eagiSudoku, alive5);
    }
    if constexpr(S == 6) {
        return EAGINE_MSG_ID(eagiSudoku, alive6);
    }
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_query_msg(unsigned_constant<S>) noexcept {
    if constexpr(S == 3) {
        return EAGINE_MSG_ID(eagiSudoku, query3);
    }
    if constexpr(S == 4) {
        return EAGINE_MSG_ID(eagiSudoku, query4);
    }
    if constexpr(S == 5) {
        return EAGINE_MSG_ID(eagiSudoku, query5);
    }
    if constexpr(S == 6) {
        return EAGINE_MSG_ID(eagiSudoku, query6);
    }
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_solved_msg(unsigned_constant<S>) noexcept
  -> message_id {
    if constexpr(S == 3) {
        return EAGINE_MSG_ID(eagiSudoku, solved3);
    }
    if constexpr(S == 4) {
        return EAGINE_MSG_ID(eagiSudoku, solved4);
    }
    if constexpr(S == 5) {
        return EAGINE_MSG_ID(eagiSudoku, solved5);
    }
    if constexpr(S == 6) {
        return EAGINE_MSG_ID(eagiSudoku, solved6);
    }
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_candidate_msg(unsigned_constant<S>) noexcept
  -> message_id {
    if constexpr(S == 3) {
        return EAGINE_MSG_ID(eagiSudoku, candidate3);
    }
    if constexpr(S == 4) {
        return EAGINE_MSG_ID(eagiSudoku, candidate4);
    }
    if constexpr(S == 5) {
        return EAGINE_MSG_ID(eagiSudoku, candidate5);
    }
    if constexpr(S == 6) {
        return EAGINE_MSG_ID(eagiSudoku, candidate6);
    }
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_done_msg(unsigned_constant<S>) noexcept
  -> message_id {
    if constexpr(S == 3) {
        return EAGINE_MSG_ID(eagiSudoku, done3);
    }
    if constexpr(S == 4) {
        return EAGINE_MSG_ID(eagiSudoku, done4);
    }
    if constexpr(S == 5) {
        return EAGINE_MSG_ID(eagiSudoku, done5);
    }
    if constexpr(S == 6) {
        return EAGINE_MSG_ID(eagiSudoku, done6);
    }
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto
sudoku_response_msg(unsigned_constant<S> rank, bool is_solved) noexcept
  -> message_id {
    return is_solved ? sudoku_solved_msg(rank) : sudoku_candidate_msg(rank);
}
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class sudoku_helper : public Base {
    using This = sudoku_helper;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        sudoku_rank_tuple<unsigned_constant> ranks;
        for_each_sudoku_rank_unit(
          [&](auto rank) {
              Base::add_method(this, _bind_handle_search(rank));
              Base::add_method(this, _bind_handle_board(rank));
          },
          ranks);

        mark_activity();
    }

public:
    auto update() -> bool {
        some_true something_done{};
        something_done(Base::update());

        for_each_sudoku_rank_unit(
          [&](auto& info) {
              if(info.update(this->bus())) {
                  something_done();
              }
          },
          _infos);

        return something_done;
    }

    void mark_activity() {
        _activity_time = std::chrono::steady_clock::now();
    }

    auto idle_time() const noexcept {
        return std::chrono::steady_clock::now() - _activity_time;
    }

private:
    template <unsigned S>
    auto _handle_search(const message_context&, stored_message& message)
      -> bool {
        _infos.get(unsigned_constant<S>{}).on_search(message.source_id);
        mark_activity();
        return true;
    }

    template <unsigned S>
    static constexpr auto
    _bind_handle_search(unsigned_constant<S> rank) noexcept {
        return message_handler_map<member_function_constant<
          bool (This::*)(const message_context&, stored_message&),
          &This::_handle_search<S>>>{sudoku_search_msg(rank)};
    }

    template <unsigned S>
    auto _handle_board(const message_context&, stored_message& message)
      -> bool {
        const unsigned_constant<S> rank{};
        auto& info = _infos.get(rank);
        basic_sudoku_board<S> board{info.traits};

        if(EAGINE_LIKELY(default_deserialize(board, message.content()))) {
            info.add_board(
              message.source_id, message.sequence_no, std::move(board));
            mark_activity();
        }
        return true;
    }

    template <unsigned S>
    static constexpr auto
    _bind_handle_board(unsigned_constant<S> rank) noexcept {
        return message_handler_map<member_function_constant<
          bool (This::*)(const message_context&, stored_message&),
          &This::_handle_board<S>>>{sudoku_query_msg(rank)};
    }

    template <unsigned S>
    struct rank_info {
        default_sudoku_board_traits<S> traits;

        std::size_t counter{0U};
        std::vector<
          std::tuple<identifier_t, message_sequence_t, basic_sudoku_board<S>>>
          boards;

        flat_set<identifier_t> searches;

        void on_search(identifier_t source_id) {
            searches.insert(source_id);
        }

        void add_board(
          identifier_t source_id,
          message_sequence_t sequence_no,
          basic_sudoku_board<S> board) {
            searches.insert(source_id);
            boards.emplace_back(source_id, sequence_no, std::move(board));
        }

        auto update(endpoint& bus) -> bool {
            const unsigned_constant<S> rank{};
            some_true something_done;

            for(auto target_id : searches) {
                message_view response{};
                response.set_target_id(target_id);
                bus.post(sudoku_alive_msg(rank), response);
                something_done();
            }
            searches.clear();

            if(!boards.empty()) {
                const auto target_id = std::get<0>(boards.back());
                const auto sequence_no = std::get<1>(boards.back());
                auto board = std::get<2>(boards.back());
                boards.pop_back();

                auto process_candidate = [&](auto& candidate) {
                    ++counter;
                    const bool is_solved = candidate.is_solved();

                    auto temp{default_serialize_buffer_for(candidate)};
                    auto serialized{default_serialize(candidate, cover(temp))};
                    EAGINE_ASSERT(serialized);

                    message_view response{extract(serialized)};
                    response.set_target_id(target_id);
                    response.set_sequence_no(sequence_no);
                    bus.post(sudoku_response_msg(rank, is_solved), response);
                };

                board.for_each_alternative(
                  board.find_unsolved(), [&](auto& intermediate) {
                      intermediate.for_each_alternative(
                        intermediate.find_unsolved(), process_candidate);
                  });

                message_view response{};
                response.set_target_id(target_id);
                response.set_sequence_no(sequence_no);
                bus.post(sudoku_done_msg(rank), response);
                something_done();
            }
            return something_done;
        }
    };
    sudoku_rank_tuple<rank_info> _infos;

    std::chrono::steady_clock::time_point _activity_time{
      std::chrono::steady_clock::now()};
};
//------------------------------------------------------------------------------
template <typename Base = subscriber, typename Key = int>
class sudoku_solver : public Base {
    using This = sudoku_solver;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        sudoku_rank_tuple<unsigned_constant> ranks;
        for_each_sudoku_rank_unit(
          [&](auto rank) {
              Base::add_method(this, _bind_handle_alive(rank));
              Base::add_method(this, _bind_handle_candidate(rank));
              Base::add_method(this, _bind_handle_solved(rank));
              Base::add_method(this, _bind_handle_done(rank));
          },
          ranks);
    }

public:
    template <unsigned S>
    auto enqueue(Key key, basic_sudoku_board<S> board) -> auto& {
        _infos.get(unsigned_constant<S>{})
          .add_board(std::move(key), std::move(board));
        return *this;
    }

    auto has_work() const noexcept -> bool {
        bool result = false;
        for_each_sudoku_rank_unit(
          [&](const auto& info) { result |= info.has_work(); }, _infos);

        return result;
    }

    auto is_done() const noexcept -> bool {
        return !has_work();
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(Base::update());

        for_each_sudoku_rank_unit(
          [&](auto& info) {
              something_done(info.handle_timeouted(*this));
              something_done(info.send_boards(this->bus()));
              something_done(info.search_helpers(this->bus()));
          },
          _infos);

        return something_done;
    }

    template <unsigned S>
    auto has_enqueued(const Key& key, unsigned_constant<S> rank) -> bool {
        return _infos.get(rank).has_enqueued(key);
    }

    virtual auto already_done(const Key&, unsigned_constant<3>) -> bool {
        return false;
    }
    virtual auto already_done(const Key&, unsigned_constant<4>) -> bool {
        return false;
    }
    virtual auto already_done(const Key&, unsigned_constant<5>) -> bool {
        return false;
    }
    virtual auto already_done(const Key&, unsigned_constant<6>) -> bool {
        return false;
    }

    virtual void on_solved(identifier_t, const Key&, basic_sudoku_board<3>&) {}
    virtual void on_solved(identifier_t, const Key&, basic_sudoku_board<4>&) {}
    virtual void on_solved(identifier_t, const Key&, basic_sudoku_board<5>&) {}
    virtual void on_solved(identifier_t, const Key&, basic_sudoku_board<6>&) {}

private:
    template <unsigned S>
    struct rank_info {
        message_sequence_t query_sequence{0};
        default_sudoku_board_traits<S> traits;
        timeout search_timeout{std::chrono::seconds(3), nothing};

        std::vector<std::tuple<Key, basic_sudoku_board<S>>> boards;

        struct pending_info {
            pending_info(basic_sudoku_board<S> b)
              : board{std::move(b)} {}

            basic_sudoku_board<S> board;
            identifier_t used_helper{0U};
            message_sequence_t sequence_no{0U};
            Key key{};
            timeout too_late{};
        };
        std::vector<pending_info> pending;

        flat_set<identifier_t> ready_helpers;
        flat_set<identifier_t> used_helpers;

        std::default_random_engine randeng{std::random_device{}()};

        auto has_work() const noexcept {
            return !boards.empty() || !pending.empty();
        }

        void add_board(Key key, basic_sudoku_board<S> board) {
            const auto alternative_count = board.alternative_count();
            auto pos = std::lower_bound(
              boards.begin(),
              boards.end(),
              alternative_count,
              [=](const auto& entry, auto value) {
                  return std::get<1>(entry).alternative_count() > value;
              });
            boards.emplace(pos, std::move(key), std::move(board));
        }

        auto search_helpers(endpoint& bus) -> bool {
            some_true something_done;
            if(search_timeout) {
                bus.broadcast(sudoku_search_msg(unsigned_constant<S>{}));
                search_timeout.reset();
                something_done();
            }
            return something_done;
        }

        auto handle_timeouted(This& solver) -> bool {
            span_size_t count = 0;
            pending.erase(
              std::remove_if(
                pending.begin(),
                pending.end(),
                [&](auto& entry) {
                    if(entry.too_late) {
                        used_helpers.erase(entry.used_helper);
                        const unsigned_constant<S> rank{};
                        if(!solver.already_done(entry.key, rank)) {
                            add_board(
                              std::move(entry.key), std::move(entry.board));
                            ++count;
                        }
                        return true;
                    }
                    return false;
                }),
              pending.end());
            if(count > 0) {
                solver.bus()
                  .log_warning("replacing ${count} timeouted boards")
                  .arg(EAGINE_ID(count), count)
                  .arg(EAGINE_ID(enqueued), boards.size())
                  .arg(EAGINE_ID(pending), pending.size())
                  .arg(EAGINE_ID(ready), ready_helpers.size())
                  .arg(EAGINE_ID(used), used_helpers.size())
                  .arg(EAGINE_ID(rank), S);
            }
            return count > 0;
        }

        void handle_response(
          This& parent,
          message_id msg_id,
          stored_message& message) {
            const unsigned_constant<S> rank{};
            basic_sudoku_board<S> board{traits};

            if(EAGINE_LIKELY(default_deserialize(board, message.content()))) {
                const auto pos = std::find_if(
                  pending.begin(), pending.end(), [&](const auto& entry) {
                      return entry.sequence_no == message.sequence_no;
                  });

                if(pos != pending.end()) {

                    if(msg_id == sudoku_solved_msg(rank)) {
                        EAGINE_ASSERT(board.is_solved());
                        boards.erase(
                          std::remove_if(
                            boards.begin(),
                            boards.end(),
                            [&](const auto& entry) {
                                return pos->key == std::get<0>(entry);
                            }),
                          boards.end());
                        parent.on_solved(pos->used_helper, pos->key, board);
                    } else {
                        add_board(pos->key, std::move(board));
                    }
                    pos->too_late.reset();
                }
            }
        }

        auto send_board_to(endpoint& bus, identifier_t helper_id) -> bool {
            if(!boards.empty()) {
                std::binomial_distribution dist(
                  boards.size() - 1U,
                  math::blend(1.0, 0.9, std::exp(-boards.size())));
                auto pos = std::next(boards.begin(), dist(randeng));
                auto& [key, board] = *pos;
                auto temp{default_serialize_buffer_for(board)};
                auto serialized{default_serialize(board, cover(temp))};
                EAGINE_ASSERT(serialized);

                const auto sequence_no = query_sequence++;
                message_view response{extract(serialized)};
                response.set_target_id(helper_id);
                response.set_sequence_no(sequence_no);
                bus.post(sudoku_query_msg(unsigned_constant<S>{}), response);

                auto& query = pending.emplace_back(std::move(board));
                query.used_helper = helper_id;
                query.sequence_no = sequence_no;
                query.key = std::move(key);
                query.too_late.reset(std::chrono::seconds(S * S));
                boards.erase(pos);

                used_helpers.insert(helper_id);
                ready_helpers.erase(helper_id);
                return true;
            }
            return false;
        }

        auto send_boards(endpoint& bus) -> bool {
            some_true something_done;

            while(!ready_helpers.empty()) {
                std::uniform_int_distribution<std::size_t> dist(
                  0U, ready_helpers.size() - 1U);
                const auto pos =
                  std::next(ready_helpers.begin(), dist(randeng));

                if(!send_board_to(bus, *pos)) {
                    break;
                }
                something_done();
            }
            return something_done;
        }

        void pending_done(message_sequence_t sequence_no) {
            const auto pos = std::find_if(
              pending.begin(), pending.end(), [&](const auto& entry) {
                  return entry.sequence_no == sequence_no;
              });
            if(pos != pending.end()) {
                used_helpers.erase(pos->used_helper);
                ready_helpers.insert(pos->used_helper);
                pending.erase(pos);
            }
        }

        void helper_alive(identifier_t id) {
            if(used_helpers.find(id) == used_helpers.end()) {
                ready_helpers.insert(id);
            }
        }

        auto has_enqueued(const Key& key) -> bool {
            return std::find_if(
                     boards.begin(),
                     boards.end(),
                     [&](const auto& entry) {
                         return std::get<0>(entry) == key;
                     }) != boards.end() ||
                   std::find_if(
                     pending.begin(), pending.end(), [&](const auto& entry) {
                         return entry.key == key;
                     }) != pending.end();
        }
    };

    sudoku_rank_tuple<rank_info> _infos;

    template <unsigned S>
    auto _handle_alive(const message_context&, stored_message& message)
      -> bool {
        _infos.get(unsigned_constant<S>{}).helper_alive(message.source_id);
        return true;
    }

    template <unsigned S>
    static constexpr auto
    _bind_handle_alive(unsigned_constant<S> rank) noexcept {
        return message_handler_map<member_function_constant<
          bool (This::*)(const message_context&, stored_message&),
          &This::_handle_alive<S>>>{sudoku_alive_msg(rank)};
    }

    template <unsigned S>
    auto _handle_board(const message_context& msg_ctx, stored_message& message)
      -> bool {

        _infos.get(unsigned_constant<S>{})
          .handle_response(*this, msg_ctx.msg_id(), message);
        return true;
    }

    template <unsigned S>
    static constexpr auto
    _bind_handle_candidate(unsigned_constant<S> rank) noexcept {
        return message_handler_map<member_function_constant<
          bool (This::*)(const message_context&, stored_message&),
          &This::_handle_board<S>>>{sudoku_candidate_msg(rank)};
    }

    template <unsigned S>
    static constexpr auto
    _bind_handle_solved(unsigned_constant<S> rank) noexcept {
        return message_handler_map<member_function_constant<
          bool (This::*)(const message_context&, stored_message&),
          &This::_handle_board<S>>>{sudoku_solved_msg(rank)};
    }

    template <unsigned S>
    auto _handle_done(const message_context&, stored_message& message) -> bool {
        _infos.get(unsigned_constant<S>{}).pending_done(message.sequence_no);
        return true;
    }

    template <unsigned S>
    static constexpr auto _bind_handle_done(unsigned_constant<S> rank) noexcept {
        return message_handler_map<member_function_constant<
          bool (This::*)(const message_context&, stored_message&),
          &This::_handle_done<S>>>{sudoku_done_msg(rank)};
    }
};
//------------------------------------------------------------------------------
template <unsigned S>
class sudoku_tiles {
public:
    using Coord = std::tuple<int, int>;

    auto get_board(Coord coord) const noexcept -> const basic_sudoku_board<S>* {
        const auto pos = _boards.find(coord);
        if(pos != _boards.end()) {
            return &pos->second;
        }
        return nullptr;
    }

    auto get_board(int x, int y) const noexcept {
        return get_board({x, y});
    }

    auto set_board(Coord coord, basic_sudoku_board<S> board) -> bool {
        return _boards.try_emplace(std::move(coord), std::move(board)).second;
    }

    void set_extent(Coord min, Coord max) noexcept {
        _minu = std::get<0>(min);
        _minv = std::get<1>(min);
        _maxu = std::get<0>(max);
        _maxv = std::get<1>(max);
    }

    void set_extent(Coord max) noexcept {
        set_extent({0, 0}, max);
    }

    auto is_in_extent(int x, int y) const noexcept -> bool {
        const int u = x * S * (S - 2);
        const int v = y * S * (S - 2);
        return (u >= _minu) && (u < _maxu) && (v >= _minv) && (v < _maxv);
    }

    auto boards_extent(Coord min, Coord max) const
      -> std::tuple<int, int, int, int> {
        const auto conv = [](int c) {
            const auto mult = S * (S - 2);
            if(c < 0) {
                return c / mult - ((-c % mult) ? 1 : 0);
            }
            return c / mult + (c % mult ? 1 : 0);
        };
        return {
          conv(std::get<0>(min)),
          conv(std::get<1>(min)),
          conv(std::get<0>(max)),
          conv(std::get<1>(max))};
    }

    auto boards_extent() const {
        return boards_extent({_minu, _minv}, {_maxu, _maxv});
    }

    auto are_complete(Coord min, Coord max) const -> bool {
        const auto [xmin, ymin, xmax, ymax] = boards_extent(min, max);
        for(auto y : integer_range(ymin, ymax)) {
            for(auto x : integer_range(xmin, xmax)) {
                if(!get_board(x, y)) {
                    return false;
                }
            }
        }
        return true;
    }

    auto are_complete() const -> bool {
        return are_complete({_minu, _minv}, {_maxu, _maxv});
    }

    auto print(std::ostream& out, Coord min, Coord max) const -> std::ostream& {
        const auto [xmin, ymin, xmax, ymax] = boards_extent(min, max);

        for(auto y : integer_range(ymin, ymax)) {
            for(auto by : integer_range(1U, S - 1U)) {
                for(auto cy : integer_range(S)) {
                    for(auto x : integer_range(xmin, xmax)) {
                        auto board = get_board(x, y);
                        for(auto bx : integer_range(1U, S - 1U)) {
                            for(auto cx : integer_range(S)) {
                                if(board) {
                                    _traits.print(
                                      out,
                                      extract(board).get({bx, by, cx, cy}));
                                } else {
                                    _traits.print_empty(out);
                                }
                            }
                        }
                    }
                    out << '\n';
                }
            }
        }
        return out;
    }

    auto print(std::ostream& out) const -> auto& {
        return print(out, {_minu, _minv}, {_maxu, _maxv});
    }

protected:
    auto new_board() noexcept -> basic_sudoku_board<S> {
        return {_traits};
    }

private:
    int _minu{0};
    int _minv{0};
    int _maxu{0};
    int _maxv{0};
    flat_map<Coord, basic_sudoku_board<S>> _boards;
    default_sudoku_board_traits<S> _traits;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class sudoku_tiling : public sudoku_solver<Base, std::tuple<int, int>> {
    using base = sudoku_solver<Base, std::tuple<int, int>>;
    using This = sudoku_tiling;
    using Coord = std::tuple<int, int>;

protected:
    using base::base;

public:
    template <unsigned S>
    auto
    initialize(Coord min, Coord max, Coord coord, basic_sudoku_board<S> board)
      -> auto& {
        const auto [x, y] = coord;
        auto& info = _infos.get(unsigned_constant<S>{});
        info.set_extent(min, max);
        info.initialize(*this, x, y, std::move(board));
        return *this;
    }

    template <unsigned S>
    auto initialize(Coord max, basic_sudoku_board<S> board) -> auto& {
        return initialize({0, 0}, max, {0, 0}, std::move(board));
    }

    template <unsigned S>
    auto tiling_complete(unsigned_constant<S> rank) const noexcept -> bool {
        return _infos.get(rank).are_complete();
    }

    auto tiling_complete() const noexcept -> bool {
        bool result = true;
        sudoku_rank_tuple<unsigned_constant> ranks;
        for_each_sudoku_rank_unit(
          [&](auto rank) { result &= tiling_complete(rank); }, ranks);
        return result;
    }

    virtual void on_tiles_generated(const sudoku_tiles<3>&) {}
    virtual void on_tiles_generated(const sudoku_tiles<4>&) {}
    virtual void on_tiles_generated(const sudoku_tiles<5>&) {}
    virtual void on_tiles_generated(const sudoku_tiles<6>&) {}

private:
    template <unsigned S>
    struct rank_info : sudoku_tiles<S> {

        void
        initialize(This& solver, int x, int y, basic_sudoku_board<S> board) {
            solver.enqueue({x, y}, std::move(board));
            solver.bus()
              .log_debug("enqueuing initial board (${x}, ${y})")
              .arg(EAGINE_ID(x), x)
              .arg(EAGINE_ID(y), y)
              .arg(EAGINE_ID(rank), S);
        }

        void do_enqueue(This& solver, int x, int y) {
            auto board{this->new_board()};
            bool should_enqueue = false;
            if(y > 0) {
                if(x > 0) {
                    auto left = this->get_board(x - 1, y);
                    auto down = this->get_board(x, y - 1);
                    if(left && down) {
                        for(auto by : integer_range(S - 1U)) {
                            board.set_block(
                              0U, by, extract(left).get_block(S - 1U, by));
                        }
                        for(auto bx : integer_range(1U, S)) {
                            board.set_block(
                              bx, S - 1U, extract(down).get_block(bx, 0U));
                        }
                        should_enqueue = true;
                    }
                } else if(x < 0) {
                    auto right = this->get_board(x + 1, y);
                    auto down = this->get_board(x, y - 1);
                    if(right && down) {
                        for(auto by : integer_range(S - 1U)) {
                            board.set_block(
                              S - 1U, by, extract(right).get_block(0U, by));
                        }
                        for(auto bx : integer_range(S - 1U)) {
                            board.set_block(
                              bx, S - 1U, extract(down).get_block(bx, 0U));
                        }
                        should_enqueue = true;
                    }
                } else {
                    auto down = this->get_board(x, y - 1);
                    if(down) {
                        for(auto bx : integer_range(S)) {
                            board.set_block(
                              bx, S - 1U, extract(down).get_block(bx, 0U));
                        }
                        should_enqueue = true;
                    }
                }
            } else if(y < 0) {
                if(x > 0) {
                    auto left = this->get_board(x - 1, y);
                    auto up = this->get_board(x, y + 1);
                    if(left && up) {
                        for(auto by : integer_range(1U, S)) {
                            board.set_block(
                              0U, by, extract(left).get_block(S - 1U, by));
                        }
                        for(auto bx : integer_range(1U, S)) {
                            board.set_block(
                              bx, 0U, extract(up).get_block(bx, S - 1U));
                        }
                        should_enqueue = true;
                    }
                } else if(x < 0) {
                    auto right = this->get_board(x + 1, y);
                    auto up = this->get_board(x, y + 1);
                    if(right && up) {
                        for(auto by : integer_range(1U, S)) {
                            board.set_block(
                              S - 1U, by, extract(right).get_block(0U, by));
                        }
                        for(auto bx : integer_range(S - 1U)) {
                            board.set_block(
                              bx, 0U, extract(up).get_block(bx, S - 1U));
                        }
                        should_enqueue = true;
                    }
                } else {
                    auto up = this->get_board(x, y + 1);
                    if(up) {
                        for(auto bx : integer_range(S)) {
                            board.set_block(
                              bx, 0U, extract(up).get_block(bx, S - 1U));
                        }
                        should_enqueue = true;
                    }
                }
            } else {
                if(x > 0) {
                    auto left = this->get_board(x - 1, y);
                    if(left) {
                        for(auto by : integer_range(S)) {
                            board.set_block(
                              0U, by, extract(left).get_block(S - 1U, by));
                        }
                        should_enqueue = true;
                    }
                } else if(x < 0) {
                    auto right = this->get_board(x + 1, y);
                    if(right) {
                        for(auto by : integer_range(S)) {
                            board.set_block(
                              S - 1U, by, extract(right).get_block(0U, by));
                        }
                        should_enqueue = true;
                    }
                }
            }
            if(should_enqueue) {
                solver.enqueue({x, y}, board.calculate_alternatives());
                solver.bus()
                  .log_debug("enqueuing board (${x}, ${y})")
                  .arg(EAGINE_ID(x), x)
                  .arg(EAGINE_ID(y), y)
                  .arg(EAGINE_ID(rank), S);
            }
        }

        void enqueue_incomplete(This& solver) {
            const unsigned_constant<S> rank{};
            const auto [xmin, ymin, xmax, ymax] = this->boards_extent();
            for(auto y : integer_range(ymin, ymax)) {
                for(auto x : integer_range(xmin, xmax)) {
                    if(!this->get_board(x, y)) {
                        if(!solver.has_enqueued({x, y}, rank)) {
                            do_enqueue(solver, x, y);
                        }
                    }
                }
            }
        }

        void handle_solved(
          This& solver,
          identifier_t helper_id,
          Coord coord,
          basic_sudoku_board<S> board) {

            if(this->set_board(coord, std::move(board))) {
                solver.bus()
                  .log_info("solved board (${x}, ${y})")
                  .arg(EAGINE_ID(rank), S)
                  .arg(EAGINE_ID(x), std::get<0>(coord))
                  .arg(EAGINE_ID(y), std::get<1>(coord))
                  .arg(EAGINE_ID(helper), helper_id);
            }

            enqueue_incomplete(solver);

            solver.on_tiles_generated(*this);
        }
    };

    sudoku_rank_tuple<rank_info> _infos;

    auto already_done(const Coord& coord, unsigned_constant<3> rank)
      -> bool final {
        return _is_already_done(coord, rank);
    }
    auto already_done(const Coord& coord, unsigned_constant<4> rank)
      -> bool final {
        return _is_already_done(coord, rank);
    }
    auto already_done(const Coord& coord, unsigned_constant<5> rank)
      -> bool final {
        return _is_already_done(coord, rank);
    }
    auto already_done(const Coord& coord, unsigned_constant<6> rank)
      -> bool final {
        return _is_already_done(coord, rank);
    }

    template <unsigned S>
    auto _is_already_done(const Coord& coord, unsigned_constant<S>& rank)
      const noexcept -> bool {
        return _infos.get(rank).get_board(coord);
    }

    void on_solved(
      identifier_t helper_id,
      const Coord& coord,
      basic_sudoku_board<3>& board) final {
        _handle_solved(helper_id, coord, board);
    }
    void on_solved(
      identifier_t helper_id,
      const Coord& coord,
      basic_sudoku_board<4>& board) final {
        _handle_solved(helper_id, coord, board);
    }
    void on_solved(
      identifier_t helper_id,
      const Coord& coord,
      basic_sudoku_board<5>& board) final {
        _handle_solved(helper_id, coord, board);
    }
    void on_solved(
      identifier_t helper_id,
      const Coord& coord,
      basic_sudoku_board<6>& board) final {
        _handle_solved(helper_id, coord, board);
    }

    template <unsigned S>
    void _handle_solved(
      identifier_t helper_id,
      const Coord& coord,
      basic_sudoku_board<S>& board) {
        auto& info = _infos.get(unsigned_constant<S>{});
        info.handle_solved(*this, helper_id, coord, std::move(board));
    }
}; // namespace eagine::msgbus
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SUDOKU_HPP
