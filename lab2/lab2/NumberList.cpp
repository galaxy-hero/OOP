#include "NumberList.h"
#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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
	quickSort(this->numbers, 0, count);
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << this->numbers[count] << " ";
	}
}

