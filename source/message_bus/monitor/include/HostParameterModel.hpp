///
/// Copyright Matus Chochlik.
//// Distributed under the GNU GENERAL PUBLIC LICENSE version 3.
/// See http://www.gnu.org/licenses/gpl-3.0.txt
//

#ifndef EAGINE_MESSAGE_BUS_MONITOR_HOST_PARAMETER_MODEL
#define EAGINE_MESSAGE_BUS_MONITOR_HOST_PARAMETER_MODEL

#include <eagine/main_ctx_object.hpp>
#include <eagine/value_with_history.hpp>

class TrackerModel;
//------------------------------------------------------------------------------
class HostParameterModel {

public:
    auto count() const noexcept {
        return 64;
    }

    auto shortAverageLoadHistory() const noexcept -> auto& {
        return _short_average_load_history.as_value();
    }

    auto longAverageLoadHistory() const noexcept -> auto& {
        return _long_average_load_history.as_value();
    }

private:
    friend class TrackerModel;

    eagine::variable_with_history<float, 64> _short_average_load_history;
    eagine::variable_with_history<float, 64> _long_average_load_history;
};
//------------------------------------------------------------------------------
#endif
