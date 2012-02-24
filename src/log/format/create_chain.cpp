//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/pre.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/tr1/functional.hpp>


fcppt::log::format::function const
fcppt::log::format::create_chain(
	fcppt::log::format::function const &_parent,
	fcppt::log::format::function const &_child
)
{
	FCPPT_ASSERT_PRE(
		_parent
		||
		_child
	);

	if(
		!_parent
	)
		return _child;

	if(
		!_child
	)
		return _parent;

	return
		fcppt::log::format::function(
			std::tr1::bind(
				fcppt::log::format::chain,
				_parent,
				_child,
				std::tr1::placeholders::_1
			)
		);
}
