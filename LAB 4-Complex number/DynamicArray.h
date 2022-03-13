#pragma once
#include "ComplexNumber.h"
#include <iostream>

typedef int T;

class DynamicArray
{
private:
	int capacity, length;
	T* data;

	void resize();

public:
	DynamicArray();
	~DynamicArray();

	DynamicArray(const DynamicArray& copied_arr);

	void insertAtEnd(T elem);
	void removeLastElement();

	int getLength() const;
	int getCapacity() const;

	DynamicArray& operator = (const DynamicArray& arr2);

	friend std::ostream& operator << (std::ostream& out, const DynamicArray& d);

	T& operator[](int index);
};