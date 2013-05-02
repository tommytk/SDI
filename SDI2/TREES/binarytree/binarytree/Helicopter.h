#ifndef HELICOPTER_H
#define HELICOPTER_H
#include <iostream>
#include <string>
#include "Aircraft.h"

using namespace std;

class Helicopter : Aircraft
{
private:
	double _maxClimbRate;
	double _rotorDiameter;
	int _rotorBladesNum;
}
#endif