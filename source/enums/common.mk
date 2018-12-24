#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt)
#
ROOT = $(PARENT)/../..
MAKE_ENUM = $(PARENT)/make_enum.py
MEFLAGS = --library "$(LIBRARY)" --lib-suffix "$(LIB_SUFFIX)" --base-lib-prefix "$(LIB_PREFIX)"

CLANG_FORMAT ?= clang-format

.PHONY: all
all: \
	_incl_enum_types_hpp \
	_incl_enum_values_hpp \
	_impl_enum_value_defs_inl \
	_impl_enum_value_names_inl \
	_impl_enum_value_range_inl \
	_impl_enum_bq_inl \
	_test_enums_cpp

.PHONY:	_binding_queries_mk
_binding_queries_mk: ./binding_queries.mk

#.INTERMEDIATE: ./binding_queries.mk
./binding_queries.mk: $(MAKE_ENUM) $(SOURCES)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action binding_queries_mk \
		--output "$@" \
		$(filter %.txt,$^)
	git add "$@"

.PHONY: _incl_enum_types_hpp
_incl_enum_types_hpp: \
	$(ROOT)/include/$(LIBRARY)/enum/types$(LIB_SUFFIX).hpp

$(ROOT)/include/$(LIBRARY)/enum/types$(LIB_SUFFIX).hpp: $(SOURCES) $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action incl_enum_types_hpp \
		--output "$@" \
		$(filter %.txt,$^)
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

.PHONY: _incl_enum_values_hpp
_incl_enum_values_hpp: \
	$(ROOT)/include/$(LIBRARY)/enum/values$(LIB_SUFFIX).hpp

$(ROOT)/include/$(LIBRARY)/enum/values$(LIB_SUFFIX).hpp: $(SOURCES) $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action incl_enum_values_hpp \
		--output "$@" \
		$(filter %.txt,$^)
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

.PHONY: _impl_enum_value_defs_inl
_impl_enum_value_defs_inl: \
	$(ROOT)/implement/$(LIBRARY)/enum/value_defs$(LIB_SUFFIX).inl

$(ROOT)/implement/$(LIBRARY)/enum/value_defs$(LIB_SUFFIX).inl: $(SOURCES) $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action impl_enum_value_defs_inl \
		--output "$@" \
		$(filter %.txt,$^)
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

.PHONY: _impl_enum_value_names_inl
_impl_enum_value_names_inl: \
	$(ROOT)/implement/$(LIBRARY)/enum/value_names$(LIB_SUFFIX).inl

$(ROOT)/implement/$(LIBRARY)/enum/value_names$(LIB_SUFFIX).inl: $(SOURCES) $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action impl_enum_value_names_inl \
		--output "$@" \
		$(filter %.txt,$^)
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

.PHONY: _impl_enum_value_range_inl
_impl_enum_value_range_inl: \
	$(ROOT)/implement/$(LIBRARY)/enum/value_range$(LIB_SUFFIX).inl

$(ROOT)/implement/$(LIBRARY)/enum/value_range$(LIB_SUFFIX).inl: $(SOURCES) $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action impl_enum_value_range_inl \
		--output "$@" \
		$(filter %.txt,$^)
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

.PHONY: _impl_enum_bq_inl
_impl_enum_bq_inl:

$(ROOT)/implement/$(LIBRARY)/enum/%_bq$(LIB_SUFFIX).inl: $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action impl_enum_bq_inl \
		--output "$@" \
		$(filter %.txt,$^)
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

.PHONY: _test_enums_cpp
_test_enums_cpp: $(addprefix $(ROOT)/test/boost_test/$(LIBRARY)/enums/,$(notdir $(patsubst %.txt,%.cpp,$(SOURCES))))

$(ROOT)/test/boost_test/$(LIBRARY)/enums/%.cpp: %.txt $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action test_enums_cpp \
		--output "$@" "$<" 
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

$(ROOT)/test/boost_test/$(LIBRARY)/enums/%.cpp: */%.txt $(MAKE_ENUM)
	$(MAKE_ENUM) $(MEFLAGS) \
		--action test_enums_cpp \
		--output "$@" "$<" 
	$(CLANG_FORMAT) -i "$@"
	git add "$@"

sinclude ./binding_queries.mk
