//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_TIME_GET_HPP_INCLUDED
#define FCPPT_TIME_TIME_GET_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <locale>

namespace fcppt
{
namespace time
{

typedef std::time_get<
	fcppt::char_type
> time_get;

}
}

#endif