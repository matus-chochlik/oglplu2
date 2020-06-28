/**
 *  @file eagine/serialize/write_backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_WRITE_BACKEND_HPP
#define EAGINE_SERIALIZE_WRITE_BACKEND_HPP

#include "../identifier.hpp"
#include "../reflect/decl_name.hpp"
#include "data_sink.hpp"
#include "result.hpp"
#include <cstdint>

namespace eagine {
//------------------------------------------------------------------------------
struct serializer_backend {
    serializer_backend() noexcept = default;
    serializer_backend(serializer_backend&&) noexcept = default;
    serializer_backend(const serializer_backend&) = delete;
    serializer_backend& operator=(serializer_backend&&) = delete;
    serializer_backend& operator=(const serializer_backend&) = delete;

    virtual ~serializer_backend() noexcept = default;

    using result = serialization_errors;

    virtual identifier type_id() = 0;
    virtual serializer_data_sink* sink() = 0;
    virtual bool enum_as_string() = 0;

    virtual result begin() = 0;
    virtual result write(span<const bool>, span_size_t&) = 0;
    virtual result write(span<const char>, span_size_t&) = 0;
    virtual result write(span<const std::int8_t>, span_size_t&) = 0;
    virtual result write(span<const short>, span_size_t&) = 0;
    virtual result write(span<const int>, span_size_t&) = 0;
    virtual result write(span<const long>, span_size_t&) = 0;
    virtual result write(span<const long long>, span_size_t&) = 0;
    virtual result write(span<const std::uint8_t>, span_size_t&) = 0;
    virtual result write(span<const unsigned short>, span_size_t&) = 0;
    virtual result write(span<const unsigned>, span_size_t&) = 0;
    virtual result write(span<const unsigned long>, span_size_t&) = 0;
    virtual result write(span<const unsigned long long>, span_size_t&) = 0;
    virtual result write(span<const float>, span_size_t&) = 0;
    virtual result write(span<const double>, span_size_t&) = 0;
    virtual result write(span<const identifier>, span_size_t&) = 0;
    virtual result write(span<const decl_name>, span_size_t&) = 0;
    virtual result write(span<const string_view>, span_size_t&) = 0;
    virtual result begin_struct(span_size_t member_count) = 0;
    virtual result begin_member(string_view name) = 0;
    virtual result finish_member(string_view name) = 0;
    virtual result finish_struct() = 0;
    virtual result begin_list(span_size_t element_count) = 0;
    virtual result begin_element(span_size_t index) = 0;
    virtual result finish_element(span_size_t index) = 0;
    virtual result finish_list() = 0;
    virtual result finish() = 0;
};
//------------------------------------------------------------------------------
template <typename Derived, typename Sink = serializer_data_sink>
class common_serializer_backend : public serializer_backend {
public:
    common_serializer_backend() noexcept = default;
    common_serializer_backend(Sink& s) noexcept
      : _sink{&s} {
    }

    Derived& set_sink(Sink& s) noexcept {
        _sink = &s;
        return derived();
    }

    serializer_data_sink* sink() final {
        return _sink;
    }

    bool enum_as_string() override {
        return false;
    }

    result begin() override {
        return {};
    }

    result write(span<const bool> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const char> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const std::int8_t> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const short> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const int> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const long> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const long long> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const std::uint8_t> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(
      span<const unsigned short> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const unsigned> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const unsigned long> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(
      span<const unsigned long long> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const float> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const double> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const identifier> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const decl_name> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result write(span<const string_view> values, span_size_t& done) override {
        return derived().do_write(values, done);
    }

    result begin_struct(span_size_t) override {
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
    result begin_list(span_size_t) override {
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
    span_size_t remaining_size() const {
        EAGINE_ASSERT(_sink);
        return _sink->remaining_size();
    }

    template <typename... Args>
    result sink(Args&&... args) const {
        EAGINE_ASSERT(_sink);
        return _sink->write(std::forward<Args>(args)...);
    }

private:
    Sink* _sink{nullptr};

    Derived& derived() noexcept {
        return *static_cast<Derived*>(this);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_WRITE_BACKEND_HPP

