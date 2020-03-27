#include "BMW.h"
#include <string>

BMW::BMW() : Car()
{
	this->fuelCapacity = 1000; // liters
	this->fuelConsumption = 1.6; // liter per 1 km
	this->avgSpeed = 98; // km per hour
	this->carName = "BMW";
}

void BMW::move(WeatherConditions weather, int length)
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

float BMW::getAvgSpeed()
{
	return this->avgSpeed;
}

float BMW::getFuelCapacity()
{
	return this->fuelCapacity;
}

string BMW::getCarName()
{
	return this->carName;
}