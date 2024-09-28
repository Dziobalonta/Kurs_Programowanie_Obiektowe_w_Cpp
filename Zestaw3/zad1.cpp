#include <iostream>
#include <cstring>
using namespace std;


template<typename T> T  max(T a, T b)
{
    return (a>b)?a:b;
}
template<typename T> T* max(T *a, T *b)
{
    return ((*a)>(*b))?a:b;
}

template<typename T>
T max(T *data, size_t n)
{
    T maks = data[0];

    for(size_t i=0;i<n;++i)
        if(data[i] > maks) 
            maks=data[i];

    return maks;
}

template<> 
char *max(char *a,char *b) 
{
  return (strcmp(a,b)>0)?a:b;
}

template<> 
const char* max(const char *a,const char *b) 
{
  return (strcmp(a,b)>0)?a:b;
}

template<typename T> const T* max(T *a,const T*b) 
{ // musi byc definowane aby ta nizej miala prawo istnienia
  return ((*a)>(*b))?a:b;
}

template<>
const char * max(char *a,const char *b)
{
    return (strcmp(a,b)>0)?a:b;
}



int main() 
{
    int intA = 10, intB = 20;                             // oznacza ze wywoluje z tego namespace a nie std::max
    cout << "Maks z " << intA << " i " << intB << ": " << ::max(intA, intB) << endl;

    double doubleA = 3.14, doubleB = 2.71;
    cout << "Maks z " << doubleA << " i " << doubleB << ": " << ::max(doubleA, doubleB) << endl;

    char charA = 'X', charB = 'Y';
    cout << "Maks z '" << charA << "' i '" << charB << "': " << ::max(charA, charB) << endl;

    const char* strA = "banan";
    const char* strB = "jablko";
    cout << "Maks z \"" << strA << "\" i \"" << strB << "\": " << ::max(strA, strB) << endl;

    char str1[] = "pomarancza";
    char str2[] = "wisnia";
    cout << "Maks z \"" << str1 << "\" i \"" << str2 << "\": " << ::max(str1, str2) << endl;

    int arr[] = { 5, 8, 3, 12, 7 };
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "Maks z tablicy: " << ::max(arr, arrSize) << endl;
    return 0;
}