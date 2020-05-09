# Copyright Matus Chochlik.
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt
#

configure_file(example-ca.crt example-ca.crt)
configure_file(example.crt example.crt)

eagine_example_common(001_list_engines)
eagine_example_common(002_hash_self)
eagine_example_common(003_verify_cert)
eagine_example_common(004_verify_cert)
eagine_example_common(005_random_engine)
#
eagine_embed_target_resources(eagine-004_verify_cert)

