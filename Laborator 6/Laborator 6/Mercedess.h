#pragma once

#include "Car.h"

class Mercedess : public Car
{
public:
	Mercedess();
	void move(WeatherConditions weather, int length) override;
	float getAvgSpeed() override;
	float getFuelCapacity() override;
	string getCarName() override;
};
