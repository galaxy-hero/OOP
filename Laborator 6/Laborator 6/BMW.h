#pragma once

#include "Car.h"

class BMW : public Car
{
public:
	BMW();
	void move(WeatherConditions weather, int length) override;
	float getAvgSpeed() override;
	float getFuelCapacity() override;
	string getCarName() override;
};

