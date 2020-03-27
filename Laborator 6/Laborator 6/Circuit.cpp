#pragma once

#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	this->carsNumber = 0;
}

void Circuit::SetLength(int length)
{
	this->length = length;
}

void Circuit::SetWeather(WeatherConditions weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	if (carsNumber == MAX_NO_CARS) return;

	cars[carsNumber++] = car;
}

void Circuit::Race()
{
	for (int i = 0; i < this->carsNumber; i++)
	{
		this->cars[i]->move(this->weather, this->length);
	}

	int j = 0;
	for (int i = 0; i < this->carsNumber; i++)
	{
		if (this->cars[i]->getFuelCapacity() > 0)
		{
			cout << "Masina " << this->cars[i]->getCarName() << " a mai ramas cu " << this->cars[i]->getFuelCapacity() << " fuel" << endl;
			this->finalCars[j] = this->cars[i];
			j++;
		}
	}
	this->finalCarsNumber = j;
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < this->carsNumber; i++)
	{
		if (this->cars[i]->getFuelCapacity() <= 0)
		{
			cout << "Masina " << this->cars[i]->getCarName() << " nu a terminat cursa bc it sucks." << endl;
		}
	}
}

void Circuit::ShowFinalRanks()
{
	int i, j;

	for (i = 0; i < this->finalCarsNumber - 1; i++)
	{
		for (j = 0; j < this->finalCarsNumber - i - 1; j++)
		{
			if (this->finalCars[j]->getAvgSpeed() < this->finalCars[j + 1]->getAvgSpeed())
			{
				Car* aux = this->finalCars[j];
				this->finalCars[j] = this->finalCars[j + 1];
				this->finalCars[j + 1] = aux;
			}
		}
	}

	for (i = 0; i < this->finalCarsNumber; i++)
	{
		cout << "Pe locul " << i + 1 << " se afla masina " << this->finalCars[i]->getCarName() << endl;
	}
}