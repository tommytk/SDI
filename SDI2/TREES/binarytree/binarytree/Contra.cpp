#include "Contra.h"
Contra::Contra()
{
	_aircraftType = "Helicopter";
	_aircraftSubType = "Contra";
	_rotorType = "";
}
Contra::Contra(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string owner, std::string rotorType)
{
	_name = name;
	 /*_aircraftType = "Fixed Wing";
	 _aircraftSubType = "Jet";*/
	_callSig = sig;
	 _owner = owner;
	 _rotorType = rotorType;

}
bool Contra::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<" \n Owner: "<<_owner<<"\n The rotor type is: "<<_rotorType<<std::endl;
	return true;
}