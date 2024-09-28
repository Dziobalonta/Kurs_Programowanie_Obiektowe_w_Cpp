#include<iostream>
#include<string>

#include"Typelist.h"
#include"Any_print.h"



int main(){

  typedef TypeList<int,Null_type> T1;
  typedef TypeList<double,T1> T2;
  typedef TypeList<float,T2> T3;
  typedef TypeList<std::string,T3> T4;
  
  // testy na length
  std::cout<<Length<T1>::value<<" ";
  std::cout<<Length<T2>::value<<" ";
  std::cout<<Length<T3>::value<<" ";
  std::cout<<Length<T4>::value<<"\n";

  // testy na typ na podanym indeksie
  std::cout << "Type at position 1 in T4: " << typeid(typename At<1, T4>::Result).name() << "\n";
  std::cout << "Type at position 2 in T4: " << typeid(typename At<2, T4>::Result).name() << "\n";
  std::cout << "Type at position 3 in T4: " << typeid(typename At<3, T4>::Result).name() << "\n";
  std::cout << "Type at position 4 in T4: " << typeid(typename At<4, T4>::Result).name() << "\n";

  // testy na to czy jest w liście
  std::cout << "Is int in T4? " << (In<float, T4>::yes ? "Yes" : "No") << "\n";
  std::cout << "Is char in T4? " << (In<char, T4>::yes ? "Yes" : "No") << "\n";
  std::cout << "Is int in T2? " << (In<float, T2>::yes ? "Yes" : "No") << "\n";



  return 0;
}