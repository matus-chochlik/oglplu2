/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/outcome.hpp>
#define BOOST_TEST_MODULE EAGINE_outcome
#include "../unit_test.inl"

#include <string>

namespace eagine {

struct mock_error_data
{
	const char* src_file;
	unsigned src_line;
	int tag;
};

template <typename T>
using test_outcome = basic_outcome<T, mock_error_data>;

void handle_error(mock_error_data& data)
{
	if(!std::uncaught_exception()) {
		throw data;
	}
}

test_outcome<void> ok_void(void)
{
	return {};
}

test_outcome<void> fail_void(int tag)
{
	return make_deferred_handler(
		&handle_error,
		mock_error_data{__FILE__, __LINE__,tag}
	);
}

test_outcome<void> foo_void(int tag)
{
	if(tag == 0) return ok_void();
	else return fail_void(tag);
}

test_outcome<std::string> ok_string(void)
{
	return {"ok"};
}

test_outcome<std::string> fail_string(int tag)
{
	return make_deferred_handler(
		&handle_error,
		mock_error_data{__FILE__, __LINE__,tag}
	);
}

test_outcome<std::string> foo_string(int tag)
{
	if(tag == 0) return ok_string();
	else return fail_string(tag);
}

test_outcome<int&> ok_ref(int& ref)
{
	return {++ref};
}

test_outcome<int&> fail_ref(int&, int tag)
{
	return make_deferred_handler(
		&handle_error,
		mock_error_data{__FILE__, __LINE__,tag}
	);
}

test_outcome<int&> foo_ref(int& ref, int tag)
{
	if(tag == 0) return ok_ref(ref);
	else return fail_ref(ref, tag);
}

} // namespace eagine

BOOST_AUTO_TEST_SUITE(outcome_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(outcome_ok_void)
{
	using namespace eagine;

	bool passed = false;

	try
	{
		ok_void();
		BOOST_CHECK(ok_void().succeeded());
		BOOST_CHECK(ok_void().done_without_error());
		passed = true;
	}
	catch(...)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw");
	}
	BOOST_CHECK(passed);
}

BOOST_AUTO_TEST_CASE(outcome_fail_void)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_void(tag).done_without_error());
		++passed;

		fail_void(tag);
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_void_2)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_void(tag).done_without_error());
		++passed;

		test_outcome<void> o = fail_void(tag);
		++passed;
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,3);
}

BOOST_AUTO_TEST_CASE(outcome_fail_void_trigger)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_void(tag).done_without_error());
		++passed;

		test_outcome<void> o = fail_void(tag);
		++passed;

		o.trigger_error();
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,3);
}

BOOST_AUTO_TEST_CASE(outcome_fail_void_ignore)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		fail_void(tag).ignore_error();
		++passed;
		BOOST_CHECK_EQUAL(
			fail_void(tag).ignore_error().handler_data().tag,
			tag
		);
		++passed;
	}
	catch(mock_error_data&)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw");
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_void_handle)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		fail_void(tag).handle_error(
			[&passed](const mock_error_data& ed)
			{
				++passed;
				throw ed.tag;
			}
		);
	}
	catch(mock_error_data&)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw mock_error_data");
	}
	catch(int err_tag)
	{
		BOOST_CHECK_EQUAL(err_tag, tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_foo_void)
{
	using namespace eagine;

	int passed = 0;

	int tag;
	do { tag = rg.get_any<int>(); }
	while(tag == 0);

	try
	{
		foo_void(0);
		++passed;

		BOOST_CHECK(foo_void(0).done_without_error());
		++passed;

		BOOST_CHECK(!foo_void(tag).done_without_error());
		++passed;

		foo_void(tag).ignore_error();
		++passed;

		foo_void(tag);
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,5);
}

BOOST_AUTO_TEST_CASE(outcome_ok_string)
{
	using namespace eagine;

	bool passed = false;

	try
	{
		BOOST_CHECK_EQUAL(ok_string().value(), "ok");
		BOOST_CHECK(ok_string().succeeded());
		BOOST_CHECK(ok_string().done_without_error());
		passed = true;
	}
	catch(...)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw");
	}
	BOOST_CHECK(passed);
}

BOOST_AUTO_TEST_CASE(outcome_fail_string)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_string(tag).done_without_error());
		++passed;

		fail_string(tag);
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_string_2)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_string(tag).done_without_error());
		++passed;

		test_outcome<std::string> o = fail_string(tag);
		++passed;
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,3);
}

BOOST_AUTO_TEST_CASE(outcome_fail_string_trigger)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_string(tag).done_without_error());
		++passed;

		fail_string(tag).trigger_error();
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_string_ignore)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		fail_string(tag).ignore_error();
		++passed;
		BOOST_CHECK_EQUAL(
			fail_string(tag).ignore_error().handler_data().tag,
			tag
		);
		++passed;
	}
	catch(mock_error_data&)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw");
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_string_handle)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		fail_string(tag).handle_error(
			[&passed](const mock_error_data& ed)
			{
				++passed;
				throw ed.tag;
			}
		);
	}
	catch(mock_error_data&)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw mock_error_data");
	}
	catch(int err_tag)
	{
		BOOST_CHECK_EQUAL(err_tag, tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_foo_string)
{
	using namespace eagine;

	int passed = 0;

	int tag;
	do { tag = rg.get_any<int>(); }
	while(tag == 0);

	try
	{
		BOOST_CHECK_EQUAL(foo_string(0).value(), "ok");
		++passed;

		BOOST_CHECK(foo_string(0).done_without_error());
		++passed;

		BOOST_CHECK(!foo_string(tag).done_without_error());
		++passed;

		foo_string(tag).ignore_error();
		++passed;

		foo_string(tag);
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,5);
}

BOOST_AUTO_TEST_CASE(outcome_ok_ref)
{
	using namespace eagine;

	int i = 0;

	bool passed = false;

	try
	{
		BOOST_CHECK_EQUAL(ok_ref(i).value(), i);
		BOOST_CHECK_EQUAL(&ok_ref(i).value(), &i);

		BOOST_CHECK(ok_ref(i).succeeded());
		BOOST_CHECK(ok_ref(i).done_without_error());
		passed = true;
	}
	catch(...)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw");
	}
	BOOST_CHECK(passed);
}

BOOST_AUTO_TEST_CASE(outcome_fail_ref)
{
	using namespace eagine;

	int passed = 0;

	int i = 0, tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_ref(i, tag).done_without_error());
		++passed;

		fail_ref(i, tag);
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_ref_2)
{
	using namespace eagine;

	int passed = 0;

	int i = 0, tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_ref(i, tag).done_without_error());
		++passed;

		test_outcome<int&> o = fail_ref(i, tag);
		++passed;
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,3);
}

BOOST_AUTO_TEST_CASE(outcome_fail_ref_trigger)
{
	using namespace eagine;

	int passed = 0;

	int i = 0, tag = rg.get_any<int>();

	try
	{
		BOOST_CHECK(!fail_ref(i, tag).done_without_error());
		++passed;

		fail_ref(i, tag).trigger_error();
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_ref_ignore)
{
	using namespace eagine;

	int passed = 0;

	int i = 0, tag = rg.get_any<int>();

	try
	{
		fail_ref(i, tag).ignore_error();
		++passed;
		BOOST_CHECK_EQUAL(
			fail_string(tag).ignore_error().handler_data().tag,
			tag
		);
		++passed;
	}
	catch(mock_error_data&)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw");
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_fail_ref_handle)
{
	using namespace eagine;

	int passed = 0;

	int i = 0, tag = rg.get_any<int>();

	try
	{
		fail_ref(i, tag).handle_error(
			[&passed](const mock_error_data& ed)
			{
				++passed;
				throw ed.tag;
			}
		);
	}
	catch(mock_error_data&)
	{
		BOOST_CHECK_MESSAGE(false, "Should not throw mock_error_data");
	}
	catch(int err_tag)
	{
		BOOST_CHECK_EQUAL(err_tag, tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_CASE(outcome_foo_ref)
{
	using namespace eagine;

	int passed = 0;

	int i = 0, tag;
	do { tag = rg.get_any<int>(); }
	while(tag == 0);

	try
	{
		BOOST_CHECK_EQUAL(foo_ref(i, 0).value(), i);
		BOOST_CHECK_EQUAL(&foo_ref(i, 0).value(), &i);
		++passed;

		BOOST_CHECK(foo_ref(i,0).done_without_error());
		++passed;

		BOOST_CHECK(!foo_ref(i,tag).done_without_error());
		++passed;

		foo_ref(i,tag).ignore_error();
		++passed;

		foo_ref(i,tag);
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(mock_error_data& med)
	{
		BOOST_CHECK_EQUAL(tag, med.tag);
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,5);
}

BOOST_AUTO_TEST_CASE(outcome_foo_void_no_abort)
{
	using namespace eagine;

	int passed = 0;

	int tag = rg.get_any<int>();

	try
	{
		test_outcome<void> o = fail_void(tag);
		++passed;
		throw std::runtime_error("EAGine Test Error");
	}
	catch(mock_error_data&)
	{
		BOOST_CHECK_MESSAGE(false, "Should not get here");
	}
	catch(std::exception& se)
	{
		BOOST_CHECK_EQUAL(se.what(), "EAGine Test Error");
		++passed;
	}
	BOOST_CHECK_EQUAL(passed,2);
}

BOOST_AUTO_TEST_SUITE_END()
