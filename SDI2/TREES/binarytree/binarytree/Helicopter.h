#ifndef HELICOPTER_H
#define HELICOPTER_H
#include <iostream>
#include <string>
#include "Aircraft.h"

using namespace std;

class Helicopter : public Aircraft
{
public:
	/*bool printAircraft();*/
	//sets
	void setMaximumSpeed(int maximumSpeed);
	void setMaximumClimbRate(int maximumVerticalClimbRate);
	void setRotorDiameter(int rotorDiameter);
	void setRotorBladesNumber(int rotorBladesNumber);
	//gets
	int maximumSpeed();
	int maximumVerticalClimbRate();
	double rotorDiameter();
	int rotorBladesNumber();
protected:
	int _maximumSpeed;
	int _maximumVerticalClimbRate;
	double _rotorDiameter;
	int _rotorBladesNumber;
};
#endif