#ifndef LOGICLAYER_H
#define LOGICLAYER_H
#include "BinSearchTree.h"
#include "Glider.h"
#include "Jet.h"
#include "Propeller.h"
#include "Counter.h"
#include "Contra.h"
#include <vector>
#include <math.h>
#include <string>
#include <vector> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

class DataManipulation 
{
public:
	bool caseInsensitiveCmp(std::string a, std::string b);
	bool retreveBySig(std::string sigToFind);
	bool retreiveByName(std::string nameToFind);
	bool addAircraft(Aircraft* aircraftToAdd);
	bool removeAircrafts(std::string sigToDelete);
	Aircraft* CSVtoAircraft(std::string filename);
	/*bool LoadAircraftInput(std::string fileName);*/
	bool printAircrafts();
	bool clearDatastore();
	Aircraft* findClosestSig(std::string sig);
private:
	int min(int a, int b);
	BinarySearchTree _AircraftStore;
	std::string _findXmlData(std::string aircraftXML, std::string variableType, std::string XMLtagName);
	std::vector<std::string> csv(string sentence);
};

#endif