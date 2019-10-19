// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

#include <algorithm>
#include <numeric>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>
#include <sstream>

#include "..\Common\Common.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//int missingNumber(vector<int>& arr) 
//{
//	if (arr.back() < arr.front())
//	{
//		reverse(arr.begin(), arr.end());
//	}
//	int k = arr[1] - arr[0];
//	for (int i = 0; i < arr.size() - 1; i++)
//	{
//		if (arr[i + 1] - arr[i] == k) continue;
//		if (arr[i + 1] - arr[i] > k) return arr[i] + k;
//		break;
//	}
//	return arr[0] + k / 2;
//}

//////////////////////////////////////////////////////////////////////////
//vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
//{
//	auto f_sort = [](const vector<int> &a, const vector<int> &b)
//	{
//		return a[0] < b[0];
//	};
//	sort(slots1.begin(), slots1.end(), f_sort);
//	sort(slots2.begin(), slots2.end(), f_sort);
//	size_t i_1 = 0, i_2 = 0;
//	while (i_1 < slots1.size() && i_2 < slots2.size())
//	{
//		vector<int> &time_1 = slots1[i_1];
//		vector<int> &time_2 = slots2[i_2];
//		if (time_1[1] - time_1[0] < duration)
//		{
//			i_1++;
//			continue;
//		}
//		if (time_2[1] - time_2[0] < duration)
//		{
//			i_2++;
//			continue;
//		}
//		int start = max(time_1[0], time_2[0]);
//		int end = min(time_1[1], time_2[1]);
//		if (end - start >= duration)
//		{
//			return { start, start + duration };
//		}
//		if (time_1[1] < time_2[1])
//		{
//			i_1++;
//		}
//		else
//		{
//			i_2++;
//		}
//	}
//	return {};
//}


//////////////////////////////////////////////////////////////////////////
double probabilityOfHeads(vector<double>& prob, int target)
{

}

int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_begin = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		cout << endl << "/////////////////////////////" << endl;
		QueryPerformanceCounter(&nBeginTime);
	};

	auto f_time_end = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	//vector<vector<int>> TESTS;
	////vector<int> K;
	//vector<int> ANSWERS;

	//TESTS.push_back({ 5,7,11,13 });
	//ANSWERS.push_back(9);

	//TESTS.push_back({ 15,13,12 });
	//ANSWERS.push_back(14);

	//TESTS.push_back({ 100,300,400 });
	//ANSWERS.push_back(200);

	//////////////////////////////////////////////////////////////////////////
	//vector<vector<vector<int>>> TESTS;
	//vector<vector<vector<int>>> K;
	//vector<int> D;
	//vector<vector<int>> ANSWERS;

	//TESTS.push_back(StringToVectorVectorInt("[[10,50],[60,120],[140,210]]"));
	//K.push_back(StringToVectorVectorInt("[[0,15],[60,70]]"));
	//D.push_back(8);
	//ANSWERS.push_back(StringToVectorInt("[60,68]"));

	//TESTS.push_back(StringToVectorVectorInt("[[10,50],[60,120],[140,210]]"));
	//K.push_back(StringToVectorVectorInt("[[0,15],[60,70]]"));
	//D.push_back(12);
	//ANSWERS.push_back(StringToVectorInt("[]"));

	//TESTS.push_back(StringToVectorVectorInt("[[216397070, 363167701],[98730764,158208909],[441003187,466254040], [558239978, 678368334], [683942980, 717766451]]"));
	//K.push_back(StringToVectorVectorInt("[[50490609, 222653186], [512711631, 670791418], [730229023, 802410205], [812553104, 891266775], [230032010, 399152578]]"));
	//D.push_back(456085);
	//ANSWERS.push_back(StringToVectorInt("[98730764,99186849]"));

	//////////////////////////////////////////////////////////////////////////
	vector<vector<double>> TESTS;
	vector<int> K;
	vector<double> ANSWERS;

	TESTS.push_back({ 0.4 });
	K.push_back(1);
	ANSWERS.push_back(0.40000);

	TESTS.push_back({ 0.5,0.5,0.5,0.5,0.5 });
	K.push_back(0);
	ANSWERS.push_back(0.03125);

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		//auto ans = missingNumber(TESTS[i]);
		//auto ans = minAvailableDuration(TESTS[i], K[i], D[i]);
		auto ans = probabilityOfHeads(TESTS[i], K[i], D[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		f_time_end();
	}
}