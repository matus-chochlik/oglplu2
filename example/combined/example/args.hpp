/**
 *  .file oglplus/example/args.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_ARGS_HPP
#define OGLPLUS_EXAMPLE_ARGS_HPP

#include <eagine/string_span.hpp>
#include <eagine/valid_if/not_empty.hpp>

namespace eagine {

class logger;
class program_arg;
class program_args;

class example_arg;
class example_args;

class example_param_tags {
protected:
    string_view _stag;
    string_view _ltag;

    friend class example_arg;
    friend class example_args;

public:
    example_param_tags(string_view stag, string_view ltag) noexcept
      : _stag(stag)
      , _ltag(ltag) {
    }
};

template <typename T>
class example_param;

template <typename T, typename P>
class example_param<valid_if<T, P>> : public example_param_tags {
private:
    valid_if<T, P> _value;

    friend class example_args;

public:
    example_param(string_view stag, string_view ltag, T initial)
      : example_param_tags(stag, ltag)
      , _value(initial) {
    }

    operator const T&() const noexcept {
        return _value.value();
    }
};

using example_string_param = example_param<valid_if_not_empty<string_view>>;

class example_arg {
private:
    const program_arg& _arg;

public:
    example_arg(const program_arg& arg) noexcept
      : _arg(arg) {
    }

    bool operator==(const example_param_tags& tags) const noexcept;
};

class example_args {
private:
    const program_args& _args;
    logger& _log;

    template <typename T>
    bool _parse_param(example_param<T>& param) const;

public:
    example_args(const program_args& args, logger& log) noexcept
      : _args(args)
      , _log(log) {
    }

    const program_args& args() const noexcept {
        return _args;
    }

    int argc() const noexcept;

    const char** argv() const noexcept;

    bool parse_param(example_string_param& param) const;
};

} // namespace eagine

#endif // OGLPLUS_EXAMPLE_ARGS_HPP
