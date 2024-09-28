#include<vector>
#include<iostream>

using namespace std;

template<typename T> class has_value_type {
  // najpierw definiujemy dwa typy rozniace sie rozmiarem 
  typedef char one;
  typedef struct {
    char c[2];
  } two;
  // teraz potrzebne beda dwa przeladowane szablony
  template<typename U> static one test(typename U::value_type* ); // oznacza wskaźnik do pola składowego klasy U  dowolnego typu value_type
  template<typename U> static two test(...);

// to ktory szablon zostal wybrany sprawdzamy poprzez sprawdzenie rozmiaru zwracanego typu
public:
  enum {
    yes = (sizeof(test<T>(0))==sizeof(one) )
  };
};

struct X {};

int main() {
  cout << has_value_type<std::vector<int> >::yes << endl; // true
  cout << has_value_type<int>::yes << endl; // false
  cout << has_value_type<X>::yes << endl; // false

  return 0;
}