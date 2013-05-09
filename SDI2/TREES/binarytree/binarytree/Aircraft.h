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

	virtual ~Aircraft() { };
	virtual bool printAircraft();
	virtual std::string aircraftToCSV();
	//Setters variables
	std::string getCallSig();
	void setName(std::string name);
	void setSerial(std::string serial);
	void setAircraftType(std::string aircraftType);
	void setAircraftSubType(std::string aircraftSubType);
	void setCallSig(std::string sig);
	void setOwner(std::string owner);
	void setRegNum(int serial);
	void setModel(std::string model);
	void setManufacturer(std::string manufacturer);
	void setProductionDate(std::string productionDate);
	void setMaximumSpeed(int maximumSpeed);
	void setlastAirWorthinessCheck(std::string lastAirWorthinessCheck);

	//Getters variables
	std::string name();
	std::string serial();
	std::string aircraftType();
	std::string aircraftSubType();
	std::string callSig();
	std::string owner();
	std::string model();
	std::string manufacturer();
	std::string productionDate();
	int maximumSpeed();
	std::string lastAirWorthinessCheck();

protected:
	std::string _name;
	std::string _serial;
	std::string _aircraftType;
	std::string _aircraftSubType;
	std::string _callSig;
	std::string _owner;
	std::string _model;
	std::string _manufacturer;
	std::string _productionDate;
	int _maximumSpeed;
	std::string _lastAirWorthinessCheck;
	std::string _intToStr(int number);
	std::string _dblToStr(double dbl);
};
#endif