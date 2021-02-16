/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_PROGRAM_ARGS_HPP
#define EAGINE_PROGRAM_ARGS_HPP

#include "assert.hpp"
#include "from_string.hpp"
#include "integer_range.hpp"
#include "memory/block.hpp"
#include "memory/span_algo.hpp"
#include "range_types.hpp"
#include "selector.hpp"
#include "span.hpp"
#include "string_span.hpp"
#include "type_identity.hpp"
#include "type_name.hpp"
#include "valid_if/in_list.hpp"
#include <memory>
#include <sstream>
#include <type_traits>
#include <utility>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
class program_args;
//------------------------------------------------------------------------------
class basic_program_parameter {
protected:
    string_view _short_tag;
    string_view _long_tag;
    string_view _description;

    constexpr basic_program_parameter(
      string_view short_tag,
      string_view long_tag) noexcept
      : _short_tag(short_tag)
      , _long_tag(long_tag) {}

public:
    constexpr auto short_tag() const noexcept -> string_view {
        return _short_tag;
    }

    constexpr auto long_tag() const noexcept -> string_view {
        return _long_tag;
    }

    constexpr auto description() const noexcept -> string_view {
        return _description;
    }

    constexpr auto description(string_view help_str) noexcept -> auto& {
        _description = help_str;
        return *this;
    }
};
//------------------------------------------------------------------------------
template <typename T>
class program_parameter : public basic_program_parameter {
private:
    T _value{};

    template <typename X>
    static inline auto _is_valid(const X&) noexcept {
        return true;
    }

    template <typename X, typename P, typename L>
    static inline auto _is_valid(const valid_if<X, P, L>& vi) noexcept {
        return vi.is_valid();
    }

    template <typename X>
    static inline void _log_invalid(const X&, const std::ostream&) noexcept {}

    template <typename X, typename P, typename L>
    static inline void
    _log_invalid(const valid_if<X, P, L>& vi, std::ostream& log) noexcept {
        vi.log_invalid(log);
    }

    template <typename X>
    static auto _get_value(X& val) noexcept -> auto& {
        return val;
    }

    template <typename X>
    static auto _get_value(const X& val) noexcept -> auto& {
        return val;
    }

    template <typename X, typename P, typename L>
    static auto _get_value(valid_if<X, P, L>& vi) -> auto& {
        return vi.value();
    }

    template <typename X, typename P, typename L>
    static auto _get_value(const valid_if<X, P, L>& vi) -> auto& {
        return vi.value();
    }

public:
    program_parameter(
      string_view short_tag,
      string_view long_tag,
      T initial) noexcept
      : basic_program_parameter(short_tag, long_tag)
      , _value(std::move(initial)) {}

    auto ref() noexcept -> auto& {
        return _value;
    }

    auto has_valid_value() const noexcept -> bool {
        return _is_valid(_value);
    }

    auto log_invalid_value(std::ostream& log) const -> auto& {
        log << "Invalid value of parameter " << long_tag() << ": ";
        _log_invalid(_value, log);
        return log << ". ";
    }

    auto validate(std::ostream& log) const -> bool {
        if(!has_valid_value()) {
            log_invalid_value(log) << std::endl;
            return false;
        }
        return true;
    }

    auto value() const -> auto& {
        return _get_value(_value);
    }

    operator const T&() const noexcept {
        return _value;
    }
};
//------------------------------------------------------------------------------
template <typename T>
class program_parameter_alias : public basic_program_parameter {
private:
    program_parameter<T>& _aliased;

public:
    ~program_parameter_alias() noexcept = default;
    program_parameter_alias(const program_parameter_alias&) = delete;
    program_parameter_alias(program_parameter_alias&&) noexcept = delete;
    auto operator=(const program_parameter_alias&) = delete;
    auto operator=(program_parameter_alias&&) noexcept = delete;

    program_parameter_alias(
      string_view short_tag,
      string_view long_tag,
      program_parameter<T>& that) noexcept
      : basic_program_parameter(short_tag, long_tag)
      , _aliased(that) {}

    auto ref() noexcept -> auto& {
        return _aliased.ref();
    }

    auto value() const noexcept -> auto& {
        return _aliased.value();
    }

    operator const T&() const noexcept {
        return static_cast<const T&>(_aliased);
    }
};
//------------------------------------------------------------------------------
template <>
class program_parameter<void> : public basic_program_parameter {
private:
    span_size_t _count{0};

public:
    program_parameter(string_view short_tag, string_view long_tag) noexcept
      : basic_program_parameter(short_tag, long_tag) {}

    void increment() noexcept {
        ++_count;
    }

    auto has_valid_value() const noexcept -> bool {
        return true;
    }

    auto log_invalid_value(std::ostream& log) const noexcept -> std::ostream& {
        return log;
    }

    auto validate(std::ostream&) const noexcept -> bool {
        return true;
    }

    auto value() const noexcept -> span_size_t {
        return _count;
    }
};

using program_option = program_parameter<void>;
//------------------------------------------------------------------------------
class program_arg_iterator;
class program_arg {
private:
    int _argi{0};
    int _argc{0};
    const char** _argv{nullptr};

    friend class program_arg_iterator;
    friend class program_args;

    template <typename T, identifier_t V>
    auto
    _do_parse(T& dest, selector<V> sel, const std::ostream&) const noexcept {
        if(auto opt_val{from_string<T>(get(), sel)}) {
            dest = std::move(extract(opt_val));
            return true;
        }
        return false;
    }

    template <identifier_t V>
    auto _do_parse(string_view& dest, selector<V>, const std::ostream&)
      const noexcept {
        dest = get();
        return true;
    }

    template <identifier_t V>
    auto _do_parse(std::string& dest, selector<V>, const std::ostream&) const {
        dest = get_string();
        return true;
    }

    template <typename T, typename P, typename L, identifier_t V>
    auto _do_parse(
      valid_if<T, P, L>& dest,
      selector<V> sel,
      std::ostream& parse_log) const {
        T value{};
        if(parse(value, sel, parse_log)) {
            if(dest.is_valid(value)) {
                dest = std::move(value);
                return true;
            } else {
                dest.log_invalid(parse_log, value);
            }
        } else {
            parse_log << "'" << get() << "' "
                      << "is not a valid `" << type_name<T>() << "` value";
        }
        return false;
    }

    template <typename T, typename A, identifier_t V>
    auto _do_parse(
      std::vector<T, A>& dest,
      selector<V> sel,
      std::ostream& parse_log) const {
        T value{};
        if(parse(value, sel, parse_log)) {
            dest.push_back(std::move(value));
            return true;
        }
        return false;
    }

public:
    program_arg() noexcept = default;

    program_arg(int argi, int argc, const char** argv) noexcept
      : _argi(argi)
      , _argc(argc)
      , _argv(argv) {}

    using value_type = string_view;

    auto is_valid() const noexcept -> bool {
        return (0 < _argi) && (_argi < _argc) && (_argv != nullptr) &&
               (_argv[_argi] != nullptr);
    }

    operator bool() const noexcept {
        return is_valid();
    }

    auto position() const noexcept {
        return _argi;
    }

    auto is_first() const noexcept -> bool {
        return _argi == 1;
    }

    auto is_last() const noexcept -> bool {
        return _argi == _argc - 1;
    }

    auto get() const noexcept -> value_type {
        if(is_valid()) {
            return value_type(_argv[_argi]);
        }
        return value_type();
    }

    auto block() const noexcept {
        return memory::as_bytes(get());
    }

    auto get_string() const -> std::string {
        return get().to_string();
    }

    operator value_type() const noexcept {
        return get();
    }

    auto starts_with(string_view str) const noexcept {
        return memory::starts_with(get(), str);
    }

    auto ends_with(string_view str) const noexcept {
        return memory::ends_with(get(), str);
    }

    auto is_tag(string_view tag) const noexcept {
        return are_equal(get(), tag);
    }

    auto is_tag(string_view short_tag, string_view long_tag) const noexcept {
        return are_equal(get(), short_tag) || are_equal(get(), long_tag);
    }

    auto is_tag_param(const basic_program_parameter& param) const {
        return is_tag(param.short_tag(), param.long_tag());
    }

    auto is_help_arg() const noexcept {
        return is_tag(string_view("-h"), string_view("--help"));
    }

    auto next() const noexcept {
        return program_arg(_argi + 1, _argc, _argv);
    }

    auto prev() const noexcept {
        return program_arg(_argi - 1, _argc, _argv);
    }

    template <typename T, identifier_t V>
    auto parse(T& dest, selector<V> sel, std::ostream& parse_log) const {
        if(is_valid()) {
            T temp = dest;
            if(_do_parse(temp, sel, parse_log)) {
                dest = std::move(temp);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    auto parse(T& dest, std::ostream& parse_log) const {
        return parse(dest, default_selector, parse_log);
    }

    template <typename T, identifier_t V>
    auto parse_next(T& dest, selector<V> sel, std::ostream& parse_log) const {
        return next().parse(dest, sel, parse_log);
    }

    template <typename T>
    auto parse_next(T& dest, std::ostream& parse_log) const {
        return parse_next(dest, default_selector, parse_log);
    }

    auto missing_handler(std::ostream& errorlog) {
        return [&errorlog](string_view arg_tag) {
            errorlog << "Missing value after '" << arg_tag << "'." << std::endl;
        };
    }

    auto invalid_handler(std::ostream& errorlog) {
        return
          [&errorlog](
            string_view arg_tag, string_view arg_val, string_view log_str) {
              errorlog << "Invalid value '" << arg_val << "' after '" << arg_tag
                       << "'. " << log_str << std::endl;
          };
    }

    template <typename T, typename MissingFunc, typename InvalidFunc>
    auto do_consume_next(
      T& dest,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) -> bool {
        if(next()) {
            std::stringstream parse_log;
            if(parse_next(dest, parse_log)) {
                *this = next();
                return true;
            } else {
                handle_invalid(
                  get(), next().get(), string_view(parse_log.str()));
            }
        } else {
            handle_missing(get());
        }
        return false;
    }

    template <typename T>
    auto consume_next(T& dest, std::ostream& errorlog) -> bool {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_consume_next(dest, if_missing, if_invalid);
    }

    template <typename T, typename MissingFunc, typename InvalidFunc>
    auto do_parse_param(
      program_parameter<T>& param,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) -> bool {
        if(is_tag_param(param)) {
            return do_consume_next(param.ref(), handle_missing, handle_invalid);
        }
        return false;
    }

    template <typename MissingFunc, typename InvalidFunc>
    auto do_parse_param(
      program_parameter<void>& param,
      const MissingFunc&,
      const InvalidFunc&) {
        if(is_tag_param(param)) {
            param.increment();
            return true;
        }
        return false;
    }

    template <typename T>
    auto parse_param(program_parameter<T>& param, std::ostream& errorlog)
      -> bool {
        auto if_missing{missing_handler(errorlog)};
        auto if_invalid{invalid_handler(errorlog)};
        return do_parse_param(param, if_missing, if_invalid);
    }

    template <typename T, typename MissingFunc, typename InvalidFunc>
    auto do_consume_next(
      T& dest,
      span<const T> choices,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        valid_if_in_list<T, span<const T>> temp(T(), choices);
        if(do_consume_next(temp, handle_missing, handle_invalid)) {
            dest = temp.value();
            return true;
        }
        return false;
    }

    template <typename T, typename P, typename L, class MissingFunc, class InvalidFunc>
    auto do_consume_next(
      valid_if<T, P, L>& dest,
      span<const T> choices,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        T temp = {};
        if(do_consume_next(temp, choices, handle_missing, handle_invalid)) {
            if(dest.is_valid(temp)) {
                dest = std::move(temp);
                return true;
            }
        }
        return false;
    }

    template <typename T, typename C>
    auto consume_next(T& dest, span<const C> choices, std::ostream& errorlog)
      -> bool {
        auto if_missing{missing_handler(errorlog)};
        auto if_invalid{invalid_handler(errorlog)};
        return do_consume_next(dest, choices, if_missing, if_invalid);
    }

    template <typename T, typename C, class MissingFunc, class InvalidFunc>
    auto do_parse_param(
      program_parameter<T>& param,
      span<const C> choices,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        if(is_tag_param(param)) {
            return do_consume_next(
              param.ref(), choices, handle_missing, handle_invalid);
        }
        return false;
    }

    template <typename T, typename C>
    auto parse_param(
      program_parameter<T>& param,
      span<const C> choices,
      std::ostream& errorlog) -> bool {
        auto if_missing{missing_handler(errorlog)};
        auto if_invalid{invalid_handler(errorlog)};
        return do_parse_param(param, choices, if_missing, if_invalid);
    }

    template <typename T, typename MissingFunc, typename InvalidFunc>
    auto do_consume_next(
      T& dest,
      span<const string_view> symbols,
      span<const T> translations,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        EAGINE_ASSERT(symbols.size() <= translations.size());

        string_view parsed;
        if(do_consume_next(parsed, symbols, handle_missing, handle_invalid)) {
            for(auto i : integer_range(symbols.size())) {
                if(are_equal(parsed, symbols[i])) {
                    dest = translations[i];
                    return true;
                }
            }
        }
        return false;
    }

    template <typename T, typename P, typename L, class MissingFunc, class InvalidFunc>
    auto do_consume_next(
      valid_if<T, P, L>& dest,
      span<const string_view> symbols,
      span<const T> translations,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        T temp{};
        if(do_consume_next(
             temp, symbols, translations, handle_missing, handle_invalid)) {
            if(dest.is_valid(temp)) {
                dest = std::move(temp);
                return true;
            }
        }
        return false;
    }

    template <typename T, typename R>
    auto consume_next(
      T& dest,
      span<const string_view> symbols,
      span<const R> translations,
      std::ostream& errorlog) -> bool {
        auto if_missing{missing_handler(errorlog)};
        auto if_invalid{invalid_handler(errorlog)};
        return do_consume_next(
          dest, symbols, translations, if_missing, if_invalid);
    }

    template <typename T, typename R, class MissingFunc, class InvalidFunc>
    auto do_parse_param(
      program_parameter<T>& param,
      span<const string_view> symbols,
      span<const R> translations,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        if(is_tag_param(param)) {
            return do_consume_next(
              param.ref(),
              symbols,
              translations,
              handle_missing,
              handle_invalid);
        }
        return false;
    }

    template <typename T, typename R>
    auto parse_param(
      program_parameter<T>& param,
      span<const string_view> symbols,
      span<const R> translations,
      std::ostream& errorlog) -> bool {
        auto if_missing{missing_handler(errorlog)};
        auto if_invalid{invalid_handler(errorlog)};
        return do_parse_param(
          param, symbols, translations, if_missing, if_invalid);
    }

    template <typename T, typename R, class MissingFunc, class InvalidFunc>
    auto do_parse_param(
      program_parameter_alias<T>& param,
      span<const string_view> symbols,
      span<const R> translations,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        if(is_tag_param(param)) {
            return do_consume_next(
              param.ref(),
              symbols,
              translations,
              handle_missing,
              handle_invalid);
        }
        return false;
    }

    template <typename T, typename R>
    auto parse_param(
      program_parameter_alias<T>& param,
      span<const string_view> symbols,
      span<const R> translations,
      std::ostream& errorlog) -> bool {
        auto if_missing{missing_handler(errorlog)};
        auto if_invalid{invalid_handler(errorlog)};
        return do_parse_param(
          param, symbols, translations, if_missing, if_invalid);
    }

    auto operator==(const value_type& v) const noexcept {
        return are_equal(get(), v);
    }

    auto operator!=(const value_type& v) const noexcept {
        return are_equal(get(), v);
    }
};
//------------------------------------------------------------------------------
static inline auto extract(const program_arg& arg) noexcept {
    return arg.get();
}
//------------------------------------------------------------------------------
static inline auto to_string(const program_arg& arg) {
    return arg.get_string();
}
//------------------------------------------------------------------------------
static inline auto operator<<(std::ostream& out, const program_arg& arg)
  -> std::ostream& {
    return out << arg.get();
}
//------------------------------------------------------------------------------
class program_arg_iterator {
    using this_class = program_arg_iterator;

public:
    program_arg_iterator(program_arg arg) noexcept
      : _a{arg} {}

    using value_type = program_arg;
    using difference_type = int;
    using reference = program_arg&;
    using const_reference = const program_arg&;
    using pointer = program_arg*;
    using const_pointer = const program_arg*;
    using iterator_category = std::random_access_iterator_tag;

    friend auto operator==(const this_class& l, const this_class& r) noexcept {
        return _cmp(l._a, r._a) == 0;
    }

    friend auto operator!=(const this_class& l, const this_class& r) noexcept {
        return _cmp(l._a, r._a) != 0;
    }

    friend auto operator<=(const this_class& l, const this_class& r) noexcept {
        return _cmp(l._a, r._a) <= 0;
    }

    friend auto operator>=(const this_class& l, const this_class& r) noexcept {
        return _cmp(l._a, r._a) >= 0;
    }

    friend auto operator<(const this_class& l, const this_class& r) noexcept {
        return _cmp(l._a, r._a) < 0;
    }

    friend auto operator>(const this_class& l, const this_class& r) noexcept {
        return _cmp(l._a, r._a) > 0;
    }

    friend auto operator-(const this_class& l, const this_class& r) noexcept
      -> difference_type {
        return _cmp(l._a, r._a);
    }

    auto operator++() noexcept -> this_class& {
        ++_a._argi;
        return *this;
    }

    auto operator--() noexcept -> this_class& {
        --_a._argi;
        return *this;
    }

    auto operator++(int) noexcept -> this_class {
        this_class result{*this};
        ++_a._argi;
        return result;
    }

    auto operator--(int) noexcept -> this_class {
        this_class result{*this};
        --_a._argi;
        return result;
    }

    auto operator+=(difference_type dist) noexcept -> this_class& {
        _a._argi += dist;
        return *this;
    }

    auto operator-=(difference_type dist) noexcept -> this_class& {
        _a._argi -= dist;
        return *this;
    }

    auto operator+(difference_type dist) noexcept -> this_class {
        this_class result{*this};
        result._a._argi += dist;
        return result;
    }

    auto operator-(difference_type dist) noexcept -> this_class {
        this_class result{*this};
        result._a._argi -= dist;
        return result;
    }

    auto operator*() noexcept -> reference {
        return _a;
    }

    auto operator*() const noexcept -> const_reference {
        return _a;
    }

private:
    static auto _cmp(const program_arg& l, const program_arg& r) noexcept
      -> int {
        EAGINE_ASSERT(l._argv == r._argv);
        return l._argi - r._argi;
    }

    program_arg _a{};
};
//------------------------------------------------------------------------------
class program_parameters {
private:
    struct _intf {
        _intf() noexcept = default;
        _intf(_intf&&) noexcept = delete;
        _intf(const _intf&) noexcept = delete;
        auto operator=(_intf&&) noexcept = delete;
        auto operator=(const _intf&) noexcept = delete;
        virtual ~_intf() = default;

        virtual auto parse(program_arg&, std::ostream&) -> bool = 0;

        virtual auto has_valid_value() const -> bool = 0;
        virtual auto validate(std::ostream&) const -> bool = 0;

        virtual auto short_tag() const -> string_view = 0;
        virtual auto long_tag() const -> string_view = 0;
        virtual auto description() const -> string_view = 0;
        virtual auto placeholder() const -> string_view = 0;
    };

    template <typename T>
    struct _impl : _intf {
        program_parameter<T>* _pparam;
        string_view _plchldr;

        auto _param() noexcept -> auto& {
            EAGINE_ASSERT(_pparam != nullptr);
            return *_pparam;
        }

        auto _param() const noexcept -> auto& {
            EAGINE_ASSERT(_pparam != nullptr);
            return *_pparam;
        }

        template <typename X>
        static auto _plchldr_name(type_identity<X>) noexcept -> string_view {
            if(std::is_same_v<X, bool>) {
                return {"BOOLEAN"};
            }
            if(std::is_same_v<X, string_view>) {
                return {"STRING"};
            }
            if(std::is_integral_v<X>) {
                return {"INTEGER"};
            }
            if(std::is_floating_point_v<X>) {
                return {"FLOAT"};
            }
            // TODO: be more precise depending on X
            return {"VALUE"};
        }

        template <typename X, typename P, typename L>
        static auto _plchldr_name(type_identity<valid_if<X, P, L>>) noexcept {
            return _plchldr_name(type_identity<X>());
        }

        template <typename X, typename A>
        static auto _plchldr_name(type_identity<std::vector<X, A>>) noexcept {
            return _plchldr_name(type_identity<X>());
        }

        _impl(program_parameter<T>& param) noexcept
          : _pparam{&param}
          , _plchldr{_plchldr_name(type_identity<T>())} {}

        auto parse(program_arg& arg, std::ostream& log) -> bool override {
            return arg.parse_param(_param(), log);
        }

        auto has_valid_value() const -> bool override {
            return _param().has_valid_value();
        }

        auto validate(std::ostream& log) const -> bool override {
            return _param().validate(log);
        }

        auto short_tag() const -> string_view override {
            return _param().short_tag();
        }

        auto long_tag() const -> string_view override {
            return _param().long_tag();
        }

        auto description() const -> string_view override {
            return _param().description();
        }

        auto placeholder() const -> string_view override {
            return _plchldr;
        }
    };

    std::vector<std::unique_ptr<_intf>> _params;

    static auto _insert(std::vector<std::unique_ptr<_intf>>& dest) noexcept
      -> auto& {
        return dest;
    }

    template <typename... Intf>
    static auto _insert(
      std::vector<std::unique_ptr<_intf>>& dest,
      std::unique_ptr<_intf>&& param,
      std::unique_ptr<Intf>&&... params) noexcept -> auto& {
        EAGINE_ASSERT(param != nullptr);
        dest.push_back(std::move(param));
        return _insert(dest, std::move(params)...);
    }

    template <typename... Intf>
    static auto _make(std::unique_ptr<Intf>&&... params) {
        std::vector<std::unique_ptr<_intf>> result;
        result.reserve(sizeof...(params));
        return std::move(_insert(result, std::move(params)...));
    }

public:
    template <typename... T>
    program_parameters(program_parameter<T>&... params)
      : _params(_make(std::unique_ptr<_intf>(new _impl<T>(params))...)) {}

    auto size() const noexcept -> span_size_t {
        return span_size(_params.size());
    }

    auto parse(program_arg& arg, std::ostream& log) -> bool {
        for(auto& param : _params) {
            EAGINE_ASSERT(param != nullptr);
            if(param->parse(arg, log)) {
                return true;
            }
        }
        return false;
    }

    auto validate(std::ostream& log) const -> bool {
        bool all_ok = true;
        for(const auto& param : _params) {
            EAGINE_ASSERT(param != nullptr);
            all_ok &= param->validate(log);
        }
        return all_ok;
    }

    auto print_usage(std::ostream& out, string_view command) -> std::ostream& {
        out << "Usage: " << command;

        span_size_t stag_maxl = 0;
        span_size_t ltag_maxl = 0;

        for(const auto& param : _params) {
            EAGINE_ASSERT(param != nullptr);

            out << " ";

            bool mandatory = !param->has_valid_value();

            out << (mandatory ? '<' : '[');

            out << param->short_tag() << "|" << param->long_tag();
            out << " " << param->placeholder();

            out << (mandatory ? '>' : ']');

            if(stag_maxl < param->short_tag().size()) {
                stag_maxl = param->short_tag().size();
            }

            if(ltag_maxl < param->long_tag().size()) {
                ltag_maxl = param->long_tag().size();
            }
        }
        out << std::endl;
        out << "  Options:" << std::endl;

        span_size_t padl;

        for(const auto& param : _params) {
            padl = 4 + stag_maxl - param->short_tag().size();
            while(padl-- > 0) {
                out << " ";
            }
            out << param->short_tag() << "|";

            out << param->long_tag();
            padl = ltag_maxl - param->long_tag().size();
            while(padl-- > 0) {
                out << " ";
            }
            out << ": " << param->description() << std::endl;
        }

        return out;
    }
};
//------------------------------------------------------------------------------
class program_args {
private:
    int _argc{0};
    const char** _argv{nullptr};

public:
    program_args() noexcept = default;

    program_args(span_size_t argn, char** args) noexcept
      : _argc(int(argn))
      , _argv(const_cast<const char**>(args)) {}

    program_args(span_size_t argn, const char** args) noexcept
      : _argc(int(argn))
      , _argv(args) {}

    using value_type = string_view;
    using size_type = int;
    using valid_index = valid_range_index<program_args>;
    using iterator = program_arg_iterator;

    auto argc() const noexcept -> int {
        return _argc;
    }

    auto argv() const noexcept -> const char** {
        return _argv;
    }

    auto empty() const noexcept -> bool {
        return _argc <= 0;
    }

    auto none() const noexcept -> bool {
        return _argc <= 1;
    }

    auto size() const noexcept -> int {
        return _argc;
    }

    auto is_valid(const valid_index& pos) const noexcept -> bool {
        return pos.is_valid(*this) && (_argv != nullptr) &&
               (_argv[pos.value_or(-1, *this)] != nullptr);
    }

    auto get(const valid_index& pos) const noexcept -> value_type {
        EAGINE_ASSERT(is_valid(pos));
        return value_type(_argv[pos.value_anyway(*this)]);
    }

    auto operator[](const valid_index& pos) const noexcept -> value_type {
        return get(pos);
    }

    auto command() const noexcept -> value_type {
        return get(0);
    }

    auto first() const noexcept -> program_arg {
        return program_arg(1, _argc, _argv);
    }

    auto begin() const noexcept -> iterator {
        return {program_arg(1, _argc, _argv)};
    }

    auto end() const noexcept -> iterator {
        return {program_arg(_argc, _argc, _argv)};
    }

    auto find(string_view what) const noexcept -> program_arg {
        int i = 1;
        while(i < _argc) {
            if((_argv != nullptr) && (_argv[i] != nullptr)) {
                if(are_equal(string_view(_argv[i]), what)) {
                    break;
                }
            }
            ++i;
        }
        return {i, _argc, _argv};
    }

    template <typename T>
    auto parse_param(program_parameter<T>& param, std::ostream& errlog) const
      -> bool {
        for(program_arg a = first(); a; a = a.next()) {
            if(a.parse_param(param, errlog)) {
                return true;
            }
        }
        return false;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_PROGRAM_ARGS_HPP
