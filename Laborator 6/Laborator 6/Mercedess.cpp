#include "Mercedess.h"
#include <string>

Mercedess::Mercedess() : Car()
{
	this->fuelCapacity = 1000; // liters
	this->fuelConsumption = 1.6; // liter per 1 km
	this->avgSpeed = 105; // km per hour
	this->carName = "Mercedess";
}

void Mercedess::move(WeatherConditions weather, int length)
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

	this->fuelCapacity = this->fuelCapacity - fuelConsumption * length;
}

float Mercedess::getAvgSpeed()
{
	return this->avgSpeed;
}

float Mercedess::getFuelCapacity()
{
	return this->fuelCapacity;
}

string Mercedess::getCarName()
{
	return this->carName;
}