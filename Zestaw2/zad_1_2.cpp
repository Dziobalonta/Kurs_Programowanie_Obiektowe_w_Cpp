// polimorfizm dynamiczny(Runtime) - korzystaja z niego funkcje wirtualne i dziedzieczenie
// 1.wymaga wspolnej hierarchii dziedziczenia
// 2.wymusza korzystanie ze wskaznikow lub referencji i funkcji wirtualnych
// 3.zazwyczaj generuje mniejszy kod.

// polimorfizm statyczny(Compile time) - implementuja go szablony
// 1.bezpiecznie obsluguje jednorodne zbiory obiektow
// 2.nie trzeba korzystac ze wskaznikow i referencji ani funkcji wirtualnych
// 3.nie musimy korzystac ze wspolnej hierarchii dziedziczenia.

// klasa abstrakcyjna - jest klasa, która posiada zadeklarowana co najmniej 
// jedna metode czysto wirtualna. Każda klasa, która dziedziczy po klasie 
// abstrakcyjnej i sama nie chce byc abstrakcyjna, musi implementowac wszystkie 
// odziedziczone metody czysto wirtualne

// Funkcja wirtualna - jest funkcja skladowa, która powinna zostac ponownie zdefiniowana w klasach pochodnych.

#include <iostream>

using std::cout;
using std::endl;

class Ksztalt
{
public:
    virtual void Rysuj()=0;
};

class Kolo : public Ksztalt
{
public:
    void Rysuj()
    {
        cout << "Rysuje kolo!" << endl;
    }
};

class Kwadrat : public Ksztalt
{
public:
    void Rysuj()
    {
        cout << "Rysuje kwadrat!" << endl;
    }
};

class Trojkat : public Ksztalt
{
public:
    void Rysuj()
    {
        cout << "Rysuje trojkat!" << endl;
    }
};

template<typename T> void Rysuj_Template(T *tablica[],size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        tablica[i]->Rysuj();
    }
    
}

int main() 
{
    Kolo kolo;
    Kwadrat kwadrat;
    Trojkat trojkat;

    // Polimorfizm statyczny - wywołanie metody na obiekcie klasy pochodnej
    kwadrat.Rysuj();

    // Polimorfizm dynamiczny - wywołanie metody na wskaźniku do obiektu klasy bazowej
    Ksztalt* lista[3] = { &kolo, &kwadrat, &trojkat };
    Rysuj_Template(lista, 3);

    return 0;
}