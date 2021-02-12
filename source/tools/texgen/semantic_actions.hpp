/// @file texgen/semantic_actions.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef TEXGEN_SEMANTIC_ACTIONS_HPP // NOLINT(llvm-header-guard)
#define TEXGEN_SEMANTIC_ACTIONS_HPP

#include "input_location.hpp"
#include "token_info.hpp"
#include <memory>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
struct semantic_actions_intf {
    semantic_actions_intf() noexcept = default;
    semantic_actions_intf(semantic_actions_intf&&) = delete;
    semantic_actions_intf(const semantic_actions_intf&) = delete;
    auto operator=(semantic_actions_intf&&) = delete;
    auto operator=(const semantic_actions_intf&) = delete;
    virtual ~semantic_actions_intf() noexcept = default;

    virtual void begin() = 0;
    virtual void finish() = 0;
};
//------------------------------------------------------------------------------
class semantic_actions {
public:
    semantic_actions(std::shared_ptr<semantic_actions_intf> pimpl)
      : _pimpl(std::move(pimpl)) {}

    void begin() const {
        if(_pimpl) {
            _pimpl->begin();
        }
    }

    void finish() const {
        if(_pimpl) {
            _pimpl->finish();
        }
    }

private:
    std::shared_ptr<semantic_actions_intf> _pimpl;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen

#endif // TEXGEN_SEMANTIC_ACTIONS_HPP
