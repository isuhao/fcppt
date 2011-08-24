//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assign/make_array.hpp>
#include <fcppt/container/array.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/array.hpp>
#include <algorithm>

BOOST_AUTO_TEST_CASE(
	assign_make_array
)
{
	typedef fcppt::container::array<
		int,
		3
	> int_3_array;

	int_3_array const array1(
		fcppt::assign::make_array<
			int
		>(
			0
		)
		(
			1
		)
		(
			2
		)
	);

	int_3_array const array2 =
	{{
		0,
		1,
		2
	}};

	BOOST_REQUIRE(
		array1 == array2
	);

	typedef boost::array<
		int,
		3
	> int_3_boost_array;

	int_3_boost_array const boost_array(
		fcppt::assign::make_array<
			int
		>(
			0
		)
		(
			1
		)
		(
			2
		)
	);

	BOOST_REQUIRE(
		std::equal(
			array2.begin(),
			array2.end(),
			boost_array.begin()
		)
	);
}