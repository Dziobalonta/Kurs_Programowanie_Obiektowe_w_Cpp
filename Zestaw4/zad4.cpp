// Uogólniona funkcja sum, aby działała nie tylko ze wskaźnikami, ale i iteratorami.
// Użycie klas cech jest już niezbędne, musimy bowiem dowiedzieć się na obiekty 
// jakiego typu wskazuje iterator. Nie można do tego celu użyć typów 
// stowarzyszonych IT::value_type, bo jako iterator może zostać 
// podstawiony zwykły wskaźnik.
// Dlatego w STL istnieje klasa iterator_traits, definiująca podstawowe 
// typy dla każdego rodzaju iteratora.

// Linia sum_type total = sum_traits<value_type>::zero(); 
// próbuje wywołać statyczną funkcję zero() z sum_traits<int>, 
// która zwraca wartość początkową dla sumy. Jeśli ta funkcja nie jest definiowana, 
// kompilator nie będzie w stanie znaleźć zero(), co prowadzi do błędu kompilacji.
// Bez tej linii, kompilator nie będzie wiedział, jaką wartość przypisać do total 
// na początku funkcji sum.
#include<iostream>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

template<typename T> struct sum_traits;

template<>
struct sum_traits<int> {
  typedef int sum_type;
  static sum_type zero() {
      return 0;
  }
};

template<typename IT>
typename sum_traits<typename iterator_traits<IT>::value_type>::sum_type 
sum(IT beg, IT end) 
{ 
  typedef typename iterator_traits<IT>::value_type value_type;
  typedef typename sum_traits<value_type>::sum_type sum_type;
  sum_type total = sum_traits<value_type>::zero();
  // Bez definiowania zero w sum_traits<int>, tez dziala
  // sum_type total = 0; 
  while(beg != end )
  { 
    total += *beg; ++beg; 
  } 
  return total; 
}

int main()
{
  vector<int> v = {1, 2, 3, 4, 5};
  cout << "Suma elementów wektora: " << sum(v.begin(), v.end()) << endl;

  list<int> l = {6, 7, 8, 9, 10};
  cout << "Suma elementów listy: " << sum(l.begin(), l.end()) << endl;

  int arr[] = {11, 12, 13, 14, 15};
  cout << "Suma elementów tablicy: " << sum(arr, arr + sizeof(arr) / sizeof(int)) << endl;

  return 0;
}
