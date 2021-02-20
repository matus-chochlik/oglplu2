/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_BUFFER_POOL_HPP
#define EAGINE_MEMORY_BUFFER_POOL_HPP

#include "buffer.hpp"
#include <algorithm>
#include <vector>

namespace eagine::memory {
//------------------------------------------------------------------------------
/// @brief Class storing multiple reusable memory buffer instances.
/// @ingroup memory
/// @see buffer
class buffer_pool {
public:
    /// @brief Gets a buffer with the specified required size.
    /// @param req_size The returned buffer will have at least this number of bytes.
    /// @see eat
    auto get(span_size_t req_size = 0) -> memory::buffer {
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

    /// @brief Returns the specified buffer back to the pool for further reuse.
    /// @see get
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
