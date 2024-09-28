#ifndef FAB_KOL_H
#define FAB_KOL_H
#include <string>
#include <map>
#include "kolor.h"

class DomyslnaPolityka
{
public:
    Kolor nieznanyKolor(std::string nazwa)
    {
        throw std::runtime_error("Nieznany kolor: " + nazwa);
    }
};

template <class Polityka = DomyslnaPolityka>
class FabrykaKolorow : public Polityka
{
public:
    Kolor zwrocKolor(std::string nazwa)
    {
        if (kolory.find(nazwa) != kolory.end())
            return kolory[nazwa];
        else
            return this->nieznanyKolor(nazwa);
    }

private:
    std::map<std::string, Kolor> kolory = {
        {"czarny", Kolor(0, 0, 0)},
        {"zielony", Kolor(0, 255, 0)}
    };
};

#endif // FAB_KOL_H