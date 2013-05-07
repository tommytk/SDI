#include "UI.h"
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <string.h>

int UserInterface::askForInputLoop(std::string question)
{
	bool validInput =false;
	int output;
	do
	{
		std::cout << question;
		std::cin>>output;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout <<"Error: that was not an integer!"<<std::endl;
		}
		else
		{
			validInput = true;
		}
	}while (!validInput);
	return output;
}
void UserInterface::displayMenu()
{
	std::cout << "------------  MENU  --------------" << std::endl;
	std::cout << "1 - ADD Aircraft" << std::endl;
	std::cout << "2 - DELETE Aircraft" << std::endl;
	std::cout << "3 - SEARCH (by Aircraft Name)" << std::endl;
	std::cout << "4 - SEARCH (by Aircraft ID)" << std::endl;
	std::cout << "5 - PRINT Aircraft(s) (to screen)"<< std::endl;
	std::cout << "6 - Incoming Signal Comparison"<< std::endl;
	std::cout << "7 - SAVE DATABASE"<< std::endl;
	std::cout << "8 - LOAD DATABASE"<< std::endl;
	std::cout << "9 - Exit program"<< std::endl;
	std::cout << "Please enter a choice from 1 - 9: ";
	return;
}
void UserInterface::addAircraft() // OPTION 1:
{

	std::string name, aircraftType, aircraftSubType, callSig, owner,model,manufacturer,productionDate, lastAirWorthinessCheck;
	int maximumSpeed;
	Aircraft* newAircraft = NULL;


	std::cout << "Please enter the type of Aircraft you wish to add: ";
	std::cin.ignore(1,'\n');//this clears buffer before the getline() takes user input
	std::getline(std::cin,aircraftType);

	aircraftType = _checkAircraftType(aircraftType,"Fixed Wing","Helicopter");
	if (aircraftType == "Incorrect value break to main loop")
	{
		return;
	}
	std::cout << "Please enter the Aircrafts unique Name: ";
	getline(std::cin,name);
	std::cout << "Enter the Aircrafts unique call signature: ";
	std::getline(std::cin,callSig);
	/*callSig = _signatureFormatCheck(callSig);*/
	while(callSig == "Incorrect Format")
	{
		std::cout << "The callSig entered is not the correct format, E.G. 'F456'"<< std::endl;
		std::cout << "Enter the Aircrafts unique call signature: ";
		std::getline(std::cin,callSig);
		callSig = _signatureFormatCheck(callSig);
	}
	maximumSpeed= askForInputLoop("Enter the aircrafts maximum speed: ");
	std::cin.ignore(1,'\n');//this clears buffer before the getline() takes user input
	std::cout << "Please enter the Owner of " << name <<std::endl;
	std::getline(std::cin,owner);
	std::cout<<"Please enter whether the last airworthness check: DD/MM/YYYY "<<std::endl;
	std::getline(std::cin,lastAirWorthinessCheck);

	if (_caseInsensitiveCmp(aircraftType,"Fixed Wing") == true)
	{
		std::cout << "Please enter the Sub-type of Fixed Wing Aircraft you wish to add (Glider, Jet or Propeller): "<<std::endl;
		/*cin.ignore(1,'\n');*/ // That causes the input of Jet to become "et" for some reason??
		std::getline(std::cin,aircraftSubType);
		aircraftSubType = _checkAircraftType(aircraftSubType,"Glider","Jet","Propeller");
		if (aircraftSubType == "IncorrectValue break to main loop")
		{
			return;
		}

		if (_caseInsensitiveCmp(aircraftSubType,"Glider") == true)
		{
			newAircraft = new Glider(name, aircraftType, aircraftSubType, callSig, owner,maximumSpeed,lastAirWorthinessCheck);
		}
		else if (_caseInsensitiveCmp(aircraftSubType,"Jet") == true)
		{
			int flightHours,numberOfEngines;
			flightHours= askForInputLoop("Please enter the number of flightHours the jet has: ");
			numberOfEngines= askForInputLoop("Please enter the number of numberOfEngines the jet has: ");
			newAircraft = new Jet(name,aircraftType,aircraftSubType,callSig,owner,maximumSpeed,lastAirWorthinessCheck,flightHours,numberOfEngines);
		}
		else if (_caseInsensitiveCmp(aircraftSubType,"Propeller") == true)
		{
			int flightHours,numberOfEngines;
			flightHours= askForInputLoop("Please enter the number of flightHours the Aircraft has: ");
			numberOfEngines= askForInputLoop("Please enter the number of numberOfEngines the Aircraft has: ");
			
			newAircraft = new Propeller(name,aircraftType,aircraftSubType,callSig,owner,maximumSpeed,lastAirWorthinessCheck,flightHours,numberOfEngines);
		}
		else
		{
			std::cout<<"Aircraft Sub type not recognized"<<std::endl;
		}
	}
	else if (_caseInsensitiveCmp(aircraftType,"Helicopter") == true)
	{
		std::cout << "Please enter the Sub-type of Helicopter you wish to add \n(Counter or Contra): ";
		
		std::getline(std::cin,aircraftSubType);
		aircraftSubType = _checkAircraftType(aircraftSubType,"Contra","Counter");
		if (aircraftSubType == "IncorrectValue break to main loop")
		{
			return;
		}
		
		if (_caseInsensitiveCmp(aircraftSubType,"Counter") == true)
		{
			std::string rotorType;
			std::cout << "Please enter the rotor type used by this Helicopter \n(Main rotor or Tilt rotor): ";
			
			getline(cin,rotorType);
			rotorType = _checkAircraftType(rotorType,"Main rotor","Tilt rotor");
			if (rotorType == "IncorrectValue break to main loop")
			{
				return;
			}
			newAircraft = new Counter(name,aircraftType,aircraftSubType,callSig,owner,rotorType);
		}
		else if (_caseInsensitiveCmp(aircraftSubType,"Contra") == true)
		{
			
			std::string rotorType;
			std::cout << "Please enter the rotor type used by this Helicopter \n(Tail rotor or NOTAR): ";
			
			getline(cin,rotorType);
			rotorType = _checkAircraftType(rotorType,"Tail rotor","NOTAR");
			if (rotorType == "IncorrectValue break to main loop")
			{
				return;
			}
			newAircraft = new Contra(name,aircraftType,aircraftSubType,callSig,owner,rotorType);
		}
	}
	if (_myFunctions.addAircraft(newAircraft) == true)
	{
		std::cout<<" ---------- Loading ------------"<<std::endl;
		std::cout<<"\n Aircraft Added"<< std::endl;
	}
	else
	{
		std::cout<< "Aircraft failed to be Added" << std::endl;
	}
	



}
void UserInterface::deleteAircraft()
{
	std::string sigToDelete;
	cout << "Please enter the Call Signature of the Aircraft you wish to delete: ";
	cin.ignore(1,'\n');
	std::getline(std::cin,sigToDelete);

	/*sigToDelete = _signatureFormatCheck(sigToDelete);*/
	/*while(sigToDelete == "Incorrect Format")
	{
		std::cout << "Enter the Aircrafts Unique Call Signature: ";
		std::getline(cin,sigToDelete);
		if (_caseInsensitiveCmp(sigToDelete,"Quit"))
		{
			return;
		}
		sigToDelete = _signatureFormatCheck(sigToDelete);
	}*/
	if (_myFunctions.removeAircrafts(sigToDelete) == true)
	{
		std::cout<<" ---------- Loading ------------"<<std::endl;
		std::cout<< "Aircraft Removed"<< std::endl;
		std::cout<<" ---------- Loading ------------"<<std::endl;
	}
	else
	{
		cout<< "Aircraft failed to be removed" << endl;
	}
}
//Option 3
void UserInterface::searchByName()
{
	std::string nameToFind;
	cout << "Please enter the Name of the Aircraft you wish to look up in the database: ";
	cin.ignore(1,'\n');
	std::getline(std::cin,nameToFind);

	try
	{
		_myFunctions.retreiveByName(nameToFind);
	}
	catch(char const* error)
	{
		std::cout<< "Error occured: "<<error<< " \nAircraft " << nameToFind<< " was not found"<<std::endl;
	}
}// OPTION 3:

void UserInterface::searchByID()
{
	std::string sigToFind;
	std::cout << "Please enter the Call Signature of the Aircraft you wish to look up in the database: ";
	std::cin.ignore(1,'\n');
	std::getline(std::cin,sigToFind);
	sigToFind = _signatureFormatCheck(sigToFind);
	while(sigToFind == "Incorrect Format")
	{
		std::cout << "Enter the Aircrafts Unique Call Signature: ";
		getline(cin,sigToFind);
		if (_caseInsensitiveCmp(sigToFind,"Quit"))
		{
			return;
		}
		sigToFind = _signatureFormatCheck(sigToFind);
	}
	if (_myFunctions.retreveBySig(sigToFind) == true)
	{
		std::cout<<" ---------- Loading ------------"<<std::endl;
		std::cout<< "Aircraft Found and printer"<< std::endl;
		std::cout<<" ---------- Loading ------------"<<std::endl;
	}
	else
	{
		cout<< "Aircraft was not found" << endl;
	}
} // OPTION 4:
void UserInterface::printToScreen()
{
	_myFunctions.printAircrafts();
}

//---------------------\\

std::string UserInterface::_checkAircraftType(std::string &_aircraftType, std::string type1, std::string type2)
{
	if ((_caseInsensitiveCmp(_aircraftType,type1) == false) && (_caseInsensitiveCmp(_aircraftType,type2) == false ))
	{
		std::cout <<"Wrong type entered!!!"<< std::endl;
	
		cout << "Please enter either a \""<<type1<<"\" or a \""<<type2<<"\": ";
		
		std::getline(std::cin,_aircraftType);
		_checkAircraftType(_aircraftType,type1,type2);
	
	}
	
	return _aircraftType;
	
	
}
std::string UserInterface::_checkAircraftType(std::string &_aircraftType, std::string type1, std::string type2, std::string type3)
{
	if ((_caseInsensitiveCmp(_aircraftType,type1) == false) && (_caseInsensitiveCmp(_aircraftType,type2) == false ) && (_caseInsensitiveCmp(_aircraftType,type3) == false))
	{
		std::cout <<"Wrong type entered!!!"<< std::endl;
		if (type3 != "")
		{
			cout << "Please enter either a \""<<type1<<"\" or a \""<<type2<<"\" or a \""<<type3<<"\": ";
		}
		else
		{
		cout << "Please enter either a \""<<type1<<"\" or a \""<<type2<<"\": ";
		}
		std::getline(std::cin,_aircraftType);
		_checkAircraftType(_aircraftType,type1,type2,type3);
	
	}
	
	return _aircraftType;
	
	
}
std::string UserInterface::_intToStr(int number) // Need this for sig comparison.
{
	std::stringstream stream; // create a new stream variable
	stream << number; // load the number into the stream variable
	return stream.str(); // return the stream variable as a string.
}
std::string UserInterface::_signatureFormatCheck(std::string sig)
{
	std::string output = "";
	if(sig.length() !=4) //The call signatures for the planes are 4 digits long, so we want to check the entered variable is 4 digits
	{
		output = "Incorrect Format";
		return output;
	}

	return output;
}
bool UserInterface::_caseInsensitiveCmp(std::string a, std::string b)
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