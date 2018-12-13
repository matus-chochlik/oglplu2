/**
 *  @file eagine/program_args.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_PROGRAM_ARGS_1509260923_HPP
#define EAGINE_PROGRAM_ARGS_1509260923_HPP

#include "identity.hpp"
#include "program_args.hpp"
#include "range_types.hpp"
#include "span.hpp"
#include "std/type_traits.hpp"
#include "string_span.hpp"
#include "type_name.hpp"
#include "valid_if/in_list.hpp"
#include <cassert>
#include <memory>
#include <sstream>
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
      string_view short_tag, string_view long_tag) noexcept
      : _short_tag(short_tag)
      , _long_tag(long_tag) {
    }

public:
    constexpr string_view short_tag() const noexcept {
        return _short_tag;
    }

    constexpr string_view long_tag() const noexcept {
        return _long_tag;
    }

    constexpr string_view description() const noexcept {
        return _description;
    }

    constexpr basic_program_parameter& description(
      string_view help_str) noexcept {
        _description = help_str;
        return *this;
    }
};
//------------------------------------------------------------------------------
template <typename T>
class program_parameter : public basic_program_parameter {
private:
    T _value;

    template <typename X>
    static inline bool _is_valid(const X&) noexcept {
        return true;
    }

    template <typename X, typename P>
    static inline bool _is_valid(const valid_if<X, P>& vi) noexcept {
        return vi.is_valid();
    }

    template <typename X>
    static inline void _log_invalid(const X&, const std::ostream&) noexcept {
    }

    template <typename X, typename P>
    static inline void _log_invalid(
      const valid_if<X, P>& vi, std::ostream& log) noexcept {
        vi.log_invalid(log);
    }

    template <typename X>
    static T& _get_value(X& val) noexcept {
        return val;
    }

    template <typename X>
    static const T& _get_value(const X& val) noexcept {
        return val;
    }

    template <typename X, typename P>
    static X& _get_value(valid_if<X, P>& vi) noexcept {
        return vi.value();
    }

    template <typename X, typename P>
    static const X& _get_value(const valid_if<X, P>& vi) noexcept {
        return vi.value();
    }

public:
    program_parameter(
      string_view short_tag, string_view long_tag, const T& initial) noexcept
      : basic_program_parameter(short_tag, long_tag)
      , _value(initial) {
    }

    T& ref() noexcept {
        return _value;
    }

    bool has_valid_value() const noexcept {
        return _is_valid(_value);
    }

    std::ostream& log_invalid_value(std::ostream& log) const {
        log << "Invalid value of parameter " << long_tag() << ": ";
        _log_invalid(_value, log);
        return log << ". ";
    }

    bool validate(std::ostream& log) const {
        if(!has_valid_value()) {
            log_invalid_value(log) << std::endl;
            return false;
        }
        return true;
    }

    const auto& value() const noexcept {
        return _get_value(_value);
    }

    operator const T&() const noexcept {
        return _value;
    }
};

template <typename T>
class program_parameter_alias : public basic_program_parameter {
private:
    program_parameter<T>& _aliased;

public:
    program_parameter_alias(const program_parameter_alias&) = delete;

    program_parameter_alias(
      string_view short_tag,
      string_view long_tag,
      program_parameter<T>& that) noexcept
      : basic_program_parameter(short_tag, long_tag)
      , _aliased(that) {
    }

    T& ref() noexcept {
        return _aliased.ref();
    }

    const auto& value() const noexcept {
        return _aliased.value();
    }

    operator const T&() const noexcept {
        return static_cast<const T&>(_aliased);
    }
};

template <>
class program_parameter<void> : public basic_program_parameter {
private:
    span_size_t _count;

public:
    program_parameter(string_view short_tag, string_view long_tag) noexcept
      : basic_program_parameter(short_tag, long_tag)
      , _count(0) {
    }

    void increment() noexcept {
        ++_count;
    }

    bool has_valid_value() const noexcept {
        return true;
    }

    std::ostream& log_invalid_value(std::ostream& log) const noexcept {
        return log;
    }

    bool validate(std::ostream&) const noexcept {
        return true;
    }

    span_size_t value() const noexcept {
        return _count;
    }
};

using program_option = program_parameter<void>;

class program_arg {
private:
    int _argi;
    int _argc;
    const char** _argv;

    program_arg(int argi, int argc, const char** argv) noexcept
      : _argi(argi)
      , _argc(argc)
      , _argv(argv) {
    }

    friend class program_args;

    template <typename T>
    bool _do_parse(T& dest, const std::ostream&) {
        std::stringstream ss(get_string());
        return !((ss >> dest).fail() || !ss.eof());
    }

    bool _do_parse(string_view& dest, const std::ostream&) {
        dest = get();
        return true;
    }

    bool _do_parse(std::string& dest, const std::ostream&) {
        dest = get_string();
        return true;
    }

    template <typename T, typename P>
    bool _do_parse(valid_if<T, P>& dest, std::ostream& parse_log) {
        T value;
        if(parse(value, parse_log)) {
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

    template <typename T, typename A>
    bool _do_parse(std::vector<T, A>& dest, std::ostream& parse_log) {
        T value;
        if(parse(value, parse_log)) {
            dest.push_back(std::move(value));
            return true;
        }
        return false;
    }

public:
    program_arg() noexcept
      : _argi(0)
      , _argc(0)
      , _argv(nullptr) {
    }

    using value_type = string_view;

    bool is_valid() const noexcept {
        return (0 < _argi) && (_argi < _argc) && (_argv != nullptr) &&
               (_argv[_argi] != nullptr);
    }

    operator bool() const noexcept {
        return is_valid();
    }

    bool operator!() const noexcept {
        return !is_valid();
    }

    value_type get() const noexcept {
        if(is_valid()) {
            return value_type(_argv[_argi]);
        }
        return value_type();
    }

    std::string get_string() const {
        return get().to_string();
    }

    operator value_type() const noexcept {
        return get();
    }

    bool is_tag(string_view short_tag, string_view long_tag) const noexcept {
        return are_equal(get(), short_tag) || are_equal(get(), long_tag);
    }

    bool is_tag_param(const basic_program_parameter& param) const {
        return is_tag(param.short_tag(), param.long_tag());
    }

    bool is_help_arg() const noexcept {
        return is_tag(string_view("-h"), string_view("--help"));
    }

    program_arg next() const noexcept {
        return program_arg(_argi + 1, _argc, _argv);
    }

    program_arg prev() const noexcept {
        return program_arg(_argi - 1, _argc, _argv);
    }

    template <typename T>
    bool parse(T& dest, std::ostream& parse_log) {
        if(is_valid()) {
            T temp = dest;
            if(_do_parse(temp, parse_log)) {
                dest = std::move(temp);
                return true;
            }
        }
        return false;
    }

    template <typename T>
    bool parse_next(T& dest, std::ostream& parse_log) {
        return next().parse(dest, parse_log);
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
    bool do_consume_next(
      T& dest, MissingFunc handle_missing, InvalidFunc handle_invalid) {
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
    bool consume_next(T& dest, std::ostream& errorlog) {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_consume_next(dest, if_missing, if_invalid);
    }

    template <typename T, typename MissingFunc, typename InvalidFunc>
    bool do_parse_param(
      program_parameter<T>& param,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        if(is_tag_param(param)) {
            return do_consume_next(param.ref(), handle_missing, handle_invalid);
        }
        return false;
    }

    template <typename MissingFunc, typename InvalidFunc>
    bool do_parse_param(
      program_parameter<void>& param, const MissingFunc&, const InvalidFunc&) {
        if(is_tag_param(param)) {
            param.increment();
            return true;
        }
        return false;
    }

    template <typename T>
    bool parse_param(program_parameter<T>& param, std::ostream& errorlog) {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_parse_param(param, if_missing, if_invalid);
    }

    template <typename T, typename MissingFunc, typename InvalidFunc>
    bool do_consume_next(
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

    template <typename T, typename P, class MissingFunc, class InvalidFunc>
    bool do_consume_next(
      valid_if<T, P>& dest,
      span<const T> choices,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        T temp;
        if(do_consume_next(temp, choices, handle_missing, handle_invalid)) {
            if(dest.is_valid(temp)) {
                dest = std::move(temp);
                return true;
            }
        }
        return false;
    }

    template <typename T, typename C>
    bool consume_next(T& dest, span<const C> choices, std::ostream& errorlog) {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_consume_next(dest, choices, if_missing, if_invalid);
    }

    template <typename T, typename C, class MissingFunc, class InvalidFunc>
    bool do_parse_param(
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
    bool parse_param(
      program_parameter<T>& param,
      span<const C> choices,
      std::ostream& errorlog) {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_parse_param(param, choices, if_missing, if_invalid);
    }

    template <typename T, typename MissingFunc, typename InvalidFunc>
    bool do_consume_next(
      T& dest,
      span<const string_view> symbols,
      span<const T> translations,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        assert(symbols.size() <= translations.size());

        string_view parsed;
        if(do_consume_next(parsed, symbols, handle_missing, handle_invalid)) {
            for(span_size_t i = 0, n = symbols.size(); i < n; ++i) {
                if(are_equal(parsed, symbols[i])) {
                    dest = translations[i];
                    return true;
                }
            }
        }
        return false;
    }

    template <typename T, typename P, class MissingFunc, class InvalidFunc>
    bool do_consume_next(
      valid_if<T, P>& dest,
      span<const string_view> symbols,
      span<const T> translations,
      MissingFunc handle_missing,
      InvalidFunc handle_invalid) {
        T temp;
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
    bool consume_next(
      T& dest,
      span<const string_view> symbols,
      span<const R> translations,
      std::ostream& errorlog) {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_consume_next(
          dest, symbols, translations, if_missing, if_invalid);
    }

    template <typename T, typename R, class MissingFunc, class InvalidFunc>
    bool do_parse_param(
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
    bool parse_param(
      program_parameter<T>& param,
      span<const string_view> symbols,
      span<const R> translations,
      std::ostream& errorlog) {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_parse_param(
          param, symbols, translations, if_missing, if_invalid);
    }

    template <typename T, typename R, class MissingFunc, class InvalidFunc>
    bool do_parse_param(
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
    bool parse_param(
      program_parameter_alias<T>& param,
      span<const string_view> symbols,
      span<const R> translations,
      std::ostream& errorlog) {
        auto if_missing = missing_handler(errorlog);
        auto if_invalid = invalid_handler(errorlog);
        return do_parse_param(
          param, symbols, translations, if_missing, if_invalid);
    }

    bool operator==(const value_type& v) const noexcept {
        return are_equal(get(), v);
    }

    bool operator!=(const value_type& v) const noexcept {
        return are_equal(get(), v);
    }
};

class program_parameters {
private:
    struct _intf {
        virtual ~_intf() = default;

        virtual bool parse(program_arg&, std::ostream&) = 0;

        virtual bool has_valid_value() const = 0;
        virtual bool validate(std::ostream&) const = 0;

        virtual string_view short_tag() const = 0;
        virtual string_view long_tag() const = 0;
        virtual string_view description() const = 0;
        virtual string_view placeholder() const = 0;
    };

    template <typename T>
    struct _impl : _intf {
        program_parameter<T>* _pparam;
        string_view _plchldr;

        program_parameter<T>& _param() noexcept {
            assert(_pparam != nullptr);
            return *_pparam;
        }

        const program_parameter<T>& _param() const noexcept {
            assert(_pparam != nullptr);
            return *_pparam;
        }

        template <typename X>
        static string_view _plchldr_name(identity<X>) noexcept {
            if(std::is_same_v<X, bool>) {
                return string_view("BOOLEAN");
            }
            if(std::is_same_v<X, string_view>) {
                return string_view("STRING");
            }
            if(std::is_integral_v<X>) {
                return string_view("INTEGER");
            }
            if(std::is_floating_point_v<X>) {
                return string_view("FLOAT");
            }
            // TODO: be more precise depending on X
            return string_view("VALUE");
        }

        template <typename X, typename P, typename L>
        static string_view _plchldr_name(identity<valid_if<X, P, L>>) noexcept {
            return _plchldr_name(identity<X>());
        }

        template <typename X, typename A>
        static string_view _plchldr_name(identity<std::vector<X, A>>) noexcept {
            return _plchldr_name(identity<X>());
        }

        _impl(program_parameter<T>& param) noexcept
          : _pparam(&param)
          , _plchldr(_plchldr_name(identity<T>())) {
        }

        bool parse(program_arg& arg, std::ostream& log) override {
            return arg.parse_param(_param(), log);
        }

        bool has_valid_value() const override {
            return _param().has_valid_value();
        }

        bool validate(std::ostream& log) const override {
            return _param().validate(log);
        }

        string_view short_tag() const override {
            return _param().short_tag();
        }

        string_view long_tag() const override {
            return _param().long_tag();
        }

        string_view description() const override {
            return _param().description();
        }

        string_view placeholder() const override {
            return _plchldr;
        }
    };

    std::vector<std::unique_ptr<_intf>> _params;

    static inline std::vector<std::unique_ptr<_intf>>& _insert(
      std::vector<std::unique_ptr<_intf>>& dest) noexcept {
        return dest;
    }

    template <typename... Intf>
    static inline std::vector<std::unique_ptr<_intf>>& _insert(
      std::vector<std::unique_ptr<_intf>>& dest,
      std::unique_ptr<_intf>&& param,
      std::unique_ptr<Intf>&&... params) noexcept {
        assert(param != nullptr);
        dest.push_back(std::move(param));
        return _insert(dest, std::move(params)...);
    }

    template <typename... Intf>
    static std::vector<std::unique_ptr<_intf>> _make(
      std::unique_ptr<Intf>&&... params) {
        std::vector<std::unique_ptr<_intf>> result;
        result.reserve(sizeof...(params));
        return std::move(_insert(result, std::move(params)...));
    }

public:
    template <typename... T>
    program_parameters(program_parameter<T>&... params)
      : _params(_make(std::unique_ptr<_intf>(new _impl<T>(params))...)) {
    }

    span_size_t size() const noexcept {
        return span_size(_params.size());
    }

    bool parse(program_arg& arg, std::ostream& log) {
        for(auto& param : _params) {
            assert(param != nullptr);
            if(param->parse(arg, log)) {
                return true;
            }
        }
        return false;
    }

    bool validate(std::ostream& log) const {
        bool all_ok = true;
        for(const auto& param : _params) {
            assert(param != nullptr);
            all_ok &= param->validate(log);
        }
        return all_ok;
    }

    std::ostream& print_usage(std::ostream& out, string_view command) {
        out << "Usage: " << command;

        span_size_t stag_maxl = 0;
        span_size_t ltag_maxl = 0;

        for(const auto& param : _params) {
            assert(param != nullptr);

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
            while(padl-- > 0)
                out << " ";
            out << param->short_tag() << "|";

            out << param->long_tag();
            padl = ltag_maxl - param->long_tag().size();
            while(padl-- > 0)
                out << " ";
            out << ": " << param->description() << std::endl;
        }

        return out;
    }
};

class program_args {
private:
    int _argc;
    const char** _argv;

public:
    program_args() noexcept
      : _argc(0)
      , _argv(nullptr) {
    }

    program_args(span_size_t argn, char** args) noexcept
      : _argc(int(argn))
      , _argv(const_cast<const char**>(args)) {
    }

    program_args(span_size_t argn, const char** args) noexcept
      : _argc(int(argn))
      , _argv(args) {
    }

    using value_type = string_view;
    using size_type = int;
    using valid_index = valid_range_index<program_args>;

    int argc() const noexcept {
        return _argc;
    }

    const char** argv() const noexcept {
        return _argv;
    }

    bool empty() const noexcept {
        return _argc <= 0;
    }

    bool none() const noexcept {
        return _argc <= 1;
    }

    int size() const noexcept {
        return _argc;
    }

    bool is_valid(valid_index pos) const noexcept {
        return pos.is_valid(*this) && (_argv != nullptr) &&
               (_argv[pos.value(*this)] != nullptr);
    }

    value_type get(valid_index pos) const noexcept {
        assert(is_valid(pos));
        return value_type(_argv[pos.value(*this)]);
    }

    value_type operator[](valid_index pos) const noexcept {
        return get(pos);
    }

    value_type command() const noexcept {
        return get(0);
    }

    program_arg first() const noexcept {
        return program_arg(1, _argc, _argv);
    }

    template <typename T>
    bool parse_param(program_parameter<T>& param, std::ostream& errlog) const {
        for(program_arg a = first(); a; a = a.next()) {
            if(a.parse_param(param, errlog)) {
                return true;
            }
        }
        return false;
    }
};

} // namespace eagine

#endif // include guard
