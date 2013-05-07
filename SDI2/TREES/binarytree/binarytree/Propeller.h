#ifndef PROPELLER_H
#define PROPELLER_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "FixedWing.h"

using namespace std;

class Propeller : public FixedWing
{
public:
	Propeller();
	Propeller(std::string name,std::string aircraftType,std::string aircraftSubType,std::string callSig,std::string owner,int maximumSpeed,std::string lastAirWorthinessCheck,int flightHours,int numberOfEngines);
	bool printAircraft();
	void setFlightHours();
	void setNumberOfEngines();
	int flightHours();
	int numberOfEngines();

protected:
		int _flightHours;
		int _numberOfEngines;
};
#endif