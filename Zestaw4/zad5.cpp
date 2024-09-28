#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <list>
using std::list;

#include <forward_list>
using std::forward_list;

#include <iterator>
using std::iterator_traits;
using std::forward_iterator_tag;
using std::random_access_iterator_tag;
using std::bidirectional_iterator_tag;


template <typename Iter>
int operacja_impl(Iter i, forward_iterator_tag)
{
    cout << "Iterator gorszy niż dwukierunkowy.\n";
    // Tu umieścić wersję algorytmu, która zadziała dla iteratora oferującego
    // tylko operację przesuwania na następny element.
    return 1;
}

template <typename Iter>
int operacja_impl(Iter i, bidirectional_iterator_tag)
{
    cout << "Iterator dwukierunkowy.\n";
    // Tu umieścić wersję algorytmu, która zadziała dla iteratora oferującego
    // operacje przesuwania do przodu i do tyłu.
    return 2;
}

template <typename Iter>
int operacja_impl(Iter i, random_access_iterator_tag)
{
    cout << "Iterator o swobodnym dostępie.\n";
    // A tu jest miejsce na efektywniejszą wersję algorytmu.
    return 3;
}

template <typename Iter>
inline int operacja(Iter i)
{
    return operacja_impl(i,
            typename iterator_traits<Iter>::iterator_category());
}

int main()
{
    list<int> l;
    operacja(l.begin());

    int t[3];
    operacja(t);

    forward_list<int> fl;
    operacja(fl.begin());

    return 0;
}