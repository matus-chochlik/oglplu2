# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

import os
import sys
import subprocess
#------------------------------------------------------------------------------#
def thisDir():
    return os.path.dirname(os.path.abspath(__file__))
#------------------------------------------------------------------------------#
def absPath(path, work_dir = thisDir()):
    if not os.path.isabs(path):
        path = os.path.join(work_dir, path)
    return os.path.realpath(path)
#------------------------------------------------------------------------------#
def makeOptionPathsAbsolute(old_opts, work_dir = thisDir()):
    new_opts = list()
    make_next_abs = False
    path_flags = ['-include', '-isystem', '-I', '-iquote', '--sysroot=']

    for opt in old_opts:
        new_opt = opt
        if make_next_abs:
            new_opt = absPath(opt, work_dir)
            make_next_abs = False
        else:
            for path_flag in path_flags:
                if opt == path_flag:
                    make_next_abs = True
                    break
                if opt.startswith(path_flag):
                    path = opt[len(path_flag):]
                    new_opt = path_flag + MakePathAbsolute(path, work_dir)
                    break

        new_opts += [new_opt]
    return new_opts
#------------------------------------------------------------------------------#
def binaryDir():
    try:
        with open(os.path.join(thisDir(), "BINARY_DIR"), "rt") as bdf:
            return absPath(bdf.read(), thisDir())
    except: pass
    return os.path.join(thisDir(), "_build")
#------------------------------------------------------------------------------#
compiler_opts = [
    '-DEAGINE_YCM',
    '-pedantic',
    '-Wall',
    '-Weverything',
    '-Werror',
    '-Wno-c++98-compat',
    '-Wno-c++98-compat-pedantic',
    '-Wno-undef',
    '-Wno-global-constructors',
    '-Wno-exit-time-destructors',
    '-Wno-date-time',
    '-Wno-weak-vtables',
    '-Wno-padded',
    '-Wno-missing-prototypes',
    '-Wno-switch-enum',
    '-std=c++17',
    '-x', 'c++',
]
#------------------------------------------------------------------------------#
def scan_for_system_include_dirs():
    try:
        clang_args = ['clang++', '-xc++', '-E', '-v', '-']
        clang_proc = subprocess.Popen(
            clang_args,
            stdin=file("/dev/null"),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        unused, output = clang_proc.communicate()
        tokens = output.split()

        result = []
        for i in xrange(1, len(tokens)):
            if tokens[i-1].endswith("-isystem"):
                if os.path.isdir(tokens[i]):
                    result.append(tokens[i])
        return result
    except: pass

    return [
        "/usr/include",
        "/usr/local/include"
    ]
#------------------------------------------------------------------------------#
system_include_dirs = scan_for_system_include_dirs()

#------------------------------------------------------------------------------#
project_include_dirs = [
    os.path.join(binaryDir(), "include"),
    'include',
    'implement',
    'third_party/include',
    'third_party/asio/asio/include',
    'source/utils'
]
#------------------------------------------------------------------------------#
def FlagsForFile(filename, ** kwargs):
    final_opts = compiler_opts

    for path in system_include_dirs:
        apath = absPath(path)
        if os.path.isdir(apath):
            final_opts += ['-isystem', apath]

    for path in project_include_dirs:
        apath = absPath(path)
        if os.path.isdir(apath):
            final_opts += ['-I', apath]

    path, ext = os.path.splitext(filename)

    if ext in [".hpp", ".inl", ".cpp", ".h"]:
        final_opts += ['-include', 'include/oglplus/gl.hpp']
        final_opts += ['-include', 'include/oalplus/al.hpp']
        final_opts += ['-include', 'include/eglplus/egl.hpp']

    if ext == ".inl":
        def repl(x): return 'include' if name == 'implement' else name
        path = os.path.sep.join([repl(name) for name in path.split(os.path.sep)])
        inl_header = path + '.hpp'

        if os.path.isfile(inl_header):
            final_opts += ['-include', inl_header]

    return {
        'flags': makeOptionPathsAbsolute(final_opts),
        'do_cache': True
    }
#------------------------------------------------------------------------------#
if __name__ == "__main__":
    for arg in sys.argv[1:]:
        if os.path.isfile(arg):
            print(FlagsForFile(arg))
#------------------------------------------------------------------------------#
