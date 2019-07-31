// 238.product-of-array-except-self.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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



vector<int> productExceptSelf(vector<int>& nums)
{
	auto calc = [](int i, int &k, vector<int> &ret, vector<int> &nums) { ret[i] *= k; k *= nums[i]; };
	vector<int> ret(nums.size(), 1);
	int k = 1;
	for (int i = 0; i < nums.size(); i++) calc(i, k, ret, nums);
	k = 1;
	for (int i = nums.size() - 1; i >= 0; i--) calc(i, k, ret, nums);
	return ret;
}

int main()
{
	vector<vector<int>> N;
	N.push_back({ 1,2,3,4 });

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		printVectorInt(N[i]);
		vector<int> ans = productExceptSelf(N[i]);
		printVectorInt(ans);
	}
}