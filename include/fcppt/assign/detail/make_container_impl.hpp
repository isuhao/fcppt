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


#ifndef FCPPT_ASSIGN_DETAIL_MAKE_CONTAINER_IMPL_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_MAKE_CONTAINER_IMPL_HPP_INCLUDED

#include <fcppt/assign/detail/insert.hpp>

template<
	typename Container
>
fcppt::assign::make_container<Container>::make_container(
	typename container_type::const_reference r)
{
	(*this)(r);
}

template<
	typename Container
>
fcppt::assign::make_container<Container> &
fcppt::assign::make_container<Container>::operator()(
	typename container_type::const_reference r
)
{
	detail::insert(
		c_,
		r
	);

	return *this;
}

template<
	typename Container
>
fcppt::assign::make_container<Container>::operator Container() const
{
	return c_;
}

#endif
