//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/index_map.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_index_map
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::container::index_map<
		int
	> int_index_map;

	int_index_map map;

	map[
		2
	] = 42;

	BOOST_REQUIRE_EQUAL(
		map.impl().size(),
		3u
	);

	BOOST_CHECK_EQUAL(
		map[0],
		0
	);

	BOOST_CHECK_EQUAL(
		map[1],
		0
	);

	BOOST_CHECK_EQUAL(
		map[2],
		42
	);
}
