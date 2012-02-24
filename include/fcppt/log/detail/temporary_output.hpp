//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_TEMPORARY_OUTPUT_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_TEMPORARY_OUTPUT_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/log/detail/output_helper.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class temporary_output
{
public:
	FCPPT_SYMBOL
	temporary_output();

	FCPPT_SYMBOL
	fcppt::string const
	result() const;
private:
	fcppt::shared_ptr<
		fcppt::io::ostringstream
	> stream_;

	template<
		typename T
	>
	friend
	fcppt::log::detail::temporary_output const
	operator<<(
		fcppt::log::detail::temporary_output const &,
		T const &
	);
};

template<
	typename T
>
fcppt::log::detail::temporary_output const
operator<<(
	fcppt::log::detail::output_helper const &,
	T const &_arg
)
{
	return
		fcppt::log::detail::temporary_output()
		<< _arg;
}

template<
	typename T
>
fcppt::log::detail::temporary_output const
operator<<(
	fcppt::log::detail::temporary_output const &_temp,
	T const &_arg
)
{
	fcppt::log::detail::temporary_output new_temp(
		_temp
	);

	*new_temp.stream_ << _arg;

	return new_temp;
}

}
}
}

#endif
