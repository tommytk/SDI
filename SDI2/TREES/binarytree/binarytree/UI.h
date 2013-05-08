#ifndef UI_H
#define UI_H
#include "LogicLayer.h"
#include "Aircraft.h"
#include "BinSearchTree.h"
#include <string>
#include <istream>
#include <iostream>
#include <sstream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
class UserInterface
{
public:
	int askForInputLoop(std::string question);
	void displayMenu();
	void addAircraft();
	void printToScreen();
	void deleteAircraft();
	void searchByName();
	void searchByID();
	void loadDatabase();
	/*void signalComparison(int incSig);
	void saveDatabase();
	void loadDatabase();
	bool exit(bool &exitSelected);
	void selectionInvalid();*/
private:

	std::string _intToStr(int number);
	/*bool _exitCheck();
	bool _saveUponExitCheck();*/
	DataManipulation _myFunctions;
	std::string _checkAircraftType(std::string &_aircraftType, std::string type1, std::string type2);
	std::string _checkAircraftType(std::string &_aircraftType, std::string type1, std::string type2, std::string type3);
	bool _caseInsensitiveCmp(std::string a, std::string b);
	std::string _signatureFormatCheck(std::string sig);
};
#endif