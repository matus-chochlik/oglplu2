#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#
import os, sys, getopt, shutil, subprocess
from tools import args
from tools import paths

# initial values for the configuration options

def get_argument_parser():
	import argparse

	def BoolArgValue(arg):
		if(arg in ("True", "true", "Yes", "yes", "Y", "On", "1")):
			return True
		elif(arg in ("False", "false", "No", "no", "N", "Off", "0")):
			return False
		else:
			msg = "'%s' is not a valid boolean value" % str(arg)
			raise argparse.ArgumentTypeError(msg)

	def JobCountValue(arg):
		msg_fmt = "'%s' is not a valid process count value"
		try:
			if int(arg) <= 0:
				msg = msg_fmt % str(arg)
				raise argparse.ArgumentTypeError(msg)
			else:
				return int(arg)
		except:
			msg = msg_fmt % str(arg)
			raise argparse.ArgumentTypeError(msg)

	def OpenGLVersionValue(arg):
		import re
		match = re.match("^([3-9]).([0-9])$", arg)
		if match:
			return match.group(1)+"_"+match.group(2)
		else:
			msg = "'%s' is not a supported OpenGL version" % str(arg)
			raise argparse.ArgumentTypeError(msg)

	CMakeGeneratorValue = str

	version_file = os.path.join(os.path.dirname(sys.argv[0]), "VERSION")
	try: version = open(version_file, "r").read().strip()
	except: version = str("<unknown>")


	argparser = argparse.ArgumentParser(
		prog="configure",
		description="""
			Configuration script for the OGLplus library (version %(version)s)
		""" % { "version" : version },
		epilog="""
			Copyright (c) Matúš Chochlík.
			Permission is granted to copy, distribute and/or modify this document
			under the terms of the Boost Software License, Version 1.0.
			(See a copy at http://www.boost.org/LICENSE_1_0.txt)
		"""
	)
	argparser.add_argument(
		"--generate-bash-complete",
		action="store_true",
		help="""
			Generates bash completion script for this configure script and quits.
			For internal use only.
		"""
	)
	argparser.add_argument(
		"--generate-manual",
		action="store_true",
		help="""
			Generates a man-compatible manual.
			For internal use only.
		"""
	)
	argparser.add_argument(
		"--prefix",
		dest="install_prefix",
		type=os.path.abspath,
		action="store",
		help="""
			Specifies the installation prefix. The path must be absolute or
			relative to the current working directory from which %(prog)s is
			invoked.
		"""
	)
	argparser.add_argument(
		"--build-dir",
		type=os.path.abspath,
		default="_build",
		action="store",
		help="""
			Specifies the work directory for cmake, where the cached files,
			generated makefiles and the intermediate build files will be
			placed. The specified path must be either absolute or
			relative to the current working directory from which %(prog)s
			is invoked (default = '%(default)s').
		"""
	)
	argparser.add_argument(
		"--include-dir", "-I",
		dest="include_dirs",
		type=os.path.abspath,
		action="append",
		default=list(),
		help="""
			Specifies additional directory to search when looking for external
			headers like GL/glew.h or GL3/gl3.h. The specified path
			must be absolute or relative to the current working directory
			from which %(prog)s is invoked. This option may be specified
			multiple times to add multiple directories to the search list.
		"""
	)
	argparser.add_argument(
		"--library-dir", "-L",
		dest="library_dirs",
		type=os.path.abspath,
		action="append",
		default=list(),
		help="""
			Specifies additional directory to search when looking for compiled
			libraries like GL, GLEW, glut, png, etc. The specified
			path must be absolute or relative to the current working directory
			from which configure is invoked. This option may be specified
			multiple times to add multiple directories to the search list.
		"""
	)
	argparser.add_argument(
		"--search-dir", "-S",
		dest="search_dirs",
		type=os.path.abspath,
		action="append",
		default=list(),
		help="""
			Specifies additional directory with include and lib subdirectories
			that should be searched when looking for C++ headers or compiled
			libraries. Specifying --search-dir PATH is equivalent to specifying
			--include-dir PATH/include --library-dir PATH/lib. The provided
			path must be absolute or relative to the current working directory
			from which configure is invoked. This option may be specified
			multiple times to add multiple directories to the search list.
		"""
	)

	argparser.add_argument(
		"--use-cxxflags",
		default=False,
		action="store_true",
		help="""
			Uses the directories specified by the -I options
			in CXXFLAGS (if available) and adds them
			to the values specified by --include-dir.
		"""
	)
	argparser.add_argument(
		"--use-ldflags",
		default=False,
		action="store_true",
		help="""
			Uses the directories specified by the -L options
			in LDFLAGS (if available) and adds them
			to the values specified by --library-dir.
		"""
	)
	argparser.add_argument(
		"--low-profile",
		dest="low_profile",
		type=BoolArgValue,
		choices=[True, False],
		action="store",
		default=None,
		help="""
			Enables or disables the low profile mode (see the documentation
			for the EAGINE_LOW_PROFILE compile-time switch).
			If this option is used, then the specified value is written to
			the oglplus/config/site.hpp file, otherwise it is set to the default
			value in oglplus/config.hpp and may be overriden in sources by
			defining this preprocessor symbol or by using the appropriate
			compiler command-line switch or build environment setting.
		"""
	)
	argparser.add_argument(
		"--info-only",
		dest="info_only",
		action="store_true",
		default=False,
		help="""
			With this option configure only generates a python script containing
			information about the available configurations on the current machine.
		"""
	)

	argparser_build_examples_group = argparser.add_mutually_exclusive_group()
	argparser_build_examples_group.add_argument(
		"--build-examples",
		dest="build_examples",
		type=BoolArgValue,
		choices=[True, False],
		action="store",
		default=True,
		help="""
			Determines whether the examples should be built (default = %(default)s).
		"""
	)
	argparser_build_examples_group.add_argument(
		"--no-examples",
		dest="build_examples",
		action="store_false",
		help="""
			Do not build the examples and the textures.
			Equivalent to --build-examples=False.
		"""
	)
	argparser_build_docs_group = argparser.add_mutually_exclusive_group()
	argparser_build_docs_group.add_argument(
		"--build-docs",
		dest="build_docs",
		type=BoolArgValue,
		choices=[True, False],
		action="store",
		default=True,
		help="""
			Determines whether the documentation should be built (default = %(default)s).
		"""
	)
	argparser_build_docs_group.add_argument(
		"--no-docs",
		dest="build_docs",
		action="store_false",
		help="""
			Do not build the documentation.
			Equivalent to --build-docs=False.
		"""
	)
	argparser_make_screenshots_group = argparser.add_mutually_exclusive_group()
	argparser_make_screenshots_group.add_argument(
		"--make-screenshots",
		dest="make_screenshots",
		type=BoolArgValue,
		choices=[True, False],
		action="store",
		default=False,
		help="""
			Determines whether screenshots from OGLplus examples should be
			made when building the documentation (default = %(default)s).
		"""
	)
	argparser_make_screenshots_group.add_argument(
		"--screenshots",
		dest="make_screenshots",
		action="store_true",
		help="""
			Equivalent to --make-screenshots=True.
		"""
	)
	argparser.add_argument(
		"--max-gl-version",
		dest="max_gl_version",
		type=OpenGLVersionValue,
		action="store",
		default=None,
		help="""
			Sets the maximum OpenGL version to be used. The cmake OpenGL
			version detection is only rudimentary and not 100%% reliable
			and may return a higher OpenGL version than actually available.
			This option can be used to limit the maximal version number.
		"""
	)
	argparser.add_argument(
		"--strict-gl-version-detection",
		dest="strict_gl_version_detection",
		type=BoolArgValue,
		action="store",
		default=None,
		help="""
			Enables (or disables) strict GL version and extension detection.
			In relaxed (non-strict) mode the only thing that is detected is
			whether specific GL symbols are defined like GL_VERSION_x_y or
			GL_EXT_extension_name. In strict mode a GL context is initialized
			and the GL version and extension list is queried and processed.
		"""
	)
	argparser.add_argument(
		"--gl-tests-compile-only",
		dest="gl_tests_compile_only",
		action="store_true",
		default=False,
		help="""
			Only compilation failures are taken into account when
			detecting GL version or extensions. Execution failures
			are ignored.
		"""
	)

	gl_api_libs = {
		"glcorearb.h" : "GL/glcorearb.h header",
		"gl3.h" : "GL3/gl3.h header",
		"GLEW" : "GLEW library",
		"GL3W" : "GL3W library"
	}

	argparser_gl_api_lib_group = argparser.add_mutually_exclusive_group()
	argparser_gl_api_lib_group.add_argument(
		"--use-gl-api-lib",
		dest="gl_api_lib",
		type=str,
		choices=[lib.upper().replace('.', '_') for lib in gl_api_libs.keys() ],
		action="store",
		default=None,
		help="""
			Forces the use of a specific header or library which
			defines the GL symbols (types, functions, defines, etc.).
			If this option is used then the header must be installed somewhere
			in the system include directories or in directories specified
			with --include-dir and the corresponding binary libraries
			must be installed in system library directories or in directories
			specified with the --library-dir option.
		"""
	)
	for gl_api_lib, gl_api_lib_name in gl_api_libs.items():
		lib_lc = gl_api_lib.lower().replace('.', '-')
		lib_uc = gl_api_lib.upper().replace('.', '_')
		argparser_gl_api_lib_group.add_argument(
			"--use-%(lib_lc)s" % { "lib_lc" : lib_lc },
			dest="gl_api_lib",
			action="store_const",
			const=lib_uc,
			help="""
				Forces the use of the %(lib_name)s to define the GL symbols
				used in OGLplus examples.
				Equivalent to --use-gl-api-lib=%(lib_uc)s.
			""" % {
				"lib" : gl_api_lib,
				"lib_name" : gl_api_lib_name,
				"lib_uc" : lib_uc
			}
		)

	# TODO
	#gl_init_libs = ["GLUT", "GLFW3", "GLFW", "wxGL", "SDL", "glX", "EGL"]
	gl_init_libs = ["GLUT", "GLFW3", "GLFW", "SDL", "glX"]
	argparser_gl_init_lib_group = argparser.add_mutually_exclusive_group()
	argparser_gl_init_lib_group.add_argument(
		"--use-gl-init-lib",
		dest="gl_init_lib",
		type=str,
		choices=[lib.upper() for lib in gl_init_libs],
		action="store",
		default=None,
		help="""
			Forces the use of a specific window library which
			initializes the default GL context. This option allows
			to force a specific example 'harness'.
		"""
	)

	for gl_init_lib in gl_init_libs:
		argparser_gl_init_lib_group.add_argument(
			"--use-%(lib_lc)s" % { "lib_lc" : gl_init_lib.lower() },
			dest="gl_init_lib",
			action="store_const",
			const=gl_init_lib.upper(),
			help="""
				Forces the use of the %(lib)s library to create
				the window and initialize the GL context in
				OGLplus examples.
				Equivalent to --use-gl-init-lib=%(lib_uc)s.
			""" % {
				"lib" : gl_init_lib,
				"lib_uc" : gl_init_lib.upper()
			}
		)

	argparser.add_argument(
		"--clean",
		default=False,
		action="store_true",
		help="""
			Remove any previous cached and intermediate files and run the
			configuration process from scratch.
			Specifying this option causes the build directory to be deleted
			and recreated.
		"""
	)
	argparser.add_argument(
		"--quiet",
		default=False,
		action="store_true",
		help="""
			Do not print regular messages, errors are still printed to
			stderr. Also any cmake output is still printed.
		"""
	)
	argparser.add_argument(
		"--quick",
		default=False,
		action="store_true",
		help="""
			Skips some optional steps in the configuration process.
		"""
	)
	argparser.add_argument(
		"--jobs",
		type=JobCountValue,
		default=None,
		action="store",
		help="""
			Specifies the number of parallel build jobs to be used,
			if applicable for the used build tool.
		"""
	)
	argparser.add_argument(
		"--build",
		default=False,
		action="store_true",
		help="""
			If possible, after running cmake also invoke the build tool
			and build the project. This is currently supported only
			for certain build tools.
		"""
	)
	argparser.add_argument(
		"--no-tests",
		default=False,
		action="store_true",
		help="""
			Disable configuring of the testsuite.
		"""
	)
	argparser.add_argument(
		"--no-enum-tests",
		default=False,
		action="store_true",
		help="""
			Don't include enumerations tests in the testsuite.
		"""
	)
	argparser.add_argument(
		"--generator",
		type=CMakeGeneratorValue,
		default=None,
		action="store",
		help="""
			Specify the cmake generator to be used.
		"""
	)
	argparser.add_argument(
		"--debug-config",
		dest="debug_config",
		default=False,
		action="store_true",
		help="""
			Enable debugging of the cmake build system.
		"""
	)
	argparser.add_argument(
		"--debug-gl-ver-error",
		dest="debug_gl_ver_error",
		default=False,
		action="store_true",
		help="""
			Enable debugging of problems with GL version detetion.
		"""
	)
	argparser.add_argument(
		"--debug-gl-ext-error",
		dest="debug_gl_ext_error",
		type=str,
		default="",
		action="store",
		help="""
			Enable debugging of problems with GL extension detetion.
		"""
	)
	argparser.add_argument(
		"--debug-lib-error",
		dest="debug_lib_error",
		default=False,
		action="store_true",
		help="""
			Enable debugging of problems with building the library.
		"""
	)
	argparser.add_argument(
		"--cmake",
		dest="cmake_options",
		nargs=argparse.REMAINDER,
		default=list(),
		help="""Everything following this option will be passed to cmake verbatim."""
	)

	return argparser

# applies LD_LIBRARY_PATH to library search directories
def search_ld_library_path():
	ld_library_path_dirs = list()
	try:
		ld_library_path = os.environ.get("LD_LIBRARY_PATH")
		if ld_library_path:
			for ld_library_dir in ld_library_path.split(':'):
				if os.path.isdir(ld_library_dir):
					ld_library_path_dirs.append(ld_library_dir)
	except: pass
	return ld_library_path_dirs

# applies CXXFLAGS to the options for cmake if possible
def search_cxxflags():
	cxxflags_include_dirs = list()
	try:
		import shlex

		cxxflags = os.environ.get("CXXFLAGS")
		if cxxflags is not None:
			flagiter = iter(shlex.split(cxxflags))
			for flag in flagiter:
				if flag == "-I":
					cxxflags_include_dirs.append(flagiter.next())
				elif flag.startswith("-I"):
					cxxflags_include_dirs.append(flag[2:])
	except: pass
	return cxxflags_include_dirs


# applies LDFLAGS to the options for cmake if possible
def search_ldflags():
	ldflags_library_dirs = list()
	try:
		import shlex

		ldflags = os.environ.get("LDFLAGS")
		if ldflags is not None:
			flagiter = iter(shlex.split(ldflags))
			for flag in flagiter:
				if flag == "-L":
					ldflags_library_dirs.append(flagiter.next())
				elif flag.startswith("-L"):
					ldflags_library_dirs.append(flag[2:])
	except: pass
	return ldflags_library_dirs

# get some useful information from cmake
def cmake_system_info(options):
	info_path = os.path.join(options.build_dir, "system-info.txt")
	command = ["cmake", "--system-information", info_path]
	try:
		proc = subprocess.Popen(
			command,
			stdin=None,
			stdout=subprocess.PIPE,
			stderr=None
		)
	except OSError as os_error:
		print("Failed to execute '%(cmd)s': %(error)s" % {
			"cmd": command,
			"error": os_error
		})
		sys.exit(2)

	result = dict()

	try:
		import shlex
		for line in open(info_path).readlines():
			try:
				words = shlex.split(line)
				if(words[0] in (
					"CMAKE_BUILD_TOOL",
					"CMAKE_INSTALL_PREFIX"
				)): result[words[0]] = words[1]
			except ValueError:
				pass
			except IndexError:
				pass
	except: pass

	return result


# the main function
def main(argv):

	# parse and process the command-line arguments
	argparser = get_argument_parser()
	options = argparser.parse_args()
	cmake_env = os.environ.copy()
	if sys.platform == 'win32':
		env_list_sep = str(";")
	else: env_list_sep = str(":")

	# if we just wanted to generate the bash completion script
	if options.generate_bash_complete:
		args.print_bash_complete_script(argparser)
		return 0

	# if we just wanted to generate the bash completion script
	if options.generate_manual:
		args.print_manual(argparser)
		return 0

	# if we are in quiet mode we may also go to quick mode
	if options.quiet: options.quick = True

	# if we also want to build the project disable quick mode
	if options.build: options.quick = False

	# get the info from cmake if we are not in a hurry
	if not options.quick:
		cmake_info = cmake_system_info(options)
	else: cmake_info = list()

	# the search prefix
	for search_dir in options.search_dirs:
		subdir = os.path.join(search_dir, "include")
		if os.path.exists(subdir):
			options.include_dirs.append(subdir)
		subdir = os.path.join(search_dir, "lib")
		if os.path.exists(subdir):
			options.library_dirs.append(subdir)
			subdir = os.path.join(subdir, "pkgconfig")
			pkg_config_path = cmake_env.get("PKG_CONFIG_PATH", None)
			if pkg_config_path:
				pc_paths = pkg_config_path.split(env_list_sep)
				pc_paths.append(subdir)
				pkg_config_path = env_list_sep.join(pc_paths)
			else: pkg_config_path = subdir
			cmake_env["PKG_CONFIG_PATH"] = pkg_config_path

	# search the LD_LIBRARY_PATH
	options.library_dirs += search_ld_library_path()
	# search the CXX and LD FLAGS if requested
	if(options.use_cxxflags): options.include_dirs += search_cxxflags()
	if(options.use_ldflags):  options.library_dirs += search_ldflags()

	# additional options for cmake
	cmake_options = list()

	# add the installation prefix if provided
	if(options.install_prefix):
		cmake_options.append(
			"-DCMAKE_INSTALL_PREFIX="+
			options.install_prefix
		)

	# set the low profile mode switch
	if(options.low_profile is not None):
		cmake_options.append("-DCONFIG_SET_LOW_PROFILE=On")
		if(options.low_profile):
			cmake_options.append("-DLOW_PROFILE=On")
		else:
			cmake_options.append("-DLOW_PROFILE=Off")

	# if we just want fo query the system configuration info
	if(options.info_only):
		cmake_options.append("-DCONFIG_INFO_ONLY=On")

	# disable building the examples
	if(not options.build_examples):
		cmake_options.append("-DNO_EXAMPLES=On")

	# limit the GL version
	if(options.max_gl_version):
		cmake_options.append("-DCONFIG_MAX_GL_VERSION=%s"%options.max_gl_version)

	# enable/disable strict version detection
	if(options.strict_gl_version_detection is not None):
		value = int(options.strict_gl_version_detection)
		cmake_options.append("-DCONFIG_STRICT_GL_VERSION_CHECK=%d"%value)

	if(options.gl_tests_compile_only):
		cmake_options.append("-DCOMPILE_ONLY_GL_TESTS=On")

	# force the GL header to be used
	if(options.gl_api_lib):
		cmake_options.append("-DFORCE_GL_API_LIB=%s"%options.gl_api_lib)

	# force the GL initialization library to be used
	if(options.gl_init_lib):
		cmake_options.append("-DFORCE_GL_INIT_LIB=%s"%options.gl_init_lib)

	# add paths for header lookop
	if(options.include_dirs):
		cmake_options.append("-DHEADER_SEARCH_PATHS="+";".join(options.include_dirs))

	# add paths for library lookup
	if(options.library_dirs):
		cmake_options.append("-DLIBRARY_SEARCH_PATHS="+";".join(options.library_dirs))

	# remove the build dir if it was requested
	if(options.clean and os.path.exists(options.build_dir)):
		try: shutil.rmtree(options.build_dir)
		except OSError as os_error:
			print("Warning failed to remove build directory")

	# configure the test suite
	if(options.no_tests):
		cmake_options.append("-DNO_TESTS=On")
	if(options.no_enum_tests):
		cmake_options.append("-DNO_ENUM_TESTS=On")

	# set the generator if specified
	if(options.generator):
		cmake_options += ['-G', options.generator]

	# put cmake in debug mode if specified
	if(options.debug_gl_ver_error):
		cmake_options += ["-DDEBUG_GL_VER_ERROR=1"]
	if(options.debug_gl_ext_error):
		cmake_options += ["-DDEBUG_GL_EXT_ERROR=%s"%options.debug_gl_ext_error]
	if(options.debug_lib_error):
		cmake_options += ["-DDEBUG_LIB_ERROR=1"]
	if(options.debug_config):
		cmake_options += ["--debug-output", "--debug-trycompile"]

	# create the build directory if necessary
	if(not os.path.isdir(options.build_dir)):
		os.makedirs(options.build_dir)

	# compose the command line for calling cmake
	workdir = os.path.abspath(os.path.dirname(sys.argv[0]))
	cmake_cmd_line = ["cmake"] + cmake_options + options.cmake_options + [workdir]

	# call cmake
	try:
		ret = subprocess.call(
			cmake_cmd_line,
			cwd=options.build_dir,
			env=cmake_env
		)
		if ret < 0:
			print("# Configuration killed by signal %d" % -ret)
			sys.exit(-ret)
		elif ret > 0:
			print("# Configuration failed with code %d" % ret)
			sys.exit(ret)
	# handle errors
	except OSError as os_error:
		print( "# Configuration failed")
		print("# Failed to execute '%(cmd)s': %(error)s" % {
			"cmd": str(" ").join(cmake_cmd_line),
			"error": str(os_error)
		})
		sys.exit(3)

	# use the specified number of jobs
	if options.jobs is not None:
		job_count = options.jobs
	else:
		# else try to get the processor count (use below)
		try:
			import multiprocessing
			job_count = multiprocessing.cpu_count()+1
		except: job_count = None

	# print some info if not supressed
	if not options.quiet and not options.info_only:
		print("# Configuration completed successfully.")

		cmake_build_tool = cmake_info.get("CMAKE_BUILD_TOOL")
		if(cmake_build_tool):
			cmake_build_tool = paths.shorten_command(cmake_build_tool)
			path_to_build_dir = paths.shortest_path_from_to(os.getcwd(), options.build_dir)

			if(not options.build):
				if(cmake_build_tool == "make"):
					print("# To build OGLplus do the following:")
					print(str())
					print("cd "+ path_to_build_dir)
					if job_count:
						print("%(tool)s -j %(jobs)d" % {
							"tool": cmake_build_tool,
							"jobs": job_count
						})
					else: print(cmake_build_tool)
					print(cmake_build_tool + " install")

	# if the user requested build after config is done
	if options.build:
		cmake_build_tool = cmake_info.get("CMAKE_BUILD_TOOL")

		if cmake_build_tool:
			build_tool_name = os.path.basename(cmake_build_tool)
		else:
			build_tool_name = str()

		if build_tool_name in ("make",):
			build_cmd_line = [cmake_build_tool];
			if job_count:
				build_cmd_line += ["-j", str(job_count)]
		elif build_tool_name in ("devenv.com", "devenv.exe"):
			build_cmd_line = [
				cmake_build_tool,
				os.path.join(options.build_dir, "OGLplus.sln"),
				"/Build",
				"Release"
			]
		else: build_cmd_line = [ "cmake", "--build", options.build_dir ]

		if build_cmd_line:
			try: subprocess.call(
				build_cmd_line,
				cwd=options.build_dir,
				env=cmake_env
			)
			except OSError as os_error:
				print( "# Build failed")
				print("# Failed to execute '%(cmd)s': %(error)s" % {
					"cmd": str(" ").join(build_cmd_line),
					"error": str(os_error)
				})
				sys.exit(4)
		else: print("# --build is not supported with the current build tool")


	# print the configuration info if requested
	if options.info_only:
		try:
			info_py_path=os.path.join(options.build_dir, 'config', 'info.py')
			info_py=open(info_py_path).read()
			exec(info_py) in locals()

			key_descs = {
				"GL_INIT_LIBS": "Possible values for --gl-init-lib",
				"GL_API_LIBS": "Possible values for --gl-api-lib",
			}
			for key, value in oglplus_config_info.items():

				try: desc=key_descs[key]
				except: desc=key

				if type(value) == list:
					value = "\n\t".join(value)

				print("%(desc)s:\n\t%(value)s" % {"desc": desc, "value": value})
		except: pass

	# print additional info if not supressed
	elif not options.quiet:

		if not options.install_prefix:
			options.install_prefix = cmake_info.get("CMAKE_INSTALL_PREFIX")

		if(options.install_prefix):

			if not os.access(options.install_prefix, os.W_OK):
				print(str())
				print("# NOTE: installing to '%(prefix)s' "\
					"may require administrative privilegues" % {
						"prefix": options.install_prefix
					}
				)

# run the main function
if __name__ == "__main__": main(sys.argv[1:])
