Building and installation
=========================

OGLplus uses a CMake-based configuration/build system.

The build system handles several important tasks:

* detects if the necessary things are installed and makes a site-configuration
  header file,

* detects the support for new C++ features and generated configuration headers,

* installs all header files to a directory specified by the install prefix,

* configures and builds the example executables,

* configures the test suite.

To configure, build and install the project you can do something like:

::

 mkdir _build
 cd _build
 cmake /path/to/oglplu2/
 make -j 16
 make install

User-friendly configuration script
----------------------------------

The ``configure.py`` or ``oglplus-config`` scripts
provide a more user-friendly way to invoke cmake and to specify additional
parameters for the configuration process.

Some of the more important command-line options are described below:

--help              Display the help screen.

--clean             Does a clean reconfigure (removes the contents of the build
                    directory).

--build             Builds the libraries, tools, examples, etc.

--prefix PATH       Specifies the installation prefix path for cmake (sets
                    the value of the ``CMAKE_INSTALL_PREFIX`` variable).
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

To configure and build the examples invoke ``oglplus-config`` by doing
the following:

::

 ./oglplus-config --build

