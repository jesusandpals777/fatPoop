#include <iostream>
#include "IntVector.h"
#include <stdexcept>

using namespace std;


IntVector::IntVector() {
	sz = 0;
	cap = 0;
	data = 0;
}

IntVector::IntVector(unsigned size, int value) {
	sz = size;
	cap = size;
	data = new int[size];
	for (unsigned i = 0; i < size; ++i) {
		data[i] = value;
	}
}

IntVector::~IntVector() {
	delete data;
}

unsigned IntVector::size() const {
	return sz;
}

unsigned IntVector::capacity() const {
	return cap;
}

bool IntVector::empty() const {
	if (sz == 0) {
		return true;
	}
	return false;
}

const int& IntVector::at(unsigned index) const {
	if (index < 0 || index >= sz) {
		throw out_of_range("IntVector::at_range_check");
	}
	return data[index];
}

int& IntVector:: front() {
	return data[0];
}

const int& IntVector::back() const {
	return data[sz - 1];
}


// New stuff
int& IntVector::at(unsigned index) {
	if (index < 0 || index >= sz) {
		throw out_of_range("IntVector::at_range_check");
	}
	return data[index];
}

void IntVector::insert(unsigned index, int value) {
	if (cap == 0) {
		expand(1);
	}
	else {
		if (cap == sz) {
			expand();
			sz++;
		}
	}
	if (index >= sz) {
		throw out_of_range("IntVector::insert_range_check");
	}
	else {
		for (unsigned i = sz - 1; i > index; --i) {
			at(i) = at(i - 1);
		}
		at(index) = value;
	}
}

void IntVector::erase(unsigned index) {
	if (index < 0 || index >= sz) {
		throw out_of_range("IntVector::erase_range_check");
	}
	for (unsigned i = index; i < sz - 1; ++i) {
		data[i] = data[i + 1];
	}
	sz -= 1;
}

const int& IntVector::front() const {
	return data[0];
}

int& IntVector::back() {
	return data[sz - 1];
}

void IntVector::expand() {
	if (cap == 0) {
		cap++;
	}
	else {
		cap *= 2;
	}
	int *temp = new int[cap];

	for (unsigned i = 0; i < sz; ++i) {
		temp[i] = data[i];
	}
	data = temp;
}


void IntVector::expand(unsigned amount) {
	cap += amount;

	int* temp = new int[cap];

	for (unsigned i = 0; i < sz; ++i) {
		temp[i] = data[i];
	}
	data = temp;
}

void IntVector::assign(unsigned n, int value) {
	if (n < cap * 2 && cap != 0) {
		expand();
	}
	else {
		expand(n - cap);
	}
	sz = n;

	for (unsigned i = 0; i < n; ++i) {
		data[i] = value;
	}
}

void IntVector::push_back(int value) {
	if (sz == cap) {
		expand();
	}
	sz++;
	data[sz - 1] = value;
}

void IntVector::pop_back() {
	sz -= 1;
}

void IntVector::clear() {
	delete data;
	data = new int[cap];
	sz = 0;
}

void IntVector::resize(unsigned size, int value) {
	if (size < sz) {
		sz = size;
	}
	else {
		if (cap < size) {
			if (size < cap * 2 && cap != 0) {
				expand();
			}
			else {
				expand(size - cap);
			}
		}
		for (unsigned i = sz; i < size; ++i) {
			data[i] = value;
		}
		sz = size;
	}
}

void IntVector::reserve(unsigned n) {
	if (cap < n) {
		if (n < cap * 2 && cap != 0) {
			expand();
		}
		else {
			expand(n - cap);
		}
	}
}




// IntVector::IntVector(const &IntVector vec){
//  sz = cpy.sz;
//  cap = cpy.cap;
//  data = new int[cap]
//  IntVector v1(6,4);
// IntVector v2(v1);
// }
