//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/map_iteration_second.hpp>
#include <fcppt/algorithm/update_action.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map_iteration_second
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::map<
		int,
		std::string
	>
	sequence;

	sequence seq{
		std::make_pair(
			1,
			std::string(
				"1"
			)
		),
		std::make_pair(
			2,
			std::string(
				"2"
			)
		),
		std::make_pair(
			3,
			std::string(
				"3"
			)
		),
		std::make_pair(
			4,
			std::string(
				"4"
			)
		)
	};

	fcppt::algorithm::map_iteration_second(
		seq,
		[](
			std::string const &_value
		)
		{
			return
				_value
				==
				"2"
				||
				_value
				==
				"4"
				?
					fcppt::algorithm::update_action::keep
				:
					fcppt::algorithm::update_action::remove
				;
		}
	);

	BOOST_CHECK((
		seq
		==
		sequence{
			std::make_pair(
				2,
				"2"
			),
			std::make_pair(
				4,
				"4"
			)
		}
	));
}
