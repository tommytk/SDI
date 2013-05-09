#include "Propeller.h"


Propeller::Propeller()
{
	_aircraftType = "Fixed Wing";
	_aircraftSubType = "Propeller";
	_flightHours = 0;
	_numberOfEngines = 0;
}
Propeller::Propeller(std::string name, std::string aircraftType,std::string aircraftSubType,std::string sig,std::string serial,std::string owner,std::string model,std::string manufacturer,std::string productionDate,int maximumSpeed,std::string lastAirWorthinessCheck, int flightHours, int numberOfEngines, std::string lastEngineCheck, int maximumClimbRate)
{
		_name = name;
	 _aircraftType = "Fixed Wing";
	 _aircraftSubType = "Propeller";
	_callSig = sig;
	_serial = serial;
	 _owner = owner;
	_model = model;
	_manufacturer = manufacturer;
	_productionDate = productionDate;
	 _maximumSpeed = maximumSpeed;
	 _lastAirWorthinessCheck = lastAirWorthinessCheck;
	 _flightHours = flightHours;
	 _numberOfEngines = numberOfEngines;
	 _lastEngineCheck = lastEngineCheck;
	 _maximumClimbRate = maximumClimbRate;

}
bool Propeller::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<"\n The serial is:"<<_serial<<" \n Owner: "<<_owner<<" \n Maximum Speed"<<_maximumSpeed<<"\n The model of the Aircraft is: "<<_model <<"\n The manufacturer is: "<<_manufacturer<<"\n The Production Date is: "<<_productionDate<<" \n Last air inspection"<<_lastAirWorthinessCheck<< "\n The Number of Flight Hours are: "<<_flightHours<< "\n The number of Engines Are: "<<_numberOfEngines<< "\n The last engine check was: "<< _lastEngineCheck<< "The max climb rate is: "<<_maximumClimbRate <<std::endl;
	return true;
}
std::string Propeller::aircraftToCSV()
{
	
	std::string data  = ""+ _aircraftType + "," +_aircraftSubType + "," + _name + "," +_callSig + "," + _serial + "," + _intToStr(_maximumSpeed) + "," + _owner + "," + _model + "," + _manufacturer + "," + _productionDate + "," + _lastAirWorthinessCheck + ","+ _intToStr(_flightHours) +"," + _intToStr(_numberOfEngines) + "," + _lastEngineCheck + "," + _intToStr(_maximumClimbRate) + "";
	return data;
}