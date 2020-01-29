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
    using result = serialization_errors;

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
        // TODO: to_chars from_chars when available
        // NOLINTNEXTLINE(hicpp-vararg)
        std::snprintf(
          temp.data(), temp.size(), static_cast<const char*>(fmt), value);
        return sink(string_view(temp.data()));
    }

    result _write_one(byte value, identity<byte>) {
        return _sprintf_one(value, "%02hhx");
    }

    result _write_one(signed char value, identity<signed char>) {
        return _sprintf_one(value, "%hhd");
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

    result _write_one(decl_name name, identity<decl_name>) {
        return sink(name);
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
                break;
            }
            ++done;
        }

        return errors;
    }

    bool enum_as_string() final {
        return true;
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
        return sink(">\0");
    }
};
//------------------------------------------------------------------------------
class string_deserializer_backend
  : public common_deserializer_backend<string_deserializer_backend> {
    using base = common_deserializer_backend<string_deserializer_backend>;

public:
    using base::base;
    using base::require;
    using error_code = deserialization_error_code;
    using result = deserialization_errors;

    identifier type_id() final {
        return EAGINE_ID(String);
    }

private:
    result _read_one(bool& value, char delimiter) {
        result temp{};
        if(this->consume("true", temp)) {
            value = true;
        } else if(this->consume("false", temp)) {
            value = false;
        } else {
            return temp;
        }
        return require(delimiter);
    }

    result _read_one(char& value, char delimiter) {
        result errors = require('\'');
        if(!errors) {
            if(auto opt_char = this->top_char()) {
                value = extract(opt_char);
                pop(1);
            } else {
                errors |= error_code::not_enough_data;
            }
            if(!errors) {
                const char t[3] = {'\'', delimiter, '\0'};
                errors |= require(string_view(t));
            }
        }
        return errors;
    }

    template <typename T, std::size_t L>
    result _sscanf_one(T& value, char delimiter, const char (&fmt)[L]) {
        result errors{};
        if(auto src = this->string_before(delimiter)) {
            if(
              // TODO: to_chars from_chars when available
              // NOLINTNEXTLINE(hicpp-vararg)
              std::sscanf(src.data(), static_cast<const char*>(fmt), &value) ==
              1) {
                pop(src.size() + 1);
            } else {
                errors |= error_code::invalid_format;
            }
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    result _read_one(byte& value, char delimiter) {
        const char fmt[6] = {'%', 'h', 'h', 'x', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(signed char& value, char delimiter) {
        const char fmt[6] = {'%', 'h', 'h', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(short& value, char delimiter) {
        const char fmt[5] = {'%', 'h', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(unsigned short& value, char delimiter) {
        const char fmt[5] = {'%', 'h', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(int& value, char delimiter) {
        const char fmt[4] = {'%', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(unsigned& value, char delimiter) {
        const char fmt[4] = {'%', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(long& value, char delimiter) {
        const char fmt[5] = {'%', 'l', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(unsigned long& value, char delimiter) {
        const char fmt[5] = {'%', 'l', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(long long& value, char delimiter) {
        const char fmt[6] = {'%', 'l', 'l', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(unsigned long long& value, char delimiter) {
        const char fmt[6] = {'%', 'l', 'l', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(float& value, char delimiter) {
        const char fmt[4] = {'%', 'f', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(double& value, char delimiter) {
        const char fmt[5] = {'%', 'l', 'f', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    result _read_one(identifier& value, char delimiter) {
        result errors{};
        if(auto src = this->string_before(delimiter)) {
            value = identifier(src);
            pop(src.size() + 1);
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    result _read_one(decl_name_storage& value, char delimiter) {
        result errors{};
        if(auto src = this->string_before(delimiter)) {
            value.assign(src);
            pop(src.size() + 1);
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    result _read_one(std::string& value, char delimiter) {
        result errors = require('"');
        if(!errors) {
            span_size_t len{0};
            errors |= _read_one(len, '|');
            if(!errors) {
                auto str = this->top_string(len);
                if(str.size() < len) {
                    errors |= error_code::not_enough_data;
                } else {
                    value.assign(str.data(), std_size(str.size()));
                    pop(str.size());
                    errors |= require('"');
                    errors |= require(delimiter);
                }
            }
        }
        return errors;
    }

public:
    template <typename T>
    result do_read(span<T> values, span_size_t& done) {
        done = 0;
        result errors{};
        for(T& val : values) {
            errors |= _read_one(val, ';');
            if(errors) {
                break;
            }
            ++done;
        }

        return errors;
    }

    bool enum_as_string() final {
        return true;
    }

    result begin() final {
        return require('<');
    }

    result begin_struct(span_size_t& count) final {
        result errors = require('{');
        if(!errors) {
            errors |= _read_one(count, '|');
        }
        return errors;
    }

    result begin_member(string_view name) final {
        result errors = require(name);
        if(!errors) {
            errors |= require(':');
        }
        return errors;
    }

    result finish_member(string_view) final {
        return {};
    }

    result finish_struct() final {
        return require("};");
    }

    result begin_list(span_size_t& count) final {
        result errors = require('[');
        if(!errors) {
            errors |= _read_one(count, '|');
        }
        return errors;
    }

    result begin_element(span_size_t) final {
        return {};
    }

    result finish_element(span_size_t) final {
        return {};
    }

    result finish_list() final {
        return require("];");
    }

    result finish() final {
        return require(">\0");
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_STRING_BACKEND_HPP

