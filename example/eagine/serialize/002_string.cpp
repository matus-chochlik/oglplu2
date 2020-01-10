/**
 *  @example eagine/serialize/002_string.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/hexdump.hpp>
#include <eagine/map_data_members.hpp>
#include <eagine/serialize/istream_source.hpp>
#include <eagine/serialize/ostream_sink.hpp>
#include <eagine/serialize/read.hpp>
#include <eagine/serialize/string_backend.hpp>
#include <eagine/serialize/write.hpp>
#include <iostream>
#include <sstream>

namespace eagine {
//------------------------------------------------------------------------------
struct my_struct {
    bool b{false};
    char c{'\0'};
    double d{0.0};
    identifier i{};
    long l{};
    std::string s{};
    unsigned u{0U};
};
//------------------------------------------------------------------------------
template <identifier_t Id>
constexpr auto data_member_mapping(identity<my_struct>, selector<Id>) noexcept {
    using S = my_struct;
    return make_data_member_mapping<
      S,
      bool,
      char,
      double,
      identifier,
      long,
      std::string,
      unsigned>(
      {"b", &S::b},
      {"c", &S::c},
      {"d", &S::d},
      {"i", &S::i},
      {"l", &S::l},
      {"s", &S::s},
      {"u", &S::u});
}
//------------------------------------------------------------------------------
void baz(const my_struct& instance) {
    std::cout << instance.b;
    std::cout << instance.c;
    std::cout << instance.d;
    std::cout << instance.i.name();
    std::cout << instance.l;
    std::cout << instance.s;
    std::cout << instance.u;
    std::cout << std::endl;
}
//------------------------------------------------------------------------------
void bar(std::istream& data) {
    istream_data_source source(data);
    string_deserializer_backend backend(source);
    my_struct instance;
    auto member_map = map_data_members(instance);
    deserialize(member_map, backend);
    baz(instance);
}
//------------------------------------------------------------------------------
void foo(const my_struct& instance) {

    std::stringstream data;
    ostream_data_sink sink(data);
    string_serializer_backend backend(sink);
    auto member_map = map_data_members(instance);
    serialize(member_map, backend);
    std::cout << hexdump(as_bytes(view(data.str())));
    bar(data);
}
//------------------------------------------------------------------------------
} // namespace eagine

int main() {
    using namespace eagine;

    my_struct x;
    x.b = true;
    x.c = '2';
    x.d = 3.4;
    x.i = identifier("FiveSix");
    x.l = 7777777L;
    x.s = "eight";
    x.u = 90U;

    foo(x);

    return 0;
}
