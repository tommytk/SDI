#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "Helicopter.h"

using namespace std;

class Counter : Helicopter : Aircraft //should aircraft be included?
{
private:
		string _rotorType;
}
#endif