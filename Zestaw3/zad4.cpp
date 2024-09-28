#include<vector>
template<typename T,int N = 100, typename R = T*> class Stack;

template<typename T,int N> class Stack<T,N,T*> 
{
  T data[N];
  unsigned int top;
  public:
  Stack():top(0){};

  void push(T e) {data[top++]=e;}

  T pop() {return data[--top];}
};

template<typename T,int N,template<typename E> class Sequence > 
class Stack<T,N,Sequence<T> > 
{
  Sequence<T> rep;
public:
  void push(T e) {rep.push_back(e);};
  T pop() {T top = rep.top();rep.pop_back();return top;}
  bool is_empty() const {return rep.empty();}
};

int main() 
{
  Stack<int, 100 ,int *> s_table;
  Stack<int, 100> s_default;
  Stack<int, 0, std::vector<int> > s_container;
  return 0;
}
