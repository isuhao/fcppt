//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/remove.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>

BOOST_AUTO_TEST_CASE(algorithm_remove)
{
	typedef std::vector<
		int
	> int_vector;

	int_vector vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	BOOST_REQUIRE(
		fcppt::algorithm::remove(
			vec,
			2
		)
	);

	BOOST_REQUIRE(
		vec.size() == 2u
		&& vec[0] == 1
		&& vec[1] == 3
	);
}