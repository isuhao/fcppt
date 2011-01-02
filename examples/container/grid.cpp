//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[grid_simple

#include <fcppt/container/grid/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

//<-
namespace
{
//->
// typedef a three dimensional grid of ints
typedef fcppt::container::grid::object<
	int,
	3
> int3d_grid;

void
use_grid()
{
	// Create a 5 by 10 by 20 grid.
	// The initial values will be unspecified.
	int3d_grid grid(
		int3d_grid::dim(
			5u,
			10u,
			20u
		)
	);

	// Set the value on position (1,2,3) to 42
	grid[
		int3d_grid::dim(
			1u,
			2u,
			3u
		)
	] = 42;

	fcppt::io::cout
		<< grid[
			int3d_grid::dim(
				1u,
				2u,
				3u
			)
		]
		<< FCPPT_TEXT('\n');
}
//]

}

//[grid_resize
#include <fcppt/container/grid/output.hpp>
#include <fcppt/container/grid/resize_preserve_init.hpp>
#include <boost/spirit/home/phoenix/core/reference.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <algorithm>

//<-
namespace
{
//->

typedef fcppt::container::grid::object<
	int,
	2
> int2d_grid;

void
resize_grid()
{
	int2d_grid grid(
		int2d_grid::dim(
			2u,
			3u
		)
	);

	{
		int count = 0;

		// Initialize the grid with numbers from 0 to 5.
		// Note, that a grid will always be laid out in memory such that
		// the lower dimensions are closer together.
		std::generate(
			grid.begin(),
			grid.end(),
			boost::phoenix::ref(
				count
			)++
		);
	}

	fcppt::io::cout
		<< grid
		<< FCPPT_TEXT('\n');

	// Give the grid one more row and column and initialize those with 42.
	fcppt::container::grid::resize_preserve_init(
		grid,
		int2d_grid::dim(
			3u,
			4u
		),
		42
	);

	fcppt::io::cout
		<< grid
		<< FCPPT_TEXT('\n');
}
//]

}

int main()
{
	use_grid();

	resize_grid();
}