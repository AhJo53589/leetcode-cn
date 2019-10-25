// 771.jewels-and-stones.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

//#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

int numJewelsInStones(string J, string S)
{
	unordered_set<char> s;
	for (auto c : J) s.insert(c);
	int i = 0;
	for (auto c : S) if (s.count(c)) i++;
	return i;
}

int main()
{
	string J = "aA";
	string S = "aAAbbbb";

	cout << numJewelsInStones(J, S) << endl;
}
