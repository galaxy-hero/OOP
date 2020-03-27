#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

class Sort
{
	list<int> mylist;
	int nr_elem;
public:
	Sort(int min, int max, int nr_elem);
	// Sort() {};
	Sort(int* vector, int nr_elem);
	Sort(int va_args, ...);
	Sort(string input);
	void InsertSort(bool reverse = false);
	void QuickSort(bool reverse = false);
	void BubbleSort (bool reverse=false); 
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};