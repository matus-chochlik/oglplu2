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

#include <set>

struct name_surname
 : eagine::ecs::component<name_surname>
{
	std::string first_name;
	std::string family_name;

	name_surname(std::string fn, std::string sn)
	 : first_name(std::move(fn))
	 , family_name(std::move(sn))
	{ }
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
		this->write().first_name = std::move(s);
	}

	const std::string& get_family_name(void) const
	{
		return this->read().family_name;
	}

	void set_family_name(std::string s)
	{
		this->write().family_name = std::move(s);
	}
};

struct measurements
 : eagine::ecs::component<measurements>
{
	float height_m;
	float weight_kg;

	measurements(float h, float w)
	 : height_m(h)
	 , weight_kg(w)
	{ }
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

template <>
struct entity_traits<std::string>
{
	typedef const std::string& parameter_type;

	static inline std::string minimum(void)
	noexcept
	{
		return {};
	}
};

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

BOOST_AUTO_TEST_CASE(ecs_test_component_manip_1)
{
	using namespace eagine::ecs;
	typedef std::string entity;

	basic_manager<entity> mgr;

	mgr.register_component_storage<std_map_cmp_storage, name_surname>();
	mgr.register_component_storage<std_map_cmp_storage, measurements>();
	BOOST_ASSERT(mgr.knows_component_type<name_surname>());
	BOOST_ASSERT(mgr.knows_component_type<measurements>());

	mgr.add("johnny", name_surname("Johnny", "Goode"));
	mgr.add("marty", name_surname("Marty", "McFly"));
	mgr.add("marty", measurements(1.6f, 70.f));
	mgr.add("doc", name_surname("Emmett", "Brown"));
	mgr.add("buford", measurements(2.0f, 110.f));
	mgr.add("biff", name_surname("Biff", "Tannen"), measurements(1.9f,100.f));
	mgr.add("griff", name_surname("Griff", "Tannen"));

	std::set<std::string> names;

	mgr.for_each_with<const name_surname>(
		[&names]
		(const std::string&, manipulator<const name_surname>& ns)
		{
			names.insert(ns.get_first_name());
		}
	);

	BOOST_CHECK_EQUAL(names.size(), 5);
	BOOST_CHECK(names.find("Johnny") != names.end());
	BOOST_CHECK(names.find("Marty") != names.end());
	BOOST_CHECK(names.find("Biff") != names.end());
	BOOST_CHECK(names.find("Griff") != names.end());
	BOOST_CHECK(names.find("Emmett") != names.end());

	mgr.for_each_with<const name_surname, measurements>(
		[](
			const std::string&,
			manipulator<const name_surname>& ns,
			manipulator<measurements>& m
		)
		{
			if(ns.get_family_name() == "Tannen")
			{
				m.set_height_m(2.0f);
				m.set_weight_kg(105.f);
			}
		}
	);


	float min_h = 3.0f;
	float max_h = 1.9f;
	float max_w = 0.0f;

	mgr.for_each_with<const measurements>(
		[&min_h,&max_h,&max_w]
		(const std::string&, manipulator<const measurements>& m)
		{
			if(min_h > m.get_height_m())
			{
				min_h = m.get_height_m();
			}
			if(max_h < m.get_height_m())
			{
				max_h = m.get_height_m();
			}
			if(max_w < m.get_weight_kg())
			{
				max_w = m.get_weight_kg();
			}
		}
	);

	BOOST_CHECK_EQUAL(min_h, 1.6f);
	BOOST_CHECK_EQUAL(max_h, 2.0f);
	BOOST_CHECK_EQUAL(max_w, 110.f);

	mgr.add("buford", name_surname("Buford", "Tannen"));

	mgr.for_each_with<name_surname>(
		[](const std::string&, manipulator<name_surname>& ns)
		{
			if(ns.get_first_name() == "Buford")
			{
				ns.set_first_name("Mad-dog");
			}
		}
	);

	BOOST_CHECK_EQUAL(
		mgr.get(&name_surname::first_name, "buford"),
		"Mad-dog"
	);

	BOOST_CHECK(mgr.has<measurements>("buford"));
	BOOST_CHECK(mgr.has<measurements>("biff"));

	mgr.for_each_with<const name_surname, measurements>(
		[](
			const std::string&,
			manipulator<const name_surname>& ns,
			manipulator<measurements>& m
		)
		{
			if(ns.get_family_name() == "Tannen")
			{
				BOOST_ASSERT(m.can_remove());
				m.remove();
			}
		}
	);

	BOOST_CHECK(!mgr.has<measurements>("buford"));
	BOOST_CHECK(!mgr.has<measurements>("biff"));

	BOOST_CHECK(mgr.has<name_surname>("buford"));
	BOOST_CHECK(mgr.has<name_surname>("biff"));
	BOOST_CHECK(mgr.has<name_surname>("griff"));

	mgr.for_each_with<name_surname>(
		[](const std::string&, manipulator<name_surname>& ns)
		{
			if(ns.get_family_name() == "Tannen")
			{
				BOOST_ASSERT(ns.can_remove());
				ns.remove();
			}
		}
	);

	BOOST_CHECK(!mgr.has<name_surname>("buford"));
	BOOST_CHECK(!mgr.has<name_surname>("biff"));
	BOOST_CHECK(!mgr.has<name_surname>("griff"));
}

BOOST_AUTO_TEST_CASE(ecs_test_relation_manip_1)
{
	using namespace eagine::ecs;
	typedef std::string entity;

	basic_manager<entity> sso; // space soap opera

	sso.register_component_storage<std_map_cmp_storage, name_surname>();
	sso.register_relation_storage<std_map_rel_storage, father>();
	sso.register_relation_storage<std_map_rel_storage, mother>();

	sso.add("luke", name_surname("Luke", "Skywalker"));
	sso.add("leia", name_surname("Leia", "Organa"));
	sso.add("hans", name_surname("Hans", "Olo"));
	sso.add("chewie", name_surname("", "Chewbacca"));
	sso.add("vader", name_surname("Anakin", "Skywalker"));
	sso.add("padme", name_surname("Padme", "Amidala"));
	sso.add("shmi", name_surname("Shmi", "Skywalker"));
	sso.add("force", name_surname("Teh", "Force"));
	sso.add("yoda", name_surname("Yoda", ""));
	sso.add("jarjar", name_surname("Jar-Jar", "Binks"));
	sso.add("vader2", name_surname("Idontknow", "Whatshisface"));

	sso.add_relation<father>("luke", "vader");
	sso.add_relation<father>("leia", "vader");
	sso.add_relation<mother>("luke", "padme");
	sso.add_relation<mother>("leia", "padme");
	sso.add_relation<mother>("vader", "shmi");
	sso.add_relation<father>("vader", "force");
	sso.add_relation<mother>("vader2", "leia");
	sso.add_relation<father>("vader2", "hans");

	BOOST_CHECK( sso.has<father>("luke", "vader"));
	BOOST_CHECK( sso.has<mother>("vader", "shmi"));
	BOOST_CHECK(!sso.has<father>("yoda", "jarjar"));
	BOOST_CHECK(!sso.has<mother>("vader", "chewie"));

}

BOOST_AUTO_TEST_SUITE_END()
