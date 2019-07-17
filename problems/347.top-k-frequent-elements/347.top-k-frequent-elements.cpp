// 347.top-k-frequent-elements.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<int> topKFrequent(vector<int>& nums, int k)
{
	vector<int> res;
	unordered_map<int, int> m;
	for (auto n : nums) m[n]++;

	vector<pair<int, int>> freq;
	for (auto x : m) freq.push_back(x);
	sort(freq.begin(), freq.end(), [](auto a, auto b) { return a.second > b.second; });

	auto it = freq.begin();
	for (int i = 0; i < k; i++)
	{
		res.push_back(it->first);
		it++;
	}
	return res;
}

//vector<int> topKFrequent(vector<int>& nums, int k) {
//	unordered_map<int, int> m;
//	for (auto i : nums) {
//		m[i]++;
//	}
//	multimap<int, int, greater<int>> s;
//	for (auto i : m) {
//		s.insert(make_pair(i.second, i.first));
//	}
//	vector<int> res;
//	for (auto i : s) {
//		if (res.size() == k) break;
//		res.push_back(i.second);
//	}
//	return res;
//}

int main()
{
	vector<int> nums = StringToVectorInt("[1,1,1,1,1,2,2,3,3,3,3,3]");
	int k = 2;
	vector<int> r = topKFrequent(nums, k);
	printVectorInt(r);
}
