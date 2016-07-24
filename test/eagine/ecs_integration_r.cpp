/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_ecs_integration
#include <boost/test/unit_test.hpp>

#include <eagine/ecs/basic_manager.hpp>
#include <eagine/ecs/storage/std_map.hpp>

struct name_surname
 : eagine::ecs::component<name_surname>
{
	std::string first_name;
	std::string family_name;
};

template <bool Const>
struct name_surname_manip
 : eagine::ecs::basic_manipulator<name_surname, Const>
{
	using eagine::ecs::basic_manipulator<name_surname, Const>::
		basic_manipulator;

	const std::string& get_first_name(void) const
	{
		return this->read().first_name;
	}

	void set_first_name(std::string s)
	{
		return this->write().first_name = std::move(s);
	}

	const std::string& get_family_name(void) const
	{
		return this->read().family_name;
	}

	void set_family_name(std::string s)
	{
		return this->write().family_name = std::move(s);
	}
};

struct measurements
 : eagine::ecs::component<measurements>
{
	float height_m;
	float weight_kg;
};

template <bool Const>
struct measurements_manip
 : eagine::ecs::basic_manipulator<measurements, Const>
{
	using eagine::ecs::basic_manipulator<measurements, Const>::
		basic_manipulator;

	float get_height_m(void) const
	{
		return this->read().height_m;
	}

	void set_height_m(float v)
	{
		assert(v > 0);
		this->write().height_m = v;
	}

	float get_weight_kg(void) const
	{
		return this->read().weight_kg;
	}

	void set_weight_kg(float v)
	{
		assert(v > 0);
		this->write().weight_kg = v;
	}
};

struct father : eagine::ecs::relation<father> { };
struct mother : eagine::ecs::relation<mother> { };

namespace eagine {
namespace ecs {

template <bool Const>
struct get_manipulator<name_surname, Const>
{
	typedef name_surname_manip<Const> type;
};

template <bool Const>
struct get_manipulator<measurements, Const>
{
	typedef measurements_manip<Const> type;
};

} // namespace ecs
} // namespace eagine

BOOST_AUTO_TEST_SUITE(ecs_tests)

BOOST_AUTO_TEST_CASE(ecs_test_component_storage_reg)
{
	using namespace eagine::ecs;
	typedef std::string entity;

	basic_manager<entity> m;

	BOOST_CHECK(!m.knows_component_type<name_surname>());
	BOOST_CHECK(!m.knows_component_type<measurements>());

	m.register_component_storage<std_map_cmp_storage, name_surname>();
	BOOST_CHECK( m.knows_component_type<name_surname>());
	BOOST_CHECK(!m.knows_component_type<measurements>());

	m.register_component_storage<std_map_cmp_storage, measurements>();
	BOOST_CHECK( m.knows_component_type<name_surname>());
	BOOST_CHECK( m.knows_component_type<measurements>());

	m.unregister_component_type<name_surname>();
	BOOST_CHECK(!m.knows_component_type<name_surname>());
	BOOST_CHECK( m.knows_component_type<measurements>());

	m.unregister_component_type<measurements>();
	BOOST_CHECK(!m.knows_component_type<name_surname>());
	BOOST_CHECK(!m.knows_component_type<measurements>());
}

BOOST_AUTO_TEST_CASE(ecs_test_relation_storage_reg)
{
	using namespace eagine::ecs;
	typedef std::string entity;

	basic_manager<entity> m;

	BOOST_CHECK(!m.knows_relation_type<father>());
	BOOST_CHECK(!m.knows_relation_type<mother>());

	m.register_relation_storage<std_map_rel_storage, father>();
	BOOST_CHECK( m.knows_relation_type<father>());
	BOOST_CHECK(!m.knows_relation_type<mother>());

	m.register_relation_storage<std_map_rel_storage, mother>();
	BOOST_CHECK( m.knows_relation_type<father>());
	BOOST_CHECK( m.knows_relation_type<mother>());

	m.unregister_relation_type<father>();
	BOOST_CHECK(!m.knows_relation_type<father>());
	BOOST_CHECK( m.knows_relation_type<mother>());

	m.unregister_relation_type<mother>();
	BOOST_CHECK(!m.knows_relation_type<father>());
	BOOST_CHECK(!m.knows_relation_type<mother>());
}

BOOST_AUTO_TEST_SUITE_END()
