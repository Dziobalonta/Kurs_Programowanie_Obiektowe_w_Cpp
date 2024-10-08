#ifndef  _stack_
#define  _stack_

#include<stdlib.h>
#include<iostream>
#include<stdexcept>
#include<algorithm>


#include "Checking_policy.h"



template<typename T = int , size_t N = 100,
	 typename Checking_policy = No_checking_policy >  
class Stack 
{
  T  _rep[N];
  size_t _top;
public:
  Stack(size_t n = N):_top(0) {};

  void push(const T &val) 
  {
    Checking_policy::check_push(_top,N);
    _rep[_top++]=val;
  }

  void pop() 
  {
    Checking_policy::check_pop(_top);
    --_top;
  }
  
  const T top() const 
  {
    Checking_policy::check_top(_top);
    return &_rep[_top-1];
  }

  T &top()
  {
    Checking_policy::check_top(_top);
    return _rep[_top-1];
  }

  
  bool is_empty()
  {
    return !_top;
  } 

};

#endif