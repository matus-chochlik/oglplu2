Requirements
============

.. _GLEW: https://glew.sourceforge.net/
.. _GL3W: https://github.com/shakesoda/gl3w
.. _GLFW: https://www.glfw.org/
.. _GLFW3: https://www.glfw.org/
.. _SDL: https://www.libsdl.org/
.. _Xlib: https://www.x.org/wiki/guide/

A compiler supporting C++17, a Python 3 interpreter and a GL API library like
`GLEW`_, and a GL context management library like `GLFW3`_, or `SDL`_
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


