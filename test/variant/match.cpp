//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_match
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::variant::object<
		boost::mpl::vector2<
			int,
			std::string
		>
	>
	variant;

	std::string const result(
		fcppt::variant::match(
			variant(
				42
			),
			[](
				int const _value
			)
			{
				return
					std::to_string(
						_value
					);
			},
			[](
				std::string const &_value
			)
			{
				return
					_value;
			}
		)
	);

	BOOST_CHECK_EQUAL(
		result,
		"42"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_match_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::variant::object<
		boost::mpl::vector2<
			int_unique_ptr,
			std::string
		>
	>
	variant;

	std::string const result(
		fcppt::variant::match(
			variant(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[](
				int_unique_ptr &&_value
			)
			{
				return
					std::to_string(
						*_value
					);
			},
			[](
				std::string const &_value
			)
			{
				return
					_value;
			}
		)
	);

	BOOST_CHECK_EQUAL(
		result,
		"42"
	);
}
