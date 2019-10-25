// 16.3sum-closest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int threeSumClosest(vector<int>& nums, int target)
{
	int ret = INT_MAX;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	if (len < 3) return 0;
	for (int i = 0; i < len; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
		int L = i + 1;
		int R = len - 1;
		while (L < R)
		{
			int sum = nums[i] + nums[L] + nums[R];
			int temp = sum - target;
			ret = (abs(temp) < abs(ret)) ? temp : ret;
			if (sum == target) return target;
			if (sum < target) L++;
			else if (sum > target) R--;
		}
	}
	return target + ret;
}


int main()
{
	vector<vector<int>> N;
	vector<int> K;

	N.push_back({ -1, 2, 1, -4 });
	K.push_back(1);

	N.push_back({ 0, 2, 1 });
	K.push_back(3);

	N.push_back({ 1, 1, 1, 1 });
	K.push_back(0);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		printVectorT(N[i]);
		sort(N[i].begin(), N[i].end());
		printVectorT(N[i]);
		int a = threeSumClosest(N[i], K[i]);
		cout << "target = " << K[i] << endl;
		cout << "threeSum = " << a << endl;
	}
}