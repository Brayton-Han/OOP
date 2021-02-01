#include "Stopwatch.h"

void Stopwatch::start()
{
	starttime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
}

void Stopwatch::stop()
{
	stoptime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
}

double Stopwatch::getMilliseconds()
{
	return (stoptime.time_since_epoch().count() - starttime.time_since_epoch().count()) / 1000.0;
}

double Stopwatch::getMicroseconds()
{
	return (stoptime.time_since_epoch().count() - starttime.time_since_epoch().count());
}
