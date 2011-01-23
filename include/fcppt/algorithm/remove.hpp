//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_REMOVE_HPP_INCLUDED

#include <algorithm>

namespace fcppt
{
namespace algorithm
{

/// Tries to remove all elements from @a _container matching @a _element
/**
 * @return true if something has been removed, false otherwise
*/
template<
	typename Container
>
bool
remove(
	Container &_container,
	typename Container::const_reference _element
)
{
	typename Container::iterator const position(
		std::remove(
			_container.begin(),
			_container.end(),
			_element
		)
	);

	if(
		position == _container.end()
	)
		return false;
	
	_container.erase(
		position,
		_container.end()
	);

	return true;
}

}
}

#endif