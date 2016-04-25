#!/usr/bin/python
# coding=utf-8
#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt)
#
import os, sys

def print_newline(options):
	options.out.write(os.linesep)

def print_line(options, line_str):
	options.out.write(line_str)
	options.out.write(os.linesep)

def print_comment(options, cs, line_str = str()):
	print_line(options, "%s%s" % (cs, line_str))

def print_header(options, cs):

	print_comment(options, cs, "  File %s" % options.rel_output)
	print_comment(options, cs)
	print_comment(options, cs, "  Automatically generated file, DO NOT modify manually.")
	print_comment(options, cs, "  Edit the enumeration source files in 'source/enums/%s'" % options.library)
	print_comment(options, cs, "  or the '%s' script instead." % options.rel_self)
	print_comment(options, cs)
	print_comment(options, cs, "  Copyright Matus Chochlik.")
	print_comment(options, cs, "  Distributed under the Boost Software License, Version 1.0.")
	print_comment(options, cs, "  See accompanying file LICENSE_1_0.txt or copy at")
	print_comment(options, cs, "   http://www.boost.org/LICENSE_1_0.txt")
	print_comment(options, cs)

def print_cpp_header(options):
	print_header(options, "//")

def print_scr_header(options):
	print_header(options, "#")

def print_incl_guard(options, name):
	print_line(options, "#ifndef %s_%s_%s" % (
		options.library_uc,
		options.base_lib_prefix,
		name
	))
	print_line(options, "#define %s_%s_%s" % (
		options.library_uc,
		options.base_lib_prefix,
		name
	))

def update_input_options(options, input_path):

	options.rel_input = os.path.relpath(input_path, options.root_dir)
	options.input_name = os.path.relpath(input_path, options.source_root_dir)
	options.input_name = os.path.splitext(options.input_name)[0]


	options.enum_name = None
	options.enum_type = "%senum" % options.base_lib_prefix

	with open(input_path, "r") as f:
		for line in f:
			line = line.strip()
			if line.startswith("#@!"):
				options.enum_type = line[3:-1]
			elif line.startswith("#@"):
				options.enum_type = "%s%s" % (options.base_lib_prefix, line[2:-1])
			elif line.startswith("#") and line.endswith("#"):
				options.enum_name = line[1:-1]

	if not options.enum_name:
		options.enum_name = os.path.splitext(os.path.basename(input_path))[0]

def src_name_to_dst_name(src_name):

	suffixes = ['ARB', 'EXT']

	for suffix in suffixes:
		if src_name.endswith('_'+suffix):
			src_name = src_name[:-len(suffix)-1]
			break

	dst_name = src_name.lower()

	keywords = [
		'void','bool','byte','short','int','unsigned','float','double',
		'not','and','or','xor', 'true', 'false',
		"static"
	]

	for keyword in keywords:
		if dst_name == keyword:
			dst_name = dst_name+'_'
			break

	return dst_name

def parse_source(options, input_path = None):

	import string

	if not input_path:
		input_path = options.inputs[0]

	result = list()

	attribs = ["src_name", "dst_name", "doc", "bind_query", "assoc_type", "prefix"]

	with open(input_path, "r") as f:

		for line in f:
			line = line.strip()
			if line and not line.startswith("#"):
				values = line.split(":")
				av = dict(zip(attribs, values))

				if not av.get("dst_name"):
					av["dst_name"] = src_name_to_dst_name(av["src_name"])

				if not av.get("prefix"):
					av["prefix"] = options.base_lib_prefix

				if av.get("doc"):
					av["comma_doc"] = ": %s" % av.get("doc")
				else:
					av["comma_doc"] = str()

				if not av.get("bind_query"):
					av["bind_query"] = None

				av["enum_class"] = options.enum_name
				av["enum_type"] = options.enum_type

				result.append(type("EnumValue", (object,), av))
	return result


def action_info(options):
	print("Inputs: %s" % options.inputs)
	print("Output: %s" % options.output)

def action_binding_queries_mk(options):

	out_dir = os.path.join(options.root_dir,"implement",options.library,"enum")

	inputs_with_bq = list()

	for input_path in sorted(options.inputs, key=lambda x: os.path.basename(x)):
		update_input_options(options, input_path)
		for value_info in parse_source(options, input_path):
			if value_info.bind_query is not None:
				inputs_with_bq.append(input_path)
				break
	outputs_with_bq = dict()

	for input_with_bq in inputs_with_bq:
		outputs_with_bq[
			os.path.relpath(
				os.path.join(
					out_dir,
					"%s_bq.inl" %
					os.path.splitext(
						os.path.basename(input_with_bq)
					)[0]
				)
			)
		] = os.path.relpath(input_with_bq, options.work_dir)

	if len(outputs_with_bq) > 0:
		print_line(options, "_impl_enum_bq_inl:\\\n\t%s" % (
			' \\\n\t'.join(outputs_with_bq)
		))
		print_newline(options)

		for output_with_bq, input_with_bq in outputs_with_bq.iteritems():
			print_line(options, "%s: %s" % (output_with_bq, input_with_bq))
			print_newline(options)
	else:
		print_line(options, "_impl_enum_bq_inl:")


def action_incl_enum_types_hpp(options):

	enum_classes = dict()

	typ_id = 0

	for input_path in sorted(options.inputs, key=lambda x: os.path.basename(x)):
		update_input_options(options, input_path)
		enum_classes[options.enum_name] = type(
			"EnumClassInfo",
			(object,), {
				"typ_id": typ_id,
				"enum_type": options.enum_type
			}
		)
		typ_id = typ_id+1

	print_cpp_header(options)
	print_incl_guard(options, "ENUM_TYPES_HPP")
	print_newline(options)
	print_line(options, '#include "../utils/enum_class.hpp"')
	print_newline(options)
	print_line(options, "namespace %s {" % options.library)
	print_newline(options)

	for enum_class, enum_info in sorted(enum_classes.items()):
		print_line(options, "struct %s" % enum_class)
		print_line(options, " : enum_class%s<%s, %s, %d>" % (
			options.lib_suffix,
			enum_class,
			enum_info.enum_type,
			enum_info.typ_id
		))
		print_line(options, "{ using enum_class::enum_class; };")
		print_newline(options)

	print_line(options, "} // namespace %s" % options.library)
	print_newline(options)
	print_line(options, "#endif // include guard")


def action_incl_enum_values_hpp(options):

	enum_map = dict()

	for input_path in options.inputs:
		update_input_options(options, input_path)

		for value_info in parse_source(options, input_path):
			try: enum_map[value_info.dst_name]
			except KeyError:
				enum_map[value_info.dst_name] = type(
					"EnumMapItem",
					(object,), {
						"info": value_info,
						"classes": set()
					}
				)

			enum_map[value_info.dst_name].classes.add(options.enum_name)

	print_cpp_header(options)
	print_incl_guard(options, "ENUM_VALUES_HPP")
	print_newline(options)
	print_line(options, '#include "types%s.hpp"' % options.lib_suffix)
	print_line(options, '#include "../utils/mp_list.hpp"')
	print_newline(options)
	print_line(options, "namespace %s {" % options.library)
	print_line(options, "struct enum_values%s {" % options.lib_suffix)
	print_newline(options)

	for value_name, value_info in sorted(enum_map.items()):
		print_line(options, "#ifdef %s_%s" % (
			options.base_lib_prefix,
			value_info.info.src_name
		))
		print_line(options, "static constexpr const enum_value<")
		print_line(options, "	%s," % value_info.info.enum_type)
		print_line(options, "	mp_list<%s>" % (
			",".join(["%s::%s" % (options.library, x) for x in value_info.classes])
		))
		print_line(options, "> %s = {%s_%s};" % (
			value_name,
			options.base_lib_prefix,
			value_info.info.src_name
		))
		print_line(options, "#endif")
		print_newline(options)


	print_line(options, "};// struct enum_values")
	print_line(options, "} // namespace %s" % options.library)
	print_newline(options)
	print_line(options, "#endif // include guard")


def action_impl_enum_value_defs_inl(options):

	enum_map = dict()

	for input_path in options.inputs:
		update_input_options(options, input_path)

		for value_info in parse_source(options, input_path):
			try: enum_map[value_info.dst_name]
			except KeyError:
				enum_map[value_info.dst_name] = type(
					"EnumMapItem",
					(object,), {
						"info": value_info,
						"classes": set()
					}
				)

			enum_map[value_info.dst_name].classes.add(options.enum_name)

	print_cpp_header(options)
	print_newline(options)
	print_line(options, "namespace %s {" % options.library)
	print_newline(options)

	for value_name, value_info in sorted(enum_map.items()):
		print_line(options, "#ifdef %s_%s" % (
			options.base_lib_prefix,
			value_info.info.src_name
		))
		print_line(options, "constexpr const enum_value<")
		print_line(options, "	%s," % value_info.info.enum_type)
		print_line(options, "	mp_list<%s>" % (
			",".join(["%s::%s" % (options.library, x) for x in value_info.classes])
		))
		print_line(options, "> enum_values%s::%s;" % (
			options.lib_suffix,
			value_name
		))
		print_line(options, "#endif")
		print_newline(options)


	print_line(options, "} // namespace %s" % options.library)


def action_impl_enum_value_names_inl(options):

	enum_classes = dict()
	enum_values = dict()

	typ_id = 0

	for input_path in sorted(options.inputs, key=lambda x: os.path.basename(x)):
		update_input_options(options, input_path)

		enum_classes[options.enum_name] = type(
			"EnumClassInfo",
			(object,), {
				"typ_id": typ_id,
				"enum_type": options.enum_type,
				"values": set()
			}
		)
		typ_id = typ_id + 1

		for value_info in parse_source(options, input_path):
			enum_classes[options.enum_name].values.add(value_info)
			enum_values[value_info.src_name] = value_info

	print_cpp_header(options)

	print_line(options, "#ifdef _MSC_VER")
	print_line(options, "#pragma warning ( push )")
	print_line(options, "#pragma warning ( disable : 4065 )")
	print_line(options, "#endif //_MSC_VER")

	print_newline(options)
	print_line(options, "namespace %s {" % options.library)
	print_newline(options)
	print_line(options, "%s_LIB_FUNC" % options.library_uc)
	print_line(options, "cstr_ref")
	print_line(options, "get_enum_value_name(const any_enum_value%s& aev)" %
		options.lib_suffix
	)
	print_line(options, "noexcept")
	print_line(options, "{")

	for enum_value_name, enum_value_info in sorted(enum_values.items()):
		print_line(options, "#ifdef %s_%s" % (
			options.base_lib_prefix,
			enum_value_name
		))
		print_line(options, '\tstatic const char s_%s[%d] =\n\t\t"%s";' % (
			enum_value_name,
			len(enum_value_name)+1,
			enum_value_name
		))
		print_line(options, "#endif")

	print_newline(options)

	print_line(options, "\tswitch(aev._type_id)")
	print_line(options, "\t{")

	for enum_class, enum_class_info in sorted(enum_classes.items()):
		print_line(options, "\t\tcase %d: /* %s */" % (
			enum_class_info.typ_id,
			enum_class
		))

		print_line(options, "\t\t\tswitch(%s(aev._value))" % enum_class_info.enum_type)
		print_line(options, "\t\t\t{")
		for enum_value in sorted(enum_class_info.values, key=lambda x: x.src_name):
			print_line(options, "#ifdef %s_%s" % (
				options.base_lib_prefix,
				enum_value.src_name
			))
			print_line(options, "\t\t\t\tcase %s_%s:" % (
				options.base_lib_prefix,
				enum_value.src_name
			))
			print_line(options, "\t\t\t\t\treturn {s_%s, %d};" % (
				enum_value.src_name,
				len(enum_value.src_name)
			))
			print_line(options, "#endif")

		print_line(options, "\t\t\t\tdefault:;")
		print_line(options, "\t\t\t}")
		print_line(options, "\t\t\tbreak;")

	print_line(options, "\tdefault:;")
	print_line(options, "\t}")


	print_newline(options)
	print_line(options, "	(void)aev;")
	print_line(options, "	return {};")
	print_line(options, "}")
	print_newline(options)
	print_line(options, "} // namespace %s" % options.library)

	print_line(options, "#ifdef _MSC_VER")
	print_line(options, "#pragma warning ( pop )")
	print_line(options, "#endif //_MSC_VER")


def action_impl_enum_value_range_inl(options):

	enum_classes = dict()

	typ_id = 0

	for input_path in sorted(options.inputs, key=lambda x: os.path.basename(x)):
		update_input_options(options, input_path)

		enum_classes[options.enum_name] = type(
			"EnumClassInfo",
			(object,), {
				"typ_id": typ_id,
				"enum_type": options.enum_type,
				"values": set()
			}
		)
		typ_id = typ_id + 1

		for value_info in parse_source(options, input_path):
			enum_classes[options.enum_name].values.add(value_info)

	print_cpp_header(options)

	print_newline(options)
	print_line(options, "namespace %s {" % options.library)
	print_newline(options)
	print_line(options, "%s_LIB_FUNC" % options.library_uc)
	print_line(options, "std::pair<const void*, std::size_t>")
	print_line(options, "get_enum_value_range(const any_enum_class%s& aec)" %
		options.lib_suffix
	)
	print_line(options, "noexcept")
	print_line(options, "{")

	print_line(options, "\tswitch(aec._type_id)")
	print_line(options, "\t{")

	for enum_class, enum_class_info in sorted(enum_classes.items()):
		print_line(options, "\t\tcase %d: /* %s */" % (
			enum_class_info.typ_id,
			enum_class
		))
		print_line(options, "\t\t{")

		print_line(options, "\t\t\tstatic const %s vr[] = {" % enum_class_info.enum_type)

		for enum_value in sorted(enum_class_info.values, key=lambda x: x.src_name):
			print_line(options, "#ifdef %s_%s" % (
				options.base_lib_prefix,
				enum_value.src_name
			))
			print_line(options, "\t\t\t\t%s_%s," % (
				options.base_lib_prefix,
				enum_value.src_name
			))
			print_line(options, "#endif")

		print_line(options, "\t\t\t\t0")
		print_line(options, "\t\t\t};")
		print_line(options, "\t\t\treturn {vr, sizeof(vr)/sizeof(vr[0])-1};")
		print_line(options, "\t\t}")

	print_line(options, "\tdefault:;")
	print_line(options, "\t}")

	print_newline(options)
	print_line(options, "	(void)aec;")
	print_line(options, "	return {nullptr, 0};")
	print_line(options, "}")
	print_newline(options)
	print_line(options, "} // namespace %s" % options.library)


def action_impl_enum_bq_inl(options):

	value_infos = dict()

	input_path = options.inputs[0]

	update_input_options(options, input_path)

	for value_info in parse_source(options, input_path):
		value_infos[value_info.dst_name] = value_info

	print_cpp_header(options)
	print_line(options, "namespace %s {" % options.library)
	print_newline(options)
	print_line(options, "%s_LIB_FUNC" % options.library_uc)
	print_line(options, "binding_query")
	print_line(options, "get_binding_query(%s tgt)" % options.enum_name)
	print_line(options, "noexcept")
	print_line(options, "{")

	print_line(options, "	%s result = 0;" % options.enum_type)
	print_line(options, "	switch(%s(tgt))" % options.enum_type)
	print_line(options, "	{")
	for value_name, value_info in sorted(value_infos.items()):
		if value_info.bind_query is not None:
			print_line(options, "#if	defined(%s_%s) && \\" % (
				options.base_lib_prefix,
				value_info.src_name
			))
			print_line(options, "	defined(%s_%s)" % (
				options.base_lib_prefix,
				value_info.bind_query
			))
			print_line(options, "		case %s_%s:" % (
				options.base_lib_prefix,
				value_info.src_name
			))
			print_line(options, "			result = %s_%s;" % (
				options.base_lib_prefix,
				value_info.bind_query
			))
			print_line(options, "			break;")
			print_line(options, "#endif")

	print_line(options, "		default:;")
	print_line(options, "	}")

	print_line(options, "	return binding_query(result);")
	print_line(options, "}")
	print_newline(options)
	print_line(options, "} // namespace %s" % options.library)


def action_test_enums_cpp(options):

	value_infos = dict()

	input_path = options.inputs[0]

	update_input_options(options, input_path)

	for value_info in parse_source(options, input_path):
		value_infos[value_info.dst_name] = value_info


	print_cpp_header(options)
	print_line(options, "#define BOOST_TEST_DYN_LINK")
	print_line(options, "#define BOOST_TEST_MODULE %s_%s" % (
		options.library_uc,
		options.enum_name
	))
	print_newline(options)
	print_line(options, "#include <boost/test/unit_test.hpp>")
	print_line(options, '#include "common%s.hpp"' % options.lib_suffix)
	print_line(options, '#include <cstring>')
	print_newline(options)
	print_line(options, "BOOST_AUTO_TEST_SUITE(enum_%s_tests)" % options.enum_name)
	print_newline(options)
	print_line(options, "BOOST_AUTO_TEST_CASE(enum_%s_values)" % options.enum_name)
	print_line(options, "{")
	print_line(options, "	using namespace %s;" % options.library)
	print_line(options, "	enum_values%s ev;" % options.lib_suffix)
	print_line(options, "	(void)ev;")
	print_line(options, "	%s x;" % options.enum_name)
	print_line(options, "	(void)x;")

	for value_name, value_info in sorted(value_infos.items()):
		print_newline(options)
		print_line(options, "#ifdef %s_%s" % (
			options.base_lib_prefix,
			value_info.src_name
		))
		print_line(options, "	x = ev.%s;" % value_name)

		for value_name2, value_info2 in sorted(value_infos.items()):
			if value_name > value_name2:
				continue

			if value_name != value_name2:
				print_line(options, "# ifdef %s_%s" % (
					options.base_lib_prefix,
					value_info2.src_name
				))

			print_line(options, "	BOOST_CHECK(x %s= ev.%s);" % (
				'=' if value_name == value_name2 else '!',
				value_name2
			))

			if value_name != value_name2:
				print_line(options, "# endif")

		print_line(options, "#endif")

	print_line(options, "}")

	print_newline(options)
	print_line(options, "BOOST_AUTO_TEST_CASE(enum_%s_names)" % options.enum_name)
	print_line(options, "{")
	print_line(options, "	using namespace %s;" % options.library)
	print_line(options, "	enum_values%s ev;" % options.lib_suffix)
	print_line(options, "	(void)ev;")
	print_line(options, "	%s x;" % options.enum_name)
	print_line(options, "	(void)x;")

	for value_name, value_info in sorted(value_infos.items()):
		print_newline(options)
		print_line(options, "#ifdef %s_%s" % (
			options.base_lib_prefix,
			value_info.src_name
		))
		print_line(options, "	x = ev.%s;" % value_name)
		print_line(options, "	BOOST_ASSERT(enum_value_name(x).data() != nullptr);")
		print_line(options, "	BOOST_CHECK(std::strcmp(")
		print_line(options, "		enum_value_name(x).data(),")
		print_line(options, '		"%s"' % value_info.src_name)
		print_line(options, "	) == 0);")

		print_line(options, "#endif")

	print_line(options, "}")

	print_newline(options)
	print_line(options, "BOOST_AUTO_TEST_CASE(enum_%s_range)" % options.enum_name)
	print_line(options, "{")
	print_line(options, "	using namespace %s;" % options.library)
	print_line(options, "	auto count = enum_value_range<%s>().size();" % (
		options.enum_name
	))

	for value_name, value_info in sorted(value_infos.items()):
		print_newline(options)
		print_line(options, "#ifdef %s_%s" % (
			options.base_lib_prefix,
			value_info.src_name
		))
		print_line(options, "{")
		print_line(options, "	--count;")
		print_line(options, "	auto r = enum_value_range<%s>();" % (
			options.enum_name
		))
		print_line(options, "	BOOST_CHECK(std::find(")
		print_line(options, "		r.begin(), r.end(),")
		print_line(options, "		%s(%s_%s)" % (
			options.enum_name,
			options.base_lib_prefix,
			value_info.src_name
		))
		print_line(options, "	) != r.end());")
		print_line(options, "}")

		print_line(options, "#endif")

	print_line(options, "	BOOST_CHECK_EQUAL(count, 0);")
	print_line(options, "}")

	print_newline(options)
	print_line(options, "BOOST_AUTO_TEST_CASE(enum_%s_any)" % options.enum_name)
	print_line(options, "{")
	print_line(options, "	using namespace %s;" % options.library)
	print_line(options, "	enum_values%s ev;" % options.lib_suffix)
	print_line(options, "	(void)ev;")
	print_line(options, "	%s x, y;" % options.enum_name)
	print_line(options, "	(void)x;")
	print_line(options, "	(void)y;")
	print_line(options, "	any_enum_value%s a;" % options.lib_suffix)
	print_line(options, "	(void)a;")


	for value_name, value_info in sorted(value_infos.items()):
		print_newline(options)
		print_line(options, "#ifdef %s_%s" % (
			options.base_lib_prefix,
			value_info.src_name
		))
		print_line(options, "	x = ev.%s;" % value_name)
		print_line(options, "	a = x;")
		print_line(options, "	y = a;")
		print_line(options, "	BOOST_CHECK(same_enum_class(x, a));")
		print_line(options, "	BOOST_CHECK(same_enum_class(a, y));")
		print_line(options, "	BOOST_CHECK(same_enum_class(x, y));")
		print_line(options, "	BOOST_CHECK(y == ev.%s);" % value_name)

		print_line(options, "#endif")

	print_line(options, "}")

	print_newline(options)
	print_line(options, "BOOST_AUTO_TEST_SUITE_END()")


actions = {
	"binding_queries_mk": action_binding_queries_mk,
	"incl_enum_types_hpp": action_incl_enum_types_hpp,
	"incl_enum_values_hpp": action_incl_enum_values_hpp,
	"impl_enum_value_defs_inl": action_impl_enum_value_defs_inl,
	"impl_enum_value_names_inl": action_impl_enum_value_names_inl,
	"impl_enum_value_range_inl": action_impl_enum_value_range_inl,
	"impl_enum_bq_inl": action_impl_enum_bq_inl,
	"test_enums_cpp": action_test_enums_cpp,
	"info":    action_info,
}

def dispatch_action(options):
	actions[options.action](options)

def get_argument_parser():
	import argparse

	root_dir = os.path.join(
		os.path.pardir,
		os.path.pardir,
		os.path.dirname(sys.argv[0])
	)

	argparser = argparse.ArgumentParser(
		prog="make_enum",
		description="""
			Helper script for generating various enum related source files.
		""",
		epilog="""
			Copyright (c) Matúš Chochlík.
			Permission is granted to copy, distribute and/or modify this document
			under the terms of the Boost Software License, Version 1.0.
			(See a copy at http://www.boost.org/LICENSE_1_0.txt)
		"""
	)

	argparser.add_argument(
		"--root-dir",
		type=os.path.abspath,
		default=root_dir,
		action="store",
		help=""" Path to the project root directory. """
	)

	argparser.add_argument(
		"--library",
		action="store",
		help=""" The all-lowercase library name. """
	)

	argparser.add_argument(
		"--base-lib-prefix",
		action="store",
		help=""" The base library prefix. """
	)

	argparser.add_argument(
		"--lib-suffix",
		default=str(),
		action="store",
		help=""" The library suffix. """
	)

	argparser.add_argument(
		"inputs",
		metavar="FILE",
		type=os.path.abspath,
		nargs="*",
		help="""Path to the input text file(s) to be processed. """
	)

	argparser.add_argument(
		"--input",
		type=os.path.abspath,
		default=list(),
		action="append",
		help=""" Path to the input text file to be processed. """
	)

	argparser.add_argument(
		"--output",
		type=os.path.abspath,
		action="store",
		help=""" Path to the output file. """
	)

	def ValidAction(arg):
		if actions.get(arg) is None:
			msg = "'%s' is not a valid action name" % str(arg)
			raise argparse.ArgumentTypeError(msg)
		return arg

	argparser.add_argument(
		"--action",
		type=ValidAction,
		default="info",
		action="store",
		help=""" The action to be executed. """
	)

	return argparser

def get_options():

	argparser = get_argument_parser()
	options = argparser.parse_args()

	options.root_dir = os.path.abspath(options.root_dir)
	options.rel_self = os.path.relpath(sys.argv[0], options.root_dir)
	options.enum_dir = os.path.abspath(os.path.dirname(sys.argv[0]))

	options.inputs += options.input
	options.input = None

	if options.output is None:
		options.out = sys.stdout
		options.rel_output = "N/A"
	else:
		options.out = open(options.output, "wt")
		options.rel_output = os.path.relpath(options.output, options.root_dir)

	options.source_root_dir = os.path.join(options.root_dir, "source", "enums", options.library)

	if options.library:
		options.library_uc = options.library.upper()

	options.work_dir = os.path.join(options.enum_dir, "%s%s" % (options.library, options.lib_suffix))

	return options

def main():
	dispatch_action(get_options())


if __name__ == "__main__": main()

