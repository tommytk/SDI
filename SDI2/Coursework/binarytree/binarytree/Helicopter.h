#ifndef HELICOPTER_H
#define HELICOPTER_H
#include <iostream>
#include <string>
#include "Aircraft.h"


class Helicopter : public Aircraft
{
public:
	Helicopter();
	//sets

	void setMaximumClimbRate(int maximumVerticalClimbRate);
	void setRotorDiameter(int rotorDiameter);
	void setRotorBladesNumber(int rotorBladesNumber);
	//gets
	int maximumVerticalClimbRate();
	double rotorDiameter();
	int rotorBladesNumber();
protected:

	int _maximumVerticalClimbRate;
	double _rotorDiameter;
	int _rotorBladesNumber;
};
#endif