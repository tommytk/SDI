
#include "Counter.h"

Counter::Counter()
{
	_aircraftType = "Helicopter";
	_aircraftSubType = "Counter";
	_rotorType = "";
}
Counter::Counter(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string owner, std::string rotorType)
{
	_name = name;
	_aircraftType = "Helicopter";
	_aircraftSubType = "Counter";
	_callSig = sig;
	 _owner = owner;
	 _rotorType = rotorType;

}
bool Counter::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<" \n Owner: "<<_owner<<"\n The rotor type is: "<<_rotorType<<std::endl;
	return true;
}