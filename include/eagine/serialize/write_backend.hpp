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

    using result = serialization_result;

    virtual result start() = 0;
    virtual result write(span<const bool>) = 0;
    virtual result write(span<const char>) = 0;
    virtual result write(span<const std::int16_t>) = 0;
    virtual result write(span<const std::int32_t>) = 0;
    virtual result write(span<const std::int64_t>) = 0;
    virtual result write(span<const std::uint8_t>) = 0;
    virtual result write(span<const std::uint16_t>) = 0;
    virtual result write(span<const std::uint32_t>) = 0;
    virtual result write(span<const std::uint64_t>) = 0;
    virtual result write(span<const float>) = 0;
    virtual result write(span<const double>) = 0;
    virtual result write(span<const string_view>) = 0;
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
    common_serializer_backend(Sink& sink) noexcept
      : _sink{&sink} {
    }

    result start() override {
        return {};
    }

    result write(span<const bool> values) override {
        return derived().do_write(values);
    }

    result write(span<const char> values) override {
        return derived().do_write(values);
    }

    result write(span<const std::int16_t> values) override {
        return derived().do_write(values);
    }

    result write(span<const std::int32_t> values) override {
        return derived().do_write(values);
    }

    result write(span<const std::int64_t> values) override {
        return derived().do_write(values);
    }

    result write(span<const std::uint8_t> values) override {
        return derived().do_write(values);
    }

    result write(span<const std::uint16_t> values) override {
        return derived().do_write(values);
    }

    result write(span<const std::uint32_t> values) override {
        return derived().do_write(values);
    }

    result write(span<const std::uint64_t> values) override {
        return derived().do_write(values);
    }

    result write(span<const float> values) override {
        return derived().do_write(values);
    }

    result write(span<const double> values) override {
        return derived().do_write(values);
    }

    result write(span<const string_view> values) override {
        return derived().do_write(values);
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
    template <typename... Args>
    result sink(Args&&... args) {
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

