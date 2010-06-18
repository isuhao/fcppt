//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/narrow.hpp>
#include "codecvt.hpp"

std::string const
fcppt::narrow(
	std::wstring const &s,
	std::locale const &locale_
)
{
	return
		fcppt::codecvt<
			char
		>(
			s,
			locale_
		);
}
