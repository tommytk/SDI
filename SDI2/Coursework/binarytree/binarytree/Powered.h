#ifndef POWERED_H
#define POWERED_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "FixedWing.h"

using namespace std;

class Powered : public FixedWing
{
public:
	Powered();
	void setFlightHours(int flightHours);
	void setNumberOfEngines(int numberOfEngines);
	void setJetEngineCheck(std::string lastEngineCheck);
	void setMaximumClimbRate(int maximumClimbRate);
	int flightHours();
	int maximumClimbRate();
	int numberOfEngines();
	std::string jetEngineCheck();
protected:
		int _numberOfEngines;
		int _flightHours;
		std::string _lastEngineCheck;
		int _maximumClimbRate;
};
#endif