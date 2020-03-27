#include "Audi.h"
#include <string>

Audi::Audi() : Car()
{
	this->fuelCapacity = 1000; // liters
	this->fuelConsumption = 1.2; // liter per 1 km
	this->avgSpeed = 100; // km per hour
	this->carName = "Audi";
}

void Audi::move(WeatherConditions weather, int length)
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

float Audi::getAvgSpeed()
{
	return this->avgSpeed;
}

float Audi::getFuelCapacity()
{
	return this->fuelCapacity;
}

string Audi::getCarName()
{
	return this->carName;
}