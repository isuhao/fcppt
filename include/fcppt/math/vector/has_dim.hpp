//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/vector/basic_fwd.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/size_type.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename Vector,
	size_type Dim
>
struct has_dim
:
boost::false_type
{};

template<
	typename T,
	typename N,
	typename S,
	size_type Dim
>
struct has_dim<
	basic<
		T,
		N,
		S
	>,
	Dim
>
:
detail::dim_matches<
	Dim,
	N::value
>
{};

}
}
}

#endif