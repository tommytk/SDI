#include "Glider.h"

Glider::Glider()
{
	
	_aircraftType = "Fixed Wing";
	_aircraftSubType = "Glider";
}

Glider::Glider(std::string name, std::string aircraftType, std::string aircraftSubType, std::string sig, std::string owner,int maximumSpeed, std::string lastAirInspection)
{
	

	
	 _name = name;
	 _aircraftType = "Fixed Wing";
	 _aircraftSubType = "Glider";
	_callSig = sig;
	 _owner = owner;
	_maximumSpeed = maximumSpeed;
	 _lastAirWorthinessCheck = lastAirInspection;
}


bool Glider::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<" \n Owner: "<<_owner<<" \n Maximum Speed"<<_maximumSpeed<<" \n Last air inspection"<<_lastAirWorthinessCheck<<std::endl;
	return true;
}