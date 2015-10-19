/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_math_matrix_ctrs
#include <boost/test/unit_test.hpp>

#include <eagine/math/matrix_identity.hpp>
#include <eagine/math/matrix_translation.hpp>
#include <eagine/math/matrix_scale.hpp>
#include <eagine/math/matrix_rotation.hpp>
#include <eagine/math/matrix_reflection.hpp>

#include <eagine/math/matrix_orbiting.hpp>
#include <eagine/math/matrix_looking_at.hpp>

#include <eagine/math/matrix_ortho.hpp>
#include <eagine/math/matrix_perspective.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(math_matrix_ctrs)

template <typename MC>
void test_math_matrix_ctr_MC(MC mc)
{
	using namespace eagine::math;

	BOOST_ASSERT(is_matrix_constructor<MC>::value);

	auto m1 = construct_matrix< true>(mc);
	auto m2 = construct_matrix<false>(mc);

	BOOST_ASSERT(rows(m1) == rows(m2));
	BOOST_ASSERT(columns(m1) == columns(m2));

	BOOST_CHECK_EQUAL(row_major(m1),!row_major(m2));
	BOOST_CHECK_EQUAL(row_major(m2),!row_major(m1));

	for(unsigned i=0; i<rows(m1); ++i)
	for(unsigned j=0; j<columns(m1); ++j)
	{
		BOOST_CHECK_EQUAL(get_rm(m1, i, j), get_cm(m2, j, i));
		BOOST_CHECK_EQUAL(get_rm(m2, i, j), get_cm(m1, j, i));
	}

	auto m3 = construct_matrix<true>(multiply(m1, m2));
	auto m4 = construct_matrix<true>(multiply(mc, mc));

	BOOST_ASSERT(rows(m3) == rows(m4));
	BOOST_ASSERT(columns(m3) == columns(m4));

	BOOST_CHECK(row_major(m3));
	BOOST_CHECK(row_major(m4));

	for(unsigned i=0; i<rows(m3); ++i)
	for(unsigned j=0; j<columns(m3); ++j)
	{
		BOOST_CHECK_CLOSE(get_rm(m3, i, j), get_cm(m4, j, i), 0.01);
		BOOST_CHECK_CLOSE(get_rm(m4, i, j), get_cm(m3, j, i), 0.01);
	}
}

template <typename T, bool RM, bool V>
void test_math_matrix_ctrs_TRMV(void)
{
	using namespace eagine::math;
	using eagine::radians;

	auto r = [](void) { return T(1+std::rand() % 10000)/3; };

	test_math_matrix_ctr_MC(identity<matrix<T,4,4,RM,V>>());
	test_math_matrix_ctr_MC(translation<matrix<T,4,4,RM,V>>(r(),r(),r()));
	test_math_matrix_ctr_MC(scale<matrix<T,4,4,RM,V>>(r(),r(),r()));
	test_math_matrix_ctr_MC(uniform_scale<matrix<T,4,4,RM,V>>(r()));
	test_math_matrix_ctr_MC(rotation_x<matrix<T,4,4,RM,V>>(radians(r())));
	test_math_matrix_ctr_MC(rotation_y<matrix<T,4,4,RM,V>>(radians(r())));
	test_math_matrix_ctr_MC(rotation_z<matrix<T,4,4,RM,V>>(radians(r())));
	test_math_matrix_ctr_MC(reflection_x<matrix<T,4,4,RM,V>>(true));
	test_math_matrix_ctr_MC(reflection_y<matrix<T,4,4,RM,V>>(true));
	test_math_matrix_ctr_MC(reflection_z<matrix<T,4,4,RM,V>>(true));

	test_math_matrix_ctr_MC(orbiting_y_up<matrix<T,4,4,RM,V>>(
		vector<T, 3, V>{{r(), r(), r()}},
		r(),
		radians(r()),
		radians(r())
	));
	test_math_matrix_ctr_MC(looking_at_y_up<matrix<T,4,4,RM,V>>(
		vector<T, 3, V>{{r(), r(), r()}},
		vector<T, 3, V>{{r(), r(), r()}}
	));

	test_math_matrix_ctr_MC(ortho<matrix<T,4,4,RM,V>>(
		-r(),+r(),-r(),+r(),1,10
	));
	test_math_matrix_ctr_MC(perspective<matrix<T,4,4,RM,V>>(
		-r(),+r(),-r(),+r(),1,10
	));
}

template <typename T>
void test_math_matrix_ctrs_T(void)
{
	test_math_matrix_ctrs_TRMV<T, true, true>();
	test_math_matrix_ctrs_TRMV<T, true,false>();
	test_math_matrix_ctrs_TRMV<T,false, true>();
	test_math_matrix_ctrs_TRMV<T,false,false>();
}

BOOST_AUTO_TEST_CASE(math_matrix_constructors)
{
	test_math_matrix_ctrs_T<float>();
	test_math_matrix_ctrs_T<double>();
}


BOOST_AUTO_TEST_SUITE_END()
