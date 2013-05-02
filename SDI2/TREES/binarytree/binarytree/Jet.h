#ifndef JET_H
#define JET_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "FixedWing.h"
#include "Powered.h"

using namespace std;

class Jet : Powered : FixedWing : Aircraft
{
private:
		int _hoursUntilInspection;
		bool _jetEngInspecNeeded;
}
#endif