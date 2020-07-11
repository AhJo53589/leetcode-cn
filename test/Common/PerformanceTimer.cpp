#pragma once

#include <iostream>
#include <iomanip>
#include <windows.h>

#include "PerformanceTimer.h"

int nid = 0;
double ntime = 0.f;
LARGE_INTEGER nFreq;
LARGE_INTEGER nBeginTime;
LARGE_INTEGER nEndTime;

void PerformanceTimer::init()
{
    QueryPerformanceFrequency(&nFreq);
}

void PerformanceTimer::start()
{

    //std::cout << std::endl << "/////////////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << std::endl << "================================================================ ## " << std::setw(6) << nid << " ##" << std::endl;
    nid++;
    QueryPerformanceCounter(&nBeginTime);
}

void PerformanceTimer::stop()
{
    QueryPerformanceCounter(&nEndTime);
    ntime = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
}

void PerformanceTimer::end()
{
    std::cout << "//////////////////////////////////////////////////////////////// ## "
        //std::cout << "============================================================= time: "
        //std::cout << "------------------------------------------------------------- time: "
        //std::cout << "                                                              time: "
        << std::fixed << std::setw(6) << std::setprecision(2) << ntime * 1000 << " ms" << std::endl;
    std::cout << std::endl << std::endl;
}