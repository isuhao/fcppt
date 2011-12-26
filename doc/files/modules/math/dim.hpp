namespace fcppt
{
namespace math
{
/**
\brief Contains \link fcppt::math::dim::basic dim::basic \endlink and helper functions, classes and types for it
*/
namespace dim
{
}
}
}

/**
\defgroup fcpptmathdim fcppt::math::dim
\ingroup fcpptmath
\brief A class representing dynamic or static n-dimensional dimensions

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref fcpptmathdimbasic_motivation</li>
	<li>\ref fcpptmathdimbasic_converting_from_and_to_vectors</li>
	<li>\ref fcpptmathdimbasic_operators</li>
	<li>\ref fcpptmathdimbasic_headers</li>
</ol>

</td>
</tr>
</table>

\section fcpptmathdimbasic_motivation Motivation

When writing code that deals with geometry, you need a type to denote the
size (or extent) of the geometry for each dimension. You also need such a class
when writing multi-dimensional containers (like
fcppt::container::grid::object).

Conceptually, you could just use fcppt::math::vector::basic, and we (the
authors of fcppt) have thought about going that way. However, a vector just
isn't a dimension type. You have operations you can apply to a vector (like the
dot product) that make no sense in the context of a dimension. Conversely, you
have operations like "take the area of the dimension" that make no sense for
vectors. Also, the lower-dimensional getters for vector (meaning
<code>x(),y(),z(),w()</code>) are not mixed with the lower-dimensional getters
for dim (meaning <code>w(),h(),d()</code>).

So don't be confused, vector and dim are distinct types, not (strong) typedefs
of another. They have a very similar interface (and the same template
parameters), but not the same member and free functions.

\section fcpptmathdimbasic_converting_from_and_to_vectors Converting from and to vectors

To convert a dimension to a vector, use fcppt::math::dim::structure_cast:

\code
typedef
fcppt::math::dim::static_<int,3>::type
dim3;

typedef
fcppt::math::vector::static_<int,3>::type
vector3;

dim3 d(1,2,3);

vector3 v = fcppt::math::dim::structure_cast<vector3>(d);
\endcode

Conversely, use fcppt::math::vector::structure_cast to convert a vector to a dim:

\code
typedef
fcppt::math::dim::static_<int,3>::type
dim3;

typedef
fcppt::math::vector::static_<int,3>::type
vector3;

vector3 d(1,2,3);

dim3 v = fcppt::math::vector::structure_cast<dim3>(d);
\endcode

If you include the fcppt/math/vector/dim.hpp header, you get the operators
<code>+-*%/</code> which all have the signature

<pre>
vector::basic<T,N,S> operator(vector::basic<T,N,S> left,dim::basic<T,N,S>)
</pre>

This way, you can add a dimension to a vector, for example.

\section fcpptmathdimbasic_operators Operators

Including <strong><code>fcppt/math/dim/basic_decl.hpp</code></strong> you
will get the following operators (<code>S2</code> defines some other storage
type):

<ul>
	<li><code>operator+=(dim::basic<T,N,S2>)</code></li>
	<li><code>operator-=(dim::basic<T,N,S2>)</code></li>
	<li><code>operator*=(dim::basic<T,N,S2>)</code></li>
	<li><code>operator/=(dim::basic<T,N,S2>)</code></li>
	<li><code>operator%=(dim::basic<T,N,S2>)</code></li>
	<li><code>operator*=(T)</code> (multiply by a scalar)</li>
	<li><code>operator/=(T)</code> (divide by a scalar)</li>
	<li><code>operator=(dim::basic const &)</code> (regular assignment operator)</li>
	<li><code>operator=(dim::basic<T,N,S2> const &)</code></li>
	<li><code>operator[](size_type>)</code></li>
</ul>

The arithmetic operators all work component-wise.

Including <strong><code>fcppt/math/dim/comparison.hpp</code></strong> you get all the comparison operators:

<ul>
	<li><code>operator==</code></li>
	<li><code>operator!=</code></li>
	<li><code>operator<=</code></li>
	<li><code>operator<</code></li>
	<li><code>operator>=</code></li>
	<li><code>operator></code></li>
</ul>

All of these work component-wise and forward to the <code>value_type</code>'s
operators. The ordering is lexicographic. This means that you can use a dim
with associative containers like <code>std::%set,std::%map,...</code>. Keep in
mind that the equality comparison operators do <em>not</em> use an epsilon so
you <em>will</em> get exact floating point comparisons (be sure that you really
want that!).

Including <strong><code>fcppt/math/dim/arithmetic.hpp</code></strong> gives
you the following operators:

<ul>
	<li><code>operator+(dim::basic<T,N,S>,dim::basic<T,N,S>)</code></li>
	<li><code>operator-(dim::basic<T,N,S>,dim::basic<T,N,S>)</code></li>
	<li><code>operator*(dim::basic<T,N,S>,dim::basic<T,N,S>)</code></li>
	<li><code>operator/(dim::basic<T,N,S>,dim::basic<T,N,S>)</code></li>
	<li><code>operator%(dim::basic<T,N,S>,dim::basic<T,N,S>)</code></li>
	<li><code>operator*(T,dim::basic<T,N,S>)</code> (scalar multiplication)</li>
	<li><code>operator/(T,dim::basic<T,N,S>)</code> (scalar division)</li>
	<li>Unary minus for dims</li>
</ul>

The arithmetic operators all work component-wise.

Including <strong><code>fcppt/math/dim/input.hpp</code></strong> gives
you an <code>operator>></code> for reading input from standard streams.
Conversely, including
<strong><code>fcppt/math/dim/output.hpp</code></strong> gives you an inverse
<code>operator<<</code>.

\section fcpptmathdimbasic_headers Header files

fcppt::math::dim is spread out across various header files. There's one
header per free function. fcppt::math::dim::basic itself is split into
various headers, too. Here's an exhaustive list:

<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>basic_fwd.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink declaration. Include this if you pass a dim by reference, for example.</td>
</tr>
<tr>
<td><code>basic_decl.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink definition.</td>
</tr>
<tr>
<td><code>basic_impl.hpp</code></td>
<td>Contains the definition of \link fcppt::math::dim::basic basic's \endlink member functions.</td>
</tr>
<tr>
<td><code>basic.hpp</code></td>
<td>Includes <code>basic_fwd.hpp</code>, <code>basic_decl.hpp</code> and <code>basic_impl.hpp</code></td>
</tr>
<tr>
<td><code>arithmetic.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink arithmetic operators.</td>
</tr>
<tr>
<td><code>comparison.hpp</code></td>
<td>Contains \link fcppt::math::dim::basic basic's \endlink comparison operators.</td>
</tr>
<tr>
<td><code>input.hpp</code></td>
<td>Contains an <code>operator>></code> for the standard input streams (wide and narrow) which expects dims to be input in the format: <code>(v1,v2,v3,...)</code></td>
</tr>
<tr>
<td><code>output.hpp</code></td>
<td>Contains an <code>operator<<</code> for the standard input streams (wide and narrow) which outputs dims in the format: <code>(v1,v2,v3,...)</code></td>
</tr>
</table>
*/