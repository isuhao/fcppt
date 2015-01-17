//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/exception.hpp>
#include <fcppt/log/make_location.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


fcppt::log::location
fcppt::log::make_location(
	fcppt::string const &_name,
	fcppt::char_type const _delim
)
{
	typedef std::vector<
		fcppt::string
	> vector_type;

	vector_type elements;

	boost::algorithm::split(
		elements,
		_name,
		boost::is_any_of(
			fcppt::string(
				1u,
				_delim
			)
		)
	);

	if(
		elements.empty()
	)
		throw fcppt::log::exception(
			FCPPT_TEXT("Invalid log location \"")
			+ _name
			+ FCPPT_TEXT("\". It has no elements after split.")
		);

	location ret(
		elements[0]
	);

	for(
		vector_type::const_iterator it(
			std::next(
				elements.begin()
			)
		);
		it != elements.end();
		++it
	)
		ret /= *it;

	return ret;
}
