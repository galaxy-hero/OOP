#include <iostream>
#include "Vector.h"

using namespace std;

float operator ""_Kelvin(unsigned long long kelvin) {
	return kelvin - 273.15f;
}

float operator ""_Fahrenheit(unsigned long long fahrenheit) {
	return (fahrenheit - 32) * 0.55f;
}

bool testGreater(const int& a, const int& b) {
	return a > b;
}

bool testDivisible(const int& a, const int& b) {
	return a % b == 0;
}
int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;

	cout << a << endl << b << endl << endl;

	Vector<int> test(2);
	test.push(2);
	test.push(10);
	test.push(13);
	test.push(8);
	test.push(125);
	test.sort(testGreater);
	test.print();
	test.sort();
	test.print();
	test.set(3, 0);
	test.insert(1, 0);
	test.print();

	cout << "Element 3: " << test.get(2) << endl;
	cout << "Last element: " << test.pop() << endl;
	cout << "After removing first: ";
	test.remove(0);
	test.print();
	cout << "Total elements: " << test.count() << endl;
	cout << "First equal to 300 (should pe -1): " << test.firstIndexOf(300) << endl;
	cout << "First equal to 10: " << test.firstIndexOf(10) << endl;
	cout << "First element divisible with 169: " << test.firstIndexOf(169, testDivisible) << endl;

	int n;
	cin >> n;

	return 0;
}