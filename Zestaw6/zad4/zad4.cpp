#include<iostream>
#include"Stack.h"


const int n = 10;

int main() {

  Stack<int, n, Std_exception_on_error_policy, Dynamic_table_allocator > s(n);

  //s.pop();

  for(int i = 0;i<n;++i)
    s.push(i);

  s.resize(20);
  std::cout<<"last straw"<<std::endl;
  s.push(0);

  while(1)
    s.pop();
  return 0;
}