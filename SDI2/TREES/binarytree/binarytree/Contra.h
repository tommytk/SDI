#ifndef CONTRA_H
#define CONTRA_H
#include <iostream>
#include <string>

#include "Helicopter.h"


class Contra : public Helicopter
{
public:
	Contra();
	Contra(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,std::string model, std::string manufacturer, std::string productionDate,std::string lastAirWorthinessCheck, std::string rotorType,int rotorBladesNumber,double rotorDiameter,int maximumVerticalClimbRate);
	std::string aircraftToCSV();
	bool printAircraft();
	
protected:
		std::string _rotorType;
};
#endif