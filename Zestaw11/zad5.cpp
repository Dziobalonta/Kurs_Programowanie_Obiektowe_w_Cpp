#include <concepts>
#include <iostream>

// When instantiating the class template, the compiler chooses the most specialized
// one. This means for the call Vector<int> myVec, the partial template
// specialization for std::regular is chosen.

template <typename T>
struct Vector
{
  Vector()
  {
    std::cout << "Vector<T>" << '\n';
  }
};

template <std::regular Reg>
struct Vector<Reg>
{
  Vector()
  {
    std::cout << "Vector<std::regular>" << '\n';
  }
};

int main()
{

std::cout << '\n';

Vector<int> myVec1;
Vector<int&> myVec2; // is not regular, the primary template is chosen.


std::cout << '\n';

}
