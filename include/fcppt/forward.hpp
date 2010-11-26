// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_FORWARD_HPP_INCLUDED
#define FCPPT_FORWARD_HPP_INCLUDED

#include <fcppt/type_traits/is_movable.hpp>
#include <fcppt/move.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{

template<
	typename T
>
inline
typename boost::disable_if<
	fcppt::type_traits::is_movable<
		T
	>,
	T const &
>::type
forward(
	T const &t
)
{
	return t;
}

template<
	typename T
>
inline
typename boost::enable_if<
	fcppt::type_traits::is_movable<
		T
	>,
	T
>::type
forward(
	typename boost::mpl::identity<T>::type &t
)
{
	return fcppt::move(t);
}

template<
	typename T
>
inline
typename boost::enable_if<
	fcppt::type_traits::is_movable<
		T
	>,
	T
>::type
forward(
	typename boost::mpl::identity<T>::type const &t
)
{
	return fcppt::move(const_cast<T &>(t));
}

}

#endif