#ifndef PROPELLER_H
#define PROPELLER_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "FixedWing.h"
#include "Powered.h"

using namespace std;

class Propeller : Powered : FixedWing : Aircraft
{
private:
		int _hoursUntilInspection;
		bool _pistEngInspecNeeded;
}
#endif