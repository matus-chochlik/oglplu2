#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
find_package(OpenSSL)

add_library(EAGreq::OpenSSL INTERFACE IMPORTED)
if(OpenSSL_FOUND)
	if(OPENSSL_INCLUDE_DIRS)
		set_target_properties(
			EAGreq::OpenSSL PROPERTIES
			INTERFACE_INCLUDE_DIRECTORIES "${OPENSSL_INCLUDE_DIRS}"
		)
	endif()

	if(OPENSSL_LIBRARY_DIRS)
		set_target_properties(
			EAGreq::OpenSSL PROPERTIES
			INTERFACE_LINK_DIRECTORIES "${OPENSSL_LIBRARY_DIRS}"
		)
	endif()

	set_target_properties(
		EAGreq::OpenSSL PROPERTIES
		INTERFACE_LINK_LIBRARIES "${OPENSSL_LIBRARIES}"
	)
endif()


