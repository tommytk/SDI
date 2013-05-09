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
	try
	{
		std::vector<Aircraft*> aircrafts = _AircraftStore.getDataAsVector();

		std::cout<<" ---------------------------------------------" <<std::endl;
		if(aircrafts.size() == 0)
		{
			throw  "the datastore is empty!";
		}
		for (int idx = 0; idx <aircrafts.size();idx++)
		{
			aircrafts[idx]->printAircraft();
			std::cout<<"\n ---------------------------------------------" <<std::endl;
			return true;
		}
	}
	catch(const char* error)
	{
		throw error;
	}
	
}


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

			std::cout<<" ---------- Loading ------------"<<std::endl;
			std::cout<< "------- Aircraft Found --------- "<< std::endl;
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
	try
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
		throw "Aircraft Not found";
	}
	
	}
	catch(const char* error)
	{
		throw error;
	}
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
			while (!filestr.eof())
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

						tempAircraft = dynamic_cast<Aircraft*> (temp);
						if (addAircraft(temp) == true)
						{
							std::cout<<" ---------- Loading ------------"<<std::endl;
							std::cout<<"\n" + name + " Added"<< std::endl;
						}
					}
					else if ((caseInsensitiveCmp(aircraftSubType,"Jet") == 1))
					{

						std::string name = fields[2];
						std::string sig = fields[3];
						std::string serial = fields[4];
						std::string ConInt = fields[9];
						int maxSpeed = atoi(ConInt.c_str());
						std::string owner = fields[5];
						std::string model = fields[6];
						std::string manufacturer = fields[7];
						std::string productionDate = fields[8];
						std::string lastAirInspection = fields[10];

						std::string flightHrs = fields[11];
						int flightHours = atoi(flightHrs.c_str());
						std::string numEngines = fields[12];
						int numberOfEngines = atoi(numEngines.c_str());
						std::string engineCheck = fields[13];
						std::string maxClmbRate = fields[14];
						int maxClimbRate = atoi(maxClmbRate.c_str());

						Aircraft* temp = new Jet(name,aircraftType,aircraftSubType,sig,serial,owner,model,manufacturer,productionDate,maxSpeed,lastAirInspection,flightHours,numberOfEngines,engineCheck,maxClimbRate);

						tempAircraft = dynamic_cast<Aircraft*> (temp);

						if (addAircraft(temp) == true)
						{
							std::cout<<" ---------- Loading ------------"<<std::endl;
							std::cout<<"\n" + name + " Added"<< std::endl;
						}
					}
					else if ((caseInsensitiveCmp(aircraftSubType,"Propeller") == 1))
					{

						std::string name = fields[2];
						std::string sig = fields[3];
						std::string serial = fields[4];
						std::string ConInt = fields[9];
						int maxSpeed = atoi(ConInt.c_str());
						std::string owner = fields[5];
						std::string model = fields[6];
						std::string manufacturer = fields[7];
						std::string productionDate = fields[8];
						std::string lastAirInspection = fields[10];

						std::string flightHrs = fields[11];
						int flightHours = atoi(flightHrs.c_str());
						std::string numEngines = fields[12];
						int numberOfEngines = atoi(numEngines.c_str());
						std::string engineCheck = fields[13];
						std::string maxClmbRate = fields[14];
						int maxClimbRate = atoi(maxClmbRate.c_str());	
						Aircraft* temp = new Propeller(name,aircraftType,aircraftSubType,sig,serial,owner,model,manufacturer,productionDate,maxSpeed,lastAirInspection,flightHours,numberOfEngines,engineCheck,maxClimbRate);

						tempAircraft = dynamic_cast<Aircraft*> (temp);

						if (addAircraft(temp) == true)
						{
							std::cout<<" ---------- Loading ------------"<<std::endl;
							std::cout<<"\n" + name + " Added"<< std::endl;
						}
					}
					else
					{
						throw "Invalid SubType";
					}

				}
				else if (caseInsensitiveCmp(aircraftType,"Helicopter") == 1)
				{
					if (caseInsensitiveCmp(aircraftSubType,"Counter") ==1)
					{
						std::string name = fields[2];
						std::string sig = fields[3];
						std::string serial = fields[4];
						std::string ConInt = fields[9];
						int maxSpeed = atoi(ConInt.c_str());
						std::string owner = fields[5];
						std::string model = fields[6];
						std::string manufacturer = fields[7];
						std::string productionDate = fields[8];
						std::string lastAirWorthinessCheck = fields[9];
						std::string rotorType = fields[10];
						std::string roBladesNum = fields[11];
						int rotorBladesNumber = atoi(roBladesNum.c_str());
						std::string roDiameter = fields[12];
						double rotorDiameter = atoi(roDiameter.c_str());
						std::string maxVerClimbRate = fields[13];
						int maximumVerticalClimbRate = atoi(maxVerClimbRate.c_str());

						Aircraft* temp = new Counter(name,aircraftType,aircraftSubType,sig,serial,owner,model,manufacturer,productionDate,lastAirWorthinessCheck,rotorType,rotorBladesNumber,rotorDiameter,maximumVerticalClimbRate);
						tempAircraft = dynamic_cast<Aircraft*> (temp);

						if (addAircraft(temp) == true)
						{
							std::cout<<" ---------- Loading ------------"<<std::endl;
							std::cout<<"\n" + name + " Added"<< std::endl;
						}
					}
					else if (caseInsensitiveCmp(aircraftSubType,"Contra") ==1)
					{
						std::string name = fields[2];
						std::string sig = fields[3];
						std::string serial = fields[4];
						std::string ConInt = fields[9];
						int maxSpeed = atoi(ConInt.c_str());
						std::string owner = fields[5];
						std::string model = fields[6];
						std::string manufacturer = fields[7];
						std::string productionDate = fields[8];
						std::string lastAirWorthinessCheck = fields[9];
						std::string rotorType = fields[10];
						std::string roBladesNum = fields[11];
						int rotorBladesNumber = atoi(roBladesNum.c_str());
						std::string roDiameter = fields[12];
						double rotorDiameter = atoi(roDiameter.c_str());
						std::string maxVerClimbRate = fields[13];
						int maximumVerticalClimbRate = atoi(maxVerClimbRate.c_str());

						Aircraft* temp = new Contra(name,aircraftType,aircraftSubType,sig,serial,owner,model,manufacturer,productionDate,lastAirWorthinessCheck,rotorType,rotorBladesNumber,rotorDiameter,maximumVerticalClimbRate);
						tempAircraft = dynamic_cast<Aircraft*> (temp);

						if (addAircraft(temp) == true)
						{
							std::cout<<" ---------- Loading ------------"<<std::endl;
							std::cout<<"\n" + name + " Added"<< std::endl;
						}
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
bool DataManipulation::editData(std::string ID)
{
	int count = 0;
	try
	{
	std::vector<Aircraft*> aircrafts = _AircraftStore.getDataAsVector();
	int i = 0;
	for (int idx = 0; idx <aircrafts.size();idx++)
	{
		if(caseInsensitiveCmp(aircrafts[idx]->name(),ID) == true)
		{
			count = 1;
			std::cout<<" ------------------Current Data --------------------" <<std::endl;
			aircrafts[idx]->printAircraft();
			std::cout<<"\n ---------------------------------------------" <<std::endl;
			i = idx;
			
		}
		if(count == NULL)
		{
			throw "Couldn't find Name in tree";
		}
	}

	std::string name;
	std::string owner;
	int maxSpeed;
	std::string maxspeed;
	std::string ModelNumber;
	std::string Manufacturer;
	std::string ProDate;
	std::string LastAirCheck;
	std::cout<<"Set the name: ";
	std::cin.ignore(1,'n');
	std::getline(std::cin,name);
	aircrafts[i]->setName(name);
	std::cout<<"\n Set the Owner: ";
	std::cin.ignore(1,'n');
	std::getline(std::cin,owner);
	aircrafts[i]->setOwner(owner);
	std::cout<<"\n Set the MaxSpeed: ";
	std::cin.ignore(1,'n');
	std::getline(std::cin,maxspeed);
	maxSpeed = atoi(maxspeed.c_str());
	aircrafts[i]->setMaximumSpeed(maxSpeed);
	std::cout<<"\n Set the Model Number: ";
	std::cin.ignore(1,'n');
	std::getline(std::cin,ModelNumber);
	aircrafts[i]->setModel(ModelNumber);
	std::cout<<"\n Set the Manufacturer: ";
	std::cin.ignore(1,'n');
	std::getline(std::cin,Manufacturer);
	aircrafts[i]->setManufacturer(Manufacturer);
	std::cout<<"\n Set the Production Date: ";
	std::cin.ignore(1,'n');
	std::getline(std::cin,ProDate);
	aircrafts[i]->setProductionDate(ProDate);
	std::cout<<"\n Set the Last Airworthiness check: ";
	std::cin.ignore(1,'n');
	std::getline(std::cin,LastAirCheck);
	aircrafts[i]->setlastAirWorthinessCheck(LastAirCheck);
	
	
	
		std::cout<<" ------------------New Data  --------------" <<std::endl;
		aircrafts[i]->printAircraft();
		std::cout<<"\n ---------------------------------------------" <<std::endl;
		return true;
	}
	catch(const char* error)
	{
		throw error;
	}

}
bool DataManipulation::clearDatastore()
{
	try
	{
	_AircraftStore.clearTree();
	return true;
	}
	catch(const char* error)
	{
		throw error;
	}
}
bool DataManipulation::dataSave(std::string filename)
{
	try
	{
		if (filename.find(".txt",0) == -1)
		{
			throw "Inavlid File Type Exception";
		}
		std::vector<Aircraft*> aircrafts = _AircraftStore.getDataAsVector();
		std::ofstream aircraftFile (filename);
		for (int idx = 0; idx <_AircraftStore.getSize();idx++)
		{
			if (aircraftFile.is_open())
			{
				if (idx != (_AircraftStore.getSize()-1))
				{
					aircraftFile << aircrafts[idx]->aircraftToCSV()<<"\n";
				}
				else
				{
					aircraftFile << aircrafts[idx]->aircraftToCSV();
				}
			}
		}
		aircraftFile.close();
	}
	catch(const char* error)
	{
		throw error;
	}
	return true;
	
}
std::vector<std::string> DataManipulation::csv(string sentence)
{
	try
	{
		std::vector<std::string> result;
		string field;
		size_t fieldStartPos, currCommaPos;
		fieldStartPos = 0;
		currCommaPos = sentence.find(",");
		if (currCommaPos == NULL)
		{
			throw "Comma not found";
		}
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
	catch(const char* error)
	{
		throw error;
	}

	

}

//Private


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

