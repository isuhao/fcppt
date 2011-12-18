/**
\defgroup fcpptcontainerarray fcppt::container::array
\ingroup fcpptcontainer
\brief An implementation of <code>std::array</code> (see <a href="http://en.wikipedia.org/wiki/Array_(C%2B%2B)">here</a> for a reference)

\section Motivation

If you want to create an array whose size is fixed at compile-time, you have a
range of options. Each option, however, has drawbacks. Here's a non-exhaustive
list of options:

<table>
<tr>
<th>Option</th>
<th>Description</th>
</tr>
<tr>
<td><code>std::array</code></td>
<td>
<ul>
	<li>Future-proof, since it's in the next C++ standard (C++11)</li>
	<li>Supported by all major compilers</li>
	<li>Clean interface</li>
	<li>Needs C++11 support enabled for your project</li>
</ul>
</td>
</tr>
<tr>
<td><code>std::tr1::array</code></td>
<td>
<ul>
	<li>Clean interface</li>
	<li>Needs tr1-compatibility</li>
	<li>Isn't well supported (gcc's tr1 implementation is frozen)</li>
</ul>
</td>
</tr>
<tr>
<td><code>boost::array</code></td>
<td>
<ul>
	<li>Needs boost</li>
	<li>Old code (support for older compilers, meaning lots of ugly macros in the code)</li>
	<li>Does out-of-bounds checks even with <code>operator[]</code> (inside a <code>BOOST_ASSERT</code>, but still unnecessary)</li>
</ul>
</td>
</tr>
</table>

fcppt::container::array is a clean (macro-free) implementation of
<code>std::%array</code> without out-of-bounds checks in
<code>operator[]</code>.
*/
