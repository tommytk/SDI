
#include "Counter.h"

Counter::Counter()
{
	_aircraftType = "Helicopter";
	_aircraftSubType = "Counter";
	_rotorType = "";
}
Counter::Counter(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner, std::string rotorType,int maximumVerticalClimbRate)
{
	_name = name;
	_aircraftType = "Helicopter";
	_aircraftSubType = "Counter";
	_callSig = sig;
	_serial = serial;
	 _owner = owner;
	 _rotorType = rotorType;
	 _maximumVerticalClimbRate = maximumVerticalClimbRate;
}
bool Counter::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<"\n The serial is:"<<_serial<<" \n Owner: "<<_owner<<" \n Maximum Speed"<<_maximumSpeed<<" \n Last air inspection"<<_lastAirWorthinessCheck<<"The max vertical climb rate is: "<<_maximumVerticalClimbRate <<std::endl;
	return true;
}