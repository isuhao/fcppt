/**
\defgroup fcpptcontainerraw_vector fcppt::container::raw_vector
\ingroup fcpptcontainer
\brief A special vector class for POD types

Ordinary arrays in C++ are not default-initialized. The following code is undefined:

\code
int main()
{
	int numbers[1024];

	std::cout << numbers[0];
}
\endcode

This is mostly for performance reasons. The array could be huge, and
initializing it would take time. Moreover, it might be unnecessary! Consider:

\code
int main()
{
	int numbers[1024];

	for(std::size_t i = 0; i < 1024; ++i)
		numbers[i] = 1;

	std::cout << numbers[0];
}
\endcode

Default-initializing the <code>numbers</code> array to zero is pointless, since
after its construction, the array is filled with a different value anyway.

If you want an array with the ability to grow and shrink dynamically, you could
use a <code>std::%vector</code>:

\code
int main()
{
	std::vector<int> numbers(1024);

	for(std::size_t i = 0; i < 1024; ++i)
		numbers[i] = 1;

	std::cout << numbers[0];
}
\endcode

However, <code>std::%vector</code> default-initialized its values! So this code
won't exhibit maximum performance.

To get the non-initializing behavior back, you can use
fcppt::container::raw_vector. It's an almost exact copy of
<code>std::vector</code>, but doesn't initialize its values.

Here's a small example:

\snippet doc/container.cpp raw_vector
*/
