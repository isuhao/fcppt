//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	maybe
)
{
FCPPT_PP_POP_WARNING
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	BOOST_CHECK(
		fcppt::optional::maybe(
			optional_int(
				10
			),
			[]
			{
				return
					std::string{};
			},
			[](
				int const _val
			)
			{
				return
					std::to_string(
						_val
					);
			}
		)
		==
		"10"
	);

	BOOST_CHECK(
		fcppt::optional::maybe(
			optional_int(),
			[]
			{
				return
					std::string(
						"42"
					);
			},
			[](
				int
			)
			{
				return
					std::string{};
			}
		)
		==
		"42"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	maybe_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	int_unique_ptr const result(
		fcppt::optional::maybe(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[]{
				return
					fcppt::make_unique_ptr<
						int
					>(
						10
					);
			},
			[](
				int_unique_ptr &&_ptr
			)
			{
				return
					std::move(
						_ptr
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		*result,
		42
	);
}
