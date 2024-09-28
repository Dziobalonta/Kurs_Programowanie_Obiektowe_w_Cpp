#include <compare>
#include <iostream>
#include <string>
#include <vector>

struct Test{};

// Koncept std::three_way_comparable w C++20 to zasada, która mówi, że dany typ danych może być porównywany za pomocą specjalnego operatora <=>. Ten operator porównuje dwie wartości i mówi, czy są one równe, czy jedna jest większa od drugiej, czy mniejsza.

int main() 
{

  std::cout << '\n';

  std::cout << std::boolalpha;

  // checks at compile time if T supports the six comparison operators
  std::cout << "std::three_way_comparable<int>: "
  << std::three_way_comparable<int> << "\n";

  std::cout << "std::three_way_comparable<double>: ";
  if (std::three_way_comparable<double>) std::cout << "True";
  else std::cout << "False";

  std::cout << "\n\n";

  // Being a compile time predicate means, that std::three_way_comparable can be used at run time or at compile time
  // static_assert and constexpr are evaluated at compile time.
  static_assert(std::three_way_comparable<std::string>);

  std::cout << "std::three_way_comparable<Test>: ";
  if constexpr(std::three_way_comparable<Test>) std::cout << "True";
  else std::cout << "False";

  std::cout << '\n';

  std::cout << "std::three_way_comparable<std::vector<int>>: ";
  if constexpr(std::three_way_comparable<std::vector<int>>) std::cout << "True";
  else std::cout << "False";

  std::cout << "\n\n";

}