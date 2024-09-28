#ifndef KOLOR_H
#define KOLOR_H

class Kolor
{
private:  
  int r, g, b;

public:
  Kolor(int rr = 0,int gg = 0,int bb = 0) : r(rr), g(gg), b(bb) {}
  int get_r() const {return r;}
  int get_g() const {return g;}
  int get_b() const {return b;}
};

std::ostream& operator<<(std::ostream& os, const Kolor& k)
{
  return os << "Kolor(" << k.get_r() << ", " << k.get_g() << ", " << k.get_b() << ")";
}
#endif // KOLOR_H