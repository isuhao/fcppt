namespace fcppt
{
namespace container
{
/// Contains fcppt::container::grid::object and helper types/functions for it.
namespace grid
{
}
}
}

/**
\defgroup fcpptcontainergrid fcppt::container::grid
\ingroup fcpptcontainer
\brief A simple n-dimensional array

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref fcpptcontainergrid_introduction</li>
	<li>\ref fcpptcontainergrid_iteration</li>
	<li>\ref fcpptcontainergrid_resizing</li>
</ol>

</td>
</tr>
</table>

\section fcpptcontainergrid_introduction Introduction

fcppt::container::grid::object is a simple multi dimensional array similar to
<a href="http://www.boost.org/doc/libs/1_48_0/libs/multi_array/doc/index.html">boost::multi_array</a>.
Let's first take a look at how to use a simple three dimensional grid of ints.

\snippet container/grid.cpp grid_simple

Grid uses fcppt::math::dim::basic to specify its size and to obtain an element.

\warning
Grid tries to be as efficient as possible and won't necessarily initialize its elements.

\section fcpptcontainergrid_iteration Iteration

Internally, the grid uses a <code>std::vector</code> or a
fcppt::container::raw_vector to linearly represent the grid. The iterators
returned by the grid are iterators over that internal storage array, so they're
not special in any way (other than begin random-access). This also means that iteration is...
<ul>
<li>
...<em>linear</em> for <em>one-dimensional</em> grids (from left to right)
</li>
<li>
...<em>row-major</em> for <em>two-dimensional</em> grids; this means that
iteration begins at the top left with row 0, proceeds to the top right, then
goes to the right of row 2 and so on.

\image html grid_row_major.svg "Row-major iteration"
</li>
<li>
...<em>vertical-slice-major</em> for <em>three-dimensional</em> grids; this
means that iteration starts at the top left back (z=0) of the cube, then
iterates over all elements with z equal to zero, then starts at the top left
back (z=1) of the cube, and so on.
</li>
<li>...and so on in higher dimensions</li>
</ul>

Here is an example of each iteration method:

\snippet container/grid_iteration.cpp grid_iteration

To get the position of an iterator, use fcppt::container::grid::iterator_position.

\section fcpptcontainergrid_resizing Resizing

To resize a grid there are a couple of options. \link
fcppt::container::grid::object::resize resize \endlink will resize the
underlying container but leave the elements of the grid in an unspecific state.

There are two functions to preserve the current elements that will still fit
into the grid after the resize: \link fcppt::container::grid::resize_preserve
resize_preserve \endlink and \link fcppt::container::grid::resize_preserve_init
resize_preserve_init \endlink.

<code>resize_preserve</code> only preserves the elements that still fit but
doesn't initialize new elements.  <code>resize_preserve_init</code> is like
<code>resize_preserve</code> but will give all new elements a default value.

Here's an example:

\snippet container/grid.cpp grid_resize
*/
