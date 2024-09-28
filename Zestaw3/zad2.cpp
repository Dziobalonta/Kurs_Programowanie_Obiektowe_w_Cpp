#include <iostream>

template<typename T,typename U> T convert(U u)
{
  return static_cast<T>(u);
};

template<>
int convert<int,double>(double u)
{
    return (int)u;
};

template<> 
double convert<double,double>(double u) 
{
    return (double)u;
};

int main()
{
    std::cout << convert<int>(3.14) << std::endl; 
    std::cout << convert<double>(2.71) << std::endl;
    return 0;
}