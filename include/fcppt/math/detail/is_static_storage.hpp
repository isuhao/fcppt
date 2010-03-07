//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/tr1/array.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <cstddef>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
struct is_static_storage
:
boost::false_type
{};

template<
	typename T,
	std::size_t N
>
struct is_static_storage<
	std::tr1::array<
		T,
		N
	>
>
:
boost::true_type
{};

}
}
}

#endif