///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include "NodeViewModel.hpp"
#include "MonitorBackend.hpp"
//------------------------------------------------------------------------------
NodeViewModel::NodeViewModel(
  MonitorBackend& backend,
  eagine::identifier_t node_id)
  : QObject{nullptr}
  , eagine::main_ctx_object{EAGINE_ID(NodeVM), backend}
  , _backend{backend}
  , _node_id{node_id} {}
//------------------------------------------------------------------------------
