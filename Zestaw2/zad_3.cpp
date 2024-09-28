#include <iostream>
#include <list>

template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init) {
    T total=init;
    for(; first != last; first++) 
    total+= *first;
    return total;
}

int main()
{
    std::list<int> l = {7, 5, 16, 8};
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        // kazdy kontener definiuje typ stowarzyszony nazwany iterator
        std::cout << *it << std::endl;
        // korzystamy z iteratorow jak ze zwyklych wskaznikach
    }
    std::cout << std::endl;

    std::cout << accumulate(l.begin(), l.end(), 0) << std::endl;

    return 0;
}
