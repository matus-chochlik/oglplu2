#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_package(OpenSSL)

add_library(EAGopt::OpenSSL INTERFACE IMPORTED)
if(OpenSSL_FOUND)
	if(OPENSSL_INCLUDE_DIRS)
		target_include_directories(
			EAGopt::OpenSSL INTERFACE "${OPENSSL_INCLUDE_DIRS}"
		)
	endif()

	if(OPENSSL_LIBRARY_DIRS)
		set_target_properties(
			EAGopt::OpenSSL PROPERTIES
			INTERFACE_LINK_DIRECTORIES "${OPENSSL_LIBRARY_DIRS}"
		)
	endif()

	target_compile_definitions(
		EAGopt::OpenSSL INTERFACE EAGINE_USE_OPENSSL=1
	)

	target_link_libraries(
		EAGopt::OpenSSL INTERFACE "${OPENSSL_LIBRARIES}"
	)
endif()


