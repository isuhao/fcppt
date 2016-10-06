//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit.hpp>


int
main()
{
	static_assert(
		sizeof(
			fcppt::unit
		)
		==
		1u,
		""
	);
}
