#include<iostream>
#include<cmath>
template<typename F> double integrate(F f,double  min,double max,double ds)
{
  double integral=.0;
  for(double x=min;x<max;x+=ds)
  {
    integral+=f(x);
  }
  return integral*ds;
};

class Variable
{
public:
  double operator()(double x)
  {
    return x;
  }
};

class Constant
{
  double _c;
public:
  Constant(double c) :_c(c){};
  double operator()(double x) {return _c;}
};


/* dodawanie */

template<typename LHS,typename RHS > class AddExpr
{
  LHS _lhs;
  RHS _rhs;
public:
  AddExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  double operator()(double x)
  {
    return _lhs(x)+_rhs(x);
  }
}; 

template<typename LHS,typename RHS > 
AddExpr<LHS,RHS>  operator+(const LHS &l, const RHS &r)
{
  return AddExpr<LHS,RHS>(l,r);
};   

template<typename LHS > 
AddExpr<LHS,Constant>  operator+(const LHS &l, double r)
{
  return AddExpr<LHS,Constant>(l,Constant(r));
};   

template<typename RHS > 
AddExpr<Constant,RHS>  operator+(double l, const RHS &r)
{
  return AddExpr<Constant,RHS>(Constant(l),r);
};   

int main()
{
  Variable x;
  Constant c(5);

  // Test 1: Dodawanie stałej do zmiennej
  auto expr1 = x + c;
  std::cout << "Test 1: x + 5 dla x=2 wynosi: " << expr1(2) << std::endl; // Powinno wyświetlić 7

  // Test 2: Dodawanie zmiennej do stałej
  auto expr2 = c + x;
  std::cout << "Test 2: 5 + x dla x=3 wynosi: " << expr2(3) << std::endl; // Powinno wyświetlić 8

  // Test 3: Dodawanie dwóch wyrażeń
  auto expr3 = expr1 + expr2;
  std::cout << "Test 3: (x + 5) + (5 + x) dla x=4 wynosi: " << expr3(4) << std::endl; // Powinno wyświetlić 18

  return 0;
}