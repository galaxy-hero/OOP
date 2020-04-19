#include "Number.h"
#include <iostream>
#include <cstdlib>

using namespace std;
#pragma warning(disable:4996)

Number::Number(const char* value, int base)
{
	this->base = base;

	strcpy(this->number, value);
}

Number::Number()
{
	this->number[0] = '\0';
}

Number::Number(int n)
{
	char result[255];
	itoa(n, this->number, 10);

	this->base = 10;
}

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

// Utility function to reverse a string 
void strev(char *str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int toDeci(const char *str, int base)
{
	int len = strlen(str);
	int power = 1; // Initialize power of base 
	int num = 0;  // Initialize result 
	int i;

	// Decimal equivalent is str[len-1]*1 + 
	// str[len-1]*base + str[len-1]*(base^2) + ... 
	for (i = len - 1; i >= 0; i--)
	{
		// A digit in input number must be 
		// less than number's base 
		if (val(str[i]) >= base)
		{
			printf("Invalid Number");
			return -1;
		}

		num += val(str[i]) * power;
		power = power * base;
	}

	return num;
}

char* fromDeci(char res[], int base, int inputNum)
{
	int index = 0;  // Initialize index of result 

	// Convert input number is given base by repeatedly 
	// dividing it by base and taking remainder 
	while (inputNum > 0)
	{
		res[index++] = reVal(inputNum % base);
		inputNum /= base;
	}
	res[index] = '\0';

	// Reverse the result 
	strev(res);

	return res;
}

void Number::SwitchBase(int newBase)
{
	char result[255];
	int auxNumber = atoi(this->number);

	if (newBase < 2 || newBase > 16)
		cout << ("Wrong base!")<<endl;

	if (auxNumber == 0)
	{
		result[0] = '0';
		result[1] = 0;
	}

	if (auxNumber < 0)
	{
		result[0] = 0;
		cout << "Negative number" << endl;
	}

	if (this->base == 10 && newBase != 10)
	{
		fromDeci(result, newBase, atoi(this->number));
		strcpy(this->number, result);
	}
	else if (this->base != 10 && newBase == 10)
	{
		int tmp = toDeci(this->number, this->base);
		itoa(tmp, this->number, 10);
	}
	else if (this->base != 10 && newBase != 10)
	{
		int tmp = toDeci(this->number, this->base);
		fromDeci(this->number, newBase, tmp);
	}

	this->base = newBase;
}

void Number::Print()
{
	cout << this->number << endl;
}

int Number::GetDigitsCount()
{
	return strlen(this->number);
}

int Number::GetBase()
{
	return this->base;
}

Number operator+(const Number& n1, const Number& n2)
{
	int maxbase = n1.base > n2.base ? n1.base : n2.base;

	int tmp = toDeci(n1.number, n1.base) + toDeci(n2.number, n2.base);
	char result[255];
	itoa(tmp, result, 10);
	Number n(result, 10);
	n.SwitchBase(maxbase);
	return n;
}

Number operator-(const Number& n1, const Number& n2)
{
	int maxbase = n1.base > n2.base ? n1.base : n2.base;

	int tmp = toDeci(n1.number, n1.base) - toDeci(n2.number, n2.base);
	char result[255];
	itoa(tmp, result, 10);
	Number n(result, 10);
	n.SwitchBase(maxbase);
	return n;
}

Number Number::operator*(const Number & number)
{
	int maxbase = this->base > number.base ? this->base : number.base;

	int tmp = toDeci(this->number, this->base) * toDeci(number.number, number.base);
	char result[255];
	itoa(tmp, result, 10);
	Number n(result, 10);
	n.SwitchBase(maxbase);
	return n;
}



char Number::operator[](int index)
{
	if (index < 0 || index >= this->GetDigitsCount())
		return 0;
	return this->number[index];
}

bool operator>(const Number & n1, const Number & n2)
{
	return (!((n1 < n2) && (n1 == n2)));
}

bool operator<(const Number & n1, const Number & n2)
{
	return toDeci(n1.number, n1.base) < toDeci(n2.number, n2.base);
}

bool operator>=(const Number & n1, const Number & n2)
{
	return (!(n1 < n2));
}

bool operator<=(const Number & n1, const Number & n2)
{
	return(!(n1 > n2));
}

bool operator==(const Number & n1, const Number & n2)
{
	return toDeci(n1.number, n1.base) == toDeci(n2.number, n2.base);
}

Number& Number::operator--()
{
	for (unsigned i = 0; i < this->GetDigitsCount() - 1; i++)
	{
		this->number[i] = this->number[i + 1];
	}
	this->number[this->GetDigitsCount() - 1] = 0;
	return *this;
}

Number Number::operator--(int)
{
	this->number[this->GetDigitsCount() - 1] = '\0';
	return *this;
}

Number Number::operator=(const char* n)
{
	strcpy(this->number, n);

	if (this->base != 0)
	{
		this->SwitchBase(this->base);
	}
	else
	{
		this->base = 10;
	}

	return *this;
}

Number& Number::operator+=(const Number& n)
{
	int maxbase = this->base > n.base ? this->base : n.base;

	int tmp = toDeci(this->number, this->base) + toDeci(n.number, n.base);
	char result[255];
	itoa(tmp, result, 10);
	strcpy(this->number, result);
	this->SwitchBase(maxbase);
	return *this;
}
