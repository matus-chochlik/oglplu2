/// @file eagine/serialize/write_backend.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

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
    auto operator=(serializer_backend&&) = delete;
    auto operator=(const serializer_backend&) = delete;

    virtual ~serializer_backend() noexcept = default;

    using result = serialization_errors;

    virtual auto type_id() -> identifier = 0;
    virtual auto sink() -> serializer_data_sink* = 0;
    virtual auto enum_as_string() -> bool = 0;

    virtual auto begin() -> result = 0;
    virtual auto write(span<const bool>, span_size_t&) -> result = 0;
    virtual auto write(span<const char>, span_size_t&) -> result = 0;
    virtual auto write(span<const std::int8_t>, span_size_t&) -> result = 0;
    virtual auto write(span<const short>, span_size_t&) -> result = 0;
    virtual auto write(span<const int>, span_size_t&) -> result = 0;
    virtual auto write(span<const long>, span_size_t&) -> result = 0;
    virtual auto write(span<const long long>, span_size_t&) -> result = 0;
    virtual auto write(span<const std::uint8_t>, span_size_t&) -> result = 0;
    virtual auto write(span<const unsigned short>, span_size_t&) -> result = 0;
    virtual auto write(span<const unsigned>, span_size_t&) -> result = 0;
    virtual auto write(span<const unsigned long>, span_size_t&) -> result = 0;
    virtual auto write(span<const unsigned long long>, span_size_t&)
      -> result = 0;
    virtual auto write(span<const float>, span_size_t&) -> result = 0;
    virtual auto write(span<const double>, span_size_t&) -> result = 0;
    virtual auto write(span<const identifier>, span_size_t&) -> result = 0;
    virtual auto write(span<const decl_name>, span_size_t&) -> result = 0;
    virtual auto write(span<const string_view>, span_size_t&) -> result = 0;
    virtual auto begin_struct(span_size_t member_count) -> result = 0;
    virtual auto begin_member(string_view name) -> result = 0;
    virtual auto finish_member(string_view name) -> result = 0;
    virtual auto finish_struct() -> result = 0;
    virtual auto begin_list(span_size_t element_count) -> result = 0;
    virtual auto begin_element(span_size_t index) -> result = 0;
    virtual auto finish_element(span_size_t index) -> result = 0;
    virtual auto finish_list() -> result = 0;
    virtual auto finish() -> result = 0;
};
//------------------------------------------------------------------------------
template <typename Derived, typename Sink = serializer_data_sink>
class common_serializer_backend : public serializer_backend {
public:
    common_serializer_backend() noexcept = default;
    common_serializer_backend(Sink& s) noexcept
      : _sink{&s} {}

    auto set_sink(Sink& s) noexcept -> auto& {
        _sink = &s;
        return derived();
    }

    auto sink() -> serializer_data_sink* final {
        return _sink;
    }

    auto enum_as_string() -> bool override {
        return false;
    }

    auto begin() -> result override {
        return {};
    }

    auto write(span<const bool> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const char> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const std::int8_t> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const short> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const int> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const long> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const long long> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const std::uint8_t> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned short> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned long> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const unsigned long long> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const float> values, span_size_t& done) -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const double> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const identifier> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const decl_name> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto write(span<const string_view> values, span_size_t& done)
      -> result override {
        return derived().do_write(values, done);
    }

    auto begin_struct(span_size_t) -> result override {
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
    auto begin_list(span_size_t) -> result override {
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
    auto remaining_size() const -> span_size_t {
        EAGINE_ASSERT(_sink);
        return _sink->remaining_size();
    }

    template <typename... Args>
    auto sink(Args&&... args) const -> result {
        EAGINE_ASSERT(_sink);
        return _sink->write(std::forward<Args>(args)...);
    }

private:
    Sink* _sink{nullptr};

    auto derived() noexcept -> Derived& {
        return *static_cast<Derived*>(this);
    }
};
//------------------------------------------------------------------------------
template <typename Base, identifier_t Id>
class serializer_backend_id : public Base {
public:
    using Base::Base;

    static constexpr const identifier_t id_value = Id;

    auto type_id() -> identifier final {
        return identifier{Id};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_WRITE_BACKEND_HPP
