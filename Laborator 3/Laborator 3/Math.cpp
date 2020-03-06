#pragma once

#include "Math.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstring>

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	double rez = x + y;
	return int(rez);
}

int Math::Add(double x, double y, double  z)
{
	double rez = x + y + z;
	return int(rez);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	double rez = x * y;
	return int(rez);
}

int Math::Mul(double x, double y, double z)
{
	double rez = x * y * z;
	return int(rez);
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list ap;
	int i;

	va_start(ap, count);
	for (i = 0; i < count; i++) {
		sum += va_arg(ap, int);
	}
	va_end(ap);

	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	char buffer[256];
	strncpy(buffer, s1, sizeof(buffer));
	strncpy(buffer, s2, sizeof(buffer));

	return buffer;
}