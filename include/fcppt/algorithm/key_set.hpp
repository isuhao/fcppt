//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_KEY_SET_HPP_INCLUDED
#define FCPPT_ALGORITHM_KEY_SET_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

/// Creates a set of keys from a map
/**
 * Inserts every key from \a map into the resulting set.
*/
template<
	typename Set,
	typename Map
>
Set const
key_set(
	Map const &map
)
{
	Set ret;

	for(
		typename Map::const_iterator it(
			map.begin()
		);
		it != map.end();
		++it
	)
		ret.insert(
			it->first
		);

	return ret;
}

}
}

#endif