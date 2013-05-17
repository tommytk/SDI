#include "Glider.h"

Glider::Glider()
{
	
	_aircraftType = "Fixed Wing";
	_aircraftSubType = "Glider";
}
Glider::Glider(std::string name, std::string aircraftType, std::string aircraftSubType, std::string sig,std::string serial, std::string owner,int maximumSpeed,std::string model,std::string manufacturer,std::string productionDate,std::string lastAirInspection)
{
	 _name = name;
	 _aircraftType = "Fixed Wing";
	 _aircraftSubType = "Glider";
	_callSig = sig;
	_serial = serial;
	 _owner = owner;
	_maximumSpeed = maximumSpeed;
	_model = model;
	_manufacturer = manufacturer;
	_productionDate = productionDate;
	 _lastAirWorthinessCheck = lastAirInspection;
}
bool Glider::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<"\n The serial is:"<<_serial<<" \n Owner: "<<_owner<<" \n Maximum Speed"<<_maximumSpeed<<"\n The model of the Aircraft is: "<<_model <<"\n The manufacturer is: "<<_manufacturer<<"\n The Production Date is: "<<_productionDate <<" \n Last air inspection"<<_lastAirWorthinessCheck<<std::endl;
	return true;
}
std::string Glider::aircraftToCSV()
{
	
	std::string data  = ""+ _aircraftType + "," +_aircraftSubType + "," + _name + "," +_callSig + "," + _serial + "," + _intToStr(_maximumSpeed) + "," + _owner + "," + _model + "," + _manufacturer + "," + _productionDate + "," + _lastAirWorthinessCheck + "";
	return data;
}
