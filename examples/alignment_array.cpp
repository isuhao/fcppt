//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [alignment_array]
#include <fcppt/text.hpp>
#include <fcppt/alignment/array.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <new>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{

// Declare a test class
struct mystruct
{
	int i;
	float f;

	mystruct()
	:
		i(42),
		f(3.5f)
	{}
};

}

int
main()
{
	// Create an array with proper alignment for mystruct
	typedef fcppt::alignment::array<
		unsigned char,
		sizeof(mystruct),
		std::alignment_of<
			mystruct
		>::value
	>::type raw_array;

	raw_array storage;

	// Now placement new can be used
	mystruct *ptr = new (storage.data()) mystruct();

	fcppt::io::cout()
		<< ptr->i
		<< FCPPT_TEXT('\n');

	// Don't forget to call its destructor manually
	ptr->~mystruct();
}
//! [alignment_array]
