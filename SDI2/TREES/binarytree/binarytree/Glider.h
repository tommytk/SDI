#ifndef GLIDER_H
#define GLIDER_H
#include <iostream>
#include <string>
#include "FixedWing.h"

class Glider : public FixedWing
{
public:
	Glider();
	Glider(std::string name, std::string aircraftType, std::string aircraftSubType, std::string sig, std::string owner,int maximumSpeed, std::string lastAirInspection);
	bool printAircraft();
};
#endif