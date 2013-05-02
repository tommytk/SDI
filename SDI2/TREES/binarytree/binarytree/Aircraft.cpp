#include "Aircraft.h"

int Aircraft::getCallSig()
{
	return _callSig;
}
void Aircraft::setCallSig(std::string sig)
{
	_callSig = sig
}
void Aircraft::setOwner(std::string owner)
{
	_owner = owner;
}
void Aircraft::setRegNum(int regNum)
{
	_regNum = regNum
}
void Aircraft::setModel(std::string model)
{
	_model = model;
}
void Aircraft::setManufacturer(std::string manufacturer)
{
	_manufacturer = manufacturer;
}
void Aircraft::setProductionDate(std::string productionDate)
{
	_productionDate = productionDate;
}
void Aircraft::setMaximumSpeed(int maximumSpeed)
{
	_maximumSpeed = maximumSpeed;
}
void Aircraft::setLastAirInspection(std::string lastAirInspection)
{
	_lastAirInspection = lastAirInspection;
}