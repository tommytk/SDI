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
//bool DataManipulation::LoadAircraftInput(std::string fileName)
//{
//	if (fileName.find(".xml",0) == -1)
//	{
//		throw "Inavlid File Type Exception";
//	}
//	std::vector<std::string> XMLdata;
//	std::string currentLine;
//	bool errorCaught = false;
//	int idx;
//	std::ifstream F(fileName.c_str());
//	if (F.bad() || F.fail())
//	{
//		throw "File not found Exception";
//	}
//	while (!F.eof())
//	{
//		std::getline(F,currentLine);
//		XMLdata.push_back(currentLine);
//	}
//	if (XMLdata.size() == 0)
//	{
//		throw "Empty file Exception";
//	}
//	for(idx = 0; idx < XMLdata.size();idx++)
//	{
//		try
//		{
//			Aircraft* temp = _XMLtoAircraft(XMLdata[idx]);
//			
//			_AircraftStore.addItem(temp);
//		}
//		catch(char const* error)
//		{
//			std::cout<< "Error occured: "<<error<< " \nVessel " << idx+1<< " was not added"<<std::endl;
//			errorCaught = true;
//		}
//	}
//	if (errorCaught)
//	{
//		std::cout<<"The rest of the vessels were added Sucessfully"<<std::endl;
//	}
//	return true;
//}
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
Aircraft* DataManipulation::CSVtoAircraft(std::string filename)
{
		Aircraft* tempAircraft;
		fstream filestr;
		string line;
		int buffId = 0;
		std::stringstream ss;
		std::vector<std::string> fields;  //the aircraft data
		int counter= 0;
	try
	{
	

		filestr.open(filename); 
		if(filestr.is_open())
		{
			while (counter != 2)
			{
				std::getline(filestr,line);
				fields = csv(line);
				std::string aircraftType = fields[0];
				std::string aircraftSubType = fields[1];
				if (caseInsensitiveCmp(aircraftType,"Fixed Wing") == 1)
				{
					if ((caseInsensitiveCmp(aircraftSubType,"Glider") == 1))
					{
						std::string ConInt = fields[5];
						int maxSpeed = atoi(ConInt.c_str());
						std::string name = fields[2];
						std::string sig = fields[3];
						std::string serial = fields[4];
						std::string owner = fields[5];
						std::string model = fields[6];
						std::string manufacturer = fields[7];
						std::string productionDate = fields[8];
						std::string lastAirInspection = fields[9];
						Aircraft* temp = new Glider(name,aircraftType,aircraftSubType,sig,serial,owner,maxSpeed,model,manufacturer,productionDate,lastAirInspection);
						
					/*	temp->setlastAirWorthinessCheck(fields[7]);
						temp->setManufacturer(fields[6]);
						temp->setModel(fields[5]);
						temp->setSerial(fields[4]);
						temp->setCallSig(fields[3]);
						temp->setAircraftSubType(aircraftSubType);
						temp->setAircraftType(aircraftType);
						temp->setName(fields[2]);*/
						tempAircraft = dynamic_cast<Aircraft*> (temp);
						
						counter++;
						std::cout<< temp->aircraftSubType() << temp->aircraftType() << temp->getCallSig() << temp->name() << std::endl;
							if (addAircraft(temp) == true)
							{
							std::cout<<" ---------- Loading ------------"<<std::endl;
							std::cout<<"\n Aircraft Added"<< std::endl;
							}
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
		}
	}
	catch(char const* error)
	{
		std::cout<< "Error occured: "<<error<<std::endl;
		throw error;
	}
	return tempAircraft;
}
std::vector<std::string> DataManipulation::csv(string sentence)
{

	std::vector<std::string> result;
	string field;
	size_t fieldStartPos, currCommaPos;
	fieldStartPos = 0;
	currCommaPos = sentence.find(",");
	while (currCommaPos != string::npos)
	{
		field = sentence.substr(fieldStartPos, currCommaPos - fieldStartPos);
		result.push_back(field);
		fieldStartPos = currCommaPos+1;
		currCommaPos = sentence.find(",", fieldStartPos);
	}
	field = sentence.substr(fieldStartPos);
	result.push_back(field);


	return result;

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

