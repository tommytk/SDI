#include "Powered.h"
Powered::Powered()
{
}
void Powered::setFlightHours(int flightHours)
{
	_flightHours = flightHours;
}
void Powered::setNumberOfEngines(int numberOfEngines)
{
	_numberOfEngines = numberOfEngines;
}
void Powered::setJetEngineCheck(std::string lastEngineCheck)
{
	_lastEngineCheck = lastEngineCheck;
}
void Powered::setMaximumClimbRate(int maximumClimbRate)
{
	_maximumClimbRate = maximumClimbRate;
}