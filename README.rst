===============
OGLplus2 README
===============

:Author: Matúš Chochlík <chochlik@gmail.com>

.. contents::
.. image:: https://travis-ci.org/matus-chochlik/oglplu2.svg?branch=develop
    :target: https://travis-ci.org/matus-chochlik/oglplu2

.. _OpenGL: http://opengl.org/
.. _OpenAL: http://openal.org/
.. _EGL: http://www.khronos.org/egl
.. _OGLplus: http://oglplus.org/
.. _CMake: http://www.cmake.org/
.. _Doxygen: http://www.doxygen.org/
.. _Inkscape: http://inkscape.org/
.. _libPNG: http://www.libpng.org/
.. _GLEW: http://glew.sourceforge.net/
.. _GL3W: http://github.com/shakesoda/gl3w
.. _GLFW: http://www.glfw.org/
.. _FreeGLUT: http://freeglut.sourceforge.net/
.. _SDL: http://www.libsdl.org/
.. _wxGL: http://www.wxwidgets.org/
.. _Qt: http://qt.digia.com/
.. _GSL: https://github.com/Microsoft/GSL

Overview
========

OGLplus2 is an experimental wrapper for modern `OpenGL`_, using latest C++ features
and a different design and naming conventions than `OGLplus`_.
OGLplus2 is in a very early stage of development.
Several examples showing the usage of OGLplus can be found in the ``example/``
directory and its subdirectories.

Requirements
============

A compiler supporting C++14 and the `GLEW`_ and `GLFW`_ libraries are required.
Currently the only compiler known to work is clang++-3.5.0.
Support for other libraries with similar functionality will be added in the future.

The `GSL`_ library is also required; the ``third_party/GSL`` directory contains
a git submodule which should be updated before building OGLplus2.

Building
========

OGLplus2 uses simple `CMake`_-based build system.
At the moment there is no user-friendly configuration script,
but the examples can be built by issuing the following commands:

::

 mkdir _build &&
 cd _build &&
 cmake .. &&
 make

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
   OGLplus. In OGLplus2 the enumerations are still type-safe, but the enumeration
   values are directly based on the OpenGL constants.
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

*  In order to ensure backward compatiblity OGLplus source code is full of various
   workarounds which makes it rather messy. By using modern C++ many features
   can be implemented in a more straithtforward way without using lots of
   C++-feature-related ``#ifdefs``.

*  The OALplus and EGLplus reuse some code defined in the original OGLplus.
   Here the common code like vectors, matrices, the framework for wrapping
   OpenGL or OpenAL objects, code related to error handling, etc. is implemented
   in the low-level ``eagine`` library and then reused by OGLplus and
   in the future by OALplus, EGLplus, possibly OVGplus, etc.

*  In OGLplus 'testing' was mostly done by trying out the various features
   in the examples. OGLplus2 brings a more comprehensive and more thorough
   testing suite.

TODO

License
=======

Copyright Matus Chochlik, 2015.
Distributed under the Boost Software License, Version 1.0.
See accompanying file LICENSE_1_0.txt or copy at
 http://www.boost.org/LICENSE_1_0.txt

