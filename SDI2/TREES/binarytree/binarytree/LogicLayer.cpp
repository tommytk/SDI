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
	throw "Vessel Not found";
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

