// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int convert(char* str)
{
	int index, sign, pos, n = 0;

	if (str[0] == -1)
	{
		sign = -1;
	}
	else
		sign = 1;

	if (sign == -1)
		pos = 1;
	else
		pos = 0;

	for (index = pos; str[index] != '\0'; index++)
	{
		int aux = (int)str[index];
		n = n * 10 + str[index] - '0';
	}

	if (sign == -1)
	{
		n = -n;
	}

	printf("The number: %i\n", n);
	return n;
}

int main()
{
	FILE* fileptr;
	char line[50];
	int sum = 0;

	fileptr = fopen("in.txt", "r");

	if (fileptr == NULL)
	{
		printf("Error, could not read from file.\n");
	}
	while (fgets(line, sizeof line, fileptr) != NULL)
	{
		line[strlen(line) - 1] = '\0';
		printf("the line: %s\n", line);
		int number = convert(line);
		sum += number;
	}

	printf("Sum is: %i", sum);
}