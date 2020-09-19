#include "dynarray.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <array>
using namespace std;

//default constructor
DynArray ::DynArray() {
	originalarray = nullptr;
	csize = 0;
	ccapacity = 2;
	originalarray = new int[this->ccapacity];
}

//creates a constructor with size 0 and capacity n
DynArray ::DynArray(int n) {
	originalarray = nullptr;
	csize = 0;
	ccapacity = n;
	originalarray = new int[this->ccapacity];
}

//copy constructor
DynArray::DynArray(const DynArray& other) {
	originalarray = new int[other.csize];
	for (int i = 0; i < other.csize; ++i) {
		originalarray[i] = other[i];
	}
	csize = other.csize;
	ccapacity = other.ccapacity;
}

//An assignment operator
DynArray& DynArray ::operator=(const DynArray& other) {
	delete[] originalarray;
	originalarray = new int[other.csize];
	for (int i = 0; i < other.csize; ++i) {
		originalarray[i] = other[i];
	}
	csize = other.csize;
	ccapacity = other.ccapacity;
	return *this;
}

//Destructor
DynArray:: ~DynArray() {
	delete[] originalarray;
	ccapacity = 0;
	originalarray = nullptr;
}

//function that returns current size of array
int DynArray ::size() const {
	return csize;
}

//function that returns allocated capacity of array:
int DynArray ::capacity() const {
	return ccapacity;
}

//Frees the currently-allocated memory, resets capacity to 2 and size to 0, and allocates fresh heap memory.
void DynArray::clear() {
	delete[] originalarray;
	ccapacity = 2;
	csize = 0;
	originalarray = new int[this->ccapacity];
}


void DynArray::push_back(const int& n) {
	if (csize == ccapacity) {
		ccapacity *= 2;
		int* temparray = new int[ccapacity];
		for (int i = 0; i < csize; ++i) {
			temparray[i] = originalarray[i];
		}
		delete[] originalarray;
		originalarray = temparray;
	}
	originalarray[csize] = n;
	csize = csize + 1;
}

void DynArray::pop_back() {
	if (csize == 0) {
		throw runtime_error("invalid index");
	}
	else {
		csize = csize - 1;
	}
}

// Returns a reference to the integer stored at index n of the DynArray. If the index is outside the range of the DynArray, 
//this function should throw a runtime_error with an appropriate message.
int& DynArray::at(int n) const {
	if (n >= csize || n < 0) {
		throw runtime_error("invalid index");
	}
	return originalarray[n];
}

//Behaves just like at(), except that it does not throw a runtime_error if the index is out-of-bounds.
int& DynArray ::operator[ ](int index) const {
	return originalarray[index];
}

// Returns a reference to the integer stored at the first index (but does not remove it).
//If the DynArray is empty, this function should throw a runtime_error with an appropriate message.
int& DynArray ::front() const {
	if (csize < 1) {
		throw runtime_error("invalid index");
	}
	return originalarray[0];
}

//Returns a reference to the integer stored at the last index (but does not remove it).
//If the DynArray is empty, this function should throw a runtime_error with an appropriate message.
int& DynArray ::back() const {
	if (csize < 1) {
		throw runtime_error("invalid index");
	}
	return originalarray[csize - 1];
}
