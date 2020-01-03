/**
 *  @file eagine/serialize/read_backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_READ_BACKEND_HPP
#define EAGINE_SERIALIZE_READ_BACKEND_HPP

#include "data_source.hpp"
#include "result.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
struct deserializer_backend {
    deserializer_backend() noexcept = default;
    deserializer_backend(deserializer_backend&&) noexcept = default;
    deserializer_backend(const deserializer_backend&) = delete;
    deserializer_backend& operator=(deserializer_backend&&) = delete;
    deserializer_backend& operator=(const deserializer_backend&) = delete;

    virtual ~deserializer_backend() noexcept = default;

    using result = deserialization_result;

    virtual result start() = 0;
    virtual result read(span<bool>, span_size_t&) = 0;
    virtual result read(span<char>, span_size_t&) = 0;
    virtual result read(span<std::int16_t>, span_size_t&) = 0;
    virtual result read(span<std::int32_t>, span_size_t&) = 0;
    virtual result read(span<std::int64_t>, span_size_t&) = 0;
    virtual result read(span<std::uint8_t>, span_size_t&) = 0;
    virtual result read(span<std::uint16_t>, span_size_t&) = 0;
    virtual result read(span<std::uint32_t>, span_size_t&) = 0;
    virtual result read(span<std::uint64_t>, span_size_t&) = 0;
    virtual result read(span<float>, span_size_t&) = 0;
    virtual result read(span<double>, span_size_t&) = 0;
    virtual result read(span<std::string>, span_size_t&) = 0;
    virtual result begin_struct(span_size_t& member_count) = 0;
    virtual result begin_member(string_view name) = 0;
    virtual result finish_member(string_view name) = 0;
    virtual result finish_struct() = 0;
    virtual result begin_list(span_size_t& element_count) = 0;
    virtual result begin_element(span_size_t index) = 0;
    virtual result finish_element(span_size_t index) = 0;
    virtual result finish_list() = 0;
    virtual result finish() = 0;
};
//------------------------------------------------------------------------------
template <typename Derived, typename Source = deserializer_data_source>
class common_deserializer_backend : public deserializer_backend {
public:
    common_deserializer_backend() noexcept = default;
    common_deserializer_backend(Source& source) noexcept
      : _source{&source} {
    }

    using error_code = deserialization_error_code;
    using result = deserialization_result;

    result start() override {
        return {};
    }

    result read(span<bool> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<char> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::int16_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::int32_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::int64_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::uint8_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::uint16_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::uint32_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::uint64_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<float> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<double> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::string> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result begin_struct(span_size_t&) override {
        return {};
    }
    result begin_member(string_view) override {
        return {};
    }
    result finish_member(string_view) override {
        return {};
    }
    result finish_struct() override {
        return {};
    }
    result begin_list(span_size_t&) override {
        return {};
    }
    result begin_element(span_size_t) override {
        return {};
    }
    result finish_element(span_size_t) override {
        return {};
    }
    result finish_list() override {
        return {};
    }
    result finish() override {
        return {};
    }

protected:
    valid_if_nonnegative<span_size_t> scan_for(
      byte what, valid_if_positive<span_size_t> step = {256}) {
        EAGINE_ASSERT(_source);
        return _source->scan_for(what, step);
    }

    memory::const_block top(span_size_t size) {
        EAGINE_ASSERT(_source);
        return _source->top(size);
    }

    void pop(span_size_t size) {
        EAGINE_ASSERT(_source);
        _source->pop(size);
    }

private:
    Source* _source{nullptr};

    Derived& derived() noexcept {
        return *static_cast<Derived*>(this);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_READ_BACKEND_HPP

