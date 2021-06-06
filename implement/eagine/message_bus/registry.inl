/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main_ctx.hpp>
#include <eagine/message_bus.hpp>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registered_entry::update_service() -> work_done {
    some_true something_done;
    if(EAGINE_LIKELY(_service)) {
        something_done(_service->update_and_process_all());
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
registry::registry(main_ctx_parent parent)
  : main_ctx_object{EAGINE_ID(MsgBusRgtr), parent}
  , _acceptor{std::make_shared<direct_acceptor>(*this)}
  , _router{*this} {
    _router.add_acceptor(_acceptor);

    setup_bus_connectors(_router);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registry::_add_entry(identifier log_id) -> registered_entry& {
    auto new_ept{std::make_unique<endpoint>(main_ctx_object{log_id, *this})};
    new_ept->add_connection(_acceptor->make_connection());

    _entries.emplace_back();
    auto& entry = _entries.back();

    entry._endpoint = std::move(new_ept);

    return entry;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void registry::remove(service_interface& service) {
    _entries.erase(
      std::remove_if(
        _entries.begin(),
        _entries.end(),
        [&service](auto& entry) { return entry._service.get() == &service; }),
      _entries.end());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registry::update() -> work_done {
    return _router.update(8);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto registry::update_all() -> work_done {
    some_true something_done{};

    something_done(_router.do_work());

    for(auto& entry : _entries) {
        something_done(entry.update_service());
    }

    something_done(_router.do_work());
    something_done(_router.do_maintenance());

    return something_done;
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus
