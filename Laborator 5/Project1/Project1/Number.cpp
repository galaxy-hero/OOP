#include "Number.h"
#include <iostream>
#include <cstdlib>

using namespace std;
#pragma warning(disable:4996)

Number::Number(const char* value, int base)
{
	this->base = base;

	int aux = atoi(value);
	if (aux == 0)
	{
		this->char_count = 1;
		this->number[0] = '0';
		this->number[1] = 0;
	}
	else
	{
		this->char_count = 0;
		while (aux != 0)
		{
			this->number[this->char_count] = aux % 10 + '0';
			this->char_count++;
			aux /= 10;
		}
		this->number[this->char_count] = 0;
	}
}

Number::Number()
{
	this->char_count = 1;
	this->number[0] = '0';
	this->number[1] = 0;
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

	unsigned int pos = 0;
	while (auxNumber > 0)
	{
		int digit = auxNumber%newBase;

		if (digit >= 0 && digit <= 9)
			result[pos] = digit + '0';
		else
			result[pos] = digit - 10 + 'A';
		auxNumber = auxNumber / newBase;
		pos++;
	}
	this->char_count = pos;
	cout << result << endl;
	strcpy(this->number, result);
}

void Number::Print()
{
	int reverse = 0;
	int rest;
	int number = atoi(this->number);

	while (number != 0)
	{
		rest = number % 10;
		reverse = reverse * 10 + rest;
		number /= 10;
	}

	cout << reverse << endl;
}

int Number::GetDigitsCount()
{
	return this->char_count;
}

int Number::GetBase()
{
	return this->base;
}

Number Number::operator+(const Number & number)
{
	Number rez;
	int i = 0, transport = 0, actual = 0;
	while (i < this->char_count && i < number.char_count)
	{
		actual = this->number[i] - '0' + number.number[i] - '0' + transport;
		rez.number[i] = actual % 10 + '0';
		transport = actual / 10;
		++i;
	}
	if (i < this->char_count)
	{
		while (i < this->char_count)
		{
			actual = this->number[i] - '0' + transport;
			rez.number[i] = actual % 10 + '0';
			transport = actual / 10;
			++i;
		}
	}
	if (i < number.char_count)
	{
		while (i < number.char_count)
		{
			actual = number.number[i] - '0' + transport;
			rez.number[i] = actual % 10 + '0';
			transport = actual / 10;
			++i;
		}
	}
	while (transport)
	{
		rez.number[i] = transport % 10 + '0';
		transport /= 10;
		++i;
	}
	if (i >= 256)
	{
		cout << "Numar prea mare"<<endl;
	}
	rez.number[i] = 0;
	rez.char_count = i;
	return rez;
}


Number Number::operator*(const Number & number)
{
	int rezNumber[256];
	memset(rezNumber, 0, 255);
	for (int i = 0; i < this->char_count; ++i)
		for (int j = 0; j < number.char_count; ++j)
			rezNumber[i + j] = rezNumber[i + j] + (this->number[i] - '0') * (number.number[j] - '0');
	int transport = 0;
	for (int i = 0; i <= this->char_count + number.char_count - 1; ++i)
	{
		int aux = transport + rezNumber[i];
		rezNumber[i] = aux % 10;
		transport = aux / 10;
	}
	char c[256];
	for (int i = 0; i <= this->char_count + number.char_count - 1; ++i)
		c[i] = rezNumber[i] + '0';
	c[this->char_count + number.char_count] = 0;
	return Number(c, 2);
}


char Number::operator[](int index)
{
	if (index < 0 || index >= this->char_count)
		return 0;
	return this->number[index];
}

bool operator>(const Number & n1, const Number & n2)
{
	return (!((n1 < n2) && (n1 == n2)));
}

bool operator<(const Number & n1, const Number & n2)
{
	if (n1.char_count < n2.char_count)
		return 1;
	if (n1.char_count > n2.char_count)
		return 0;
	bool egale = true;
	for (int i = n1.char_count - 1; i >= 0; --i)
	{
		if (n1.number[i] > n2.number[i])
			return false;
		if (n1.number[i] > n2.number[i])
			egale = false;
	}
	return (!egale);
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
	if (n1.char_count != n2.char_count)
		return 0;
	for (int i = 0; i < n1.char_count; ++i)
		if (n1.number[i] != n2.number[i])
			return 0;
	return 1;
}
