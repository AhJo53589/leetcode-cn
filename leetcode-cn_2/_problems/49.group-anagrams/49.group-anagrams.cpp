// 49.group-anagrams.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> hashmap;
	for (auto s : strs) {
		string temp = s;
		sort(temp.begin(), temp.end());
		hashmap[temp].push_back(s);
	}
	int len = hashmap.size();
	vector<vector<string>> ans(len);
	int index = 0;
	for (auto i : hashmap) {
		ans[index] = i.second;
		++index;
	}
	return ans;
}

int main()
{
	vector<string> strs = StringToVectorString("[\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"]");

	vector<vector<string>> vvs = groupAnagrams(strs);
	for (auto vs : vvs)
	{
		for (auto s : vs)
		{
			cout << s << " ";
		}
		cout << endl;
	}
}
