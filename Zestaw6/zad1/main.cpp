#include <iostream>
using std::cin;
using std::cout;

#include "kolor.h"
#include "fab_kol.h"

template <int red, int green, int blue>
struct PolitykaDefaultowegoKoloru
{
    Kolor nieznanyKolor(std::string nazwa)
    {
        return Kolor(red, green, blue);
    }
};

typedef PolitykaDefaultowegoKoloru<128, 128, 128> SzaraPolityka;

int main()
{
    FabrykaKolorow<SzaraPolityka> fabryka;
    try {
        cout << fabryka.zwrocKolor("zielony") << '\n';
        cout << fabryka.zwrocKolor("green") << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }

    return 0;
}