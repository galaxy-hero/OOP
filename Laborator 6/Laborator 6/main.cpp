#pragma once
#include <iostream>

#include "Car.h"
#include "Circuit.h"
#include "Audi.h"
#include "BMW.h"
#include "Maserati.h"
#include "Mercedess.h"
#include "Dacia.h"

using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(WeatherConditions::sunny);
	c.AddCar(new Dacia());
	c.AddCar(new Maserati());
	c.AddCar(new Mercedess());
	c.AddCar(new Audi());
	c.AddCar(new BMW());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	
	int n;
	cin >> n;

	return 0;
}
