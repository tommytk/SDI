#ifndef CONTRA_H
#define CONTRA_H
#include <iostream>
#include <string>
#include "Aircraft.h"
#include "Helicopter.h"

using namespace std;

class Contra : Helicopter : Aircraft //should aircraft be included?
{
private:
		string _rotorType;
}
#endif