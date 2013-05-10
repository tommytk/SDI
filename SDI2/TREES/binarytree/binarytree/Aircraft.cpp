#include "Aircraft.h"
bool Aircraft::printAircraft()
{
	std::cout<<"The Aircraft type is: "<<_aircraftType<<"\n The Aircraft Sub Type is: "<<_aircraftSubType<<"\n The name is: "<<_name <<"\n The Call Signature is : "<<_callSig<<"\n The serial is: "<<_serial <<"\n The Maximum Speed is: "<<_maximumSpeed<<" Owner: "<<_owner<<"\n The model is: "<<_model<<"\n The manufacturer is: "<<_manufacturer<<"\n The production date: "<<_productionDate<<"\n The last Air worthiness inspection was: "<<_lastAirWorthinessCheck<<std::endl;
	return true;
}
std::string Aircraft::aircraftToCSV()
{
	
	std::string data  = ""+ _aircraftType + "," +_aircraftSubType + "," + _name + "," +_callSig + "," + _serial + "," + _intToStr(_maximumSpeed) + "," + _owner + "," + _model + "," + _manufacturer + "," +_productionDate +"," + _lastAirWorthinessCheck + "";
	return data;
}

std::string Aircraft::getCallSig()
{
	return _callSig;
}
void Aircraft::setSerial(std::string serial)
{
	_serial = serial;
}
void Aircraft::setName(std::string name)
{
	_name = name;
}
void Aircraft::setAircraftType(std::string aircraftType)
{
	_aircraftType = aircraftType;
}
void Aircraft::setAircraftSubType(std::string aircraftSubType)
{
	_aircraftSubType = aircraftSubType;
}
void Aircraft::setCallSig(std::string sig)
{
	_callSig = sig;
}
void Aircraft::setOwner(std::string owner)
{
	_owner = owner;
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
void Aircraft::setlastAirWorthinessCheck(std::string lastAirWorthinessCheck)
{
	_lastAirWorthinessCheck = lastAirWorthinessCheck;
}
//Getters
std::string Aircraft::name()
{
	return _name;
}
std::string Aircraft::serial()
{
	return _serial;
}
std::string Aircraft::aircraftType()
{
	return _aircraftType;
}
std::string Aircraft::aircraftSubType()
{
	return _aircraftSubType;
}
std::string Aircraft::callSig()
{
	return _callSig;
}
std::string Aircraft::owner()
{
	return _owner;
}
std::string Aircraft::model()
{
	return _model;
}
std::string Aircraft::manufacturer()
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
std::string Aircraft::lastAirWorthinessCheck()
{
	return _lastAirWorthinessCheck;
}
std::string Aircraft::_intToStr(int number)//Might not need this function to convert from int to string
{
	std::stringstream stream;
	stream << number;
	return stream.str();
}
std::string Aircraft::_dblToStr(double dbl)
{
	std::ostringstream strs;
strs << dbl;
std::string str = strs.str();
return str;
}