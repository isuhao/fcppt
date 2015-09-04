//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_AT_C_HPP_INCLUDED
#define FCPPT_MATH_AT_C_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Access an element using a compile-time constant

\ingroup fcpptmath
*/
template<
	fcppt::math::size_type Index,
	typename Type
>
// FIXME: This might return references to rvalues
inline
fcppt::container::to_reference_type<
	typename
	std::remove_reference<
		Type
	>::type
>
at_c(
	Type &&_value
)
{
	static_assert(
		Index
		<
		std::decay<
			Type
		>::type::static_size::value,
		"at_c: out of range"
	);

	return
		_value[
			Index
		];
}

}
}

#endif
