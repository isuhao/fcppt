//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/// Creates the default formatter for the given log level
FCPPT_SYMBOL
fcppt::log::format::function const
default_level(
	fcppt::log::level::type
);

}
}
}

#endif
