//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/append.hpp>
#include <fcppt/algorithm/contains.hpp>
#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/algorithm/find_exn.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/algorithm/shortest_levenshtein.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


int main()
{
	// TODO: Split this file into tests and move doc/algorithm here
	typedef
	std::vector<
		unsigned char
	>
	vector_type;

	std::string const str("test");

	vector_type a;

	a.reserve(
		str.size()
	);

	// copy_n
	fcppt::algorithm::copy_n(
		str.data(),
		str.size(),
		std::back_inserter(
			a
		)
	);

	a.push_back(' ');

	vector_type b(a);

	// append
	fcppt::algorithm::append(
		a,
		b
	);

	// find_exn
	fcppt::algorithm::find_exn(
		str,
		't',
		[]{
			return
				std::runtime_error(
					"c not found"
				);
		}
	);

	std::cout << std::string(a.begin(), a.end()) << '\n';

	// contains
	std::cout << "Vector contains 's':" << fcppt::algorithm::contains(a.begin(),a.end(),'s') << "\n";

	typedef
	std::vector<std::string>
	string_vector;

	string_vector strings{
		"foo",
		"ba",
		"bu"
	};

	// join_strings, outputs "foo|bar|baz"
	std::cout << fcppt::algorithm::join_strings(strings,"|") << "\n";

	string_vector const more_strings{
		"test",
		"test2"
	};

	std::string const &string_cref =
		fcppt::algorithm::shortest_levenshtein(
			more_strings,
			std::string("test3"));

	std::cout << "Shortest distance to \"test\" and \"test2\" is: " << string_cref << "\n";

	std::string &nonconst_ref =
		fcppt::algorithm::shortest_levenshtein(
			strings,
			std::string("test3"));

	std::cout << "Shortest distance to \"foo\", \"ba\" and \"bu\" is: " << nonconst_ref << "\n";
}
