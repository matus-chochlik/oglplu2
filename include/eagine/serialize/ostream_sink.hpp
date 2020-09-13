/**
 *  @file eagine/serialize/ostream_sink.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_OSTREAM_SINK_HPP
#define EAGINE_SERIALIZE_OSTREAM_SINK_HPP

#include "data_sink.hpp"
#include <limits>
#include <ostream>
#include <sstream>
#include <stack>

namespace eagine {
//------------------------------------------------------------------------------
class ostream_data_sink : public serializer_data_sink {
public:
    ostream_data_sink(std::ostream& out) noexcept
      : _out{out} {}

    span_size_t remaining_size() final {
        return std::numeric_limits<span_size_t>::max();
    }

    using serializer_data_sink::write;

    serialization_errors write(memory::const_block blk) final {
        current().write(
          reinterpret_cast<const char*>(blk.data()),
          static_cast<std::streamsize>(blk.size()));
        if(current().eof()) {
            return {serialization_error_code::too_much_data};
        }
        if(!current().good()) {
            return {serialization_error_code::data_sink_error};
        }
        return {};
    }

    transaction_handle begin_work() final {
        _subs.emplace();
        return transaction_handle(_subs.size());
    }

    void commit(transaction_handle th) final {
        EAGINE_ASSERT(th == transaction_handle(_subs.size()));
        EAGINE_MAYBE_UNUSED(th);
        std::stringstream top{std::move(_subs.top())};
        _subs.pop();
        current() << top.rdbuf();
    }

    void rollback(transaction_handle th) final {
        EAGINE_ASSERT(th == transaction_handle(_subs.size()));
        EAGINE_MAYBE_UNUSED(th);
        _subs.pop();
    }

private:
    std::ostream& current() noexcept {
        if(_subs.empty()) {
            return _out;
        }
        return _subs.top();
    }

    std::ostream& _out;
    std::stack<std::stringstream> _subs;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_OSTREAM_SINK_HPP
