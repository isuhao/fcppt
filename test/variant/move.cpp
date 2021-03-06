//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/get_exn.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_move
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

	variant test(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		*fcppt::variant::get_exn<
			int_unique_ptr
		>(
			test
		),
		42
	);

	variant test2(
		std::move(
			test
		)
	);

	BOOST_CHECK_EQUAL(
		*fcppt::variant::get_exn<
			int_unique_ptr
		>(
			test2
		),
		42
	);

	variant test3(
		std::string(
			"test"
		)
	);

	variant test4(
		std::string(
			"test2"
		)
	);

	test4 =
		std::move(
			test3
		);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			std::string
		>(
			test4
		),
		std::string(
			"test"
		)
	);

	test4 =
		std::move(
			test2
		);

	BOOST_CHECK_EQUAL(
		*fcppt::variant::get_exn<
			int_unique_ptr
		>(
			test4
		),
		42
	);
}
