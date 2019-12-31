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

    virtual void start() = 0;
    virtual void read(span<bool>) = 0;
    virtual void read(span<char>) = 0;
    virtual void read(span<std::int16_t>) = 0;
    virtual void read(span<std::int32_t>) = 0;
    virtual void read(span<std::int64_t>) = 0;
    virtual void read(span<std::uint8_t>) = 0;
    virtual void read(span<std::uint16_t>) = 0;
    virtual void read(span<std::uint32_t>) = 0;
    virtual void read(span<std::uint64_t>) = 0;
    virtual void read(span<float>) = 0;
    virtual void read(span<double>) = 0;
    virtual void read(span<std::string>) = 0;
    virtual void begin_struct() = 0;
    virtual void begin_member(string_view name) = 0;
    virtual void finish_member(string_view name) = 0;
    virtual void finish_struct() = 0;
    virtual void begin_list(span_size_t&) = 0;
    virtual void begin_element(span_size_t index) = 0;
    virtual void finish_element(span_size_t index) = 0;
    virtual void finish_list() = 0;
    virtual void finish() = 0;
};
//------------------------------------------------------------------------------
template <typename Derived>
class common_deserializer_backend : public deserializer_backend {
public:
    common_deserializer_backend() noexcept = default;

    void start() override {
    }

    void read(span<bool> values) override {
        derived().do_read(values);
    }

    void read(span<char> values) override {
        derived().do_read(values);
    }

    void read(span<std::int16_t> values) override {
        derived().do_read(values);
    }

    void read(span<std::int32_t> values) override {
        derived().do_read(values);
    }

    void read(span<std::int64_t> values) override {
        derived().do_read(values);
    }

    void read(span<std::uint8_t> values) override {
        derived().do_read(values);
    }

    void read(span<std::uint16_t> values) override {
        derived().do_read(values);
    }

    void read(span<std::uint32_t> values) override {
        derived().do_read(values);
    }

    void read(span<std::uint64_t> values) override {
        derived().do_read(values);
    }

    void read(span<float> values) override {
        derived().do_read(values);
    }

    void read(span<double> values) override {
        derived().do_read(values);
    }

    void read(span<string_view> values) override {
        derived().do_read(values);
    }

    void begin_struct() override {
    }
    void begin_member(string_view) override {
    }
    void finish_member(string_view) override {
    }
    void finish_struct() override {
    }
    void begin_list(span_size_t&) override {
    }
    void begin_element(span_size_t) override {
    }
    void finish_element(span_size_t) override {
    }
    void finish_list() override {
    }
    void finish() override {
    }

private:
    Derived& derived() noexcept {
        return *static_cast<Derived*>(this);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_READ_BACKEND_HPP

