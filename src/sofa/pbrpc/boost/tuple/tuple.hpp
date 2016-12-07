//  tuple.hpp - Boost Tuple Library --------------------------------------

// Copyright (C) 1999, 2000 Jaakko Jarvi (jaakko.jarvi@cs.utu.fi)
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

// ----------------------------------------------------------------- 

#ifndef SOFA_PBRPC_BOOST_TUPLE_HPP
#define SOFA_PBRPC_BOOST_TUPLE_HPP

#if defined(__sgi) && defined(_COMPILER_VERSION) && _COMPILER_VERSION <= 730
// Work around a compiler bug.
// sofa::pbrpc::boost::python::tuple has to be seen by the compiler before the
// sofa::pbrpc::boost::tuple class template.
namespace sofa {
namespace pbrpc {
namespace boost { namespace python { class tuple; }}}}
#endif

#include "sofa/pbrpc/boost/config.hpp"
#include "sofa/pbrpc/boost/static_assert.hpp"

// other compilers
#include "sofa/pbrpc/boost/ref.hpp"
#include "sofa/pbrpc/boost/tuple/detail/tuple_basic.hpp"


namespace sofa {
namespace pbrpc {
namespace boost {    

using tuples::tuple;
using tuples::make_tuple;
using tuples::tie;
#if !defined(BOOST_NO_USING_TEMPLATE)
using tuples::get;
#else
//
// The "using tuples::get" statement causes the
// Borland compiler to ICE, use forwarding
// functions instead:
//
template<int N, class HT, class TT>
inline typename tuples::access_traits<
                  typename tuples::element<N, tuples::cons<HT, TT> >::type
                >::non_const_type
get(tuples::cons<HT, TT>& c) {
  return tuples::get<N,HT,TT>(c);
} 
// get function for const cons-lists, returns a const reference to
// the element. If the element is a reference, returns the reference
// as such (that is, can return a non-const reference)
template<int N, class HT, class TT>
inline typename tuples::access_traits<
                  typename tuples::element<N, tuples::cons<HT, TT> >::type
                >::const_type
get(const tuples::cons<HT, TT>& c) {
  return tuples::get<N,HT,TT>(c);
}

#endif // BOOST_NO_USING_TEMPLATE
   
} // end namespace boost
} // namespace pbrpc
} // namespace sofa


#endif // SOFA_PBRPC_BOOST_TUPLE_HPP
