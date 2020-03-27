#pragma once

class Number
{
private:
	char number[255];
	int base;
	int char_count;
public:
	Number(const char * value, int base); // where base is between 2 and 16
	Number();

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

	Number operator+(const Number& number);
	Number operator-(const Number& number);
	Number operator*(const Number& number);
	Number operatorNeg(const Number& number);
	char operator[](int index);
	friend bool operator >(const Number& n1, const Number& n2);
	friend bool operator <(const Number& n1, const Number& n2);
	friend bool operator >=(const Number& n1, const Number& n2);
	friend bool operator <=(const Number& n1, const Number& n2);
	friend bool operator ==(const Number& n1, const Number& n2);
};