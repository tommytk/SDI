#ifndef GLIDER_H
#define GLIDER_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "FixedWing.h"

using namespace std;

class Glider : FixedWing// : Aircraft
{
private:
		bool _winchable;
		float _minimumSinkRate;
}
#endif