//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/is_power_of_2.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	is_power_of_2
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			0u
		)
	);

	BOOST_CHECK(
		fcppt::math::is_power_of_2(
			1u
		)
	);

	BOOST_CHECK(
		fcppt::math::is_power_of_2(
			2u
		)
	);

	BOOST_CHECK(
		fcppt::math::is_power_of_2(
			4u
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			3u
		)
	);

	BOOST_CHECK(
		!fcppt::math::is_power_of_2(
			5u
		)
	);
}
