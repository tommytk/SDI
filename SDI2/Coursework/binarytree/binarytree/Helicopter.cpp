#include "Helicopter.h"
Helicopter::Helicopter()
{

}
void Helicopter::setMaximumClimbRate(int maximumVerticalClimbRate)
{
	_maximumVerticalClimbRate = maximumVerticalClimbRate;
}
void Helicopter::setRotorDiameter(int rotorDiameter)
{
	_rotorDiameter = rotorDiameter;
}
void Helicopter::setRotorBladesNumber(int rotorBladesNumber)
{
	_rotorBladesNumber = rotorBladesNumber;
}
int Helicopter::maximumVerticalClimbRate()
{
	return _maximumVerticalClimbRate;
}
double Helicopter::rotorDiameter()
{
	return _rotorDiameter;
}
int Helicopter::rotorBladesNumber()
{
	return _rotorBladesNumber;
}