#include "NumberList.h"
#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[high]);
	return (i + 1);
}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int p = partition(a, low, high);

		quickSort(a, low, p - 1);
		quickSort(a, p + 1, high);
	}
}

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
	{
		return false;
	}

	this->numbers[count++] = x;
	return true;
}

void NumberList::Sort()
{
	quickSort(this->numbers, 0, count-1);
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << this->numbers[i] << " ";
	}
	cout << endl;
}

