/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SPAN_HPP
#define EAGINE_SPAN_HPP

#include "memory/span.hpp"
#include "valid_if/decl.hpp"
#include <iosfwd>

namespace eagine {
//------------------------------------------------------------------------------
using memory::span;
//------------------------------------------------------------------------------
using memory::cover;
using memory::cover_one;
using memory::view;
using memory::view_one;
//------------------------------------------------------------------------------
/// @brief Helper function for pretty-printing spans as lists into output streams.
/// @ingroup memory
/// @see write_to_stream
/// @relates memory::basic_span
template <typename T, typename P, typename S, typename Output>
static inline auto list_to_stream(Output& out, memory::basic_span<T, P, S> s)
  -> Output& {
    out << '[';
    bool first = true;
    for(const auto& e : s) {
        if(first) {
            first = false;
        } else {
            out << ',';
        }
        out << e;
    }
    return out << ']';
}
//------------------------------------------------------------------------------
/// @brief Helper function for raw-reading spans from output streams.
/// @ingroup memory
/// @see write_to_stream
/// @relates memory::basic_span
template <typename Input, typename T, typename P, typename S>
static inline auto read_from_stream(Input& in, memory::basic_span<T, P, S> s)
  -> auto& {
    return in.read(
      reinterpret_cast<char*>(s.data()), limit_cast<std::streamsize>(s.size()));
}
//------------------------------------------------------------------------------
/// @brief Helper function for raw-reading spans into output streams.
/// @ingroup memory
/// @see read_from_stream
/// @see list_to_stream
/// @relates memory::basic_span
template <typename Output, typename T, typename P, typename S>
static inline auto write_to_stream(Output& out, memory::basic_span<T, P, S> s)
  -> auto& {
    return out.write(
      reinterpret_cast<const char*>(s.data()),
      limit_cast<std::streamsize>(s.size()));
}
//------------------------------------------------------------------------------
/// @brief Operator for printing generic element spans into output streams.
/// @ingroup memory
/// @see list_to_stream
/// @relates memory::basic_span
template <typename T, typename P, typename S>
static inline auto operator<<(std::ostream& out, memory::basic_span<T, P, S> s)
  -> std::
    enable_if_t<!std::is_same_v<std::remove_const_t<T>, char>, std::ostream&> {
    return list_to_stream(out, s);
}
//------------------------------------------------------------------------------
/// @brief Operator for printing spans of string characters into output streams.
/// @ingroup memory
/// @see write_to_stream
/// @relates memory::basic_span
template <typename T, typename P, typename S>
static inline auto operator<<(std::ostream& out, memory::basic_span<T, P, S> s)
  -> std::
    enable_if_t<std::is_same_v<std::remove_const_t<T>, char>, std::ostream&> {
    return write_to_stream(out, absolute(s));
}
//------------------------------------------------------------------------------
/// @brief Makes a callable that returns consecutive span elements starting at i.
/// @ingroup memory
/// @see make_span_putter
/// @relates memory::basic_span
///
/// The constructed callable object does not take any arguments in the call
/// operator and returns optional values of T.
template <typename T, typename P, typename S>
static inline auto
make_span_getter(span_size_t& i, memory::basic_span<T, P, S> spn) {
    return [&i, spn]() -> optionally_valid<std::remove_const_t<T>> {
        if(i < spn.size()) {
            return {spn[i++], true};
        }
        return {};
    };
}
//------------------------------------------------------------------------------
template <typename Src>
static inline auto make_span_getter(span_size_t& i, const Src& src) {
    return make_span_getter(i, view(src));
}
//------------------------------------------------------------------------------
/// @brief Makes a callable getting consecutive, transformed span elements starting at i.
/// @ingroup memory
/// @see make_span_putter
/// @relates memory::basic_span
///
/// The constructed callable object does not take any arguments in the call
/// operator and returns the result of the transform function.
/// The transform function takes a single optional value of T.
template <typename T, typename P, typename S, typename Transform>
static inline auto make_span_getter(
  span_size_t& i,
  memory::basic_span<T, P, S> spn,
  Transform transform) {
    return [&i, spn, transform]() -> decltype(transform(std::declval<T>())) {
        if(i < spn.size()) {
            return transform(spn[i++]);
        }
        return {};
    };
}
//------------------------------------------------------------------------------
template <typename Src, typename Transform>
static inline auto
make_span_getter(span_size_t& i, const Src& src, Transform transform) {
    return make_span_getter(i, view(src), std::move(transform));
}
//------------------------------------------------------------------------------
/// @brief Makes a callable setting consecutive elementsof a span starting at i.
/// @ingroup memory
/// @see make_span_getter
/// @relates memory::basic_span
///
/// The constructed callable takes a single value explicitly convertible to T.
template <typename T, typename P, typename S>
static inline auto
make_span_putter(span_size_t& i, memory::basic_span<T, P, S> spn) {
    return [&i, spn](auto value) mutable -> bool {
        if(i < spn.size()) {
            spn[i++] = T(std::move(value));
            return true;
        }
        return false;
    };
}
//------------------------------------------------------------------------------
template <typename Dst>
static inline auto make_span_putter(span_size_t& o, Dst& dst) {
    return make_span_putter(o, cover(dst));
}
//------------------------------------------------------------------------------
/// @brief Makes a callable setting consecutive elementsof a span starting at i.
/// @ingroup memory
/// @param transform transformation operation to the applied
/// @see make_span_getter
/// @relates memory::basic_span
/// The constructed callable takes a single value explicitly convertible to the
/// argument of the transform function.
template <typename T, typename P, typename S, typename Transform>
static inline auto make_span_putter(
  span_size_t& i,
  memory::basic_span<T, P, S> spn,
  Transform transform) {
    return [&i, spn, transform](auto value) mutable -> bool {
        if(i < spn.size()) {
            if(auto transformed = transform(value)) {
                spn[i++] = T(std::move(extract(transformed)));
                return true;
            }
        }
        return false;
    };
}
//------------------------------------------------------------------------------
template <typename Dst, typename Transform>
static inline auto
make_span_putter(span_size_t& o, Dst& dst, Transform transform) {
    return make_span_putter(o, cover(dst), std::move(transform));
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SPAN_HPP
