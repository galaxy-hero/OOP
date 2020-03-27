#pragma once
#include "Car.h"

class Audi : public Car
{
public:
	Audi();
	void move(WeatherConditions weather, int length) override;
	float getAvgSpeed() override;
	float getFuelCapacity() override;
	string getCarName() override;
};
