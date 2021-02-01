// Author: Vincent Wang
// Date  : 2016/3/16
// Purpose:
//	简单的码表类，参考
//  http://blog.csdn.net/qq_31175231/article/details/77923212
//  调用方法
//  Stopwatch sw;
// sw.start();
// ....
// sw.stop();
// cout << sw.getMilliseconds() << " ms";

#pragma once

#include <chrono>
#include <ctime>

class Stopwatch
{
  public:
	Stopwatch() {}
	void start();
	void stop();
	double getMicroseconds();
	double getMilliseconds();

  private:
	typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> microClock_type;

	microClock_type starttime, stoptime;
};
