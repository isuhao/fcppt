//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/safe_bool.hpp>
#include <ostream>
#include <iostream>

namespace
{

//[safebool_example
class my_class
{
	FCPPT_SAFE_BOOL(my_class)
private:
	bool
	boolean_test() const
	{
		return isset;
	}
public:
	explicit my_class(
		bool const isset
	)
	:
		isset(isset)
	{}
private:
	bool isset;
};
//]

}

int main()
{
//[safebool_usage
	my_class test(true);

	if(test)
		std::cout << "test is set\n";
//]
}