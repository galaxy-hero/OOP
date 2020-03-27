#pragma once
#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	//Sort s = { new int[3]{3,2,1},3 };

	Sort s1(4, 10, 5);
	//s1.InsertSort(false);
	//s1.Print();

	int vect[5] = { 4, 2, 7, 1 };
	Sort s2(vect, 4);
	s2.GetElementFromIndex(3);


	Sort s3(5, 1, 8, 5, 9, 20);

	Sort s4("6,10,5,2,8,55,66,77");
	s4.GetElementsCount();



	int n;
	cin >> n;
	return 0;
}