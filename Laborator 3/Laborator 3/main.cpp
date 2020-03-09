#include "Math.h"
#include "Canvas.h"
#include <iostream>

using namespace std;
#pragma warning(disable:4996)

void main()
{
	// ------------- MATH

	int x = 2, y = 3, z = 4, n;
	double a = 2.73, b = 6.54321, c = 9.325;
	const char* s1 = "aaa";
	const char* s2 = "bbbbbbb";
	Math m;

	cout << m.Add(x, y) << endl;
	cout << m.Add(x, y, z) << endl;
	cout << m.Add(a, b) << endl;
	cout << m.Add(a, b, c) << endl;;
	cout << m.Mul(a, b) << endl;;
	cout << m.Mul(a, b, c) << endl;
	cout << m.Mul(x, y) << endl;
	cout << m.Mul(x, y, z) << endl;
	cout << m.Add(5, 1,2,3,4,5) << endl;
	m.Add(s1, s2);

	// -------------- CANVAS

	Canvas canvas(20,20);

	canvas.DrawCircle(10, 10, 3, 'a');
	canvas.FillCircle(10, 10, 3, 'b');
	canvas.Print();

	canvas.Clear();
	canvas.DrawRect(2,3,10,12, 'f');
	canvas.FillRect(2,3,10,12, 'u');
	canvas.Print();

	canvas.Clear();
	canvas.SetPoint(10, 10, 'a');
	canvas.Print();

	canvas.Clear();
	canvas.DrawLine(1, 2, 10, 11, 'd');
	canvas.Print();

	cin >> n;
}