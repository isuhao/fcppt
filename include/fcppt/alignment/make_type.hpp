//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALIGNMENT_MAKE_TYPE_HPP_INCLUDED
#define FCPPT_ALIGNMENT_MAKE_TYPE_HPP_INCLUDED

#include <fcppt/alignment/detail/make_type.hpp>
#include <fcppt/alignment/size_type.hpp>

namespace fcppt
{
namespace alignment
{

template<
	typename T,
	size_type Alignment
>
struct make_type
:
fcppt::alignment::detail::make_type<
    T,
    Alignment
>
{};

}
}

#endif
