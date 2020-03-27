#include "Dacia.h"
#include <string>

Dacia::Dacia() : Car()
{
	this->fuelCapacity = 80; // liters
	this->fuelConsumption = 0.9; // liter per 1 km
	this->avgSpeed = 80; // km per hour
	this->carName = "Dacia";
}

void Dacia::move(WeatherConditions weather, int length)
{
	switch (weather)
	{
	case rainy:
		this->avgSpeed = this->avgSpeed * 0.8;
		break;
	case snowy:
		this->avgSpeed = this->avgSpeed * 0.6;
		break;
	case sunny:
		this->avgSpeed = this->avgSpeed;
		break;
	}

	fuelCapacity = fuelCapacity - fuelConsumption * length;
}

float Dacia::getAvgSpeed()
{
	return this->avgSpeed;
}

float Dacia::getFuelCapacity()
{
	return this->fuelCapacity;
}

string Dacia::getCarName()
{
	return this->carName;
}