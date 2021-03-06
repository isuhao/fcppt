//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_MAKE_CONTAINER_HPP_INCLUDED
#define FCPPT_ASSIGN_MAKE_CONTAINER_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace assign
{

/**
\brief Creates a container from variadic arguments by moving.

\ingroup fcpptassign
*/
template<
	typename Container,
	typename... Args
>
inline
Container
make_container(
	Args &&... _args
)
{
	typedef
	fcppt::reference<
		typename
		Container::value_type
	>
	reference_type;

	return
		fcppt::algorithm::map<
			Container
		>(
			std::array<
				reference_type,
				sizeof...(
					Args
				)
			>{{
				reference_type(
					_args
				)...
			}},
			[](
				reference_type const _ref
			)
			{
				return
					std::move(
						_ref.get()
					);
			}
		);
}

}
}

#endif
