#include "Maserati.h"
#include <string>

Maserati::Maserati() : Car()
{
	this->fuelCapacity = 100; // liters
	this->fuelConsumption = 0.95; // liter per 1 km
	this->avgSpeed = 150; // km per hour
	this->carName = "Maserati";
}

void Maserati::move(WeatherConditions weather, int length)
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

float Maserati::getAvgSpeed()
{
	return this->avgSpeed;
}

float Maserati::getFuelCapacity()
{
	return this->fuelCapacity;
}

string Maserati::getCarName()
{
	return this->carName;
}