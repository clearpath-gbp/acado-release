/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2013 by Boris Houska, Hans Joachim Ferreau,
 *    Milan Vukov, Rien Quirynen, KU Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC)
 *    under supervision of Moritz Diehl. All rights reserved.
 *
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *    \author Joris Gillis, Boris Houska, Joachim Ferreau
 *    
 */


#include <acado/modeling_tools/frame_node.hpp>
#include <cassert>

#ifndef __MATLAB__
using namespace std;
#endif

USING_NAMESPACE_ACADO

FrameNode::FrameNode( const String    & name_,
                      const Expression& q_   ,
                      const Expression& dq_  ,
                      const Expression& ddq_){

    name = name_;
    q    = q_   ;
    dq   = dq_  ;
    ddq  = ddq_ ;

    count = 0;
}


FrameNode::FrameNode( const String& name_,
                      const Frame &  ref_,
                      const Expression & T ){

    name = name_;
    ref  = ref_ ;

    R=zeros(3,3);
    p=zeros(3,1);
    R(0,0)=T(0,0);R(0,1)=T(0,1);R(0,2)=T(0,2);
    R(1,0)=T(1,0);R(1,1)=T(1,1);R(1,2)=T(1,2);
    R(2,0)=T(2,0);R(2,1)=T(2,1);R(2,2)=T(2,2);
    p(0)=T(0,3);
    p(1)=T(1,3);
    p(2)=T(2,3);
    time = ref.node->time;
    q = ref.node->q;
    dq = ref.node->dq;
    ddq = ref.node->ddq;
    count = 0;
}


FrameNode::~FrameNode(){

    assert(count==0);
}


Stream FrameNode::print(Stream &stream) const {
  // stream << ref;
   stream << " -> ";
   stream << name;
   return stream;
}
