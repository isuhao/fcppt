//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_DETAIL_LL_ADD_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LL_ADD_HPP_INCLUDED

#include <fcppt/ratio/detail/static_sign.hpp>
#include <fcppt/ratio/detail/min_c.hpp>
#include <fcppt/ratio/int_type.hpp>
#include <boost/static_assert.hpp>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	int_type X,
	int_type Y,
	int_type = static_sign<Y>::value
>
struct ll_add;

template<
	int_type X,
	int_type Y
>
struct ll_add<X, Y, 1>
{
private:
	static int_type const
		min = min_c,
		max = -min;

	BOOST_STATIC_ASSERT(
		X <= max - Y
	);
public:
	static int_type const value = X + Y;
};

template<
	int_type X,
	int_type Y
>
struct ll_add<X, Y, 0>
{
	static int_type const value = X;
};

template<
	int_type X,
	int_type Y
>
struct ll_add<X, Y, -1>
{
private:
	static int_type const
		min = min_c,
		max = -min;

	BOOST_STATIC_ASSERT(
		min - Y <= X
	);
public:
	static int_type const value = X + Y;
};

}
}
}

#endif