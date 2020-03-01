#pragma once

#include <iostream>
#include <windows.h>


//////////////////////////////////////////////////////////////////////////
class PerformanceTimer
{
public:
	PerformanceTimer() : id(0)
	{
		QueryPerformanceFrequency(&nFreq); 
	}

	void start()
	{
		//std::cout << std::endl << "/////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << std::endl << "================================================================ ## " << std::setw(6) << id << " ##" << std::endl;
		id++;
		QueryPerformanceCounter(&nBeginTime);
	}

	void stop()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	}

	void end()
	{
		std::cout << "//////////////////////////////////////////////////////////////// ## "
		//std::cout << "============================================================= time: "
		//std::cout << "------------------------------------------------------------- time: "
		//std::cout << "                                                              time: "
			<< std::fixed << std::setw(6) << std::setprecision(2) << time * 1000 << " ms" << std::endl;
        std::cout << std::endl << std::endl;
	}

private:
	int id;
	double time;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
};
