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

#include "../identifier.hpp"
#include "../reflect/decl_name.hpp"
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

    using result = deserialization_errors;

    virtual identifier type_id() = 0;
    virtual deserializer_data_source* source() = 0;
    virtual bool enum_as_string() = 0;

    virtual result begin() = 0;
    virtual result read(span<bool>, span_size_t&) = 0;
    virtual result read(span<char>, span_size_t&) = 0;
    virtual result read(span<std::int8_t>, span_size_t&) = 0;
    virtual result read(span<short>, span_size_t&) = 0;
    virtual result read(span<int>, span_size_t&) = 0;
    virtual result read(span<long>, span_size_t&) = 0;
    virtual result read(span<long long>, span_size_t&) = 0;
    virtual result read(span<std::uint8_t>, span_size_t&) = 0;
    virtual result read(span<unsigned short>, span_size_t&) = 0;
    virtual result read(span<unsigned>, span_size_t&) = 0;
    virtual result read(span<unsigned long>, span_size_t&) = 0;
    virtual result read(span<unsigned long long>, span_size_t&) = 0;
    virtual result read(span<float>, span_size_t&) = 0;
    virtual result read(span<double>, span_size_t&) = 0;
    virtual result read(span<identifier>, span_size_t&) = 0;
    virtual result read(span<decl_name_storage>, span_size_t&) = 0;
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

    Derived& set_source(Source& s) noexcept {
        _source = &s;
        return derived();
    }

    using error_code = deserialization_error_code;
    using result = deserialization_errors;

    deserializer_data_source* source() final {
        return _source;
    }

    bool enum_as_string() override {
        return false;
    }

    result begin() override {
        return {};
    }

    result read(span<bool> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<char> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::int8_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<short> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<int> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<long> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<long long> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<std::uint8_t> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<unsigned short> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<unsigned> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<unsigned long> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<unsigned long long> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<float> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<double> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<identifier> values, span_size_t& done) override {
        return derived().do_read(values, done);
    }

    result read(span<decl_name_storage> values, span_size_t& done) override {
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
      byte what,
      const valid_if_positive<span_size_t>& max,
      const valid_if_positive<span_size_t>& step = {256}) {
        EAGINE_ASSERT(_source);
        return _source->scan_for(what, max, step);
    }

    memory::const_block top(span_size_t size) {
        EAGINE_ASSERT(_source);
        return _source->top(size);
    }

    auto top_string(span_size_t size) {
        return as_chars(top(size));
    }

    auto string_before(
      char c,
      const valid_if_positive<span_size_t>& max,
      const valid_if_positive<span_size_t>& step = {256}) {
        auto found = scan_for(byte(c), max, step);
        return top_string(extract_or(found, 0));
    }

    auto top_char() {
        return top_string(1);
    }

    void pop(span_size_t size) {
        EAGINE_ASSERT(_source);
        _source->pop(size);
    }

    bool starts_with(string_view what) {
        return are_equal(top_string(what.size()), what);
    }

    bool starts_with(char c) {
        return starts_with(view_one(c));
    }

    bool consume(string_view what, result& errors) {
        errors = {};
        auto top_str = top_string(what.size());
        if(top_str.size() < what.size()) {
            errors |= error_code::not_enough_data;
        } else {
            if(are_equal(top_str, what)) {
                pop(what.size());
                return true;
            } else {
                errors |= error_code::unexpected_data;
            }
        }
        return false;
    }

    bool consume(char what, result& errors) {
        return consume(view_one(what), errors);
    }

    template <typename Function>
    void consume_until(
      Function predicate, const valid_if_positive<span_size_t> step = {256}) {
        while(auto pos = _source->scan_until(predicate, step, step)) {
            if(extract(pos) > 0) {
                pop(extract(pos));
            } else {
                break;
            }
        }
    }

    result require(string_view what) {
        result errors{};
        auto top_str = top_string(what.size());
        if(top_str.size() < what.size()) {
            errors |= error_code::not_enough_data;
        } else {
            if(are_equal(top_str, what)) {
                pop(what.size());
            } else {
                errors |= error_code::invalid_format;
            }
        }

        return errors;
    }

    result require(char what) {
        return require(view_one(what));
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

