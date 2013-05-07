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
	Propeller(std::string name,std::string aircraftType,std::string aircraftSubType,std::string callSig,std::string serial,std::string owner,int maximumSpeed,std::string lastAirWorthinessCheck,int flightHours,int numberOfEngines, std::string propellerEngineCheck, int maximumClimbRate);
	bool printAircraft();
	void setFlightHours();
	void setNumberOfEngines();
	int flightHours();
	int numberOfEngines();
	void setPropellerEngineCheck(std::string propellerEngineCheck);
	std::string propellerEngineCheck();
protected:
		int _flightHours;
		int _maximumClimbRate;
		int _numberOfEngines;
		std::string _propellerEngineCheck;
};
#endif