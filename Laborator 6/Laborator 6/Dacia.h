#pragma once

#include "Car.h"

class Dacia : public Car
{
public:
	Dacia();
	void move(WeatherConditions weather, int length) override;
	float getAvgSpeed() override;
	float getFuelCapacity() override;
	string getCarName() override;
};

