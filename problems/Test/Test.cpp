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
	if (nums.size() < 3) return {};
	unordered_set<vector<int>> set;
	int l = 0;
	int r = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= 0)
		{
			if (nums[i] == 0) l = i;
			break;
		}
		for (int j = nums.size() - 1; j >= 0; j--)
		{
			if (nums[j] <= 0)
			{
				if (nums[j] == 0) r = j;
				break;
			}
			for (int k = i + 1; k < j; k++)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					if (set.count({ i, k, j })) break;
					set.insert({ i, k, j });
					break;
				}
			}
		}
	}
	if (r - l > 2) set.insert({ 0, 0, 0 });
	vector<vector<int>> ret;
	for (auto s : set)
	{
		ret.push_back(s);
	}
	return ret;
}


int main()
{
	vector<vector<int>> N;
	//vector<int> K;
	//vector<double> A;

	N.push_back({ -1, 0, 1, 2, -1, -4 });

	//N.push_back({ 1,3,1 });
	//K.push_back(2);
	//A.push_back(2);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		printVectorInt(N[i]);
		vector<vector<int>> a = threeSum(N[i]);
		cout << "three Sum: " << endl;
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
