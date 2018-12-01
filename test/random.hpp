/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_TEST_RANDOM_1510290655_HPP
#define EAGINE_TEST_RANDOM_1510290655_HPP

#include <type_traits>
#include <array>
#include <cctype>
#include <limits>
#include <random>
#include <string>
#include <vector>
#include <eagine/span.hpp>
#include <eagine/string_span.hpp>
#include <eagine/types.hpp>

namespace eagine {

class test_random_generator {
private:
    std::mt19937 _re;

public:
    test_random_generator(void)
      : _re(std::random_device()()) {
    }

    template <typename T>
    T get_integer(T min, T max) {
        return std::uniform_int_distribution<T>(min, max)(_re);
    }

    template <typename R>
    R get_real(R min, R max) {
        return std::uniform_real_distribution<R>(min, max)(_re);
    }

    template <typename T>
    typename std::enable_if<std::is_same<T, bool>::value, T>::type get(T, T) {
        return get_integer<int>(0, 1) == 1;
    }

    template <typename T>
    typename std::enable_if<
      std::is_integral<T>::value && !std::is_same<T, bool>::value,
      T>::type
    get(T min, T max) {
        return get_integer<T>(min, max);
    }

    template <typename T>
    typename std::enable_if<std::is_floating_point<T>::value, T>::type get(
      T min, T max) {
        return get_real<T>(min, max);
    }

    template <typename T>
    T get_any(void) {
        return get(
          std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    }

    bool get_bool(void) {
        return get_integer<int>(0, 1) == 1;
    }

    char get_char(char min, char max) {
        return get_integer<char>(min, max);
    }

    unsigned char get_byte(unsigned char min, unsigned char max) {
        return get_integer<unsigned char>(min, max);
    }

    char get_char_from(cstring_span chars) {
        return chars[get_span_size(0, chars.size() - 1)];
    }

    int get_short(short min, short max) {
        return get_integer<short>(min, max);
    }

    int get_int(int min, int max) {
        return get_integer<int>(min, max);
    }

    unsigned get_uint(unsigned min, unsigned max) {
        return get_integer<unsigned>(min, max);
    }

    span_size_t get_span_size(span_size_t min, span_size_t max) {
        return get_integer<span_size_t>(min, max);
    }

    std::size_t get_std_size(std::size_t min, std::size_t max) {
        return get_integer<std::size_t>(min, max);
    }

    float get_float(float min, float max) {
        return get_real<float>(min, max);
    }

    double get_double(double min, double max) {
        return get_real<double>(min, max);
    }

    template <typename Pred>
    std::string get_string(std::size_t min, std::size_t max, Pred pred) {
        std::string result(get_std_size(min, max), '\0');
        for(char& c : result) {
            do {
                c = get_any<char>();
            } while(!pred(c));
        }
        return result;
    }

    std::string get_string(std::size_t min, std::size_t max) {
        return get_string(
          min, max, [](char c) { return std::isprint(c) != 0; });
    }

    std::string get_string_from(
      std::size_t min, std::size_t max, cstring_span chars) {
        std::string result(get_std_size(min, max), '\0');
        for(char& c : result) {
            c = get_char_from(chars);
        }
        return result;
    }

    template <typename T>
    void fill(std::vector<T>& v, T min, T max) {
        for(auto& e : v) {
            e = get<T>(min, max);
        }
    }

    template <typename T>
    void fill(std::vector<T>& v) {
        return fill(
          v, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    }

    template <typename T, std::size_t N>
    void fill(std::array<T, N>& a, T min, T max) {
        for(auto& e : a) {
            e = get<T>(min, max);
        }
    }

    template <typename T, std::size_t N>
    void fill(std::array<T, N>& a) {
        return fill(
          a, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    }
};

} // namespace eagine

#endif // include guard
