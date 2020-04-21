#include <iostream>
#include "IntVector.h"

using namespace std;

int main() {
	unsigned size;
	int value;

	cout << "Enter the size of the array: " << endl;
	cin >> size;
	cout << endl;

	cout << "Enter value to be stored in the array: " << endl;
	cin >> value;
	cout << endl;

	IntVector test(size, value);
	cout << "size: " << test.size() << endl;
	cout << "capacity: " << test.capacity() << endl;
	if (test.empty()) {
		cout << "IntVector empty" << endl;
	}
	else {
		cout << "IntVector not empty" << endl;
	}

	cout << "value at index 3: " << test.at(3) << endl;
	cout << "Front value: " << test.front() << endl;
	cout << "Back value: " << test.back() << endl;

	// Insert
	cout << "Insert value 5 at index1" << endl;
	test.insert(1, 5);
	cout << "Value at index 1: " << test.at(1) << endl;

	// Erase
	cout << "Erase value at index 1" << endl;
	test.erase(1);
	cout << "Value at index 1: " << test.at(1) << endl;

	// Push Back
	cout << "Push back value 5" << endl;
	test.push_back(5);
	cout << "value at last index: " << test.at(test.size() - 1) << endl;

	// Pop Back
	cout << "Pop Back value" << endl;
	test.pop_back();
	cout << "Value at las index: " << test.at(test.size() - 1) << endl;

	// Resize
	cout << "Resize to a smaller value" << endl;
	test.resize(5, 10);
	cout << "Size: " << test.size() << endl;

	cout << "Resize to a larger value" << endl;
	test.resize(10, 5);
	cout << "Size: " << test.size() << endl;
	cout << "Value at index 8: " << test.at(8) << endl;

	// Reserve
	cout << "Reserves" << endl;
	test.reserve(15);
	cout << "size: " << test.size() << endl;

	// Assign
	cout << "Assign to a smaller vector" << endl;
	test.assign(5, 10);
	cout << "Size: " << test.size() << endl;
	cout << "value at index 4: " << test.at(4) << endl;
	cout << "Assign larger Vector" << endl;
	test.assign(5, 10);
	cout << "Size: " << test.size() << endl;
	cout << "Value ar index 8: " << test.at(8) << endl;

	// Clear
	cout << "Clear everything." << endl;
	test.clear();
	cout << "Size: " << test.size() << endl;

	return 0;
}