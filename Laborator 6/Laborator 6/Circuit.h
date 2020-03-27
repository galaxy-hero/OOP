#pragma once
#include "Car.h"
#define MAX_NO_CARS 10

class Circuit
{
private:
	int length;
	int carsNumber;
	WeatherConditions weather;
	Car* cars[MAX_NO_CARS];
	Car* finalCars[MAX_NO_CARS];
	int finalCarsNumber;
public:
	Circuit();
	void SetLength(int length);
	void SetWeather(WeatherConditions weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};