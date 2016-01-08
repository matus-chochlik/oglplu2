#!/usr/bin/python
# coding=utf-8
# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
import os
import argparse

# returns a normalized path to the project root directory
def get_root_dir():
	import sys

	return os.path.normpath(
		os.path.join(
			os.path.dirname(sys.argv[0]),
			os.path.pardir
		)
	)


# returns the path to the build directory
def get_build_dir():
	return os.path.join(get_root_dir(), "_build");


# returns the path to the config script
def configure_script():
	return os.path.join(get_root_dir(), "configure.py")


# executes a command in a subprocess
def execute_command(options, cmd_line, work_dir, simulate=None, quiet=False):
	import subprocess

	if simulate is None: simulate = options.dry_run
	if simulate or not quiet:
		if len(cmd_line) == 1:
			cmd_str = cmd_line[0]
		else: cmd_str = cmd_line[0]+" '"+str("' '").join(cmd_line[1:])+"'"

		if work_dir == os.path.curdir:
			print(cmd_str)
		else: print("(cd %s && %s)" % (work_dir, cmd_str))
	if not simulate:
		subprocess.check_call(cmd_line, cwd=work_dir)

# executes the configure script
def execute_configure(options, parameters, simulate=None, quiet=False):

	if options.jobs is None:
		job_params = list()
	else: job_params = ["--jobs", str(options.jobs)]

	execute_command(
		options,
		[configure_script()]+job_params+parameters+options.config_options,
		get_root_dir(),
		simulate, quiet
	)

# executes ctest in the configured test directory
def execute_ctest(options):
	if options.jobs is None:
		job_params = list()
	else: job_params = ["-j", str(options.jobs)]

	test_dir = os.path.join(get_build_dir(), "test")

	import subprocess

	try:
		execute_command(
			options,
			["ctest"]+job_params,
			test_dir
		);
	except subprocess.CalledProcessError:
		failed_tests_path = os.path.join(
			test_dir,
			"Testing", "Temporary", "LastTestsFailed.log"
		)
		with open(failed_tests_path) as failed_tests:
			for line in failed_tests:
				test_name = line.rstrip().split(':')[1]
				test_lib = test_name.split('-')[0]

				try:
					cmd_line = ["ctest", "-VV", "-R", test_name];
					work_dir = os.path.join(test_dir, test_lib)
					proc = subprocess.Popen(cmd_line, cwd=work_dir)
					proc.communicate()
				except subprocess.CalledProcessError: pass
		raise


# options for the --gl-apis parameter
gl_libs_names = ["default", "all-apis", "all-libs"]
# options for the --test-level parameter
test_level_names = ["minimal", "basic", "extended", "complete"]
# options for the --test-type parameter
test_type_names = ["everything", "ctest", "build-examples", "configure-gl"]

# checks if arg is valid option for --gl-libs
def gl_libs_value(arg):
	if(arg in gl_libs_names):
		return arg;
	else:
		msg = "'%s' is not a valid GL library combination" % str(arg)
		raise argparse.ArgumentTypeError(msg)

# checks if arg is valid option for --test-level
def test_level_value(arg):
	if(arg in test_level_names):
		return arg;
	else:
		msg = "'%s' is not a valid test level" % str(arg)
		raise argparse.ArgumentTypeError(msg)

# checks if arg is valid option for --test-type
def test_type_value(arg):
	if(arg in test_type_names):
		return arg;
	else:
		msg = "'%s' is not a valid test type" % str(arg)
		raise argparse.ArgumentTypeError(msg)


# checks if the value specfied as --test-level was at least level
def test_level_at_least(options, level):
	result = True
	for name in test_level_names:
		if name == level:
			break
		if name == options.test_level:
			result = False
	return result

# checks if the value specfied as --gl-libs was at least level
def gl_libs_at_least(options, level):
	result = True
	for name in gl_libs_names:
		if name == level:
			break
		if name == options.gl_libs:
			result = False
	return result


def execute_tests(options, parameters):
	for name in set(options.test_type):
		if name == "everything":
			execute_configure(options, parameters+["--build"])
			execute_ctest(options)
		elif name == "ctest":
			execute_configure(options, parameters+["--no-examples"])
			execute_ctest(options)
		elif name == "build-examples":
			execute_configure(options, parameters+["--no-tests", "--build"])
		elif name == "configure-gl":
			execute_configure(options, parameters+["--gl-tests-compile-only", "--debug-gl-ver-error", "--no-tests", "--no-examples"])


def for_each_gl_init_lib(options, parameters):
	func = execute_tests
	if gl_libs_at_least(options, "all-libs"):
		for gl_init_lib in options.config_info['GL_INIT_LIBS']:
			func(options, parameters+["--use-gl-init-lib=%s" % gl_init_lib])
	else:
		func(options, parameters)


def for_each_gl_api_lib(options, parameters):
	func = for_each_gl_init_lib
	if gl_libs_at_least(options, "all-apis"):
		for gl_api_lib in options.config_info['GL_API_LIBS']:
			func(options, parameters+["--use-gl-api-lib=%s" % gl_api_lib])
	else:
		func(options, parameters)


def for_each_profile(options, parameters):
	func = for_each_gl_api_lib
	if test_level_at_least(options, "basic"):
		func(options, parameters+["--low-profile=True"])
		func(options, parameters+["--low-profile=False"])
	else:
		func(options, parameters)
	

# creates the command line argument parser
def get_argument_parser():

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

	argparser = argparse.ArgumentParser(
		prog="test",
		description="""
		Utility script running various tests
		""",
		epilog="""
		Copyright (c) Matúš Chochlík.
		Permission is granted to copy, distribute and/or modify this document
		under the terms of the Boost Software License, Version 1.0.
		(See a copy at http://www.boost.org/LICENSE_1_0.txt)
		"""
	)

	argparser.add_argument(
		"--dry-run",
		default=False,
		action="store_true",
		help="""
		Only print the commands that should be executed
		but don't do anything.
		"""
	)

	argparser.add_argument(
		"--release",
		default=False,
		action="store_true",
		help="""
		Run all tests usually done for release candidate testing.
		"""
	)
	argparser.add_argument(
		"--jobs",
		type=JobCountValue,
		default=None,
		action="store",
		help="""
		Specifies the number of parallel jobs to be used.
		"""
	)

	argparser.add_argument(
		"--max-jobs",
		type=JobCountValue,
		default=None,
		action="store",
		help="""
		Specifies the maximum number of parallel jobs to be used.
		"""
	)

	argparser.add_argument(
		"--gl-libs",
		type=gl_libs_value,
		default=None,
		help="""
		Influences the GL library combinations with which
		the tests are configured and executed.
		"""
	)

	argparser.add_argument(
		"--test-level",
		type=test_level_value,
		default=None,
		help="""
		Influences the number of configurations in which
		the tests are executed.
		"""
	)

	argparser.add_argument(
		"--test-type",
		type=test_type_value,
		default=list(),
		action="append",
		help="""
		Specifies the test type(s) to be executed.
		"""
	)

	argparser.add_argument(
		"--config-info",
		default=dict()
	)

	argparser.add_argument(
		"--config",
		dest="config_options",
		nargs=argparse.REMAINDER,
		default=list(),
		help="""
		Everything following this option will be passed
		to configure verbatim.
		"""
	)

	return argparser
	

def main():
	import os, sys
	try:
		# parse and process the command-line arguments
		argparser = get_argument_parser()
		options = argparser.parse_args()

		# set the test level if none
		if options.test_level is None:
			if options.release:
				options.test_level = "complete"
			else: options.test_level="minimal"

		# set the test type if empty
		if len(options.test_type) == 0:
			options.test_type = ["everything"]

		if options.jobs is None:
			try:
				import multiprocessing
				options.jobs = multiprocessing.cpu_count()+1
			except: pass

		# limit the number of jobs
		if options.jobs is not None and options.max_jobs is not None:
			if options.jobs > options.max_jobs:
				options.jobs = options.max_jobs

		# set the gl-libs if none
		if options.test_level is None:
			if options.release:
				options.test_level = "all-libs"
			else: options.test_level="default"


		# if necessary ..
		if gl_libs_at_least(options, "all-apis"):
			# get configuration info
			execute_configure(
				options,
				["--clean", "--info-only"],
				simulate=False,
				quiet=True
			)
			# load configuration info
			info_py_path=os.path.join(get_build_dir(), 'config', 'info.py')
			info_py=open(info_py_path).read()
			exec(info_py) in locals()
			options.config_info = system_config_info;

		for_each_profile(options, ["--clean"])

	except RuntimeError as rte:
		print("Runtime error: " + str(rte))

if __name__ == "__main__": main()

