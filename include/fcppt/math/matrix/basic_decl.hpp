/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_MATH_MATRIX_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/matrix/basic_fwd.hpp>
#include <fcppt/math/matrix/detail/dim_storage.hpp>
#include <fcppt/math/detail/view_storage.hpp>
#include <fcppt/math/detail/make_op_decl.hpp>
#include <fcppt/math/detail/make_variadic_constructor_decl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <boost/mpl/times.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <iterator>

#ifndef FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS
#define FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS 16
#endif

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M,
	typename S
>
class basic
:
public
	detail::dim_storage<N, M>
{
	typedef detail::dim_storage<N, M> dim_base;
public:
	BOOST_STATIC_ASSERT((
		boost::is_same<
			typename N::value_type,
			typename M::value_type
		>::value
	));

	typedef typename boost::mpl::times<
		N,
		M
	>::type dim_wrapper;

	typedef S storage_type;

	typedef typename N::value_type size_type;

	typedef T value_type;

	typedef vector::basic<
		T,
		N,
		math::detail::view_storage<
			T,
			N
		>
	> reference;

	typedef vector::basic<
		T,
		N,
		math::detail::view_storage<
			T const,
			N
		>
	> const_reference;

	typedef T *pointer;

	typedef T const *const_pointer;

	typedef pointer iterator;

	typedef const_pointer const_iterator;

	typedef std::reverse_iterator<iterator> reverse_iterator;

	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef typename math::dim::static_<size_type, 2>::type dim;

	basic();

	explicit basic(
		dim const &
	);

	template<
		typename In
	>
	basic(
		In beg,
		In end
	);

	template<
		typename Container
	>
	basic(
		dim const &,
		Container const &
	);

	FCPPT_MATH_DETAIL_ARRAY_ADAPTER(basic)

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE FCPPT_MATH_MATRIX_MAX_CTOR_PARAMS
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(basic)
#undef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE

#define FCPPT_MATH_MATRIX_BASIC_DECLARE_OPERATOR(op)\
FCPPT_MATH_DETAIL_MAKE_OP_DECL(basic, op)
	FCPPT_MATH_MATRIX_BASIC_DECLARE_OPERATOR(+=)
	FCPPT_MATH_MATRIX_BASIC_DECLARE_OPERATOR(-=)
#undef FCPPT_MAT_MATRIX_BASIC_DECLARE_OPERATOR
public:
	reference
	operator[](
		size_type
	);

	const_reference const
	operator[](
		size_type
	) const;

	pointer
	data();

	const_pointer
	data() const;

	size_type
	size() const;

	size_type
	rows() const;

	size_type
	columns() const;

	dim const
	dimension() const;

	static basic const
	identity();

	void
	resize(
		dim const &
	);
private:
	S storage;
};

}
}
}

#endif
