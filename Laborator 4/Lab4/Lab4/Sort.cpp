#include <iostream>
#include "Sort.h"
#include <string>
#include <stdlib.h>
#include <list>
#include <stdarg.h>

using namespace std;

Sort::Sort(int min, int max, int nr_elem)
{
	int element;
	this->nr_elem = nr_elem;
	list<int>::iterator it;
	for (int i = 0; i < nr_elem; i++)
	{
		element = rand() % max + min;
		mylist.push_back(element);
	}

	cout << "List elements: ";
	for (it = mylist.begin(); it != mylist.end(); it++)
		cout << *it << " ";
	cout << endl;

}


Sort::Sort(int* vector, int nr_elem)
{
	this->nr_elem = nr_elem;
	for (int i = 0; i < nr_elem; i++)
		mylist.push_back(vector[i]);


	cout << "List elements: ";
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		cout << *it << " ";
	cout << endl;

}


Sort::Sort(int count, ...)
{
	this->nr_elem = count;
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
		mylist.push_back(va_arg(args, int));

	cout << "List elements: ";
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		cout << *it << " ";
	cout << endl;
}


Sort::Sort(string input)
{
	int i = 0, number;
	while (i < input.length())
	{
		number = 0;
		while (input[i] != ',' && i < input.length())
		{
			number = number * 10 + (int)input[i] - 48;
			i++;
		}
		mylist.push_back(number);
		i++;
	}

	cout << "List elements: ";
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		cout << *it << " ";
	cout << endl;

	this->nr_elem = mylist.size();
}


void Sort::InsertSort(bool)
{
	int key;
	int n = this->nr_elem;
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
	{
		int aux = *it;
		key = *it;
		list<int>::iterator j = --it;
		++it;

		while (j != mylist.begin() && *j > key)
		{
			*(++j) = *j;
			j--;
			j--;
		}
		*(++j) = key;
	}
}

void Sort::BubbleSort(bool)
{
	int i, j;
	for (i = 0; i< this->nr_elem-1; i++)
	{
		for (j = 0; j<this->nr_elem-i-1; j++)
		{
			if (GetElementFromIndex(j) > GetElementFromIndex(j + 1))
			{
				list<int>::iterator it = mylist.begin();
				list<int>::iterator it2 = mylist.begin();
				advance(it, j);
				advance(it2, j + 1); 

				int aux = GetElementFromIndex(j);
				mylist.insert(it, GetElementFromIndex(j + 1));
			}
		}
	}
}

void Sort::Print()
{
	cout << "Sorted: ";
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int Sort::GetElementsCount()
{
	cout << "The list has " << nr_elem << " elements." << endl;
	return this->nr_elem;
}

int Sort::GetElementFromIndex(int index)
{
	list<int>::iterator it = mylist.begin();
	advance(it, index - 1);
	cout << "The elem. at pos. " << index << " is: " << *it << endl;
	return *it;
}
