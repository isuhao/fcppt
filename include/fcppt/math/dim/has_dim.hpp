//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_HAS_DIM_HPP_INCLUDED
#define FCPPT_MATH_DIM_HAS_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/dim/object_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Metafunction to check the dimension of a static dim
*/
template<
	typename Dim,
	size_type Size
>
struct has_dim
:
boost::false_type
{};

/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	typename N,
	typename S,
	size_type Size
>
struct has_dim<
	object<
		T,
		N,
		S
	>,
	Size
>
:
detail::dim_matches<
	Size,
	N::value
>
{};
/// \endcond

FCPPT_PP_POP_WARNING

}
}
}

#endif
