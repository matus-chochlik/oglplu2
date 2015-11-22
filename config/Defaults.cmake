#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
option(CONFIG_INFO_ONLY "Only generate the config/info.py script" Off)
option(CONFIG_SET_LOW_PROFILE "Set the LOW_PROFILE switch in site_config.hpp." Off)
option(CONFIG_STRICT_GL_VERSION_CHECK "Do rigorous GL version checking" On)

option(NO_EXAMPLES "Don't configure examples" Off)
option(NO_TESTS "Don't configure tests." Off)

set(HEADER_SEARCH_PATHS ${HEADER_SEARCH_PATHS};${PROJECT_SOURCE_DIR}/third_party/include)

