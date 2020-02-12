#pragma once

#include <iostream>
#include <windows.h>


//////////////////////////////////////////////////////////////////////////
class PerformanceTimer
{
public:
	PerformanceTimer() 
	{
		QueryPerformanceFrequency(&nFreq); 
	}

	void start()
	{
		std::cout << std::endl << "/////////////////////////////" << std::endl;
		QueryPerformanceCounter(&nBeginTime);
	}

	void stop()
	{
		QueryPerformanceCounter(&nEndTime);
		double time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		std::cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << std::endl;
	}

private:
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
};
