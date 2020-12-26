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
        const unsigned_constant<S> rank{};
        _boards.get(rank).emplace_back(std::move(key), std::move(board));
        return *this;
    }

    auto is_done() -> bool {
        bool has_work = false;
        for_each_sudoku_rank_unit(
          [&](const auto& pending, const auto& boards) {
              has_work |= !pending.empty() || !boards.empty();
          },
          _pending,
          _boards);

        return !has_work;
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(Base::update());

        // move timeouted pending boards back to board stack
        for_each_sudoku_rank_unit(
          [&](auto& pending, auto& boards) {
              pending.erase(
                std::remove_if(
                  pending.begin(),
                  pending.end(),
                  [&](auto& entry) {
                      auto& [seq_no, key, board, too_late] = entry;
                      EAGINE_MAYBE_UNUSED(seq_no);

                      if(too_late) {
                          boards.emplace_back(std::move(key), std::move(board));
                          something_done();
                          return true;
                      }
                      return false;
                  }),
                pending.end());
          },
          _pending,
          _boards);

        // search for ready helpers
        for_each_sudoku_rank_unit(
          [&](auto rank, auto& search_timeout, auto& boards) {
              if(!boards.empty()) {
                  if(search_timeout) {
                      this->bus().broadcast(sudoku_search_msg(rank));
                      search_timeout.reset();
                      something_done();
                  }
              }
          },
          _ranks,
          _search_timeouts,
          _boards);

        return something_done;
    }

    virtual void on_solved(const Key&, basic_sudoku_board<2>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<3>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<4>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<5>&) {}
    virtual void on_solved(const Key&, basic_sudoku_board<6>&) {}

private:
    sudoku_rank_tuple<unsigned_constant> _ranks;
    sudoku_rank_tuple<default_sudoku_board_traits> _traits;

    template <unsigned S>
    using _board_stack = std::vector<std::tuple<Key, basic_sudoku_board<S>>>;
    sudoku_rank_tuple<_board_stack> _boards;

    template <unsigned S>
    using _query_seq = message_sequence_t;
    sudoku_rank_tuple<_query_seq> _query_sequences{0U};

    template <unsigned S>
    using _pending_list = std::vector<
      std::tuple<message_sequence_t, Key, basic_sudoku_board<S>, timeout>>;
    sudoku_rank_tuple<_pending_list> _pending;

    template <unsigned S>
    using _search_timeout = timeout;
    sudoku_rank_tuple<_search_timeout> _search_timeouts{
      std::chrono::milliseconds(250),
      nothing};

    template <unsigned S>
    auto _handle_ready(const message_context& msg_ctx, stored_message& message)
      -> bool {
        const unsigned_constant<S> rank{};
        auto& boards = _boards.get(rank);
        auto& pending = _pending.get(rank);

        if(!boards.empty()) {
            _search_timeouts.get(rank).reset();

            auto& [key, board] = boards.back();
            auto temp{default_serialize_buffer_for(board)};
            auto serialized{default_serialize(board, cover(temp))};
            EAGINE_ASSERT(serialized);

            const auto query_seq_no = _query_sequences.get(rank)++;
            message_view response{extract(serialized)};
            response.setup_response(message);
            response.set_sequence_no(query_seq_no);
            msg_ctx.bus().post(sudoku_query_msg(rank), response);

            pending.emplace_back(
              query_seq_no,
              std::move(key),
              std::move(board),
              std::chrono::seconds(S * S));
            boards.pop_back();
        }
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
        const unsigned_constant<S> rank{};
        basic_sudoku_board<S> board{_traits.get(rank)};

        if(default_deserialize(board, message.content())) {
            auto& pending = _pending.get(rank);
            const auto pos = std::find_if(
              pending.begin(), pending.end(), [&](const auto& entry) {
                  return std::get<0>(entry) == message.sequence_no;
              });

            if(pos != pending.end()) {
                auto& boards = _boards.get(rank);
                auto& key = std::get<1>(*pos);

                if(msg_ctx.msg_id() == sudoku_solved_msg(rank)) {
                    EAGINE_ASSERT(board.is_solved());
                    boards.erase(
                      std::remove_if(
                        boards.begin(),
                        boards.end(),
                        [&](const auto& entry) {
                            return key == std::get<0>(entry);
                        }),
                      boards.end());
                    on_solved(key, board);
                } else {
                    std::get<3>(*pos).reset();
                    boards.emplace_back(key, std::move(board));
                }
            }
        }
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
        const unsigned_constant<S> rank{};
        auto& pending = _pending.get(rank);
        const auto pos =
          std::find_if(pending.begin(), pending.end(), [&](const auto& entry) {
              return std::get<0>(entry) == message.sequence_no;
          });
        if(pos != pending.end()) {
            pending.erase(pos);
        }
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
