Building your own applications
------------------------------

This directory contains examples showing how to build your own applications
using OGLplus.

Each subdirectory has its own standalone cmake project. Before building
these example(s) you need first build OGLplus from sources located
in a ``${source_dir}`` with ``cmake`` and install it (into the system or into
a separate ``${install_prefix}`` directory).

Then you can use the following commands to configure and build the individual
examples:
::

    mkdir build_dir
    cd build_dir
    cmake \
        ${source_dir}/examples/external/${example_name}/ \
        -DCMAKE_PREFIX_PATH=${install_prefix}/lib/cmake/
    cmake --build .

If you have installed OGLplus in your system directories you can omit
the ``-DCMAKE_PREFIX_PATH=...`` parameter.
