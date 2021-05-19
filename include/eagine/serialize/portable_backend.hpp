/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_PORTABLE_BACKEND_HPP
#define EAGINE_SERIALIZE_PORTABLE_BACKEND_HPP

#include "fputils.hpp"
#include "read_backend.hpp"
#include "write_backend.hpp"

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Cross-platform implementation serializer backend.
/// @ingroup serialization
/// @see portable_deserializer_backend
class portable_serializer_backend
  : public serializer_backend_id<
      common_serializer_backend<portable_serializer_backend>,
      EAGINE_ID_V(Portable)> {
    using base = serializer_backend_id<
      common_serializer_backend<portable_serializer_backend>,
      EAGINE_ID_V(Portable)>;

public:
    using base::base;
    using base::remaining_size;
    using base::sink;
    using error_code = serialization_error_code;
    using result = serialization_errors;

    template <typename T>
    auto do_write(span<const T> values, span_size_t& done) -> result {
        done = 0;
        result errors{};
        for(auto& val : values) {
            errors |= _write_one(val, type_identity<T>{});
            errors |= sink(';');
            if(errors) {
                break;
            }
            ++done;
        }

        return errors;
    }

    auto enum_as_string() -> bool final {
        return true;
    }

    auto begin() -> result final {
        return sink('<');
    }

    auto begin_struct(span_size_t count) -> result final {
        result errors = sink('{');
        errors |= _write_one(count, type_identity<span_size_t>{});
        errors |= sink('|');
        return errors;
    }

    auto begin_member(string_view name) -> result final {
        result errors = sink(name);
        errors |= sink(':');
        return errors;
    }

    auto finish_member(string_view) -> result final {
        return {};
    }

    auto finish_struct() -> result final {
        return sink("};");
    }

    auto begin_list(span_size_t count) -> result final {
        result errors = sink('[');
        errors |= _write_one(count, type_identity<span_size_t>{});
        errors |= sink('|');
        return errors;
    }

    auto begin_element(span_size_t) -> result final {
        return {};
    }

    auto finish_element(span_size_t) -> result final {
        return {};
    }

    auto finish_list() -> result final {
        return sink("];");
    }

    auto finish() -> result final {
        return sink(">\0");
    }

private:
    auto _write_one(bool value, type_identity<bool>) -> result {
        if(value) {
            return sink("T");
        }
        return sink("U");
    }

    template <typename I>
    auto _write_one(I value, type_identity<I>) noexcept
      -> std::enable_if_t<std::is_integral_v<I> && std::is_unsigned_v<I>, result> {
        result errors{};
        auto encode = [&]() {
            // clang-format off
			const char c[16] = {
				'0','1','2','3','4','5','6','7',
				'8','9','A','B','C','D','E','F'};
            // clang-format on
            errors |= sink(c[(value & 0xFU)]);
            value >>= 4U;
        };
        encode();
        while(!errors && value) {
            encode();
        }
        return errors;
    }

    template <typename I>
    auto _write_one(I value, type_identity<I>) noexcept
      -> std::enable_if_t<std::is_integral_v<I> && std::is_signed_v<I>, result> {
        result errors = sink(value < 0 ? '-' : '+');
        using U = std::make_unsigned_t<I>;
        errors |= _write_one(
          limit_cast<U>(value < 0 ? -value : value), type_identity<U>{});
        return errors;
    }

    template <typename F>
    auto _write_one(F value, type_identity<F> tid)
      -> std::enable_if_t<std::is_floating_point_v<F>, result> {
        const auto [f, e] = fputils::decompose(value, tid);
        result errors =
          _write_one(f, type_identity<fputils::decompose_fraction_t<F>>{});
        errors |= sink('`');
        errors |=
          _write_one(e, type_identity<fputils::decompose_exponent_t<F>>{});

        return errors;
    }

    auto _write_one(identifier id, type_identity<identifier>) -> result {
        return sink(id.name().view());
    }

    auto _write_one(decl_name name, type_identity<decl_name>) -> result {
        return sink(name);
    }

    auto _write_one(string_view str, type_identity<string_view>) -> result {
        result errors = sink('"');
        errors |= _write_one(str.size(), type_identity<span_size_t>{});
        errors |= sink('|');
        errors |= sink(str);
        errors |= sink('"');
        return errors;
    }
};
//------------------------------------------------------------------------------
/// @brief Cross-platform implementation of deserializer backend.
/// @ingroup serialization
/// @see portable_serializer_backend
class portable_deserializer_backend
  : public serializer_backend_id<
      common_deserializer_backend<portable_deserializer_backend>,
      EAGINE_ID_V(Portable)> {
    using base = serializer_backend_id<
      common_deserializer_backend<portable_deserializer_backend>,
      EAGINE_ID_V(Portable)>;

public:
    using base::base;
    using base::consume_until;
    using base::require;
    using error_code = deserialization_error_code;
    using result = deserialization_errors;

    template <typename T>
    auto do_read(span<T> values, span_size_t& done) -> result {
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

    auto enum_as_string() -> bool final {
        return true;
    }

    void skip_whitespaces() {
        consume_until([](byte b) { return !std::isspace(b); });
    }

    auto begin() -> result final {
        skip_whitespaces();
        return require('<');
    }

    auto begin_struct(span_size_t& count) -> result final {
        result errors = require('{');
        if(!errors) {
            errors |= _read_one(count, '|');
        }
        return errors;
    }

    auto begin_member(string_view name) -> result final {
        result errors = require(name);
        if(!errors) {
            errors |= require(':');
        }
        return errors;
    }

    auto finish_member(string_view) -> result final {
        return {};
    }

    auto finish_struct() -> result final {
        return require("};");
    }

    auto begin_list(span_size_t& count) -> result final {
        result errors = require('[');
        if(!errors) {
            errors |= _read_one(count, '|');
        }
        return errors;
    }

    auto begin_element(span_size_t) -> result final {
        return {};
    }

    auto finish_element(span_size_t) -> result final {
        return {};
    }

    auto finish_list() -> result final {
        return require("];");
    }

    auto finish() -> result final {
        return require(">\0");
    }

private:
    auto _read_one(bool& value, char delimiter) -> result {
        result temp{};
        if(this->consume('T', temp)) {
            value = true;
        } else if(this->consume('U', temp)) {
            value = false;
        } else {
            return temp;
        }
        return require(delimiter);
    }

    template <typename I>
    auto _read_one(I& value, char delimiter)
      -> std::enable_if_t<std::is_integral_v<I> && std::is_unsigned_v<I>, result> {
        value = I(0);
        result errors{};
        if(auto src{this->string_before(delimiter, 48)}) {
            const auto skip_len = src.size() + 1;
            unsigned shift = 0U;
            while(src) {
                const char c = extract(src);
                I frag{};
                if((c >= '0') && (c <= '9')) {
                    frag = I(c - '0');
                } else if((c >= 'A') && (c <= 'F')) {
                    frag = I(10 + c - 'A');
                } else {
                    errors |= deserialization_error_code::invalid_format;
                    return errors;
                }
                EAGINE_ASSERT(frag < 16U);
                value |= I(frag << shift);
                shift += 4U;
                src = skip(src, 1);
            }
            pop(skip_len);
        }
        return errors;
    }

    template <typename I>
    auto _read_one(I& value, char delimiter)
      -> std::enable_if_t<std::is_integral_v<I> && std::is_signed_v<I>, result> {
        using U = std::make_unsigned_t<I>;
        const char sign = extract_or(top_char(), '\0');
        result errors{};
        if(EAGINE_LIKELY((sign == '+') || (sign == '-'))) {
            pop(1);
            U temp{};
            errors |= _read_one(temp, delimiter);
            if(const auto conv{convert_if_fits<I>(temp)}) {
                value = (sign == '-') ? -extract(conv) : extract(conv);
            } else {
                errors |= deserialization_error_code::invalid_format;
            }
        } else {
            errors |= deserialization_error_code::invalid_format;
        }
        return errors;
    }

    template <typename F>
    auto _read_one(F& value, char delimiter)
      -> std::enable_if_t<std::is_floating_point_v<F>, result> {
        fputils::decompose_fraction_t<F> f{};

        result errors = _read_one(f, '`');
        if(EAGINE_LIKELY(!errors)) {
            fputils::decompose_exponent_t<F> e{};
            errors |= _read_one(e, delimiter);
            if(EAGINE_LIKELY(!errors)) {
                value = fputils::compose({f, e}, type_identity<F>{});
            }
        }
        return errors;
    }

    auto _read_one(identifier& value, char delimiter) -> result {
        result errors{};
        if(auto src{this->string_before(delimiter, 32)}) {
            value = identifier(src);
            pop(src.size() + 1);
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    auto _read_one(decl_name_storage& value, char delimiter) -> result {
        result errors{};
        const auto max = decl_name_storage::max_length + 1;
        if(auto src{this->string_before(delimiter, max)}) {
            value.assign(src);
            pop(src.size() + 1);
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    auto _read_one(std::string& value, char delimiter) -> result {
        result errors = require('"');
        if(!errors) {
            span_size_t len{0};
            errors |= _read_one(len, '|');
            if(!errors) {
                auto str{this->top_string(len)};
                if(str.size() < len) {
                    errors |= error_code::not_enough_data;
                } else {
                    assign_to(value, str);
                    pop(str.size());
                    errors |= require('"');
                    errors |= require(delimiter);
                }
            }
        }
        return errors;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_PORTABLE_BACKEND_HPP
