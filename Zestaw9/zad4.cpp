#include <memory>
#include <iostream>

int main() {

// ! template< class T, class... Args > unique_ptr<T> make_unique( Args&&... args );
// * Wywołuje konstruktor o danych argumentach, rezerwując miejsce w pamięci na 1 obiekt danego typu.
// Ta specjalizacja jest przeznaczona do tworzenia jednostkowych obiektów z dynamicznie alokowanej
// pamięci, podobnie jak konstruktor std::unique_ptr.
// Pozwala na tworzenie obiektów o dowolnych typach T przy użyciu przekazywanych argumentów args.
auto ptr1 = std::make_unique<int>(42); // Tworzy unikatowy wskaźnik na int z wartością 42

// ! template< class T > unique_ptr<T> make_unique( std::size_t size );
// * Rezerwuje miejsce w pamięci na tablicy obiektów danego typu o rozmiarze size
// Ta specjalizacja jest przeznaczona do tworzenia dynamicznie alokowanej tablicy obiektów.
// Używamy jej, gdy chcemy utworzyć tablicę obiektów o określonym rozmiarze.
auto ptr2 = std::make_unique<int[]>(10); // Tworzy unikatowy wskaźnik na tablicę 10 obiektów typu int

return 0;
}