//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SPHERE_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/math/sphere/basic_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::sphere::basic<T, N>::basic(
	point_type const &origin_,
	const_reference radius_
)
:
	origin_(origin_),
	radius_(radius_)
{}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::point_type &
fcppt::math::sphere::basic<T, N>::origin()
{
	return origin_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::point_type const &
fcppt::math::sphere::basic<T, N>::origin() const
{
	return origin_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::reference
fcppt::math::sphere::basic<T, N>::radius()
{
	return radius_;
}

template<
	typename T,
	fcppt::math::size_type N
>
typename fcppt::math::sphere::basic<T, N>::const_reference
fcppt::math::sphere::basic<T, N>::radius() const
{
	return radius_;
}

#endif
