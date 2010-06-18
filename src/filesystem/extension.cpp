//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/extension.hpp>

fcppt::string const
fcppt::filesystem::extension(
	path const &p
)
{
	return p.extension();
}
