#include <iostream>
#include <memory>

using namespace std;

weak_ptr<int> weak_pointer;

void check() {
	cout << "Refrence counter: " << weak_pointer.use_count() << " | ";
	
	if (shared_ptr<int> shared_pointer = weak_pointer.lock()) {
		cout << "shared_pointer = " << *shared_pointer << endl;
	} else {
		cout << "weak_pointer is expired" << endl;
	}
}

int main() {
	{
		auto shared_pointer = make_shared<int>(42);
		weak_pointer = shared_pointer;
 
		check();
    }
 
	check();

    return 0;
}