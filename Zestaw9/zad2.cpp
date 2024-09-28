#include <iostream>
#include <memory>

using std::cout;
using std::endl;

int main() 
{
  int* ptr_og = new int(10);
  std::unique_ptr<int> ptr_uni(new int(20));
  std::shared_ptr<int> ptr_shr(new int(30));
  std::weak_ptr<int> weak_ptr = std::make_shared<int>(40);

  cout << "Rozmiar zwyklego pointer'a: " << sizeof(ptr_og) << endl;
  cout << "Rozmiar unique pointer'a: " << sizeof(ptr_uni) << endl;
  cout << "Rozmiar shared pointer'a: " << sizeof(ptr_shr) << endl;
  cout << "Rozmiar weak_ptr: " << sizeof(weak_ptr) << endl;


  delete ptr_og;
  return 0;
}
