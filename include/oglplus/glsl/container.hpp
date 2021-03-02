/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GLSL_CONTAINER_HPP
#define OGLPLUS_GLSL_CONTAINER_HPP

#include "string_ref.hpp"
#include <string>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Base class typically storing GLSL source code strings.
/// @ingroup glsl_utils
template <typename Container>
class glsl_container {
public:
    /// @brief Default constructor.
    glsl_container() = default;

    /// @brief Construction from the storage container.
    glsl_container(Container storage) noexcept
      : _storage(std::move(storage))
      , _str_ref(_storage.data(), _storage.size()) {}

    /// @brief Returns a reference to the storage container.
    auto storage() noexcept -> Container& {
        return _storage;
    }

    /// @brief Conversion to glsl_string_ref.
    operator glsl_source_ref() const noexcept {
        return _str_ref;
    }

private:
    Container _storage;
    glsl_string_ref _str_ref;
};

using glsl_string = glsl_container<std::string>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GLSL_CONTAINER_HPP
