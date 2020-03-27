#pragma once
#include <string>
using namespace std;

enum WeatherConditions {
	rainy,
	sunny,
	snowy
};

class Car
{
protected:
	string carName;
	float fuelCapacity;
	float fuelConsumption;
	float avgSpeed;

public:
	virtual void move(WeatherConditions weather, int length) = 0;
	virtual float getAvgSpeed() = 0;
	virtual float getFuelCapacity() = 0;
	virtual string getCarName() = 0;
};
