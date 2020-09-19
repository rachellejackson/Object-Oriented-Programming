#include <iostream>

using namespace std;
#ifndef DynArray_h
#define DynArray_h

class DynArray {
public:
	int csize; //the current number of elements stores by the array
	int ccapacity; //how many elements the array can hold
	int* originalarray;
	DynArray(); //default constructor
	DynArray(int n);
	DynArray(const DynArray& other);
	DynArray& operator=(const DynArray& other);
	~DynArray();
	int size() const;
	int capacity() const;
	void clear();
	void push_back(const int& n);
	void pop_back();
	int& at(int n) const;
	int& operator[ ](int index) const;
	int& front() const;
	int& back() const;
};
#endif
