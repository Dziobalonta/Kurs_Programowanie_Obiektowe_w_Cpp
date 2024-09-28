#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    Test () {
      cout << "Wywolanie konstruktora" << endl;
    }

	~Test () {
		cout << "Wywolanie destruktora" << endl;
	}
};

int main () {
  shared_ptr<Test> ptr1 = make_shared<Test> ();
  shared_ptr<Test> ptr2 (ptr1);
  shared_ptr<Test> ptr3 (ptr1);

  cout << "Liczba referencji: " << ptr1.use_count() << endl;

  return 0;
}