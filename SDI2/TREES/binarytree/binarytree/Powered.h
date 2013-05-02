#ifndef POWERED_H
#define POWERED_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "FixedWing.h"

using namespace std;

class Powered : FixedWing : Aircraft
{
private:
		int _numEngines;
		int _hoursOperated;
		double _maxClimbRate;
}
#endif