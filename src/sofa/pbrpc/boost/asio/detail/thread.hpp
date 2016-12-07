//
// detail/thread.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SOFA_PBRPC_BOOST_ASIO_DETAIL_THREAD_HPP
#define SOFA_PBRPC_BOOST_ASIO_DETAIL_THREAD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <sofa/pbrpc/boost/asio/detail/config.hpp>

#if !defined(BOOST_ASIO_HAS_THREADS)
# include <sofa/pbrpc/boost/asio/detail/null_thread.hpp>
#elif defined(BOOST_ASIO_WINDOWS)
# if defined(UNDER_CE)
#  include <sofa/pbrpc/boost/asio/detail/wince_thread.hpp>
# else
#  include <sofa/pbrpc/boost/asio/detail/win_thread.hpp>
# endif
#elif defined(BOOST_ASIO_HAS_PTHREADS)
# include <sofa/pbrpc/boost/asio/detail/posix_thread.hpp>
#elif defined(BOOST_ASIO_HAS_STD_THREAD)
# include <sofa/pbrpc/boost/asio/detail/std_thread.hpp>
#else
# error Only Windows, POSIX and std::thread are supported!
#endif

namespace sofa {
namespace pbrpc {
namespace boost {
namespace asio {
namespace detail {

#if !defined(BOOST_ASIO_HAS_THREADS)
typedef null_thread thread;
#elif defined(BOOST_ASIO_WINDOWS)
# if defined(UNDER_CE)
typedef wince_thread thread;
# else
typedef win_thread thread;
# endif
#elif defined(BOOST_ASIO_HAS_PTHREADS)
typedef posix_thread thread;
#elif defined(BOOST_ASIO_HAS_STD_THREAD)
typedef std_thread thread;
#endif

} // namespace detail
} // namespace asio
} // namespace boost
} // namespace pbrpc
} // namespace sofa

#endif // SOFA_PBRPC_BOOST_ASIO_DETAIL_THREAD_HPP
