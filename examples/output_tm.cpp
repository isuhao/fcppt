//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[output_tm
#include <fcppt/time/gmtime.hpp>
#include <fcppt/time/output_tm.hpp>
#include <fcppt/time/std_time.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/default_locale.hpp>
#include <fcppt/text.hpp>

int
main()
{
	fcppt::io::cout.imbue(
		fcppt::default_locale()
	);

	fcppt::time::output_tm(
		fcppt::io::cout,
		fcppt::time::gmtime(
			fcppt::time::std_time()
		)
	)
	<< FCPPT_TEXT('\n');
}
//]