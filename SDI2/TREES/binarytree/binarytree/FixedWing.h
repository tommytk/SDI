#ifndef FIXEDWING_H
#define FIXEDWING_H
#include <iostream>
#include <string>
#include "Aircraft.h"
using namespace std;

class  FixedWing : public Aircraft
{
public:
	bool printAircraft();
	//sets
	void setWingSpan(float wingSpan);
	void setMaximumSpeed(int maximumSpeed);
	void setMinimumSpeed(int minimumSpeed);
	void setMaximumClimbRate(int maximumClimbRate);
	//gets
	float wingSpan();
	int maximumSpeed();
	int minimumSpeed();
	int maximumClimbRate();
protected:
		float _wingSpan;
		int _minimumSpeed;
		
};
#endif