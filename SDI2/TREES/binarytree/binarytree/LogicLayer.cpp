#include "LogicLayer.h"


bool DataManipulation::addAircraft(Aircraft *aircraftToAdd)
{
	try
	{
		_AircraftStore.addItem(aircraftToAdd);
		return true;
	}
	catch (char const* error)
	{
		std::cout<<"Error: "<<error<<std::endl;
	}
}

bool DataManipulation::printAircrafts()
{
	std::vector<Aircraft*> aircrafts = _AircraftStore.getDataAsVector();

	std::cout<<" ---------------------------------------------" <<std::endl;
	if(aircrafts.size() == 0)
	{
		std::cout<<" the datastore is empty!"<<std::endl;
	}
	for (int idx = 0; idx <aircrafts.size();idx++)
	{
		aircrafts[idx]->printAircraft();
		std::cout<<"\n ---------------------------------------------" <<std::endl;
	}
	return true;
}

//bool DataManipulation::clearDatastore()
//{
//	_AircraftStore.clearTree();
//	return true;
//}

bool DataManipulation::removeAircrafts(std::string sigToDelete)
{
	try
	{
		if (_AircraftStore.remove(sigToDelete) == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (char const* error)
	{
		std::cout<<"Error: "<<error<<std::endl;
	}
}
bool DataManipulation::retreveBySig(std::string sigToFind)
{
	try
	{
		if (_AircraftStore.retreiveByCallSig(sigToFind) != NULL)
		{ 
			Aircraft* retreived = _AircraftStore.retreiveByCallSig(sigToFind);
			retreived->printAircraft();
			return true;
		}

		return false;
	}
	catch (char const* error)
	{
		std::cout<<"Error: "<<error<<std::endl;
	}
}
bool DataManipulation::retreiveByName(std::string nameToFind)
{
	std::vector<Aircraft*> aircrafts = _AircraftStore.getDataAsVector();
	for (int idx = 0; idx <aircrafts.size();idx++)
	{
		if(caseInsensitiveCmp(aircrafts[idx]->name(),nameToFind) == true)
		{
			std::cout<<" ---------------------------------------------" <<std::endl;
			aircrafts[idx]->printAircraft();
			std::cout<<"\n ---------------------------------------------" <<std::endl;
			return true;
		}
	}
	throw "Aircraft Not found";
}
Aircraft* DataManipulation::_XMLtoAircraft(std::string aircraftXML)
{
	std::string aircraftType;
	std::string aircraftSubType;
	std::string XMLTagName = "Field";
	Aircraft* tempAircraft;
	try
	{
		aircraftType = _findXmlData(aircraftXML,"_aircraftType",XMLTagName);
		aircraftSubType = _findXmlData(aircraftXML,"_aircraftSubType",XMLTagName);
		if (caseInsensitiveCmp(aircraftType,"Fixed Wing") == 1)
		{
			if ((caseInsensitiveCmp(aircraftSubType,"Glider") == 1))
			{
				Glider* temp = new Glider();
				temp->setlastAirWorthinessCheck(_findXmlData(aircraftXML,"Last_Airworthiness_check",XMLTagName));
				temp->setManufacturer(_findXmlData(aircraftXML,"Manufacturer",XMLTagName));
				temp->setModel(_findXmlData(aircraftXML,"Model",XMLTagName));
				temp->setSerial(_findXmlData(aircraftXML,"Serial",XMLTagName));
				temp->setCallSig(_findXmlData(aircraftXML,"Call_Sig",XMLTagName));
				temp->setAircraftSubType(aircraftSubType);
				temp->setAircraftType(aircraftType);
				temp->setName(_findXmlData(aircraftXML,"Name",XMLTagName));
				tempAircraft = dynamic_cast<Aircraft*> (temp);
			}
			else
			{
				throw "Invalid SubType";
			}
		}
		else
		{
			throw "Invalid Type";
		}
	}
	catch(char const* error)
	{
		std::cout<< "Error occured: "<<error<<std::endl;
		throw error;
	}
	return tempAircraft;
}
std::string DataManipulation::_findXmlData(std::string aircraftXML, std::string variableType, std::string XMLtagName)
{
	size_t tagStart;
	size_t tagLength;
	std::string tagSearch;
	tagSearch = "<" + XMLtagName + " " + variableType;
	if(aircraftXML.find(tagSearch) == -1)
	{
		throw "Opening Tag Not Found Exception";
	}
	tagStart = aircraftXML.find(tagSearch);
	tagSearch = ">";
	tagStart = (aircraftXML.find(tagSearch,tagStart)+1);
	tagSearch = "</";
	if(aircraftXML.find(tagSearch,tagStart) == -1)
	{
		throw "Close Tag Not Found Exception";
	}
	tagLength = (aircraftXML.find(tagSearch,tagStart)-tagStart);
	return (aircraftXML.substr(tagStart,tagLength));
}
//Private

// <Field vesselType>submarine</Field>
bool DataManipulation::caseInsensitiveCmp(std::string a, std::string b)
{
	if(strcmp(a.c_str(), b.c_str()))
	{
		return false;
	}
	if(!strcmp(a.c_str(),b.c_str()))
	{
		return true;
	}
}
int DataManipulation::min(int a, int b)
{
	if ( b < a )
	{
		return b;
	}
	else
	{
		return a;
	}
}

