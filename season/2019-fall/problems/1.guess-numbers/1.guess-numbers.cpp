// 1.guess-numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include <algorithm>
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
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
int game(vector<int>& guess, vector<int>& answer)
{
	int ans = 0;
	for (size_t i = 0; i < guess.size(); i++)
	{
		ans = (guess[i] == answer[i]) ? ans + 1 : ans;
	}
	return ans;
}


int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_cout = [&]()
	{
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	//vector<vector<vector<int>>> TESTS;
	////vector<int> K;
	//vector<vector<int>> ANSWERS;

	//TESTS.push_back({ 3,2,0,2 });
	//ANSWERS.push_back({ 13,4 });

	//TESTS.push_back({ 0,0,3 });
	//ANSWERS.push_back({ 3,1 });

	//TESTS.push_back({ 3 });
	//ANSWERS.push_back({ 3,1 });

	//////////////////////////////////////////////////////////////////////////
	//vector<vector<vector<int>>> TESTS;
	//vector<string> C;
	//vector<int> X;
	//vector<int> Y;
	//vector<bool> ANSWERS;

	//TESTS.push_back({  });
	//C.push_back("URR");
	//X.push_back(3);
	//Y.push_back(2);
	//ANSWERS.push_back(true);

	//TESTS.push_back({ {2,2} });
	//C.push_back("URR");
	//X.push_back(3);
	//Y.push_back(2);
	//ANSWERS.push_back(false);

	//TESTS.push_back({ {4,2} });
	//C.push_back("URR");
	//X.push_back(3);
	//Y.push_back(2);
	//ANSWERS.push_back(true);

	//////////////////////////////////////////////////////////////////////////
	//vector<int> TESTS;
	//vector<vector<vector<int>>> L;
	//vector<vector<vector<int>>> O;
	//vector<vector<int>> ANSWERS;

	//TESTS.push_back(6);
	//L.push_back({ {1, 2},{1, 6},{2, 3},{2, 5},{1, 4} });
	//O.push_back({ {1, 1, 500},{2, 2, 50},{3, 1},{2, 6, 15},{3, 1} });
	//ANSWERS.push_back({ 650, 665 });

	vector<vector<int>> TESTS;
	vector<vector<int>> N;
	vector<int> ANSWERS;

	TESTS.push_back({ 1,2,3 });
	N.push_back({ 1,2,3 });
	ANSWERS.push_back(3);

	TESTS.push_back({ 2,2,3 });
	N.push_back({ 3,2,1 });
	ANSWERS.push_back(1);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = game(TESTS[i], N[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//nextPermutation(TESTS[i]);
		//cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}