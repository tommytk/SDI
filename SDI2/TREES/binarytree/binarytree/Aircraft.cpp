#include "Aircraft.h"

std::string Aircraft::getCallSig()
{
	return _callSig;
}
void Aircraft::setCallSig(std::string sig)
{
	_callSig = sig;
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
//Getters
std::string Aircraft::callsig()
{
	return _callSig;
}
std::string Aircraft::owner()
{
	return _owner;
}
int Aircraft::regNum()
{
	return _regNum;
}
std::string Aircraft::model()
{
	return _model;
}
std::string Aircraft::manafacturer()
{
	return _manufacturer;
}
std::string Aircraft::productionDate()
{
	return _productionDate;
}
int Aircraft::maximumSpeed()
{
	return _maximumSpeed;
}
std::string Aircraft::lastAirInspection()
{
	return _lastAirInspection;
}
std::string Aircraft::_intToStr(int number)//Might not need this function to convert from int to string
{
	std::stringstream stream;
	stream << number;
	return stream.str();
}