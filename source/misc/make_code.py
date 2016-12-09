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
	print_comment(options, cs, "  Edit the the '%s' script instead." % options.rel_self)
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

def action_info(options):
	print("Inputs: %s" % options.inputs)
	print("Output: %s" % options.output)


type_infos = {
	"byte": type("TI", (object,), {
		"suffix": 'b'
	}),
	"ubyte": type("TI", (object,), {
		"suffix": 'ub'
	}),
	"short": type("TI", (object,), {
		"suffix": 's'
	}),
	"ushort": type("TI", (object,), {
		"suffix": 'us'
	}),
	"int": type("TI", (object,), {
		"suffix": 'i'
	}),
	"uint": type("TI", (object,), {
		"suffix": 'ui'
	}),
	"float": type("TI", (object,), {
		"suffix": 'f'
	}),
	"double": type("TI", (object,), {
		"suffix": 'd'
	})
}

def print_glUniformNT(options, typ, n):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset(")
	print_line(options, "\t\tidentity<GL%s>," % typ)
	print_line(options, "\t\tuniform_location u,")

	print_line(options, "\t\t" + ", ".join(
		["GL%s v%d" % (typ, i) for i in range(n)]
	))

	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	glfunc = "Uniform%d%s" % (n, info.suffix)
	print_line(
		options,
		"\t\tOGLPLUS_GLFUNC(%s)" % glfunc +
		"(u.location(), " +
		", ".join(["v%d" % i for i in range(n)]) +
		");"
	)
	print_line(
		options,
		"\t\tOGLPLUS_VERIFY_SIMPLE"+
		"(%s, debug);" % glfunc
	)
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def print_glUniformNTv(options, typ, n):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset(")
	print_line(options, "\t\tidentity<GL%s[%d]>," % (typ, n))
	print_line(options, "\t\tuniform_location u,")
	print_line(options, "\t\tGLsizei count,")
	print_line(options, "\t\tconst span<const GL%s>& v" % typ)
	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	print_line(options, "\t\tassert(count >= 0);")
	print_line(options, "\t\tassert(v.size() >= span_size_t(%d*count));" % (n))
	glfunc = "Uniform%d%sv" % (n, info.suffix)
	print_line(
		options,
		"\t\tOGLPLUS_GLFUNC(%s)" % glfunc +
		"(u.location(), count, v.data());"
	)
	print_line(
		options,
		"\t\tOGLPLUS_VERIFY_SIMPLE"+
		"(%s, debug);" % glfunc
	)
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def print_glUniformMatrixMxNTv(options, typ, m, n):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset(")
	print_line(options, "\t\tidentity<GL%s[%d][%d]>," % (typ, m, n))
	print_line(options, "\t\tuniform_location u,")
	print_line(options, "\t\tGLsizei count,")
	print_line(options, "\t\tGLboolean transpose,")
	print_line(options, "\t\tconst span<const GL%s>& v" % typ)
	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	print_line(options, "\t\tassert(count >= 0);")
	print_line(options, "\t\tassert(v.size() >= span_size_t(%d*%d*count));" % (m,n))

	glfunc = "UniformMatrix%s%sv" % (
		"%dx%d" % (m, n) if m != n else "%d" % m,
		info.suffix
	)

	print_line(
		options,
		"\t\tOGLPLUS_GLFUNC(%s)" % glfunc +
		"(u.location(), count, transpose, v.data());"
	)
	print_line(
		options,
		"\t\tOGLPLUS_VERIFY_SIMPLE"+
		"(%s, debug);" % glfunc
	)
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def print_glProgramUniformNT(options, typ, n):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset(")
	print_line(options, "\t\tidentity<GL%s>," % typ)
	print_line(options, "\t\tprogram_uniform_location pu,")

	print_line(options, "\t\t" + ", ".join(
		["GL%s v%d" % (typ, i) for i in range(n)]
	))

	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	glfunc = "ProgramUniform%d%s"  % (n, info.suffix)
	print_line(
		options,
		"\t\tOGLPLUS_GLFUNC(%s)(" % glfunc
	)
	print_line(options, "\t\t\tget_raw_name(pu.program()),")
	print_line(options, "\t\t\tpu.location(),")
	print_line(
		options,
		"\t\t\t"+", ".join(["v%d" % i for i in range(n)])
	)
	print_line(options, "\t\t);")
	print_line(options, "\t\tOGLPLUS_VERIFY(")
	print_line(options, "\t\t\t%s," % glfunc) 
	print_line(options, "\t\t\tgl_object(pu.program()),")
	print_line(options, "\t\t\tdebug")
	print_line(options, "\t\t);")
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def print_glProgramUniformNTv(options, typ, n):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset(")
	print_line(options, "\t\tidentity<GL%s[%d]>," % (typ, n))
	print_line(options, "\t\tprogram_uniform_location pu,")
	print_line(options, "\t\tGLsizei count,")
	print_line(options, "\t\tconst span<const GL%s>& v" % typ)
	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	print_line(options, "\t\tassert(count >= 0);")
	print_line(options, "\t\tassert(v.size() >= span_size_t(%d*count));" % (n))
	glfunc = "ProgramUniform%d%sv"  % (n, info.suffix)
	print_line(options, "\t\tOGLPLUS_GLFUNC(%s)(" % glfunc)
	print_line(options, "\t\t\tget_raw_name(pu.program()),")
	print_line(options, "\t\t\tpu.location(),")
	print_line(options, "\t\t\tcount,")
	print_line(options, "\t\t\tv.data()")
	print_line(options, "\t\t);")
	print_line(options, "\t\tOGLPLUS_VERIFY(")
	print_line(options, "\t\t\t%s," % glfunc)
	print_line(options, "\t\t\tgl_object(pu.program()),")
	print_line(options, "\t\t\tdebug")
	print_line(options, "\t\t);")
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def print_glProgramUniformMatrixMxNTv(options, typ, m, n):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\ttemplate <span_size_t N>")
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset(")
	print_line(options, "\t\tidentity<GL%s[%d][%d]>," % (typ, m, n))
	print_line(options, "\t\tprogram_uniform_location pu,")
	print_line(options, "\t\tGLsizei count,")
	print_line(options, "\t\tGLboolean transpose,")
	print_line(options, "\t\tconst span<const GL%s, N>& v" % typ)
	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	print_line(options, "\t\tassert(count >= 0);")
	print_line(options, "\t\tassert(v.size() >= span_size_t(%d*%d*count));" % (m,n))

	glfunc = "ProgramUniformMatrix%s%sv" % (
		"%dx%d" % (m, n) if m != n else "%d" % m,
		info.suffix
	)

	print_line(options, "\t\tOGLPLUS_GLFUNC(%s)(" % glfunc)
	print_line(options, "\t\t\tget_raw_name(pu.program()),")
	print_line(options, "\t\t\tpu.location(),")
	print_line(options, "\t\t\tcount,")
	print_line(options, "\t\t\ttranspose,")
	print_line(options, "\t\t\tv.data()")
	print_line(options, "\t\t);")
	print_line(
		options,
		"\t\tOGLPLUS_VERIFY_SIMPLE"+
		"(%s, debug);" % glfunc
	)
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def print_prog_var_get_set_decl(options, kind, typ):
	print_line(options, "template <>")
	print_line(options, "struct prog_var_get_set_ops<tag::%s, GL%s>" % (
		kind, typ
	))
	print_line(options, "{")

def action_gl_uniform_get_set(options):
	print_cpp_header(options)

	print_line(options, "#include <cassert>")
	print_newline(options)
	print_line(options, "namespace %s {" % options.library)
	print_newline(options)

	for typ in ["int", "uint", "float"]:
		print_prog_var_get_set_decl(options, "uniform", typ)
		for n in range(1,5):
			print_glUniformNT(options, typ, n)

		for n in range(1,5):
			print_glUniformNTv(options, typ, n)

		if typ in ["float"]:
			for m in range(2,5):
				for n in range(2,5):
					print_glUniformMatrixMxNTv(options, typ, m, n)

		print_newline(options)
		print_line(
			options,
			"#if "+
			"defined(GL_VERSION_4_1) || "+
			"defined(GL_ARB_separate_shader_objects)"
		)

		for n in range(1,5):
			print_glProgramUniformNT(options, typ, n)

		for n in range(1,5):
			print_glProgramUniformNTv(options, typ, n)

		if typ in ["float"]:
			for m in range(2,5):
				for n in range(2,5):
					print_glProgramUniformMatrixMxNTv(options, typ, m, n)
		print_line(options, "#endif") 

		print_line(options, "};")
		print_newline(options)

	print_newline(options)
	print_line(options, "} // namespace %s" % options.library)


def print_glVertexAttribNT(options, typ, prefix, n, infix):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset%s%s(" % (prefix, infix))
	print_line(options, "\t\tidentity<GL%s>," % typ)
	print_line(options, "\t\tvertex_attrib_location va,")
	print_line(options, "\t\tbool ge,")

	print_line(options, "\t\t" + ", ".join(
		["GL%s v%d" % (typ, i) for i in range(n)]
	))

	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	glfunc = "VertexAttrib%s%d%s%s" % (prefix, n, infix, info.suffix)
	print_line(
		options,
		"\t\tOGLPLUS_GLFUNC(%s)" % glfunc +
		"(va.index(), " +
		", ".join(["v%d" % i for i in range(n)]) +
		");"
	)
	print_line(
		options,
		"\t\tif(ge) { OGLPLUS_VERIFY_SIMPLE"+
		"(%s, debug); }" % glfunc
	)
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def print_glVertexAttribNTv(options, typ, prefix, n, infix):
	info = type_infos[typ]
	print_newline(options)
	print_line(options, "\ttemplate <span_size_t N>")
	print_line(options, "\tstatic")
	print_line(options, "\toutcome<void>")
	print_line(options, "\tset%s%s(" % (prefix, infix))
	print_line(options, "\t\tidentity<GL%s[%d]>," % (typ, n))
	print_line(options, "\t\tvertex_attrib_location va,")
	print_line(options, "\t\tbool ge,")
	print_line(options, "\t\tconst span<const GL%s, N>& v" % typ)
	print_line(options, "\t) noexcept")
	print_line(options, "\t{")
	print_line(options, "\t\tassert(v.size() >= %d);" % (n))
	glfunc = "VertexAttrib%s%d%s%sv" % (prefix, n, infix, info.suffix)
	print_line(
		options,
		"\t\tOGLPLUS_GLFUNC(%s)" % glfunc +
		"(va.index(), v.data());"
	)
	print_line(
		options,
		"\t\tif(ge) { OGLPLUS_VERIFY_SIMPLE"+
		"(%s, debug); }" % glfunc
	)
	print_line(options, "\t\treturn {};")
	print_line(options, "\t}")

def action_gl_vertex_attrib_get_set(options):
	print_cpp_header(options)

	print_line(options, "#include <cassert>")
	print_newline(options)
	print_line(options, "namespace %s {" % options.library)
	print_newline(options)

	for typ in ["short", "int", "uint", "float", "double"]:
		print_prog_var_get_set_decl(options, "vertex_attrib", typ)
		prefix = "I" if typ in ["int", "uint"] else ""
		for n in range(1,5):
			print_glVertexAttribNT(options, typ, prefix, n, "")
		print_newline(options)

		prefix = "I" if typ in ["int", "uint"] else ""
		for n in range(1,5):
			print_glVertexAttribNTv(options, typ, prefix, n, "")

		if typ in ["double"]:
			for n in range(1,5):
				print_glVertexAttribNT(options, "double", "L", n, "")

		print_line(options, "};")
		print_newline(options)

	print_prog_var_get_set_decl(options, "vertex_attrib", "ubyte")
	print_glVertexAttribNT(options, "ubyte", "", 4, "N")
	print_line(options, "};")
	print_newline(options)

	print_line(options, "} // namespace %s" % options.library)

actions = {
	"gl_uniform_get_set" : action_gl_uniform_get_set,
	"gl_vertex_attrib_get_set" : action_gl_vertex_attrib_get_set,
	"info":    action_info
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

	return options

def main():
	dispatch_action(get_options())


if __name__ == "__main__": main()

