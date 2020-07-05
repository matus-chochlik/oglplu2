/**
 *  @file eagine/memory/buffer_pool.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BUFFER_POOL_HPP
#define EAGINE_MEMORY_BUFFER_POOL_HPP

#include "buffer.hpp"
#include <algorithm>
#include <vector>

namespace eagine::memory {
//------------------------------------------------------------------------------
class buffer_pool {
public:
    memory::buffer get(span_size_t req_size = 0) {
        auto pos = std::lower_bound(
          _pool.begin(), _pool.end(), req_size, [](auto& buf, auto req) {
              return buf.capacity() < req;
          });
        if(pos != _pool.end()) {
            memory::buffer result{std::move(*pos)};
            _pool.erase(pos);
            result.resize(req_size);
            return result;
        }
        memory::buffer result{};
        result.resize(req_size);
        return result;
    }

    void eat(memory::buffer used) {
        auto pos = std::lower_bound(
          _pool.begin(),
          _pool.end(),
          used.capacity(),
          [](auto& buf, auto capacity) { return buf.capacity() < capacity; });
        _pool.emplace(pos, std::move(used));
    }

private:
    std::vector<memory::buffer> _pool;
};
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_BUFFER_POOL_HPP
