#include<vector>
#include<iostream>

using namespace std;

template<typename T> class Is_class {
  // najpierw definiujemy dwa typy rozniace sie rozmiarem 
  typedef char one;
  typedef struct {
    char c[2];
  } two;
  // teraz potrzebne beda dwa przeladowane szablony
  template<typename U> static one test(int U::* ); // oznacza wskaźnik do pola składowego klasy U typu int
  template<typename U> static two test(...);

// to ktory szablon zostal wybrany sprawdzamy poprzez sprawdzenie rozmiaru zwracanego typu
public:
  enum {
    yes = (sizeof(test<T>(0))==sizeof(one) )
  };
};


struct X {};

int main() {

  cout<<Is_class<int>::yes<<endl;
  cout<<Is_class<X>::yes<<endl;
  cout<<Is_class<vector<double> >::yes<<endl;

  return 0;
}