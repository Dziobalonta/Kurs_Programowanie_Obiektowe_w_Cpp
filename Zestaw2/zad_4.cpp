// Funktor w C++ to obiekt klasy lub struktury, który mozna wywolac jak funkcje.
// Funktory przeciazaja operator wywolania funkcji () i pozwalaja nam uzywac obiektu jak funkcji

#include <iostream>
#include <vector>
#include <functional>


using namespace std;

template<typename T> class SequenceGen {
private:
    T _start; 
    T _step;
public:
    SequenceGen(T start = T(),T step = 1 ): _start(start),_step(step){};

    T operator()() // When an object of this class is called like a function (e.g., mySequenceGen()), 
                // it returns the current value of _start and then increments _start by _step
    {
        T tmp = _start;
        _start+= _step;
        return tmp;
    }
};

const size_t n = 20 ;

int main() 
{
    vector<int> v(n);

    generate_n(v.begin(),  n, SequenceGen<int>(1, 2));
    vector<int>::iterator it = find_if(v.begin(),
                                        v.end(),
                                        std::bind2nd(greater<int>(),4)); //std::bind
    cout<<*it<<endl;

    return 0;
}