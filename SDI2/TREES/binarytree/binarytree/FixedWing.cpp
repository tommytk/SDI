#include "FixedWing.h"

bool FixedWing::printAircraft()
{
	std::cout<<" Call Signature: "<<_callSig<<" Owner: "<<_owner<<"Maximum Speed"<<_maximumSpeed<<"Last air inspection"<<_lastAirWorthinessCheck<<std::endl;return true;
}
void  FixedWing::setWingSpan(float wingSpan)
{
	_wingSpan = wingSpan;
}
void  FixedWing::setMaximumSpeed(int maximumSpeed)
{
	_maximumSpeed = maximumSpeed;
}
void  FixedWing::setMinimumSpeed(int minimumSpeed)
{
	_minimumSpeed = minimumSpeed;
}
float  FixedWing::wingSpan()
{
	return _wingSpan;
}
int  FixedWing::maximumSpeed()
{
	return _maximumSpeed;
}
int  FixedWing::minimumSpeed()
{
	return _minimumSpeed;
}



