/**
 *  @file eagine/utils/buffer_data.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_BUFFER_DATA_HPP
#define EAGINE_BUFFER_DATA_HPP

#include "buffer_size.hpp"
#include "memory/block.hpp"
#include "types.hpp"

namespace eagine {

template <typename S>
class buffer_data_spec {
private:
    buffer_size<S> _size;
    const void* _data{nullptr};

public:
    buffer_data_spec() noexcept
      : _size() {}

    buffer_data_spec(const memory::block& blk) noexcept
      : _size(S(blk.size()))
      , _data(blk.data()) {}

    template <typename T, span_size_t N>
    buffer_data_spec(const T (&data)[N]) noexcept
      : _size(identity<T>(), N)
      , _data(static_cast<const void*>(data)) {}

    template <typename T>
    buffer_data_spec(const T* data, span_size_t n) noexcept
      : _size(identity<T>(), n)
      , _data(data) {}

    template <typename T>
    buffer_data_spec(span<T> av) noexcept
      : _size(av)
      , _data(av.data()) {}

    bool empty() const noexcept {
        return _size.get() == 0;
    }

    buffer_size<S> size() const noexcept {
        return _size;
    }

    const void* data() const noexcept {
        return _data;
    }

    span<const byte> view() const noexcept {
        return {
          static_cast<const byte*>(_data), static_cast<std::ptrdiff_t>(_size)};
    }
};

} // namespace eagine

#endif // EAGINE_BUFFER_DATA_HPP
