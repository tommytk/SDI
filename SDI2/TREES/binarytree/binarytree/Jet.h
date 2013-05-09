#ifndef JET_H
#define JET_H
#include <iostream>
#include <string>

#include "Powered.h"


using namespace std;

class Jet : public Powered
{
public:
	Jet();
	Jet(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,std::string model,std::string manufacturer,std::string productionDate,int maximumSpeed,std::string lastAirWorthinessCheck, int flightHours, int numberOfEngines, std::string jetEngineCheck, int maximumClimbRate);
	bool printAircraft();
	std::string aircraftToCSV();
	
};
#endif