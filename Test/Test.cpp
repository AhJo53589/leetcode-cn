// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

#include "..\Common\TreeNode.h"
using namespace std;

int openLock(vector<string>& deadends, string target) 
{
	map<string, bool> mapDeadends;
	for (string s : deadends)
	{
		mapDeadends[s] = true;
	}

	queue<string> qLockNum;
	qLockNum.push("0000");
	mapDeadends["0000"] = true;
	qLockNum.push("----");

	int num = 0;

	while (!qLockNum.empty())
	{
		string strCurrent = qLockNum.front();
		qLockNum.pop();

		if (strCurrent == "----")
		{
			if (qLockNum.front() != "----")
			{
				num++;
				qLockNum.push("----");
			}
			else
			{
				break;
			}
		}

		if (!mapDeadends[strCurrent])
		{
			mapDeadends[strCurrent] = true;

			
		}
	}
	return 0;
}

vector<string> initVectorString()
{
	string str[] = { "0201","0101","0102","1212","2002" };
	vector<string> vString(str, str + sizeof(str) / sizeof(str[0]));
	return vString;
}

int main()
{
	string target = "0202";
	vector<string> deadends;
	deadends = initVectorString();

	cout << openLock(deadends, target);
}
