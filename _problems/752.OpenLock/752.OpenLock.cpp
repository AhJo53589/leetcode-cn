// 752.OpenLock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

using namespace std;



//int openLock(vector<string>& deadends, string target) {
//	unordered_set<string> deadset(deadends.begin(), deadends.end());
//	if (deadset.count("0000") || deadset.count(target)) {
//		return -1;
//	}
//	vector<string> movesToTarget;
//	auto moves = getValidMoves(target);
//	for (auto& move : moves) {
//		if (!deadset.count(move)) {
//			movesToTarget.push_back(move);
//		}
//	}
//	// 可以直接从deadends中看出target可不可达
//	if (movesToTarget.empty()) {
//		return -1;
//	}
//	// 最大步长是40步（每位转动10次）
//	int min_stride = 40;
//	// 计算到达每个可达结果的步长，取最小
//	for (auto& move : movesToTarget) {
//		int cur_stride = 0;
//		for (int i = 0; i < 4; ++i) {
//			int turns = move[i] - '0';
//			// 可以倒着转，所以转动次数不会大过5
//			if (turns > 5) {
//				turns = 10 - turns;
//			}
//			cur_stride += turns;
//		}
//		if (cur_stride < min_stride) {
//			min_stride = cur_stride;
//		}
//	}
//	// 最后加上到达target的那一步
//	return min_stride + 1;
//}
//
//vector<string> getValidMoves(const string& sequence) {
//	vector<string> moves;
//	for (int i = 0; i < 4; i++) {
//		string temp = sequence;
//		// +1
//		temp[i] = temp[i] == '9' ? '0' : temp[i] + 1;
//		moves.push_back(temp);
//		// -1
//		temp = sequence;
//		temp[i] = temp[i] == '0' ? '9' : temp[i] - 1;
//		moves.push_back(temp);
//	}
//	return moves;
//}

vector<string> getNextMoveList(string strCurrent)
{
	vector<string> vStr;
	for (int i = 0; i < 4; i++)
	{
		string strTemp = strCurrent;
		int iCurrent = strCurrent[i] - '0';

		strTemp[i] = ((iCurrent + 1) % 10) + '0';
		vStr.push_back(strTemp);
		strTemp[i] = ((iCurrent + 10 - 1) % 10) + '0';
		vStr.push_back(strTemp);
	}
	return vStr;
}

int openLock(vector<string>& deadends, string target)
{
	map<string, bool> mapDeadends;
	for (string s : deadends)
	{
		mapDeadends[s] = true;
	}

	string strInit("0000");
	string strEnd("----");
	if (mapDeadends[strInit]) return -1;

	queue<string> qLockNum;
	qLockNum.push(strInit);
	mapDeadends[strInit] = true;
	qLockNum.push(strEnd);

	int num = 1;
	while (!qLockNum.empty())
	{
		string strCurrent = qLockNum.front();
		qLockNum.pop();
		//cout << strCurrent << endl;

		if (strCurrent == strEnd)
		{
			if (qLockNum.empty() || qLockNum.front() == strEnd) break;

			num++;
			qLockNum.push(strEnd);
			continue;
		}

		vector<string> strNextMoveList = getNextMoveList(strCurrent);
		for (string sNext : strNextMoveList)
		{
			if (!mapDeadends[sNext])
			{
				if (sNext == target) return num;
				mapDeadends[sNext] = true;
				qLockNum.push(sNext);
			}
		}
	}
	return -1;
}

void init(vector<string> &strDeadends, string &strTarget)
{
	// test 01
	strTarget = "0202";
	string _sDeadends[] = { "0201","0101","0102","1212","2002" };
	vector<string> vString(_sDeadends, _sDeadends + sizeof(_sDeadends) / sizeof(_sDeadends[0]));
	strDeadends = vString;

	//// test 02
	//strTarget = "0009";
	//string _sDeadends[] = { "8888" };
	//vector<string> vString(_sDeadends, _sDeadends + sizeof(_sDeadends) / sizeof(_sDeadends[0]));
	//strDeadends = vString;

	//// test 03
	//strTarget = "8888";
	//string _sDeadends[] = { "8887","8889","8878","8898","8788","8988","7888","9888" };
	//vector<string> vString(_sDeadends, _sDeadends + sizeof(_sDeadends) / sizeof(_sDeadends[0]));
	//strDeadends = vString;

	//// test 04
	//strTarget = "8888";
	//string _sDeadends[] = { "0000" };
	//vector<string> vString(_sDeadends, _sDeadends + sizeof(_sDeadends) / sizeof(_sDeadends[0]));
	//strDeadends = vString;
}

int main()
{
	string strTarget;
	vector<string> strDeadends;
	init(strDeadends, strTarget);

	int a;
	cin >> a;
	cout << openLock(strDeadends, strTarget) << endl;
}
