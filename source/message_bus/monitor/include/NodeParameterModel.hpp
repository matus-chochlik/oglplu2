///
/// Copyright Matus Chochlik.
//// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
//

#ifndef EAGINE_MESSAGE_BUS_MONITOR_NODE_PARAMETER_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_NODE_PARAMETER_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/value_with_history.hpp>

class TrackerModel;
//------------------------------------------------------------------------------
class NodeParameterModel {

public:
    auto count() const noexcept {
        return 64;
    }

    auto pingSuccessRateHistory() const noexcept -> auto& {
        return _ping_success_rate_history.as_value();
    }

private:
    friend class TrackerModel;

    eagine::variable_with_history<float, 64> _ping_success_rate_history;
};
//------------------------------------------------------------------------------
#endif
