//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_LERP_HPP_INCLUDED
#define FCPPT_MATH_LERP_HPP_INCLUDED

#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
/// Interpolates between a and b (works only with a floating point
/// parameter)
template<typename Float,typename Value>
typename
boost::enable_if_c
<
	boost::is_floating_point<Float>::value,
	Value const
>::type
lerp(
	Float const &f,
	Value const &v1,
	Value const &v2)
{
	return f * v1 + (static_cast<Float>(1) - f) * v2;
}
}
}

#endif