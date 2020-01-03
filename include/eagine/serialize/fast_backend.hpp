/**
 *  @file eagine/serialize/fast_backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_FAST_BACKEND_HPP
#define EAGINE_SERIALIZE_FAST_BACKEND_HPP

#include "read_backend.hpp"
#include "write_backend.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class fast_serializer_backend
  : public common_serializer_backend<fast_serializer_backend> {
    using base = common_serializer_backend<fast_serializer_backend>;

public:
    using base::base;
    using base::remaining_size;
    using base::sink;
    using error_code = serialization_error_code;
    using result = serialization_result;

    template <typename T>
    result do_write(span<const T> values, span_size_t& done) {
        result errors{};
        const span_size_t remaining = remaining_size();
        span_size_t can_do = remaining / span_size_t(sizeof(T));
        if(can_do < values.size()) {
            values = head(values, can_do);
            errors |= serialization_error_code::incomplete_write;
        } else {
            can_do = values.size();
        }
        errors |= sink(as_bytes(values));
        done = can_do;
        return errors;
    }

    result do_write(span<const string_view> values, span_size_t& done) {
        done = 0;
        serialization_result errors{};
        for(auto& str : values) {
            span_size_t written{0};
            errors |= do_write(view_one(str.size()), written);
            if(errors) {
                return errors;
            }
            sink(str);
            done += written;
        }
        return errors;
    }

    result begin_struct(span_size_t size) final {
        span_size_t written{0};
        return do_write(view_one(size), written);
    }

    result begin_list(span_size_t size) final {
        span_size_t written{0};
        return do_write(view_one(size), written);
    }
};
//------------------------------------------------------------------------------
class fast_deserializer_backend
  : public common_deserializer_backend<fast_deserializer_backend> {
    using base = common_deserializer_backend<fast_deserializer_backend>;

public:
    using base::base;
    using base::pop;
    using base::top;
    using error_code = deserialization_error_code;
    using result = deserialization_result;

    template <typename T>
    result do_read(span<T> values) {
        auto dst = as_bytes(values);
        auto src = top(dst.size());
        if(dst.size() != src.size()) {
            EAGINE_ASSERT(src.size() < dst.size());
            return {error_code::not_enough_data};
        }
        memory::copy(src, dst);
        pop(dst.size());
        return {};
    }

    result do_read(span<std::string> values) {
        for(auto& str : values) {
            span_size_t size{0};
            do_read(cover_one(size));
            auto src = memory::accomodate<const char>(top(size));
            if(src.size() != size) {
                EAGINE_ASSERT(src.size() < size);
                return {error_code::not_enough_data};
            }
            str.assign(src.data(), std::size_t(src.size()));
            pop(size);
        }
        return {};
    }

    result begin_struct(span_size_t& size) final {
        return do_read(cover_one(size));
    }

    result begin_list(span_size_t& size) final {
        return do_read(cover_one(size));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_FAST_BACKEND_HPP

