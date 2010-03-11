//[signals_combine
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/connection_manager.hpp>
#include <iostream>

namespace
{
int first_callback()
{
	return 4;
}

int second_callback()
{
	return 8;
}

int third_callback()
{
	return 15;
}

int combiner(int const a,int const b)
{
	return a * b;
}
}

int main()
{
	typedef int function();

	// This aggregates multiple connections
	fcppt::signal::connection_manager c;
	// Pass the combiner here - can also be changed later
	fcppt::signal::object<function> s(
		&combiner);

	c.connect(
		s.connect(&first_callback));
	c.connect(
		s.connect(&second_callback));
	c.connect(
		s.connect(&third_callback));

	// Outputs (4*8)*15=480
	std::cout << s() << "\n";
}
//]
