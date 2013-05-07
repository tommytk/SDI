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
	Jet(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,int maximumSpeed,std::string lastAirWorthinessCheck, int flightHours, int numberOfEngines, std::string jetEngineCheck, int maximumClimbRate);
		bool printAircraft();
	void setFlightHours(int flightHours);
	void setNumberOfEngines(int numberOfHours);
	void jetEngineCheck(std::string jetEngineCheck);
	int flightHours();
	int numberOfEngines();
	std::string jetEngineCheck();
protected:
		int _flightHours;
		int _numberOfEngines;
		int _maximumClimbRate;
		std::string _jetEngineCheck;
};
#endif