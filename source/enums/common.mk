#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt)
#
ROOT = $(PARENT)/../..
MAKE_ENUM = $(PARENT)/make_enum.py

.PHONY: all
all: \
	_incl_enum_types_hpp \
	_incl_enum_values_hpp \
	_test_enums_cpp

.PHONY: _incl_enum_types_hpp
_incl_enum_types_hpp: $(ROOT)/include/$(LIBRARY)/enum_types.hpp

$(ROOT)/include/$(LIBRARY)/enum_types.hpp: $(SOURCES) $(MAKE_ENUM)
	$(MAKE_ENUM) \
		--library $(LIBRARY) \
		--base-lib-prefix $(LIB_PREFIX)\
		--action incl_enum_types_hpp \
		--output "$@" \
		$(filter %.txt,$^)
	git add "$@"

.PHONY: _incl_enum_values_hpp
_incl_enum_values_hpp: $(ROOT)/include/$(LIBRARY)/enum_values.hpp

$(ROOT)/include/$(LIBRARY)/enum_values.hpp: $(SOURCES) $(MAKE_ENUM)
	$(MAKE_ENUM) \
		--library $(LIBRARY) \
		--base-lib-prefix $(LIB_PREFIX)\
		--action incl_enum_values_hpp \
		--output "$@" \
		$(filter %.txt,$^)
	git add "$@"

.PHONY: _test_enums_cpp
_test_enums_cpp: $(addprefix $(ROOT)/test/$(LIBRARY)/enums/,$(patsubst %.txt,%.cpp,$(SOURCES)))

$(ROOT)/test/$(LIBRARY)/enums/%.cpp: %.txt $(MAKE_ENUM)
	$(MAKE_ENUM) \
		--library $(LIBRARY) \
		--base-lib-prefix $(LIB_PREFIX)\
		--action test_enums_cpp \
		--output "$@" "$<" 
	git add "$@"

