#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	this->capacity = 2;
	this->length = 0;
	this->data = new T[capacity];
}

DynamicArray::~DynamicArray()
{
	delete[] this->data;
}

DynamicArray::DynamicArray(const DynamicArray& copied_arr)
{
	this->capacity = copied_arr.capacity;
	this->length = copied_arr.length;
	this->data = new T[this->capacity];

	for (int i = 0; i < this->length; i++)
		this->data[i] = copied_arr.data[i];
}


void DynamicArray::insertAtEnd(T elem)
{
	if (this->length == this->capacity)
		this->resize();
	this->data[this->length] = elem;
	this->length++;
}

void DynamicArray::removeLastElement()
{
	if (this->length > 0)
		this->length--;
}

int DynamicArray::getLength() const
{
	return this->length;
}

int DynamicArray::getCapacity() const
{
	return this->capacity;
}

void DynamicArray::resize()
{
	this->capacity = this->capacity * 2;
	T* newArray = new T[this->capacity];

	for (int i = 0; i < this->length; i++)
		newArray[i] = this->data[i];

	delete[] this->data;
	this->data = newArray;
}

std::ostream& operator << (std::ostream& out, const DynamicArray& d)
{
	for (int i = 0; i < d.length; i++)
		out << d.data[i] << " ";
	return out;
}

DynamicArray& DynamicArray::operator = (const DynamicArray& arr2)
{
	this->capacity = arr2.capacity;
	this->length = arr2.length;
	this->data = new T[this->capacity];

	for (int i = 0; i < this->length; i++)
		this->data[i] = arr2.data[i];

	return *this;
}

T& DynamicArray::operator[](int index)
{
	if (index < 0 || index >= this->length)
		throw std::exception();
	return this->data[index];
}