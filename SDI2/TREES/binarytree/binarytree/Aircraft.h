#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <iostream>
#include <string>
#include <sstream>
//Class is created upon the theory of private member variables and the use of getters and setters to change or access them.
//This means the varibales can't be accessed directly.
class Aircraft
{
public:
	//Setters variables
	std::string getCallSig();
	void setCallSig(std::string sig);
	void setOwner(std::string owner);
	void setRegNum(int serial);
	void setModel(std::string model);
	void setManufacturer(std::string manufacturer);
	void setProductionDate(std::string productionDate);
	void setMaximumSpeed(int maximumSpeed);
	void setLastAirInspection(std::string lastAirInspection);

	//Getters variables
	std::string callsig();
	std::string owner();
	int regNum();
	std::string model();
	std::string manafacturer();
	std::string productionDate();
	int maximumSpeed();
	std::string lastAirInspection();

private:

	std::string _callSig;
	std::string _owner;
	int _regNum;
	std::string _model;
	std::string _manufacturer;	
	std::string _productionDate;
	int _maximumSpeed;
	std::string _lastAirInspection;
		std::string _intToStr(int number);
};
#endif