// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> ret;
	unordered_multimap<int, pair<int, int>> map;
	int low = -1;
	int high = -1;
	int mid = 0;
	sort(nums.begin(), nums.end());

	if (nums.size() < 3) return {};
	if (nums[0] > 0) return {};
	if (nums[nums.size() - 1] < 0) return {};
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0) low = i;
		if (nums[i] == 0) mid++;
		if (nums[i] > 0)
		{
			high = i;
			break;
		}
	}
	if ((low == -1 || high == -1) && mid >= 3) return { {0, 0, 0} };
	if ((low == -1 || high == -1) && mid < 3) return {};

	for (int i = 0; i <= low; i++)
	{
		if (i != 0 && nums[i] == nums[i - 1]) continue;
		for (int j = nums.size() - 1; j >= high; j--)
		{
			if (j != nums.size() - 1 && nums[j] == nums[j + 1]) continue;
			map.insert({ nums[i] + nums[j], {i, j} });
		}
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (i < low && nums[i] == nums[i + 1]) continue;
		if (nums[i] == 0 && nums[i + 1] == 0) continue;
		if (i > high && nums[i] == nums[i - 1]) continue;
		auto pr = map.equal_range(-nums[i]);
		while (pr.first != pr.second)
		{
			if (pr.first->second.first < i && i < pr.first->second.second)
			{
				ret.push_back({ nums[pr.first->second.first], nums[i], nums[pr.first->second.second] });
			}
			++pr.first;
		}
	}
	if (mid >= 3) ret.push_back({ 0, 0, 0 });
	return ret;
}



int main()
{
	vector<vector<int>> N;
	//vector<int> K;
	//vector<double> A;

	//N.push_back({ -1, 0, 1, 2, -1, -4 });
	//K.push_back(1142);
	//A.push_back(2);

	//N.push_back({ -1, 0, 1, 2, -1, -4 });
	//N.push_back({ 0, 0, 1 });
	//N.push_back({ 0, 0, 0 });
	//N.push_back({ 0, 0, 0, 1 });
	//N.push_back({  });
	//N.push_back({ -2, -3, 0, 0, -2 });
	//N.push_back({ -1, 0, 1, 0 });
	//N.push_back({ 3, 0, -2, -1, 1, 2 });
	//N.push_back({ 1, 1, -2 });
	//N.push_back({ -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 });
	N.push_back({ -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 });


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		printVectorInt(N[i]);
		sort(N[i].begin(), N[i].end());
		printVectorInt(N[i]);
		vector<vector<int>> a = threeSum(N[i]);
		cout << "threeSum = " << endl;
		printVectorVectorInt(a);
	}
}

//int main()
//{
//	vector<string> str;
//	//str.push_back("babad");
//	//str.push_back("babab");
//	//str.push_back("cbbd");
//	str.push_back("ac");
//
//	for (auto s : str)
//	{
//		cout << endl << "/////////////////////////////////" << endl;
//		cout << s << endl;
//		cout << longestPalindrome(s) << endl;
//	}
//}
