//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/maybe_multi.hpp>
#include <fcppt/optional/object_impl.hpp>
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
	maybe_multi
)
{
FCPPT_PP_POP_WARNING
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	fcppt::optional::object<
		unsigned
	>
	optional_unsigned;

	BOOST_CHECK(
		fcppt::optional::maybe_multi(
			[]
			{
				return
					std::string{};
			},
			[](
				int const _val1,
				unsigned const _val2
			)
			{
				return
					std::to_string(
						_val1
					)
					+
					std::to_string(
						_val2
					);
			},
			optional_int(
				10
			),
			optional_unsigned(
				20u
			)
		)
		==
		"1020"
	);

	BOOST_CHECK(
		fcppt::optional::maybe_multi(
			[]
			{
				return
					std::string(
						"42"
					);
			},
			[](
				int,
				unsigned
			)
			{
				return
					std::string{};
			},
			optional_int(),
			optional_unsigned(
				20
			)
		)
		==
		"42"
	);
}
