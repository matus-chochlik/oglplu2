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
#include "../../maybe_unused.hpp"
#include "../../serialize/type/sudoku.hpp"
#include "../../sudoku.hpp"
#include "../serialize.hpp"
#include "../subscriber.hpp"
#include <algorithm>
#include <chrono>
#include <tuple>
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <template <unsigned> class U>
struct sudoku_rank_tuple
  : std::tuple<nothing_t, nothing_t, U<2>, U<3>, U<4>, U<5>, U<6>> {
    using base = std::tuple<nothing_t, nothing_t, U<2>, U<3>, U<4>, U<5>, U<6>>;

    sudoku_rank_tuple() = default;

    template <typename... Args>
    sudoku_rank_tuple(const Args&... args)
      : base{
          nothing,
          nothing,
          {args...},
          {args...},
          {args...},
          {args...},
          {args...}} {}

    template <unsigned S>
    auto get(unsigned_constant<S>) noexcept -> auto& {
        return std::get<S>(*this);
    }
};
//------------------------------------------------------------------------------
template <typename Function, typename... RankTuple>
static inline void for_each_sudoku_rank_unit(Function func, RankTuple&... t) {
    func(std::get<2>(t)...);
    func(std::get<3>(t)...);
    func(std::get<4>(t)...);
    func(std::get<5>(t)...);
    func(std::get<6>(t)...);
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_search_msg(unsigned_constant<S>) noexcept {
    if constexpr(S == 2) {
        return EAGINE_MSG_ID(eagiSudoku, search2);
    }
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
static inline auto sudoku_ready_msg(unsigned_constant<S>) noexcept {
    if constexpr(S == 2) {
        return EAGINE_MSG_ID(eagiSudoku, ready2);
    }
    if constexpr(S == 3) {
        return EAGINE_MSG_ID(eagiSudoku, ready3);
    }
    if constexpr(S == 4) {
        return EAGINE_MSG_ID(eagiSudoku, ready4);
    }
    if constexpr(S == 5) {
        return EAGINE_MSG_ID(eagiSudoku, ready5);
    }
    if constexpr(S == 6) {
        return EAGINE_MSG_ID(eagiSudoku, ready6);
    }
}
//------------------------------------------------------------------------------
template <unsigned S>
static inline auto sudoku_query_msg(unsigned_constant<S>) noexcept {
    if constexpr(S == 2) {
        return EAGINE_MSG_ID(eagiSudoku, query2);
    }
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
    if constexpr(S == 2) {
        return EAGINE_MSG_ID(eagiSudoku, solved2);
    }
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
    if constexpr(S == 2) {
        return EAGINE_MSG_ID(eagiSudoku, candidate2);
    }
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
    if constexpr(S == 2) {
        return EAGINE_MSG_ID(eagiSudoku, done2);
    }
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

        for_each_sudoku_rank_unit(
          [&](auto rank) {
              Base::add_method(this, _bind_handle_search(rank));
              Base::add_method(this, _bind_handle_board(rank));
          },
          _ranks);
    }

private:
    template <unsigned S>
    auto _handle_search(const message_context& msg_ctx, stored_message& message)
      -> bool {
        const unsigned_constant<S> rank{};
        msg_ctx.bus().respond_to(message, sudoku_ready_msg(rank));
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
    auto _handle_board(const message_context& msg_ctx, stored_message& message)
      -> bool {
        const unsigned_constant<S> rank{};
        basic_sudoku_board<S> board{_traits.get(rank)};

        if(default_deserialize(board, message.content())) {
            board.for_each_alternative(
              board.find_unsolved(), [&](auto& intermediate) {
                  intermediate.for_each_alternative(
                    intermediate.find_unsolved(), [&](auto& candidate) {
                        auto temp{default_serialize_buffer_for(candidate)};
                        auto serialized{
                          default_serialize(candidate, cover(temp))};
                        EAGINE_ASSERT(serialized);

                        msg_ctx.bus().respond_to(
                          message,
                          sudoku_response_msg(rank, candidate.is_solved()),
                          {extract(serialized)});
                    });
              });
            msg_ctx.bus().respond_to(message, sudoku_done_msg(rank));
            msg_ctx.bus().respond_to(message, sudoku_ready_msg(rank));
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

    sudoku_rank_tuple<unsigned_constant> _ranks;
    sudoku_rank_tuple<default_sudoku_board_traits> _traits;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber, typename Key = int>
class sudoku_solver : public Base {
    using This = sudoku_solver;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        for_each_sudoku_rank_unit(
          [&](auto rank) {
              Base::add_method(this, _bind_handle_ready(rank));
              Base::add_method(this, _bind_handle_candidate(rank));
              Base::add_method(this, _bind_handle_solved(rank));
              Base::add_method(this, _bind_handle_done(rank));
          },
          _ranks);
    }

public:
    template <unsigned S>
    auto enqueue(Key key, basic_sudoku_board<S> board) -> auto& {
        _infos.get(unsigned_constant<S>{})
          .boards.emplace_back(std::move(key), std::move(board));
        return *this;
    }

    auto is_done() -> bool {
        bool has_work = false;
        for_each_sudoku_rank_unit(
          [&](const auto& info) { has_work |= info.has_work(); }, _infos);

        return !has_work;
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(Base::update());

        for_each_sudoku_rank_unit(
          [&](auto& info) {
              something_done(info.handle_timeouted());
              something_done(info.send_boards(this->bus()));
              something_done(info.search_helpers(this->bus()));
          },
          _infos);

        return something_done;
    }

    virtual void on_solved(const Key&, basic_sudoku_board<2>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<3>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<4>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<5>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<6>&) {}

private:
    sudoku_rank_tuple<unsigned_constant> _ranks;

    template <unsigned S>
    struct rank_info {
        message_sequence_t query_sequence{0};
        default_sudoku_board_traits<S> traits;
        timeout search_timeout{std::chrono::seconds(2)};

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

        auto has_work() const noexcept {
            return !boards.empty() || !pending.empty();
        }

        auto search_helpers(endpoint& bus) -> bool {
            some_true something_done;
            if(ready_helpers.empty() || search_timeout) {
                bus.broadcast(sudoku_search_msg(unsigned_constant<S>{}));
                search_timeout.reset();
                something_done();
            }
            return something_done;
        }

        auto handle_timeouted() -> bool {
            some_true something_done;
            pending.erase(
              std::remove_if(
                pending.begin(),
                pending.end(),
                [&](auto& entry) {
                    if(entry.too_late) {
                        used_helpers.erase(entry.used_helper);
                        boards.emplace_back(
                          std::move(entry.key), std::move(entry.board));
                        something_done();
                        return true;
                    }
                    return false;
                }),
              pending.end());
            return something_done;
        }

        void handle_response(
          This& parent,
          message_id msg_id,
          stored_message& message) {
            const unsigned_constant<S> rank{};
            basic_sudoku_board<S> board{traits};

            if(default_deserialize(board, message.content())) {
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
                        parent.on_solved(pos->key, board);
                    } else {
                        boards.emplace_back(pos->key, std::move(board));
                    }
                    pos->too_late.reset();
                }
            }
        }

        auto send_boards(endpoint& bus) -> bool {
            const unsigned_constant<S> rank{};
            some_true something_done;

            while(!boards.empty() && !ready_helpers.empty()) {
                const auto pos = ready_helpers.begin();

                auto& [key, board] = boards.back();
                auto temp{default_serialize_buffer_for(board)};
                auto serialized{default_serialize(board, cover(temp))};
                EAGINE_ASSERT(serialized);

                const auto sequence_no = query_sequence++;
                message_view response{extract(serialized)};
                response.set_target_id(*pos);
                response.set_sequence_no(sequence_no);
                bus.post(sudoku_query_msg(rank), response);

                auto& query = pending.emplace_back(std::move(board));
                query.used_helper = *pos;
                query.sequence_no = sequence_no;
                query.key = std::move(key);
                query.too_late.reset(std::chrono::seconds(S * S));
                boards.pop_back();

                used_helpers.insert(*pos);
                ready_helpers.erase(pos);
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

        void ready_helper(identifier_t id) {
            if(used_helpers.find(id) == used_helpers.end()) {
                ready_helpers.insert(id);
            }
        }
    };

    sudoku_rank_tuple<rank_info> _infos;

    template <unsigned S>
    auto _handle_ready(const message_context&, stored_message& message)
      -> bool {
        _infos.get(unsigned_constant<S>{}).ready_helper(message.source_id);
        return true;
    }

    template <unsigned S>
    static constexpr auto
    _bind_handle_ready(unsigned_constant<S> rank) noexcept {
        return message_handler_map<member_function_constant<
          bool (This::*)(const message_context&, stored_message&),
          &This::_handle_ready<S>>>{sudoku_ready_msg(rank)};
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
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SUDOKU_HPP
