//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_int_range_count.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::container::grid::object<
	int,
	2
>
int2_grid;

struct nonpod
{
	nonpod()
	:
		member_(
			42
		)
	{
	}

	int member_;
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_init_reference
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			10u,
			20u
		),
		42
	);

	BOOST_CHECK_EQUAL(
		std::count(
			test.begin(),
			test.end(),
			42
		),
		200
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_index_2d
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			5u,
			10u
		),
		[](
			int2_grid::pos
		)
		{
			static int entry{
				0
			};

			return
				entry++;
		}
	);

	for(
		auto const y
		:
		fcppt::make_int_range_count(
			test.size().h()
		)
	)
		for(
			auto const x
			:
			fcppt::make_int_range_count(
				test.size().w()
			)
		)
		{
			BOOST_REQUIRE_EQUAL(
				test[
					int2_grid::pos(
						x,
						y
					)
				],
				fcppt::cast::size<
					int2_grid::value_type
				>(
					fcppt::cast::to_signed(
						x + y * 5
					)
				)
			);
		}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_index_3d
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		int,
		3
	>
	int3_grid;

	int3_grid const test(
		int3_grid::dim(
			5u,
			10u,
			8u
		),
		[](
			int3_grid::pos
		)
		{
			static int entry{
				0
			};

			return
				entry++;
		}
	);

	for(
		auto const z
		:
		fcppt::make_int_range_count(
			test.size().d()
		)
	)
		for(
			auto const y
			:
			fcppt::make_int_range_count(
				test.size().h()
			)
		)
			for(
				auto const x
				:
				fcppt::make_int_range_count(
					test.size().w()
				)
			)
			{
				BOOST_CHECK_EQUAL(
					test[
						int3_grid::pos(
							x,
							y,
							z
						)
					],
					fcppt::cast::size<
						int3_grid::value_type
					>(
						fcppt::cast::to_signed(
							x + y * 5 + z * 5 * 10
						)
					)
				);
			}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_const_data
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			5u,
			2u
		),
		42
	);

	BOOST_CHECK_EQUAL(
		std::count(
			test.begin(),
			test.end(),
			42
		),
		10
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_size
)
{
FCPPT_PP_POP_WARNING

	int2_grid const test(
		int2_grid::dim(
			3u,
			2u
		),
		fcppt::no_init{}
	);

	BOOST_CHECK_EQUAL(
		test.content(),
		6u
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_non_pod
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::object<
		nonpod,
		2
	>
	grid2_nonpod;

	grid2_nonpod const test(
		grid2_nonpod::dim(
			5u,
			3u
		),
		nonpod()
	);

	for(
		auto const &element
		:
		test
	)
		BOOST_CHECK_EQUAL(
			element.member_,
			42
		);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_move
)
{
FCPPT_PP_POP_WARNING

	int2_grid grid1(
		int2_grid::dim(
			2u,
			3u
		),
		fcppt::no_init{}
	);

	grid1[
		int2_grid::pos(
			0u,
			0u
		)
	] = 1;

	grid1[
		int2_grid::pos(
			1u,
			1u
		)
	] = 2;

	int2_grid grid2(
		std::move(
			grid1
		)
	);

	BOOST_CHECK(
		grid2.size()
		==
		int2_grid::dim(
			2u,
			3u
		)
	);

	BOOST_CHECK(
		grid2[
			int2_grid::pos(
				0u,
				0u
			)
		] == 1
	);

	BOOST_CHECK(
		grid2[
			int2_grid::pos(
				1u,
				1u
			)
		] == 2
	);

	BOOST_CHECK(
		grid1.begin()
		==
		grid1.end()
	);

	int2_grid grid3;

	grid3 =
		std::move(
			grid2
		);

	BOOST_CHECK(
		grid3.size()
		==
		int2_grid::dim(
			2u,
			3u
		)
	);

	BOOST_CHECK(
		grid3[
			int2_grid::pos(
				0u,
				0u
			)
		] == 1
	);

	BOOST_CHECK(
		grid3[
			int2_grid::pos(
				1u,
				1u
			)
		] == 2
	);

	BOOST_CHECK(
		grid2.begin()
		==
		grid2.end()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_init_function
)
{
FCPPT_PP_POP_WARNING
	int2_grid const grid(
		int2_grid::dim(
			2u,
			3u
		),
		[](
			int2_grid::pos const _pos
		)
		{
			return
				fcppt::cast::size<
					int
				>(
					fcppt::cast::to_signed(
						_pos.x()
						*
						_pos.y()
					)
				);
		}
	);

	typedef
	int2_grid::pos
	pos;

	BOOST_CHECK_EQUAL(
		fcppt::cast::to_signed(
			grid.content()
		),
		std::distance(
			grid.begin(),
			grid.end()
		)
	);

	BOOST_CHECK_EQUAL(
		grid[
			pos(
				0u,
				0u
			)
		],
		0
	);

	BOOST_CHECK_EQUAL(
		grid[
			pos(
				1u,
				2u
			)
		],
		2
	);
}
