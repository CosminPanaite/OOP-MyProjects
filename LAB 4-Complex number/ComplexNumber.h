#pragma once
class ComplexNumber
{
private:
	float real, imag;

public:
	ComplexNumber();
	ComplexNumber(float real, float imag);

	float getReal();
	void setReal(float real);
	float getImaginary();
	void setImaginary(float imag);

	bool operator == (const ComplexNumber& c2);
	ComplexNumber& operator + (const ComplexNumber& c2);
};

