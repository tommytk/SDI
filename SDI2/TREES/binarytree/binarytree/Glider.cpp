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

	 _lastAirWorthinessCheck = lastAirInspection;
}
bool Glider::printAircraft()
{
	std::cout<<"Aircrafts name: "<<_name<< "\n Aircraft Type: "<<_aircraftType << " \n Aircraft Sub Type: " <<_aircraftSubType <<" \n Aircraft call signature: "<<_callSig<<"\n The serial is:"<<_serial<<" \n Owner: "<<_owner<<" \n Maximum Speed"<<_maximumSpeed<<"\n The model of the Aircraft is: "<<_model <<"\n The manufacturer is: "<<_manufacturer<<"\n The Production Date is: "<<_productionDate <<" \n Last air inspection"<<_lastAirWorthinessCheck<<std::endl;
	return true;
}
std::string Glider::aircraftToXML()
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