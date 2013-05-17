#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
#include <string>
#include "Counter.h"
#include "Helicopter.h"

class Counter : public Helicopter
{
public:
	Counter();
	Counter(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,std::string model, std::string manufacturer, std::string productionDate,std::string lastAirWorthinessCheck, std::string rotorType,int rotorBladesNumber,double rotorDiameter,int maximumVerticalClimbRate);
	void setRotarType(std::string rotarType);
	bool printAircraft();
	std::string aircraftToCSV();
	std::string rotorType();
protected:
		std::string _rotorType;
		
};
#endif