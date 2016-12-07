
#ifndef SOFA_PBRPC_BOOST_MPL_AUX_EMPTY_IMPL_HPP_INCLUDED
#define SOFA_PBRPC_BOOST_MPL_AUX_EMPTY_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <sofa/pbrpc/boost/mpl/empty_fwd.hpp>
#include <sofa/pbrpc/boost/mpl/begin_end.hpp>
#include <sofa/pbrpc/boost/mpl/aux_/traits_lambda_spec.hpp>
#include <sofa/pbrpc/boost/type_traits/is_same.hpp>

namespace sofa {
namespace pbrpc {
namespace boost { namespace mpl {

// default implementation; conrete sequences might override it by 
// specializing either the 'empty_impl' or the primary 'empty' template

template< typename Tag >
struct empty_impl
{
    template< typename Sequence > struct apply
        : is_same<
              typename begin<Sequence>::type
            , typename end<Sequence>::type
            >
    {
    };
};

BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(1,empty_impl)

}}}}

#endif // SOFA_PBRPC_BOOST_MPL_AUX_EMPTY_IMPL_HPP_INCLUDED
