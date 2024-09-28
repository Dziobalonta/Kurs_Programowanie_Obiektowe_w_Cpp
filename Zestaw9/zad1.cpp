#include <iostream>
#include <memory>

// unique_ptr unique_ptr to typ inteligentnego wskaźnika, który pozwala na dokładnie jednego właściciela wskaźnika. Jest to domyślny wybór dla POCO, chyba że na pewno wiesz, że potrzebujesz shared_ptr. unique_ptr może być przeniesiony do nowego właściciela, ale nie może być kopiowany ani współdzielony. Zastępuje on auto_ptr, który jest przestarzały. unique_ptr jest mały i wydajny; jego rozmiar to jeden wskaźnik, a także obsługuje referencje do wartości prawej strony (rvalue references) dla szybkiego wstawiania i pobierania z kolekcji Standardowej Biblioteki C++. Plik nagłówkowy to <memory>.

// shared_ptr shared_ptr to inteligentny wskaźnik z licznikiem referencji. Używaj go, gdy chcesz przypisać jeden surowy wskaźnik do wielu właścicieli, na przykład, gdy zwracasz kopię wskaźnika z kontenera, ale chcesz zachować oryginał. Surowy wskaźnik nie jest usuwany, dopóki wszyscy właściciele shared_ptr nie wyjdą z zakresu lub inaczej zrezygnują z własności. Rozmiar to dwa wskaźniki; jeden dla obiektu i jeden dla wspólnego bloku kontrolnego, który zawiera licznik referencji. Plik nagłówkowy to <memory>

// Przykład użycia unique_ptr
void unique_ptr_example() 
{
  std::unique_ptr<int> ptr(new int(10));
  std::cout << "Wartość unique_ptr: " << *ptr << std::endl;

  // unique_ptr nie może być kopiowany, ale może być przeniesiony
  std::unique_ptr<int> ptr2 = std::move(ptr);
  std::cout << "Wartość przeniesionego unique_ptr: " << *ptr2 << std::endl;
}

// Przykład użycia shared_ptr
void shared_ptr_example() 
{
  std::shared_ptr<int> ptr1(new int(20));
  std::cout << "Wartość shared_ptr: " << *ptr1 << std::endl;

  // shared_ptr może być kopiowany
  std::shared_ptr<int> ptr2 = ptr1;
  std::cout << "Wartość skopiowanego shared_ptr: " << *ptr2 << std::endl;
  std::cout << "Liczba właścicieli: " << ptr2.use_count() << std::endl;
}

int main() 
{
  unique_ptr_example();
  shared_ptr_example();
  return 0;
}
