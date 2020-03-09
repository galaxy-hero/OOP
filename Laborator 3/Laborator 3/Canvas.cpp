#include "Canvas.h"
#include <iostream>
#include <math.h>

using namespace std;


Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->canvas = new char*[width];
	int i, j;
	for (i = 0; i < width; i++)
	{
		canvas[i] = new char[height];
		for (j = 0; j < height; j++)
			canvas[i][j] = ' ';
	}

}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (ray > width / 2 || ray > height / 2 || ray > x || ray > y || ray + x > width || ray + y > height)
		cout << "Coordonate incorecte\n";

	else {
		int i, j;
		for (i = 0; i < width; i++)
			for (j = 0; j < height; j++)
				if (round(sqrt(((i - x)*(i - x) + (j - y)*(j - y)))) == ray)
					this->canvas[i][j] = ch;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (ray > width / 2 || ray > height / 2 || ray > x || ray > y || ray + x > width || ray + y > height)
		cout << "Coordonate incorecte\n";
	else {
		int i, j;
		for (i = 0; i < width; i++)
			for (j = 0; j < height; j++)
				if (round(sqrt(((i - x)*(i - x) + (j - y)*(j - y)))) < ray)
					this->canvas[i][j] = ch;
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || top < 0 || left >= right || top >= bottom || right > width || bottom > height)
		cout << "Coordonate incorecte\n";
	else
	{
		for (int i = left; i <= right; i++)
		{
			canvas[top][i] = ch;
			canvas[bottom][i] = ch;
		}
		for (int i = top; i <= bottom; i++)
		{
			canvas[i][left] = ch;
			canvas[i][right] = ch;
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || top < 0 || left >= right || top >= bottom || right > width || bottom > height)
		cout << "Coordonate incorecte\n";
	else
	{
		for (int i = left + 1; i < right; i++)
		{
			for (int j = top + 1; j < bottom; j++)
			{
				canvas[j][i] = ch;
			}
		}
	}
}


void Canvas::SetPoint(int x, int y, char ch)
{
	if (x < 0 || x > width || y < 0 || y > height)
		cout << "Coordonate incorecte\n";
	else
		canvas[x][y] = ch;
}


void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (x1 < 0 || y1 < 0 || x1 >= x2 || y1 >= y2 || x2 > width || y2 > height)
		cout << "Coordonatele incorecte\n";
	else
	{
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				if ((float)(j - y1) / (y1 - y2) == (float)(i - x1) / (x1 - x2))
					canvas[i][j] = ch;

	}

}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			cout << canvas[i][j] << " ";
		cout << endl;
	}
}


void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			canvas[i][j] = ' ';
}
