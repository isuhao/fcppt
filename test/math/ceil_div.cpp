//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/ceil_div.hpp>
#include <fcppt/math/ceil_div_signed.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	ceil_div
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			0u,
			1u
		),
		0u
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			1u,
			1u
		),
		1u
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			5u,
			3u
		),
		2u
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			6u,
			3u
		),
		2u
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	ceil_div_signed
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div_signed(
			-3,
			2
		),
		-1
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div_signed(
			5,
			3
		),
		2
	);
}
