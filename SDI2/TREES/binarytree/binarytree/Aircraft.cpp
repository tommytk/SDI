#include "Aircraft.h"
bool Aircraft::printAircraft()
{
	std::cout<<" Call Signature: "<<_callSig<<" Owner: "<<_owner<<"\n Maximum Speed"<<_maximumSpeed<<"Last air inspection"<<_lastAirWorthinessCheck<<std::endl;
	return true;
}
std::string Aircraft::aircraftToXML()
{
	std::string output = "";
	output.append("<Field _CallSignature>");
	output.append(_callSig);
	output.append("</Field>");
	output.append("<Field _aircraftName>");
	output.append(_name);
	output.append("</Field>");
	output.append("<Field _aircraftType>");
	output.append(_aircraftType);
	output.append("</Field>");
	output.append("<Field _aircraftSubType>");
	output.append(_aircraftSubType);
	output.append("</Field>");
	output.append("<Field _serial>");
	output.append(_serial);
	output.append("</Field>");
	output.append("<Field _maximumSpeed>");
	output.append(_intToStr(_maximumSpeed));
	output.append("</Field>");
	output.append("</Field>");
	output.append("<Field _model>");
	output.append(_model);
	output.append("</Field>");
	output.append("<Field _manafacturer>");
	output.append(_manufacturer);
	output.append("</Field>");
	output.append("<Field _productionDate>");
	output.append(_productionDate);
	output.append("</Field>");
	output.append("<Field _lastAirWorthinessCheck>");
	output.append(_lastAirWorthinessCheck);
	output.append("</Field>");
	return output;
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