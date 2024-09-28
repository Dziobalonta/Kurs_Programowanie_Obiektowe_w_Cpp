#include <iostream>
#include <math.h>

using std::cout;
using std::endl;
using std::string;

// Zadanie1
template<typename T> 
T maksimum(T a,T b) 
{
    return (a>b)?a:b;
};

//Zadanie2
template<typename T, typename U>
T convert(U u)
{
    return (T)u;
};

//Zadanie3
template<size_t N,typename T>
T dot_product(T *a,T *b)
{
    T total=0.0;
    for(size_t i=0; i<N; i++) total += a[i]*b[i];

    return total;
};

//Zadanie4
template< template<int N>class  C,int K> 
void f(C<K>)
{
  //cout<<N<<endl; // use of undeclared identifier 'N'
  cout<<K<<endl; 
};

template<int N>
struct SomeClass {};

//Zadanie5
template<typename T,size_t N>
class Stack 
{
private:	
    T data[N];
    size_t top;
public:
    typedef T value_type;

    Stack():top(0) {};

    void push(T val) 
    {
        data[top++]=val;
    }

    T pop()
    {
        return data[--top];
    }
    bool is_empty() const
    {
        return (top==0);
    }
};

template<typename S>
typename S::value_type suma(S s) 
{
    typename S::value_type total = 0; 
    //slowo typename jest wymagane, inaczej kompilator założy, że 
    //S::value_type odnosi się do statycznej składowej klasy
    while(!s.is_empty()) 
    {
        total+=s.pop();
    }
    return total;
}

int main()
{
    double a=M_PI, b=M_PI_2;
    cout << "Zadanie 1: " << endl << maksimum(a,b) << endl;

    char c = 'd';
    int d = 100;
    //cout << "Zadanie 2: " << endl << convert<int>(c) << endl << convert<char>(d) << endl;
    cout << "Zadanie 2: " << endl << convert<char,int>(c) << endl << convert<int,char>(d) << endl;
    
    double x[3] = {2.0, 2.5, 1.0};
    double y[3] = {1.0, 3.0, -1.0};
    cout << "Zadanie 3: " << endl << dot_product<3>(x,y) << endl;

    SomeClass<1111> c1;
    SomeClass<2222> c2;
    cout << "Zadanie 4: " << endl;
    f(c1);
    f(c2);

    Stack<int,3> stos;
    stos.push(1);
    stos.push(2);
    stos.push(4);
    cout << "Zadanie 5: " << endl << suma(stos) << endl;
    return 0;
}