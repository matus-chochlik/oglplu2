/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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
    auto operator=(deserializer_backend&&) = delete;
    auto operator=(const deserializer_backend&) = delete;

    virtual ~deserializer_backend() noexcept = default;

    using result = deserialization_errors;

    virtual auto type_id() -> identifier = 0;
    virtual auto source() -> deserializer_data_source* = 0;
    virtual auto enum_as_string() -> bool = 0;

    virtual auto begin() -> result = 0;
    virtual auto read(span<bool>, span_size_t&) -> result = 0;
    virtual auto read(span<char>, span_size_t&) -> result = 0;
    virtual auto read(span<std::int8_t>, span_size_t&) -> result = 0;
    virtual auto read(span<short>, span_size_t&) -> result = 0;
    virtual auto read(span<int>, span_size_t&) -> result = 0;
    virtual auto read(span<long>, span_size_t&) -> result = 0;
    virtual auto read(span<long long>, span_size_t&) -> result = 0;
    virtual auto read(span<std::uint8_t>, span_size_t&) -> result = 0;
    virtual auto read(span<unsigned short>, span_size_t&) -> result = 0;
    virtual auto read(span<unsigned>, span_size_t&) -> result = 0;
    virtual auto read(span<unsigned long>, span_size_t&) -> result = 0;
    virtual auto read(span<unsigned long long>, span_size_t&) -> result = 0;
    virtual auto read(span<float>, span_size_t&) -> result = 0;
    virtual auto read(span<double>, span_size_t&) -> result = 0;
    virtual auto read(span<identifier>, span_size_t&) -> result = 0;
    virtual auto read(span<decl_name_storage>, span_size_t&) -> result = 0;
    virtual auto read(span<std::string>, span_size_t&) -> result = 0;
    virtual auto begin_struct(span_size_t& member_count) -> result = 0;
    virtual auto begin_member(string_view name) -> result = 0;
    virtual auto finish_member(string_view name) -> result = 0;
    virtual auto finish_struct() -> result = 0;
    virtual auto begin_list(span_size_t& element_count) -> result = 0;
    virtual auto begin_element(span_size_t index) -> result = 0;
    virtual auto finish_element(span_size_t index) -> result = 0;
    virtual auto finish_list() -> result = 0;
    virtual auto finish() -> result = 0;
};
//------------------------------------------------------------------------------
template <typename Derived, typename Source = deserializer_data_source>
class common_deserializer_backend : public deserializer_backend {
public:
    common_deserializer_backend() noexcept = default;
    common_deserializer_backend(Source& source) noexcept
      : _source{&source} {}

    auto set_source(Source& s) noexcept -> Derived& {
        _source = &s;
        return derived();
    }

    using error_code = deserialization_error_code;
    using result = deserialization_errors;

    auto source() -> deserializer_data_source* final {
        return _source;
    }

    auto enum_as_string() -> bool override {
        return false;
    }

    auto begin() -> result override {
        return {};
    }

    auto read(span<bool> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<char> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<std::int8_t> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<short> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<int> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<long> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<long long> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<std::uint8_t> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<unsigned short> values, span_size_t& done)
      -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<unsigned> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<unsigned long> values, span_size_t& done)
      -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<unsigned long long> values, span_size_t& done)
      -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<float> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<double> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<identifier> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<decl_name_storage> values, span_size_t& done)
      -> result override {
        return derived().do_read(values, done);
    }

    auto read(span<std::string> values, span_size_t& done) -> result override {
        return derived().do_read(values, done);
    }

    auto begin_struct(span_size_t&) -> result override {
        return {};
    }
    auto begin_member(string_view) -> result override {
        return {};
    }
    auto finish_member(string_view) -> result override {
        return {};
    }
    auto finish_struct() -> result override {
        return {};
    }
    auto begin_list(span_size_t&) -> result override {
        return {};
    }
    auto begin_element(span_size_t) -> result override {
        return {};
    }
    auto finish_element(span_size_t) -> result override {
        return {};
    }
    auto finish_list() -> result override {
        return {};
    }
    auto finish() -> result override {
        return {};
    }

protected:
    auto scan_for(
      byte what,
      const valid_if_positive<span_size_t>& max,
      const valid_if_positive<span_size_t>& step = {256})
      -> valid_if_nonnegative<span_size_t> {
        EAGINE_ASSERT(_source);
        return _source->scan_for(what, max, step);
    }

    auto top(span_size_t size) -> memory::const_block {
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

    auto starts_with(string_view what) -> bool {
        return are_equal(top_string(what.size()), what);
    }

    auto starts_with(char c) -> bool {
        return starts_with(view_one(c));
    }

    auto consume(string_view what, result& errors) -> bool {
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

    auto consume(char what, result& errors) -> bool {
        return consume(view_one(what), errors);
    }

    template <typename Function>
    void consume_until(
      Function predicate,
      const valid_if_positive<span_size_t> step = {256}) {
        while(auto pos = _source->scan_until(predicate, step, step)) {
            if(extract(pos) > 0) {
                pop(extract(pos));
            } else {
                break;
            }
        }
    }

    auto require(string_view what) -> result {
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

    auto require(char what) -> result {
        return require(view_one(what));
    }

private:
    Source* _source{nullptr};

    auto derived() noexcept -> Derived& {
        return *static_cast<Derived*>(this);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_READ_BACKEND_HPP
