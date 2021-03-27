===============
OGLplus2 README
===============

:Author: Matúš Chochlík <chochlik@gmail.com>

.. image:: https://travis-ci.org/matus-chochlik/oglplu2.svg?branch=develop
    :target: https://travis-ci.org/matus-chochlik/oglplu2

.. contents::

.. _OGLplus: http://oglplus.org/
.. _Doxygen documentation: https://matus-chochlik.github.io/oglplu2/doxygen/
.. _OpenGL: https://opengl.org/
.. _OpenAL: https://openal.org/
.. _EGL: https://www.khronos.org/egl
.. _CMake: https://www.cmake.org/
.. _Doxygen: https://www.doxygen.org/
.. _Inkscape: https://inkscape.org/
.. _libPNG: https://www.libpng.org/
.. _GLEW: https://glew.sourceforge.net/
.. _GL3W: https://github.com/shakesoda/gl3w
.. _GLFW: https://www.glfw.org/
.. _GLFW3: https://www.glfw.org/
.. _FreeGLUT: https://freeglut.sourceforge.net/
.. _SDL: https://www.libsdl.org/
.. _wxGL: https://www.wxwidgets.org/
.. _Qt: https://qt.digia.com/
.. _Xlib: https://www.x.org/wiki/guide/
.. _GSL: https://github.com/Microsoft/GSL

Overview
========

OGLplus2 is a new wrapper for modern `OpenGL`_, using latest C++
features and a different design and naming conventions than `OGLplus`_.
Several examples showing the usage of OGLplus can be found in the ``example/``
directory and its subdirectories.

Cloning the repo
================
::

 git clone --recursive https://github.com/matus-chochlik/oglplu2.git

Requirements
============

A compiler supporting C++17, a Python 3 interpreter and a GL API library like
`GLEW`_, and a GL context management library like `GLFW3`_, `GLFW`_ or `SDL`_
are required. On Linux OGLplus2 also works with the `Xlib`_ library
and the ``GL/glcorearb.h`` header (the latter is included in the repository).

On recent Debian-like Linux distributions with the ``apt`` package manager,
the following should be enough to install most of the dependencies
for the GLFW3+GLEW configuration:

::

 sudo apt install \
    python3 \
    pkgconf \
    cmake \
    make \
    g++ \
    libglew-dev \
    libglfw3-dev \
    libssl-dev \
    libpng-dev \
    libsystemd-dev \
    libboost-test-dev

For other configurations using SDL, wxWidgets, GLUT, etc. you need to install
the appropriate packages (the names vary between distributions or even
between versions of the same distribution so they are not listed here).

Building
========

OGLplus2 uses a CMake-based build/configuration system.

The build system handles several important tasks:

 * Detects if the necessary things are installed and makes a site-configuration
   header file

 * Detects the support for C++17 features and builds configuration headers

 * Builds several additional, automatically generated headers mostly for
   compiler deficiency workarounds.

 * Installs all header files to a directory specified by the install prefix

 * Configures and builds the example executables.

 * Configures the test suite.

User-friendly configuration script
----------------------------------

The ``configure.py`` or ``oglplus-config`` scripts
provide a more user-friendly way to invoke cmake and to specify additional
parameters for the configuration process.

Some of the more important command-line options are described below:

--help              Display the help screen.

--clean             Does a clean reconfigure.

--build             Also builds the examples if possible.

--prefix PATH       Specifies the installation prefix path for cmake (sets
                    the value of the CMAKE_INSTALL_PREFIX variable).
                    If this option is not specified, cmake's default prefix
                    is used.

--include-dir PATH  Specify additional directiories
                    to search when looking for header files. It may be used
                    multiple times to specify multiple directories. Headers
                    are searched in the directories specified with this option
                    in the same order in which they appear on the command-line
                    and the default system header locations are searched only
                    afterwards. The first header found is used, in case there
                    are multiple versions of the searched header file.


--library-dir PATH  Specify additional directiories to search when looking
                    for compiled libraries. It may beused multiple times
                    to specify multiple directories. Libraries are
                    searched in the directories specified with this option
                    in the same order in which they appear on the command-line
                    and the default system library locations are searched
                    afterwards. The first library found is used, in case
                    there are multiple versions of the searched library.

See the ``--help`` option for the full description and detailed info
on the usage of these scripts.
Bash users can also do ``source config/configure.bash_complete``
to install a bash completion extension that allows to TAB-complete the command
line arguments for the ``oglplus-config`` configuration script that invokes
``configure.py``.

To configure and build the examples invoke ``oglplus-config`` in the following
way:

::

 ./oglplus-config --build

Documentation
=============

- The API is documented by `Doxygen documentation`_. Note, that it is
  work-in-progress and incomplete.

Why rebooting OGLplus?
======================

After several years of work on the original `OGLplus`_ library and after
using it in multiple different applications, some issues were identified.
OGLplus2 tries to address these issues:

*  Original OGLplus uses a naming convention which tries to match OpenGLs
   naming. This does not look very good when combined with other code
   using the naming conventions more typical for C++.
   OGLplus2 uses a more C++-ish naming convention similar to the one used
   by the standard library.

*  The enumeration types in the original OGLplus are rather verbose
   and require the library user to learn a lot of new names invented by
   OGLplus. In OGLplus2 the enumerations are still type-safe,
   but the enumeration values are directly based on the OpenGL constants.
   This allows for example to use ``gl.enable(GL.depth_test)`` instead of
   ``gl.Enable(Capability::DepthTest)``, or ``gl.begin(GL.triangles)``
   instead of ``gl.Begin(CompatibilityPrimitiveType::Triangles)``, etc.

*  In OGLplus most of the functions eagerly throw an exception immediately
   after a GL error is detected. In OGLplus2 the GL-wrapping functions
   return an object which either handles the error by default in its destructor
   or this behavior can be overriden by specifying a user-defined error handler
   or even cancelled on per-call basis as necessary.

*  The original OGLplus defines several abstractions which diverge from
   the OpenGL 'programming model', which may be misleading in some cases.
   OGLplus2 tries to stay closer to how things are done in OpenGL.

*  OGLplus2 provides a more fine-grained control over GL object lifetime.

*  Some parts of OGLplus (for example the object naming registry, the limited
   value checkers, etc.) don't work very well in applications using multiple
   GL contexts.

*  In order to ensure backward compatiblity OGLplus source code is full
   of various workarounds which makes it rather messy. By using modern C++
   many features can be implemented in a more straithtforward way without using
   lots of C++-feature-related ``#ifdefs``.

*  The OALplus and EGLplus reuse some code defined in the original OGLplus.
   Here the common code like vectors, matrices, the framework for wrapping
   OpenGL or OpenAL objects, code related to error handling, etc. is implemented
   in the low-level ``eagine`` library and then reused by OGLplus and
   in the future by OALplus, EGLplus, possibly OVGplus, etc.

*  In OGLplus 'testing' was mostly done by trying out the various features
   in the examples. OGLplus2 brings a more comprehensive and more thorough
   testing suite.

License
=======

Copyright Matus Chochlik, 2015-2021.
Distributed under the Boost Software License, Version 1.0.
See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt

