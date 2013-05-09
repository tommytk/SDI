#ifndef PROPELLER_H
#define PROPELLER_H
#include <iostream>
#include <string>
#include "Powered.h"

using namespace std;

class Propeller : public Powered
{
public:
	Propeller();
	Propeller(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,std::string model,std::string manufacturer,std::string productionDate,int maximumSpeed,std::string lastAirWorthinessCheck, int flightHours, int numberOfEngines, std::string lastEngineCheck, int maximumClimbRate);
	bool printAircraft();
	std::string aircraftToCSV();
protected:

};
#endif