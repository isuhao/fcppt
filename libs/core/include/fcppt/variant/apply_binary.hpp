//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Does a binary visitation

\ingroup fcpptvariant

Visits \a _obj1 and \a _obj2 with the visitor \a _op. <code>_op.operator()(T,
U)</code> will be called where <code>T</code> is the type held by \a _obj1 and
<code>U</code> is the type held by \a _obj2.

\tparam Operation The visitor type
\tparam Variant1 The first variant
\tparam Variant2 The second variant

\param _op The visitor to execute
\param _obj1 The first variant to visit
\param _obj2 The second variant to visit

\return The result of <code>_op.operator()(T, U)</code>
*/
template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
inline
decltype(
	auto
)
apply_binary(
	Operation &&_op,
	Variant1 &&_obj1,
	Variant2 &&_obj2
)
{
	return
		fcppt::variant::apply_unary(
			[
				&_obj1,
				&_op
			](
				auto &_t2
			)
			->
			decltype(
				auto
			)
			{
				return
					fcppt::variant::apply_unary(
						[
							&_op,
							&_t2
						](
							auto &_t1
						)
						->
						decltype(
							auto
						)
						{
							return
								_op(
									_t1,
									_t2
								);
						},
						_obj1
					);
			},
			_obj2
		);
}

}
}

#endif
