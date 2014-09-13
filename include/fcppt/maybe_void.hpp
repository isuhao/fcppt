//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAYBE_VOID_HPP_INCLUDED
#define FCPPT_MAYBE_VOID_HPP_INCLUDED

#include <fcppt/maybe.hpp>
#include <fcppt/optional_fwd.hpp>


namespace fcppt
{

/**
\brief Transforms an optional value or does nothing

\ingroup fcpptoptional

If \a _optional is set to x, then <code>_transform(x)</code> is called.

\tparam Transform Must be a function of type <code>void (Type)</code>
*/
template<
	typename Type,
	typename Transform
>
inline
void
maybe_void(
	fcppt::optional<
		Type
	> const &_optional,
	Transform const _transform
)
{
	fcppt::maybe(
		_optional,
		[]{},
		_transform
	);
}

}

#endif