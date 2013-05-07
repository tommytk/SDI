#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
#include <string>
#include "Helicopter.h"


class Counter : public Helicopter
{
public:
	Counter();
	Counter(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string owner, std::string rotorType);
	void setRotarType(std::string rotarType);
	bool printAircraft();
	std::string rotorType();
protected:
		std::string _rotorType;
};
#endif