#include "ComplexNumber.h"

ComplexNumber::ComplexNumber()
{
	this->real = 0;
	this->imag = 0;
}
ComplexNumber::ComplexNumber(float real, float imag)
{
	this->real = real;
	this->imag = imag;
}

float ComplexNumber::getReal()
{
	return this->real;
}
void ComplexNumber::setReal(float real)
{
	this->real = real;
}

float ComplexNumber::getImaginary()
{
	return this->real;
}
void ComplexNumber::setImaginary(float imag)
{
	this->imag = imag;
}

bool ComplexNumber::operator == (const ComplexNumber& c2)
{
	return this->real == c2.real && this->imag == c2.imag;
}

ComplexNumber& ComplexNumber::operator + (const ComplexNumber& c2)
{
	ComplexNumber result(this->real + c2.real, this->imag + c2.imag);
	return result;
}