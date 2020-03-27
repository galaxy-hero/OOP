#pragma once

#include "Car.h"

class Maserati : public Car
{
public:
	Maserati();
	void move(WeatherConditions weather, int length) override;
	float getAvgSpeed() override;
	float getFuelCapacity() override;
	string getCarName() override;
};

