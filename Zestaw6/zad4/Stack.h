#ifndef  _stack_
#define  _stack_

#include<stdlib.h>
#include<iostream>
#include<stdexcept>
#include<algorithm>

#include"Checking_policy.h"
#include"Allocator.h"

template<typename T = int , size_t N = 100,
	 typename Checking_policy = No_checking_policy,  
    template<typename U,size_t M> class Allocator_policy = Static_table_allocator>
class Stack: private Checking_policy, public Allocator_policy<T,N> { //prywatne dziedziczenie

  typedef typename Allocator_policy<T,N>::rep_type rep_type;

  size_t _top;

public:
  Stack(size_t n = N):_top(0) {
    Stack::init(n);
  };

  void push(const T &val) {
    Stack::expand_if_needed(_top);
    Checking_policy::check_push(_top,this->size());
    Stack::_rep[_top++]=val;
  }

  void pop() {
    Checking_policy::check_pop(_top);
    --_top;
    Stack::shrink_if_needed(_top);
  }
  
  const T& top() const {
    Checking_policy::check_top(_top);
    return Stack::_rep[top-1];
  }
  
  bool is_empty() {
    return !_top;
  } 

  ~Stack() {Stack::dealocate();}

};

#endif