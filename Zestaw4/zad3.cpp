// Gdy chcemy sprecyzować, że sumujemy np. int we float, a float we float.
// Dodajemy domyślny dodatkowy parametr do szablonu, który będzie definiował
// wybraną klasę cech. Domyślny, aby nie trzeba było podawać go jawnie w 
// typowych przypadkach. Problem w tym, że szablony funkcji nie dopuszczają 
// stosowania parametrów domyślnych. Obchodzimy to za pomocą przeciążenia.
#include  <iostream>
#include  <cstring>
using  namespace std;

template<typename T>  struct sum_traits;


template<>  struct sum_traits<char>
{
  typedef int sum_type; 
};
template<>  struct sum_traits<int>
{
  typedef long int sum_type; 
};
template<>  struct sum_traits<float>
{
  typedef double sum_type; 
};
template<>  struct sum_traits<double>
{
  typedef double sum_type; 
};

template<typename Traits,typename T > 
typename Traits::sum_type sum(T *beg,T *end)
{ 
  typedef typename Traits::sum_type sum_type;
  sum_type total = sum_type(); 
  while(beg != end)
  { 
    total += *beg;
    beg++; 
  } 
  return total; 
};

template<typename T > 
typename sum_traits<T>::sum_type sum(T *beg,T *end) 
{ 
  return sum<sum_traits<T>, T>(beg,end);
}


struct char_sum
{
  typedef char sum_type;
};


int main() 
{
  char name[]="@ @ @";
  int length=strlen(name);

  cout << (int) sum(name,&name[length]) << endl;

  cout << (int) sum<char_sum>(name,&name[length]) << endl;

  cout << (int) sum<char>(name,&name[length]) << endl;
  return 0;
}
