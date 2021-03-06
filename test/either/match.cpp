//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/match.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	either_match
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	auto const success_function(
		[](
			int const _value
		)
		{
			return
				std::string(
					"success: "
				)
				+
				std::to_string(
					_value
				);
		}
	);

	auto const failure_function(
		[](
			std::string const &_value
		)
		{
			return
				std::string(
					"failure: "
				)
				+
				_value;
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::match(
			either_int(
				std::string(
					"test"
				)
			),
			failure_function,
			success_function
		),
		std::string(
			"failure: test"
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::match(
			either_int(
				42
			),
			failure_function,
			success_function
		),
		std::string(
			"success: 42"
		)
	);
}
