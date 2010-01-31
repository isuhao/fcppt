//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_EQUAL_HPP_INCLUDED
#define FCPPT_RATIO_EQUAL_HPP_INCLUDED

#include <fcppt/ratio/equal_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace ratio
{

template<
	typename R1,
	typename R2
>
struct equal
:
boost::integral_constant<
	bool,
	R1::num == R2::num
	&& R1::den == R2::den
>
{};

}
}

#endif
