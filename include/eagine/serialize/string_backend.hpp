/**
 *  @file eagine/serialize/string_backend.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_STRING_BACKEND_HPP
#define EAGINE_SERIALIZE_STRING_BACKEND_HPP

#include "read_backend.hpp"
#include "write_backend.hpp"
#include <cstdio>

namespace eagine {
//------------------------------------------------------------------------------
class string_serializer_backend
  : public common_serializer_backend<string_serializer_backend> {
    using base = common_serializer_backend<string_serializer_backend>;

public:
    using base::base;
    using base::remaining_size;
    using base::sink;
    using error_code = serialization_error_code;
    using result = serialization_result;

    identifier type_id() final {
        return EAGINE_ID(String);
    }

private:
    result _write_one(bool value, identity<bool>) {
        if(value) {
            return sink("true");
        }
        return sink("false");
    }

    result _write_one(char value, identity<char>) {
        result errors = sink('\'');
        errors |= sink(value);
        errors |= sink('\'');
        return errors;
    }

    template <typename T, std::size_t L>
    result _sprintf_one(T value, const char (&fmt)[L]) {
        std::array<char, 64> temp{};
        std::snprintf(temp.data(), temp.size(), fmt, value);
        return sink(string_view(temp.data()));
    }

    result _write_one(byte value, identity<byte>) {
        return _sprintf_one(value, "%02hhx");
    }

    result _write_one(short value, identity<short>) {
        return _sprintf_one(value, "%hd");
    }

    result _write_one(unsigned short value, identity<unsigned short>) {
        return _sprintf_one(value, "%hu");
    }

    result _write_one(int value, identity<int>) {
        return _sprintf_one(value, "%d");
    }

    result _write_one(unsigned value, identity<unsigned>) {
        return _sprintf_one(value, "%u");
    }

    result _write_one(long value, identity<long>) {
        return _sprintf_one(value, "%ld");
    }

    result _write_one(unsigned long value, identity<unsigned long>) {
        return _sprintf_one(value, "%lu");
    }

    result _write_one(long long value, identity<long long>) {
        return _sprintf_one(value, "%lld");
    }

    result _write_one(unsigned long long value, identity<unsigned long long>) {
        return _sprintf_one(value, "%llu");
    }

    result _write_one(float value, identity<float>) {
        return _sprintf_one(value, "%f");
    }

    result _write_one(double value, identity<double>) {
        return _sprintf_one(value, "%lf");
    }

    result _write_one(identifier id, identity<identifier>) {
        return sink(id.name().view());
    }

    result _write_one(string_view str, identity<string_view>) {
        result errors = sink('"');
        errors |= _write_one(str.size(), identity<span_size_t>{});
        errors |= sink('|');
        errors |= sink(str);
        errors |= sink('"');
        return errors;
    }

public:
    template <typename T>
    result do_write(span<const T> values, span_size_t& done) {
        done = 0;
        result errors{};
        for(auto& val : values) {
            errors |= _write_one(val, identity<T>{});
            errors |= sink(';');
            if(errors) {
                return errors;
            }
            ++done;
        }

        return errors;
    }

    result begin() final {
        return sink('<');
    }

    result begin_struct(span_size_t count) final {
        result errors = sink('{');
        errors |= _write_one(count, identity<span_size_t>{});
        errors |= sink('|');
        return errors;
    }
    result begin_member(string_view name) final {
        result errors = sink(name);
        errors |= sink(':');
        return errors;
    }
    result finish_member(string_view) final {
        return {};
    }
    result finish_struct() final {
        return sink("};");
    }
    result begin_list(span_size_t count) final {
        result errors = sink('[');
        errors |= _write_one(count, identity<span_size_t>{});
        errors |= sink('|');
        return errors;
    }
    result begin_element(span_size_t) final {
        return {};
    }
    result finish_element(span_size_t) final {
        return {};
    }
    result finish_list() final {
        return sink("];");
    }
    result finish() final {
        return sink('>');
    }
};
//------------------------------------------------------------------------------
class string_deserializer_backend
  : public common_deserializer_backend<string_deserializer_backend> {
    using base = common_deserializer_backend<string_deserializer_backend>;

public:
    using base::base;
    using base::pop;
    using base::top;
    using error_code = deserialization_error_code;
    using result = deserialization_result;

    identifier type_id() final {
        return EAGINE_ID(String);
    }

    template <typename T>
    result do_read(span<T>, span_size_t& done) {
        done = 0;
        return {};
    }

    result begin() final {
        return {};
    }
    result begin_struct(span_size_t&) final {
        return {};
    }
    result begin_member(string_view) final {
        return {};
    }
    result finish_member(string_view) final {
        return {};
    }
    result finish_struct() final {
        return {};
    }
    result begin_list(span_size_t&) final {
        return {};
    }
    result begin_element(span_size_t) final {
        return {};
    }
    result finish_element(span_size_t) final {
        return {};
    }
    result finish_list() final {
        return {};
    }
    result finish() final {
        return {};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_STRING_BACKEND_HPP

