//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_TERNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_TERNARY_HPP_INCLUDED

#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/detail/ternary_unwrap.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Does a ternary visitation

Visits \a _obj1, \a _obj2 and \a _obj3 with the visitor \a _op.
<code>_op.operator()(T, U, W)</code> will be called where <code>T</code> is the
type held by \a _obj1, <code>U</code> is the type held by \a _obj2 and
<code>V</code> is the type held by \a _obj3.

\tparam Operation The visitor type
\tparam Types1 The types of the first variant
\tparam Types2 The types of the second variant
\tparam Types3 The types of the third variant

\param _op The visitor to execute
\param _obj1 The first variant to visit
\param _obj2 The second variant to visit
\param _obj3 The third variant to visit

\return The result of <code>_op.operator()(T, U, V)</code>
*/
template<
	typename Operation,
	typename Types1,
	typename Types2,
	typename Types3
>
typename Operation::result_type
apply_ternary(
	Operation const &_op,
	fcppt::variant::object<
		Types1
	> const &_obj1,
	fcppt::variant::object<
		Types2
	> const &_obj2,
	fcppt::variant::object<
		Types3
	> const &_obj3
)
{
	return
		variant::apply_binary(
			detail::ternary_unwrap<
				Operation,
				fcppt::variant::object<
					Types1
				>
			>(
				_op,
				_obj1
			),
			_obj2,
			_obj3
		);
}

}
}

#endif
