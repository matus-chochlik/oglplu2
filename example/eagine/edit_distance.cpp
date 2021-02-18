/// @example eagine/edit_distance.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/integer_range.hpp>
#include <eagine/memory/span_algo.hpp>
#include <eagine/span.hpp>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

auto main() -> int {
    using namespace eagine;

    std::ifstream input("/usr/share/dict/words");
    std::vector<std::string> words;
    std::string word;

    while(std::getline(input, word).good()) {
        words.emplace_back(std::move(word));
    }

    while(std::getline(std::cin, word).good()) {
        std::size_t min_idx = words.size();
        auto min_dist = span_size(word.length() + 1);
        for(auto idx : integer_range(words.size())) {
            const auto dist = memory::basic_edit_distance<span_size_t>(
              view(word), view(words[idx]), [](auto c1, auto c2) {
                  return std::tolower(c1) == std::tolower(c2) ? 0 : 1;
              });
            if(min_dist > dist) {
                min_dist = dist;
                min_idx = idx;
            }
        }
        if(min_idx < words.size()) {
            if(min_dist == 0) {
                std::cout << "Found: " << words[min_idx] << std::endl;
            } else {
                std::cout << "Did you mean " << words[min_idx] << '?'
                          << std::endl;
            }
        } else {
            std::cout << "Did not find nothing similar" << std::endl;
        }
    }

    return 0;
}
