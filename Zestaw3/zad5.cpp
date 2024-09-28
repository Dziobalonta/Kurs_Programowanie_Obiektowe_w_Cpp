#include <iostream>
#include <set>

int main()
{
  std::set<int,std::greater_equal<>> vals = {2, 12, 467, 4533, 102, 30};

  for (auto num: vals)
  {
    std::cout << num << " ";
  }std::cout << std::endl;
  
  return 0;
}