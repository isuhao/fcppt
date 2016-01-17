//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/optional_context_tree_ref.hpp>
#include <fcppt/log/impl/find_inner_node.hpp>
#include <fcppt/log/impl/find_location.hpp>
#include <fcppt/optional/bind.hpp>


fcppt::log::detail::optional_context_tree_ref
fcppt::log::impl::find_location(
	fcppt::log::detail::context_tree &_tree,
	fcppt::log::location const &_location
)
{
	fcppt::log::detail::optional_context_tree_ref cur(
		fcppt::make_ref(
			_tree
		)
	);

	for(
		auto const &item
		:
		_location
	)
	{
		cur =
			fcppt::optional::bind(
				cur,
				[
					&item
				](
					fcppt::reference<
						fcppt::log::detail::context_tree
					> const _next_tree
				)
				{
					return
						fcppt::log::impl::find_inner_node(
							_next_tree.get(),
							item
						);

				}
			);

		if(
			!cur.has_value()
		)
			break;
	}

	return
		cur;
}
