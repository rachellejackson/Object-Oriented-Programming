#include <iostream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <array>
using namespace std;

template<typename T>
class DynArray {
private:


public:
	int csize; //the current number of elements stores by the array
	int ccapacity; //how many elements the array can hold
	T* originalarray;
	DynArray(); //default constructor
	DynArray(int n);
	DynArray(const DynArray& other);
	const DynArray& operator=(const DynArray& other);
	~DynArray();
	int size() const;
	int capacity() const;
	void clear();
	void push_back(const T& n);
	void pop_back();
	T& at(int n) const;
	T& operator[ ](int index) const;
	T& front() const;
	T& back() const;
};

//default constructor
template<typename T>
DynArray<T>::DynArray() {
	originalarray = nullptr;
	csize = 0;
	ccapacity = 2;
	originalarray = new T[this->ccapacity];
}

//creates a constructor with size 0 and capacity n
template<typename T>
DynArray<T>::DynArray(int n) {
	originalarray = nullptr;
	csize = 0;
	ccapacity = n;
	originalarray = new T[this->ccapacity];
}

//copy constructor
template<typename T>
DynArray<T>::DynArray(const DynArray& other) {
	cout << "copy" << endl;
	originalarray = new T[other.csize];
	for (int i = 0; i < other.csize; ++i) {
		originalarray[i] = other[i];
	}
	csize = other.csize;
	ccapacity = other.ccapacity;
}

//An assignment operator
template<typename T>
const DynArray<T>& DynArray<T>::operator=(const DynArray& other) {
	cout << "assign" << endl;
	originalarray = new T[other.csize];
	for (int i = 0; i < other.csize; ++i) {
		originalarray[i] = other[i];
	}
	csize = other.csize;
	ccapacity = other.ccapacity;
	return *this;
}

//Destructor
template<typename T>
DynArray<T>:: ~DynArray() {
	delete[] originalarray;
	ccapacity = 0;
	originalarray = nullptr;
}

//function that returns current size of array
template<typename T>
int DynArray<T>::size() const {
	return csize;
}

//function that returns allocated capacity of array:
template<typename T>
int DynArray<T>::capacity() const {
	return ccapacity;
}

//Frees the currently-allocated memory, resets capacity to 2 and size to 0, and allocates fresh heap memory.
template<typename T>
void DynArray<T>::clear() {
	delete[] originalarray;
	ccapacity = 2;
	csize = 0;
	originalarray = new T[this->ccapacity];
}

//adds stuff
template<typename T>
void DynArray<T>::push_back(const T& n) {
	if (csize == ccapacity) {
		cout << "grow" << endl;
		ccapacity *= 2;
		T* temparray = new T[ccapacity];
		for (int i = 0; i < csize; ++i) {
			temparray[i] = originalarray[i];
		}
		delete[] originalarray;
		originalarray = temparray;
	}
	originalarray[csize] = n;
	csize = csize + 1;
}

//deletes stuff from the end. 
template<typename T>
void DynArray<T>::pop_back() {
	if (csize == 0) {
		throw runtime_error("invalid index");
	}
	else {
		csize = csize - 1;
	}
}

// Returns a reference to the integer stored at index n of the DynArray. If the index is outside the range of the DynArray, 
//this function should throw a runtime_error with an appropriate message.
template<typename T>
T& DynArray<T>::at(int n) const {
	if (n >= csize || n < 0) {
		throw runtime_error("invalid index");
	}
	return originalarray[n];
}

//Behaves like at(), except that it does not throw a runtime_error if the index is out-of-bounds.
template<typename T>
T& DynArray<T>::operator[ ](int index) const {
	return originalarray[index];
}

// Returns a reference to the integer stored at the first index (but does not remove it).
//If the DynArray is empty, this function should throw a runtime_error with an appropriate message.
template<typename T>
T& DynArray<T>::front() const {
	if (csize < 1) {
		throw runtime_error("invalid index");
	}
	return originalarray[0];
}

//Returns a reference to the integer stored at the last index (but does not remove it).
//If the DynArray is empty, this function should throw a runtime_error with an appropriate message.
template<typename T>
T& DynArray<T>::back() const {
	if (csize < 1) {
		throw runtime_error("invalid index");
	}
	return originalarray[csize - 1];
}
