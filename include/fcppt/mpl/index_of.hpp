//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INDEX_OF_HPP_INCLUDED
#define FCPPT_MPL_INDEX_OF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/find.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Calculates the index of an element in a sequence

\ingroup fcpptmpl

Calculates the index of \a Element in \a Sequence.

\snippet mpl/various.cpp mpl_index_of

\tparam Sequence The MPL sequence

\tparam Element The element to calculate the index of

\return The index of the element or an error if the element was not found
*/
template<
	typename Sequence,
	typename Element
>
struct index_of
:
boost::mpl::distance<
	typename boost::mpl::begin<
		Sequence
	>::type,
	typename boost::mpl::find<
		Sequence,
		Element
	>::type
>
{
	BOOST_STATIC_ASSERT((
		boost::mpl::contains<
			Sequence,
			Element
		>::value
	));
};

}
}

#endif
