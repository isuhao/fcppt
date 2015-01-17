//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <set>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	assign_make_container
)
{
FCPPT_PP_POP_WARNING

	{
	typedef
	std::vector<int>
	sequence;

	sequence c(
		fcppt::assign::make_container<sequence>
			(
				3)
			(
				4)
			(
				5));

	BOOST_REQUIRE(
		c.size() == fcppt::literal<sequence::size_type>(3) &&
		c[0] == 3 &&
		c[1] == 4 &&
		c[2] == 5);
	}

	{
	typedef
	std::set<int>
	set;

	set c(
		fcppt::assign::make_container<set>
			(
				3)
			(
				4)
			(
				5));

	BOOST_REQUIRE(
		c.size() == fcppt::literal<set::size_type>(3) &&
		c.find(3) != c.end() &&
		c.find(4) != c.end() &&
		c.find(5) != c.end());
	}

	{
	typedef
	std::map<int,int>
	map;

	map m(
		fcppt::assign::make_container<map>
			(std::make_pair(
				3,
				2))
			(std::make_pair(
				4,
				5)));

	BOOST_REQUIRE(
		m.size() == fcppt::literal<map::size_type>(2) &&
		m.find(3) != m.end() &&
		m.find(3)->second == 2 &&
		m.find(4) != m.end() &&
		m.find(4)->second == 5);
	}
}
