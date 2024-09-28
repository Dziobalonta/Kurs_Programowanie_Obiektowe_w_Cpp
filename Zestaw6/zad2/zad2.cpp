#include <iostream>
#include "Stack.h"

const int n=10;

int main() {
  Stack<int,10,No_checking_policy>               s_no_check; // lub po prostu Stack<int,10>
  Stack<double ,100,Abort_on_error_policy>       s_abort;
  Stack<int *,25,Std_exception_on_error_policy>  s_except;

  return 0;
}