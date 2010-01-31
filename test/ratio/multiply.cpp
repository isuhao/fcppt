//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/ratio/ratio.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(ratio_multiply)
{
	typedef fcppt::ratio::object<
		10,
		3
	> x;

	typedef fcppt::ratio::object<
		2,
		5
	> y;

	typedef fcppt::ratio::multiply<
		x,
		y
	>::type result;

	BOOST_REQUIRE(
		result::num == 4
		&& result::den == 3
	);
}