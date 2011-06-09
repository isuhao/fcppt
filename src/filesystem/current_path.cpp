//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/current_path.hpp>
#include <boost/filesystem/operations.hpp>

fcppt::filesystem::path const
fcppt::filesystem::current_path()
{
	return boost::filesystem::current_path();
}
