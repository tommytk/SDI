
#include "Counter.h"

Counter::Counter()
{
	_aircraftType = "Helicopter";
	_aircraftSubType = "Counter";
	
}
Counter::Counter(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,std::string model, std::string manufacturer, std::string productionDate,std::string lastAirWorthinessCheck, std::string rotorType,int rotorBladesNumber,double rotorDiameter,int maximumVerticalClimbRate)
{
	_name = name;
	_aircraftType = "Helicopter";
	_aircraftSubType = "Counter";
	_callSig = sig;
	_serial = serial;
	 _owner = owner;
	 _model = model;
	 _manufacturer = manufacturer;
	 _productionDate = productionDate;
	 _lastAirWorthinessCheck = lastAirWorthinessCheck;
	 _rotorType = rotorType;
	 _rotorBladesNumber = rotorBladesNumber;
	 _rotorDiameter = rotorDiameter;
	 _maximumVerticalClimbRate = maximumVerticalClimbRate;
}
bool Counter::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<"\n The serial is:"<<_serial<<" \n Owner: "<<_owner<<"\n The model is: "<<_model<<"\n The manufacturer is: "<<_manufacturer<<"\n The production date is: "<<_productionDate<<" \n Maximum Speed"<<_maximumSpeed<<" \n Last air inspection"<<_lastAirWorthinessCheck<<"The max vertical climb rate is: "<<_maximumVerticalClimbRate <<std::endl;
	return true;
}
std::string Counter::aircraftToCSV()
{
	
	std::string data  = ""+ _aircraftType + "," +_aircraftSubType + "," + _name + "," +_callSig + "," + _serial + "," + _intToStr(_maximumSpeed) + "," + _owner + "," + _model + "," + _manufacturer + "," + _productionDate +"," + _lastAirWorthinessCheck +  "," + _rotorType +"," + _intToStr(_rotorBladesNumber) +"," + _dblToStr(_rotorDiameter) + "," +  _intToStr(_maximumVerticalClimbRate) + "";
	return data;
}