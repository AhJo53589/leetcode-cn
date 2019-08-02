// 292.nim-game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;



bool canWinNim(int n)
{
	return n % 4 != 0;
}


int main()
{
	vector<int> N;
	vector<int> A;

	N.push_back(4);
	A.push_back(1);


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << N[i] << " = " << A[i] << endl;
		bool ans = canWinNim(N[i]);
		cout << "my answer = " << ans << endl;
	}
}
