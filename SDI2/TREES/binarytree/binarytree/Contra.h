#ifndef CONTRA_H
#define CONTRA_H
#include <iostream>
#include <string>

#include "Helicopter.h"


class Contra : public Helicopter
{
public:
	Contra();
	Contra(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner, std::string rotorType, int maximumVerticalClimbRate);
	void setRotarType(std::string rotarType);
	bool printAircraft();
	std::string rotorType();
protected:
		std::string _rotorType;
};
#endif