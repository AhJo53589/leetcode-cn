// 599.minimum-index-sum-of-two-lists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
	unordered_map<string, int> restIndex;
	unordered_set<string> restList2;
	for (int i = 0; i < list1.size(); i++)
	{
		restIndex[list1[i]] = i;
	}
	for (int i = 0; i < list2.size(); i++)
	{
		if (!restIndex.count(list2[i])) continue;
		restList2.insert(list2[i]);
		restIndex[list2[i]] += i;
	}

	int rIndex = INT_MAX;
	vector<string> rst;
	for (auto r : restIndex)
	{
		if (!restList2.count(r.first)) continue;
		if (r.second == rIndex)
		{
			rst.push_back(r.first);
		}
		else if (r.second < rIndex)
		{
			rIndex = r.second;
			rst.clear();
			rst.push_back(r.first);
		}
	}
	return rst;
}

int main()
{
	//string s1 = "[\"KFC\", \"Shogun\", \"Burger King\"]";
	//string s2 = "aa";
	string s1 = "[\"Shogun\", \"Tapioca Express\", \"Burger King\", \"KFC\"]";
	string s2 = "[\"KFC\", \"Shogun\", \"Burger King\"]";
	vector<string> vs1 = StringToVectorString(s1);
	for_each(vs1.begin(), vs1.end(), [](auto s) {cout << s << " "; });
	cout << endl;
	vector<string> vs2 = StringToVectorString(s2);
	for_each(vs2.begin(), vs2.end(), [](auto s) {cout << s << " "; });
	cout << endl;

	vector<string> vs = findRestaurant(vs1, vs2);
	for (auto s : vs) cout << s << " ";
}
