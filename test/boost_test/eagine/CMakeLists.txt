#  Copyright Matus Chochlik.
#  Distributed under the Boost Software License, Version 1.0.
#  See accompanying file LICENSE_1_0.txt or copy at
#   http://www.boost.org/LICENSE_1_0.txt
#
cmake_minimum_required(VERSION 2.8)

enable_testing()
include(../testing.cmake)

add_runtime_tests(eagine)

add_runtime_test_dependency(eagine "deferred_handler" "outcome")
add_runtime_test_dependency(eagine "mp_list" "enum_class")
add_runtime_test_dependency(eagine "enum_class" "enum_bitfield")
add_runtime_test_dependency(eagine "make_view" "buffer_size")
add_runtime_test_dependency(eagine "buffer_size" "buffer_data")
add_runtime_test_dependency(eagine "array_size" "program_args")
add_runtime_test_dependency(eagine "deep_copy_ptr" "any_iterator")

# vect
add_runtime_test_dependency(eagine "vect_data" "vect_fill")
add_runtime_test_dependency(eagine "vect_data" "vect_axis")
add_runtime_test_dependency(eagine "vect_data" "vect_from")
add_runtime_test_dependency(eagine "vect_data" "vect_shuffle")
add_runtime_test_dependency(eagine "vect_data" "vect_view")
add_runtime_test_dependency(eagine "vect_shuffle" "vect_hsum")
add_runtime_test_dependency(eagine "vect_data" "vect_abs")
add_runtime_test_dependency(eagine "vect_abs" "vect_diff")
add_runtime_test_dependency(eagine "vect_esum" "vect_diff")
add_runtime_test_dependency(eagine "vect_fill" "vect_compare")

# math
add_runtime_test_dependency(eagine "vect_fill" "math_scalar")
add_runtime_test_dependency(eagine "math_scalar" "math_vector")
add_runtime_test_dependency(eagine "vect_axis" "math_vector")
add_runtime_test_dependency(eagine "vect_cast" "math_vector")
add_runtime_test_dependency(eagine "vect_from" "math_vector")
add_runtime_test_dependency(eagine "vect_view" "math_vector")
add_runtime_test_dependency(eagine  "math_vector" "math_vector_ops")
add_runtime_test_dependency(eagine  "math_vector" "math_tvec")
add_runtime_test_dependency(eagine  "math_vector" "math_matrix_1")
add_runtime_test_dependency(eagine  "math_vector" "math_matrix_2")
add_runtime_test_dependency(eagine  "math_vector" "math_matrix_3")
add_runtime_test_dependency(eagine  "math_matrix_2" "math_matrix_ctrs")
add_runtime_test_dependency(eagine  "math_matrix_3" "math_matrix_ctrs")

# memory
add_runtime_test_dependency(eagine "memory_block" "memory_null_alloc")
add_runtime_test_dependency(eagine "memory_block" "memory_c_realloc")
add_runtime_test_dependency(eagine "memory_block" "memory_stack_alloc")
add_runtime_test_dependency(eagine "memory_block" "memory_std_alloc")
add_runtime_test_dependency(eagine "memory_c_realloc" "memory_shared_alloc")
add_runtime_test_dependency(eagine "memory_c_realloc" "memory_fallback_alloc")
add_runtime_test_dependency(eagine "memory_c_realloc" "memory_std_alloc")
add_runtime_test_dependency(eagine "memory_stack_alloc" "memory_fallback_alloc")
add_runtime_test_dependency(eagine "memory_stack_alloc" "memory_align_alloc")
add_runtime_test_dependency(eagine "memory_block" "memory_buffer")
add_runtime_test_dependency(eagine "memory_c_realloc" "memory_buffer")
