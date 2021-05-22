/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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
#include "../signal.hpp"
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
/// @brief Service helping to partially solve sudoku boards sent by sudoku_solver.
/// @ingroup msgbus
/// @see service_composition
/// @see sudoku_solver
/// @see sudoku_tiling
template <typename Base = subscriber>
class sudoku_helper : public Base {
    using This = sudoku_helper;

public:
    auto update() -> bool {
        some_true something_done{};
        something_done(Base::update());

        for_each_sudoku_rank_unit(
          [&](auto& info) {
              if(info.update(this->bus_node(), _compressor)) {
                  something_done();
              }
          },
          _infos);

        return something_done;
    }

    void mark_activity() {
        _activity_time = std::chrono::steady_clock::now();
    }

    /// @brief Returns current idle time interval.
    auto idle_time() const noexcept {
        return std::chrono::steady_clock::now() - _activity_time;
    }

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

        const auto deserialized{
          (S >= 4)
            ? default_deserialize_packed(board, message.content(), _compressor)
            : default_deserialize(board, message.content())};

        if(EAGINE_LIKELY(deserialized)) {
            info.add_board(
              this->bus_node(),
              message.source_id,
              message.sequence_no,
              std::move(board));
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
          endpoint& bus,
          identifier_t source_id,
          message_sequence_t sequence_no,
          basic_sudoku_board<S> board) {
            if(EAGINE_LIKELY(boards.size() < 8)) {
                searches.insert(source_id);
                boards.emplace_back(source_id, sequence_no, std::move(board));
            } else {
                bus.log_warning("too many boards in backlog")
                  .arg(EAGINE_ID(rank), S)
                  .arg(EAGINE_ID(count), boards.size());
            }
        }

        auto update(endpoint& bus, const data_compressor& compressor) -> bool {
            const unsigned_constant<S> rank{};
            some_true something_done;

            if(boards.size() < 6) {
                for(auto target_id : searches) {
                    message_view response{};
                    response.set_target_id(target_id);
                    bus.post(sudoku_alive_msg(rank), response);
                    something_done();
                }
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
                    const auto serialized{
                      (S >= 4) ? default_serialize_packed(
                                   candidate, cover(temp), compressor)
                               : default_serialize(candidate, cover(temp))};
                    EAGINE_ASSERT(serialized);

                    message_view response{extract(serialized)};
                    response.set_target_id(target_id);
                    response.set_sequence_no(sequence_no);
                    bus.post(sudoku_response_msg(rank, is_solved), response);
                };

                board.for_each_alternative(
                  board.find_unsolved(), process_candidate);

                message_view response{};
                response.set_target_id(target_id);
                response.set_sequence_no(sequence_no);
                bus.post(sudoku_done_msg(rank), response);
                something_done();
            }
            return something_done;
        }
    };

    data_compressor _compressor{};

    sudoku_rank_tuple<rank_info> _infos;

    std::chrono::steady_clock::time_point _activity_time{
      std::chrono::steady_clock::now()};
};
//------------------------------------------------------------------------------
/// @brief Service solving sudoku boards with the help of helper service on message bus.
/// @ingroup msgbus
/// @see service_composition
/// @see sudoku_helper
/// @see sudoku_tiling
template <typename Base = subscriber, typename Key = int>
class sudoku_solver : public Base {
    using This = sudoku_solver;

public:
    /// @brief Enqueues a Sudoku board for solution under the specified unique key.
    /// @see has_enqueued
    /// @see has_work
    /// @see is_done
    template <unsigned S>
    auto enqueue(Key key, basic_sudoku_board<S> board) -> auto& {
        _infos.get(unsigned_constant<S>{})
          .add_board(std::move(key), std::move(board));
        return *this;
    }

    /// @brief Indicates if there are pending boards being solved.
    /// @see enqueue
    /// @see is_done
    auto has_work() const noexcept -> bool {
        bool result = false;
        for_each_sudoku_rank_unit(
          [&](const auto& info) { result |= info.has_work(); }, _infos);

        return result;
    }

    /// @brief Indicates if there is not work being done. Opposite of has_work.
    /// @see enqueue
    /// @see has_work.
    auto is_done() const noexcept -> bool {
        return !has_work();
    }

    void init() {
        Base::init();
        this->bus_node().id_assigned.connect(
          EAGINE_THIS_MEM_FUNC_REF(on_id_assigned));
        this->bus_node().connection_established.connect(
          EAGINE_THIS_MEM_FUNC_REF(on_connection_established));
        this->bus_node().connection_lost.connect(
          EAGINE_THIS_MEM_FUNC_REF(on_connection_lost));
    }

    void on_id_assigned(identifier_t) {
        _can_work = true;
    }

    void on_connection_established(bool usable) {
        _can_work = usable;
        this->bus_node().log_info("connection established");
    }

    void on_connection_lost() {
        _can_work = false;
        this->bus_node().log_warning("connection lost");
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(Base::update());

        for_each_sudoku_rank_unit(
          [&](auto& info) {
              something_done(info.handle_timeouted(*this));
              if(EAGINE_LIKELY(_can_work)) {
                  something_done(
                    info.send_boards(this->bus_node(), _compressor));
                  something_done(info.search_helpers(this->bus_node()));
              }
          },
          _infos);

        return something_done;
    }

    /// @brief Resets all boards with the given rank.
    template <unsigned S>
    auto reset(unsigned_constant<S> rank) noexcept -> auto& {
        _infos.get(rank).reset(*this);
        return *this;
    }

    /// @brief Indicates if a board with the given rank and key is enqueued.
    /// @see enqueue
    template <unsigned S>
    auto has_enqueued(const Key& key, unsigned_constant<S> rank) -> bool {
        return _infos.get(rank).has_enqueued(key);
    }

    /// @brief Sets the solution timeout for the specified rank.
    template <unsigned S>
    auto set_solution_timeout(
      unsigned_constant<S> rank,
      std::chrono::seconds sec) noexcept -> bool {
        return _infos.get(rank).solution_timeout.reset(sec);
    }

    /// @brief Indicates if the solution of board with the specified rank timeouted.
    template <unsigned S>
    auto solution_timeouted(unsigned_constant<S> rank) const noexcept -> bool {
        return _infos.get(rank).solution_timeout.is_expired();
    }

    /// @brief Indicates if board with the specified rank is already solved.
    virtual auto already_done(const Key&, unsigned_constant<3>) -> bool {
        return false;
    }
    /// @brief Indicates if board with the specified rank is already solved.
    virtual auto already_done(const Key&, unsigned_constant<4>) -> bool {
        return false;
    }
    /// @brief Indicates if board with the specified rank is already solved.
    virtual auto already_done(const Key&, unsigned_constant<5>) -> bool {
        return false;
    }
    /// @brief Indicates if board with the specified rank is already solved.
    virtual auto already_done(const Key&, unsigned_constant<6>) -> bool {
        return false;
    }

    /// @brief Triggered when the board with the specified key is solved.
    signal<void(identifier_t, const Key&, basic_sudoku_board<3>&)> solved_3;
    /// @brief Triggered when the board with the specified key is solved.
    signal<void(identifier_t, const Key&, basic_sudoku_board<4>&)> solved_4;
    /// @brief Triggered when the board with the specified key is solved.
    signal<void(identifier_t, const Key&, basic_sudoku_board<5>&)> solved_5;
    /// @brief Triggered when the board with the specified key is solved.
    signal<void(identifier_t, const Key&, basic_sudoku_board<6>&)> solved_6;

    /// @brief Returns a reference to the solved_3 signal.
    /// @see solved_3
    auto solved_signal(unsigned_constant<3> = {}) noexcept -> auto& {
        return solved_3;
    }

    /// @brief Returns a reference to the solved_4 signal.
    /// @see solved_4
    auto solved_signal(unsigned_constant<4> = {}) noexcept -> auto& {
        return solved_4;
    }

    /// @brief Returns a reference to the solved_5 signal.
    /// @see solved_5
    auto solved_signal(unsigned_constant<5> = {}) noexcept -> auto& {
        return solved_5;
    }

    /// @brief Returns a reference to the solved_6 signal.
    /// @see solved_6
    auto solved_signal(unsigned_constant<6> = {}) noexcept -> auto& {
        return solved_6;
    }

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

private:
    template <unsigned S>
    struct rank_info {
        message_sequence_t query_sequence{0};
        default_sudoku_board_traits<S> traits;
        timeout search_timeout{std::chrono::seconds(3), nothing};
        timeout solution_timeout{std::chrono::seconds(S * S * S * S)};

        flat_map<Key, std::vector<basic_sudoku_board<S>>> key_boards;

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

        std::default_random_engine randeng{std::random_device{}()};

        auto has_work() const noexcept {
            return !key_boards.empty() || !pending.empty();
        }

        void add_board(Key key, basic_sudoku_board<S> board) {
            const auto alternative_count = board.alternative_count();
            auto& boards = key_boards[key];
            auto pos = std::lower_bound(
              boards.begin(),
              boards.end(),
              alternative_count,
              [=](const auto& entry, auto value) {
                  return entry.alternative_count() > value;
              });
            boards.emplace(pos, std::move(board));
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
                        const unsigned_constant<S> rank{};
                        if(!solver.already_done(entry.key, rank)) {
                            entry.board.for_each_alternative(
                              entry.board.find_unsolved(),
                              [&](auto& candidate) {
                                  if(candidate.is_solved()) {
                                      solver.solved_signal(rank)(
                                        entry.used_helper,
                                        entry.key,
                                        candidate);
                                  } else {
                                      add_board(
                                        std::move(entry.key),
                                        std::move(candidate));
                                      ++count;
                                  }
                              });
                        }
                        return true;
                    }
                    return false;
                }),
              pending.end());
            if(count > 0) {
                solver.bus_node()
                  .log_warning("replacing ${count} timeouted boards")
                  .arg(EAGINE_ID(count), count)
                  .arg(EAGINE_ID(enqueued), key_boards.size())
                  .arg(EAGINE_ID(pending), pending.size())
                  .arg(EAGINE_ID(ready), ready_helpers.size())
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

            const auto deserialized{
              (S >= 4) ? default_deserialize_packed(
                           board, message.content(), parent._compressor)
                       : default_deserialize(board, message.content())};

            if(EAGINE_LIKELY(deserialized)) {
                const auto pos = std::find_if(
                  pending.begin(), pending.end(), [&](const auto& entry) {
                      return entry.sequence_no == message.sequence_no;
                  });

                if(pos != pending.end()) {

                    if(msg_id == sudoku_solved_msg(rank)) {
                        EAGINE_ASSERT(board.is_solved());
                        key_boards.erase(
                          std::remove_if(
                            key_boards.begin(),
                            key_boards.end(),
                            [&](const auto& entry) {
                                return pos->key == std::get<0>(entry);
                            }),
                          key_boards.end());
                        parent.solved_signal(rank)(
                          pos->used_helper, pos->key, board);
                        solution_timeout.reset();
                    } else {
                        add_board(pos->key, std::move(board));
                    }
                    pos->too_late.reset();
                }
            }
        }

        auto send_board_to(
          endpoint& bus,
          data_compressor& compressor,
          identifier_t helper_id) -> bool {
            if(!key_boards.empty()) {
                auto kbpos =
                  key_boards.begin() + (query_sequence % key_boards.size());
                EAGINE_ASSERT(kbpos < key_boards.end());
                auto& [key, boards] = *kbpos;
                std::binomial_distribution dist(
                  boards.size() - 1U,
                  math::blend(1.0, 0.8, std::exp(-boards.size())));

                auto pos = std::next(boards.begin(), dist(randeng));
                auto& board = *pos;
                auto temp{default_serialize_buffer_for(board)};
                const auto serialized{
                  (S >= 4)
                    ? default_serialize_packed(board, cover(temp), compressor)
                    : default_serialize(board, cover(temp))};
                EAGINE_ASSERT(serialized);

                const auto sequence_no = query_sequence++;
                message_view response{extract(serialized)};
                response.set_target_id(helper_id);
                response.set_sequence_no(sequence_no);
                bus.post(sudoku_query_msg(unsigned_constant<S>{}), response);

                pending.emplace_back(std::move(board));
                auto& query = pending.back();
                query.used_helper = helper_id;
                query.sequence_no = sequence_no;
                query.key = std::move(key);
                query.too_late.reset(std::chrono::seconds(S * S));
                boards.erase(pos);
                if(boards.empty()) {
                    key_boards.erase(kbpos);
                }

                ready_helpers.erase(helper_id);
                return true;
            }
            return false;
        }

        auto send_boards(endpoint& bus, data_compressor& compressor) -> bool {
            some_true something_done;

            for(const auto i : integer_range(4)) {
                EAGINE_MAYBE_UNUSED(i);
                if(ready_helpers.empty()) {
                    break;
                }
                std::uniform_int_distribution<std::size_t> dist(
                  0U, ready_helpers.size() - 1U);
                const auto pos =
                  std::next(ready_helpers.begin(), dist(randeng));

                if(!send_board_to(bus, compressor, *pos)) {
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
                ready_helpers.insert(pos->used_helper);
                pending.erase(pos);
            }
        }

        void helper_alive(identifier_t id) {
            ready_helpers.insert(id);
        }

        auto has_enqueued(const Key& key) -> bool {
            return std::find_if(
                     key_boards.begin(),
                     key_boards.end(),
                     [&](const auto& entry) {
                         return std::get<0>(entry) == key;
                     }) != key_boards.end() ||
                   std::find_if(
                     pending.begin(), pending.end(), [&](const auto& entry) {
                         return entry.key == key;
                     }) != pending.end();
        }

        void reset(This& parent) noexcept {
            key_boards.clear();
            pending.clear();
            solution_timeout.reset();

            parent.bus_node()
              .log_info("reset sudoku solution")
              .arg(EAGINE_ID(rank), S);
        }
    };

    data_compressor _compressor{};

    sudoku_rank_tuple<rank_info> _infos;
    bool _can_work{false};

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
class sudoku_tiles;
//------------------------------------------------------------------------------
/// @brief Class providing view to a solved fragment in sudoku_tiles.
/// @ingroup msgbus
/// @see sudoku_tiles
template <unsigned S>
class sudoku_fragment_view {
public:
    /// @brief The board/cell coordinate type.
    using Coord = std::tuple<int, int>;

    /// @brief Returns the width (in cells) of the tile.
    constexpr auto width() const noexcept -> int {
        return limit_cast<int>(S * (S - 2));
    }

    /// @brief Returns the height (in cells) of the tile.
    constexpr auto height() const noexcept -> int {
        return limit_cast<int>(S * (S - 2));
    }

    /// @brief Calls the specified function for each cell in the fragment.
    /// The function should have the following arguments:
    /// - std::tuple<int, int> the fragment coordinate (in cell units),
    /// - std::tuple<int, int> the cell offset within the fragment,
    /// - basic_sudoku_glyph<S> the glyph at the cell.
    template <typename Function>
    void for_each_cell(Function function) const;

private:
    friend class sudoku_tiles<S>;

    sudoku_fragment_view(
      const sudoku_tiles<S>& tiles,
      Coord board_coord) noexcept
      : _tiles{tiles}
      , _board_coord{std::move(board_coord)} {}

    const sudoku_tiles<S>& _tiles;
    Coord _board_coord;
};
//------------------------------------------------------------------------------
/// @brie Class representing a set of related Sudoku tiles.
/// @ingroup msgbus
/// @see sudoku_tiling
template <unsigned S>
class sudoku_tiles {
public:
    /// @brief The board coordinate/key type.
    using Coord = std::tuple<int, int>;

    /// @brief Returns the width (in cells) of the tiling.
    auto width() const noexcept -> int {
        return _maxu - _minu;
    }

    /// @brief Returns the height (in cells) of the tiling.
    auto height() const noexcept -> int {
        return _maxv - _minv;
    }

    /// @brief Get the board at the specified coordinate if it is solved.
    auto get_board(Coord coord) const noexcept -> const basic_sudoku_board<S>* {
        const auto pos = _boards.find(coord);
        if(pos != _boards.end()) {
            return &pos->second;
        }
        return nullptr;
    }

    /// @brief Get the board at the specified coordinate if it is solved.
    auto get_board(int x, int y) const noexcept {
        return get_board({x, y});
    }

    /// @brief Sets the board at the specified coordinate.
    auto set_board(Coord coord, basic_sudoku_board<S> board) -> bool {
        return _boards.try_emplace(std::move(coord), std::move(board)).second;
    }

    /// @brief Return a view of the fragment at the specified board coordinate.
    auto get_fragment(Coord coord) const noexcept -> sudoku_fragment_view<S> {
        return {*this, coord};
    }

    /// @brief Sets the extent (number of tiles in x and y dimension) of the tiling.
    void set_extent(Coord min, Coord max) noexcept {
        _minu = std::get<0>(min);
        _minv = std::get<1>(min);
        _maxu = std::get<0>(max);
        _maxv = std::get<1>(max);
    }

    /// @brief Sets the extent (number of tiles in x and y dimension) of the tiling.
    /// @see is_in_extent
    void set_extent(Coord max) noexcept {
        set_extent({0, 0}, max);
    }

    /// @brief Indicates in the specified coordinate is in the extent of this tiling.
    /// @see set_extent
    auto is_in_extent(int x, int y) const noexcept -> bool {
        const int u = x * S * (S - 2);
        const int v = y * S * (S - 2);
        return (u >= _minu) && (u < _maxu) && (v >= _minv) && (v < _maxv);
    }

    /// @brief Returns the extent between min and max in units of boards.
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

    /// @brief Returns the extent of this tiling in units of boards.
    auto boards_extent() const {
        return boards_extent({_minu, _minv}, {_maxu, _maxv});
    }

    /// @brief Indicates if the boards between the min and max coordinates are solved.
    auto are_complete(Coord min, Coord max) const -> bool {
        const auto [xmin, ymin, xmax, ymax] = boards_extent(min, max);
        for(const auto y : integer_range(ymin, ymax)) {
            for(const auto x : integer_range(xmin, xmax)) {
                if(!get_board(x, y)) {
                    return false;
                }
            }
        }
        return true;
    }

    /// @brief Indicates if the boards in this tiling's extent are solved.
    auto are_complete() const -> bool {
        return are_complete({_minu, _minv}, {_maxu, _maxv});
    }

    /// @brief Prints the current tiling using the specified sudoku board traits.
    auto print(
      std::ostream& out,
      Coord min,
      Coord max,
      const basic_sudoku_board_traits<S>& traits) const -> std::ostream& {
        const auto [xmin, ymin, xmax, ymax] = boards_extent(min, max);

        for(const auto y : integer_range(ymin, ymax)) {
            for(const auto by : integer_range(1U, S - 1U)) {
                for(const auto cy : integer_range(S)) {
                    for(const auto x : integer_range(xmin, xmax)) {
                        auto board = get_board(x, y);
                        for(const auto bx : integer_range(1U, S - 1U)) {
                            for(const auto cx : integer_range(S)) {
                                if(board) {
                                    traits.print(
                                      out,
                                      extract(board).get({bx, by, cx, cy}));
                                } else {
                                    traits.print_empty(out);
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

    /// @brief Shows which tiles are solved and which unsolved.
    auto print_progress(std::ostream& out, Coord min, Coord max) const
      -> std::ostream& {
        const auto [xmin, ymin, xmax, ymax] = boards_extent(min, max);

        for(const auto y : integer_range(ymin, ymax)) {
            for(const auto x : integer_range(xmin, xmax)) {
                if(get_board(x, y)) {
                    out << "██";
                } else {
                    out << "▒▒";
                }
            }
            out << '\n';
        }
        return out;
    }

    /// @brief Prints the current tiling using the specified sudoku board traits.
    auto print(std::ostream& out, Coord min, Coord max) const -> std::ostream& {
        return print(out, min, max, _traits);
    }

    /// @brief Prints the current tiling using the specified sudoku board traits.
    auto
    print(std::ostream& out, const basic_sudoku_board_traits<S>& traits) const
      -> auto& {
        return print(out, {_minu, _minv}, {_maxu, _maxv}, traits);
    }

    /// @brief Prints the current tiling using the specified sudoku board traits.
    auto print(std::ostream& out) const -> auto& {
        return print(out, {_minu, _minv}, {_maxu, _maxv});
    }

    /// @brief Shows which tiles are solved and which unsolved.
    auto print_progress(std::ostream& out) const -> auto& {
        return print_progress(out, {_minu, _minv}, {_maxu, _maxv});
    }

    /// @brief Resets all pending tilings.
    auto reset() noexcept -> auto& {
        _boards.clear();
        return *this;
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
template <unsigned S>
template <typename Function>
void sudoku_fragment_view<S>::for_each_cell(Function function) const {
    if(auto board{_tiles.get_board(_board_coord)}) {
        const auto [bx, by] = _board_coord;
        const Coord frag_coord{
          limit_cast<int>(bx * width()), limit_cast<int>(by * height())};
        for(const auto y : integer_range(height())) {
            for(const auto x : integer_range(width())) {
                const Coord cell_offset{x, y};
                std::array<unsigned, 4> cell_coord{
                  limit_cast<unsigned>(1 + x / S),
                  limit_cast<unsigned>(1 + y / S),
                  limit_cast<unsigned>(x % S),
                  limit_cast<unsigned>(y % S)};
                function(
                  frag_coord, cell_offset, extract(board).get(cell_coord));
            }
        }
    }
}
//------------------------------------------------------------------------------
/// @brief Service generating a sudoku tiling using helper message bus nodes.
/// @ingroup msgbus
/// @see service_composition
/// @see sudoku_helper
/// @see sudoku_solver
template <typename Base = subscriber>
class sudoku_tiling : public sudoku_solver<Base, std::tuple<int, int>> {
    using base = sudoku_solver<Base, std::tuple<int, int>>;
    using This = sudoku_tiling;
    using Coord = std::tuple<int, int>;

public:
    /// @brief Initializes the tiling to be generated with initial board.
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

    /// @brief Initializes the tiling to be generated with initial board.
    template <unsigned S>
    auto initialize(Coord max, basic_sudoku_board<S> board) -> auto& {
        return initialize({0, 0}, max, {0, 0}, std::move(board));
    }

    /// @brief Resets the tiling with the specified rank.
    template <unsigned S>
    auto reset(unsigned_constant<S> rank) -> auto& {
        base::reset(rank);
        _infos.get(rank).reset();
        return *this;
    }

    /// @brief Re-initializes the tiling with the specified board.
    template <unsigned S>
    auto reinitialize(Coord max, basic_sudoku_board<S> board) -> auto& {
        reset(unsigned_constant<S>{});
        return initialize(max, board);
    }

    /// @brief Indicates that pending tiling with the specified rank is complete.
    template <unsigned S>
    auto tiling_complete(unsigned_constant<S> rank) const noexcept -> bool {
        return _infos.get(rank).are_complete();
    }

    /// @brief Indicates that all pending tilings are complete.
    auto tiling_complete() const noexcept -> bool {
        bool result = true;
        sudoku_rank_tuple<unsigned_constant> ranks;
        for_each_sudoku_rank_unit(
          [&](auto rank) { result &= tiling_complete(rank); }, ranks);
        return result;
    }

    /// @brief Triggered then all tiles with rank 3 are generated.
    signal<void(const sudoku_tiles<3>&, const Coord&)> tiles_generated_3;
    /// @brief Triggered then all tiles with rank 4 are generated.
    signal<void(const sudoku_tiles<4>&, const Coord&)> tiles_generated_4;
    /// @brief Triggered then all tiles with rank 5 are generated.
    signal<void(const sudoku_tiles<5>&, const Coord&)> tiles_generated_5;
    /// @brief Triggered then all tiles with rank 6 are generated.
    signal<void(const sudoku_tiles<6>&, const Coord&)> tiles_generated_6;

    /// @brief Returns a reference to the tiles_generated_3 signal.
    /// @see tiles_generated_3
    auto tiles_generated_signal(unsigned_constant<3>) noexcept -> auto& {
        return tiles_generated_3;
    }

    /// @brief Returns a reference to the tiles_generated_4 signal.
    /// @see tiles_generated_4
    auto tiles_generated_signal(unsigned_constant<4>) noexcept -> auto& {
        return tiles_generated_4;
    }

    /// @brief Returns a reference to the tiles_generated_5 signal.
    /// @see tiles_generated_5
    auto tiles_generated_signal(unsigned_constant<5>) noexcept -> auto& {
        return tiles_generated_5;
    }

    /// @brief Returns a reference to the tiles_generated_6 signal.
    /// @see tiles_generated_6
    auto tiles_generated_signal(unsigned_constant<6>) noexcept -> auto& {
        return tiles_generated_6;
    }

    /// @brief Logs the contributions of the helpers to the solution.
    template <unsigned S>
    auto log_contribution_histogram(unsigned_constant<S> rank) -> auto& {
        _infos.get(rank).log_contribution_histogram(*this);
        return *this;
    }

protected:
    sudoku_tiling(endpoint& bus)
      : base{bus} {
        this->solved_3.connect(
          EAGINE_THIS_MEM_FUNC_REF(template _handle_solved<3>));
        this->solved_4.connect(
          EAGINE_THIS_MEM_FUNC_REF(template _handle_solved<4>));
        this->solved_5.connect(
          EAGINE_THIS_MEM_FUNC_REF(template _handle_solved<5>));
        this->solved_6.connect(
          EAGINE_THIS_MEM_FUNC_REF(template _handle_solved<6>));
    }

private:
    template <unsigned S>
    struct rank_info : sudoku_tiles<S> {

        void
        initialize(This& solver, int x, int y, basic_sudoku_board<S> board) {
            solver.enqueue({x, y}, std::move(board));
            solver.bus_node()
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
                        for(const auto by : integer_range(S - 1U)) {
                            board.set_block(
                              0U, by, extract(left).get_block(S - 1U, by));
                        }
                        for(const auto bx : integer_range(1U, S)) {
                            board.set_block(
                              bx, S - 1U, extract(down).get_block(bx, 0U));
                        }
                        should_enqueue = true;
                    }
                } else if(x < 0) {
                    auto right = this->get_board(x + 1, y);
                    auto down = this->get_board(x, y - 1);
                    if(right && down) {
                        for(const auto by : integer_range(S - 1U)) {
                            board.set_block(
                              S - 1U, by, extract(right).get_block(0U, by));
                        }
                        for(const auto bx : integer_range(S - 1U)) {
                            board.set_block(
                              bx, S - 1U, extract(down).get_block(bx, 0U));
                        }
                        should_enqueue = true;
                    }
                } else {
                    auto down = this->get_board(x, y - 1);
                    if(down) {
                        for(const auto bx : integer_range(S)) {
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
                        for(const auto by : integer_range(1U, S)) {
                            board.set_block(
                              0U, by, extract(left).get_block(S - 1U, by));
                        }
                        for(const auto bx : integer_range(1U, S)) {
                            board.set_block(
                              bx, 0U, extract(up).get_block(bx, S - 1U));
                        }
                        should_enqueue = true;
                    }
                } else if(x < 0) {
                    auto right = this->get_board(x + 1, y);
                    auto up = this->get_board(x, y + 1);
                    if(right && up) {
                        for(const auto by : integer_range(1U, S)) {
                            board.set_block(
                              S - 1U, by, extract(right).get_block(0U, by));
                        }
                        for(const auto bx : integer_range(S - 1U)) {
                            board.set_block(
                              bx, 0U, extract(up).get_block(bx, S - 1U));
                        }
                        should_enqueue = true;
                    }
                } else {
                    auto up = this->get_board(x, y + 1);
                    if(up) {
                        for(const auto bx : integer_range(S)) {
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
                        for(const auto by : integer_range(S)) {
                            board.set_block(
                              0U, by, extract(left).get_block(S - 1U, by));
                        }
                        should_enqueue = true;
                    }
                } else if(x < 0) {
                    auto right = this->get_board(x + 1, y);
                    if(right) {
                        for(const auto by : integer_range(S)) {
                            board.set_block(
                              S - 1U, by, extract(right).get_block(0U, by));
                        }
                        should_enqueue = true;
                    }
                }
            }
            if(should_enqueue) {
                solver.enqueue({x, y}, board.calculate_alternatives());
                solver.bus_node()
                  .log_debug("enqueuing board (${x}, ${y})")
                  .arg(EAGINE_ID(x), x)
                  .arg(EAGINE_ID(y), y)
                  .arg(EAGINE_ID(rank), S);
            }
        }

        void enqueue_incomplete(This& solver) {
            const unsigned_constant<S> rank{};
            const auto [xmin, ymin, xmax, ymax] = this->boards_extent();
            for(const auto y : integer_range(ymin, ymax)) {
                for(const auto x : integer_range(xmin, xmax)) {
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
                solver.bus_node()
                  .log_info("solved board (${x}, ${y})")
                  .arg(EAGINE_ID(rank), S)
                  .arg(EAGINE_ID(x), std::get<0>(coord))
                  .arg(EAGINE_ID(y), std::get<1>(coord))
                  .arg(EAGINE_ID(helper), helper_id);

                auto helper_pos = helper_contrib.find(helper_id);
                if(helper_pos == helper_contrib.end()) {
                    helper_pos = helper_contrib.emplace(helper_id, 0).first;
                }
                ++helper_pos->second;

                const unsigned_constant<S> rank{};
                solver.tiles_generated_signal(rank)(*this, coord);
            }

            enqueue_incomplete(solver);
        }

        void log_contribution_histogram(This& solver) {
            span_size_t max_count = 0;
            for(const auto& p : helper_contrib) {
                max_count = std::max(max_count, std::get<1>(p));
            }
            solver.bus_node()
              .log_stat("solution contributions by helpers")
              .arg(EAGINE_ID(rank), S)
              .arg_func([this, max_count](logger_backend& backend) {
                  for(const auto& [helper_id, count] : helper_contrib) {
                      backend.add_float(
                        EAGINE_ID(helper),
                        EAGINE_ID(Histogram),
                        float(0),
                        float(count),
                        float(max_count));
                  }
              });
        }

        flat_map<identifier_t, span_size_t> helper_contrib;
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

    template <unsigned S>
    void _handle_solved(
      identifier_t helper_id,
      const Coord& coord,
      basic_sudoku_board<S>& board) {
        auto& info = _infos.get(unsigned_constant<S>{});
        info.handle_solved(*this, helper_id, coord, std::move(board));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SUDOKU_HPP
