#include "Propeller.h"


Propeller::Propeller()
{
	_aircraftType = "Fixed Wing";
	_aircraftSubType = "Propeller";
	_flightHours = 0;
	_numberOfEngines = 0;
}
Propeller::Propeller(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string owner,int maximumSpeed,std::string lastAirWorthinessCheck, int flightHours, int numberOfEngines)
{
	_name = name;
	 _aircraftType = "Fixed Wing";
	 _aircraftSubType = "Propeller";
	_callSig = sig;
	 _owner = owner;
	_maximumSpeed = maximumSpeed;
	 _lastAirWorthinessCheck = lastAirWorthinessCheck;
	 _flightHours = flightHours;
	 _numberOfEngines = numberOfEngines;

}
bool Propeller::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<" \n Owner: "<<_owner<<" \n Maximum Speed"<<_maximumSpeed<<" \n Last air inspection"<<_lastAirWorthinessCheck<< "\n The Number of Flight Hours are: "<<_flightHours<< "\n The number of Engines Are: "<<_numberOfEngines <<std::endl;
	return true;
}