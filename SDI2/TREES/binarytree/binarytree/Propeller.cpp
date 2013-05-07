#include "Propeller.h"


Propeller::Propeller()
{
	_aircraftType = "Fixed Wing";
	_aircraftSubType = "Propeller";
	_flightHours = 0;
	_numberOfEngines = 0;
}
Propeller::Propeller(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,int maximumSpeed,std::string lastAirWorthinessCheck, int flightHours, int numberOfEngines, std::string propellerEngineCheck, int maximumClimbRate)
{
	_name = name;
	 _aircraftType = "Fixed Wing";
	 _aircraftSubType = "Propeller";
	_callSig = sig;
	_serial = serial;
	 _owner = owner;
	_maximumSpeed = maximumSpeed;
	 _lastAirWorthinessCheck = lastAirWorthinessCheck;
	 _flightHours = flightHours;
	 _numberOfEngines = numberOfEngines;
	 _propellerEngineCheck = propellerEngineCheck;
	 _maximumClimbRate = maximumClimbRate;

}
bool Propeller::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<"\n The serial is:"<<_serial<<" \n Owner: "<<_owner<<" \n Maximum Speed"<<_maximumSpeed<<" \n Last air inspection"<<_lastAirWorthinessCheck<< "\n The Number of Flight Hours are: "<<_flightHours<< "\n The number of Engines Are: "<<_numberOfEngines<< "\n The last engine check was: "<<_propellerEngineCheck<< "The max climb rate is: "<<_maximumClimbRate <<std::endl;
	return true;
}