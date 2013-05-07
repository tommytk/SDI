#ifndef JET_H
#define JET_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "FixedWing.h"

using namespace std;

class Jet : public FixedWing
{
public:
	Jet();
	Jet(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string owner,int maximumSpeed,std::string lastAirWorthinessCheck, int flightHours, int numberOfEngines);
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