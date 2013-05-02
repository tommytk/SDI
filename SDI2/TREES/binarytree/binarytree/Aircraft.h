#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <iostream>
#include <string>

using namespace std;

class Aircraft
{
public:
	int getCallSig();
	void setCallSig(std::string sig);
	void setOwner(std::string owner);
	void setRegNum(int serial);
	void setModel(std::string model);
	void setManufacturer(std::string manufacturer);
	void setProductionDate(std::string productionDate);
	void setMaximumSpeed(int maximumSpeed);
	void setLastAirInspection(std::string lastAirInspection);

private:
	int _callSig;
	string _owner;
	int _regNum;
	string _model;
	string _manufacturer;	
	string _productionDate;
	int _maximumSpeed;
	string _lastAirInspection
};
#endif