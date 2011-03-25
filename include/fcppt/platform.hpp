//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PLATFORM_HPP_INCLUDED
#define FCPPT_PLATFORM_HPP_INCLUDED

#if defined(_WIN32)
#define FCPPT_WINDOWS_PLATFORM
#elif defined(__unix__)
#define FCPPT_POSIX_PLATFORM
#elif defined(__APPLE__)
#define FCPPT_DARWIN_PLATFORM
#endif

#endif