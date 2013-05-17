#ifndef GLIDER_H
#define GLIDER_H
#include <iostream>
#include <string>
#include "NonPowered.h"

class Glider : public NonPowered
{
public:
	Glider();
	Glider(std::string name, std::string aircraftType, std::string aircraftSubType, std::string sig,std::string serial, std::string owner,int maximumSpeed,std::string model,std::string manufacturer,std::string productionDate,std::string lastAirInspection);
	bool printAircraft();
	std::string aircraftToCSV();

};
#endif