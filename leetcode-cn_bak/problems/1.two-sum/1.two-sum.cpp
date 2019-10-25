// 1.two-sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> sum;
	vector<int> rst;
	for (int i = 0; i < nums.size(); i++)
	{
		if (sum.find(target - nums[i]) != sum.end())
		{
			rst.push_back(sum[target - nums[i]]);
			rst.push_back(i);
			break;
		}
		else
		{
			sum[nums[i]] = i;
		}
	}
	return rst;
}

//vector<int> twoSum(vector<int> &nums, int target)	// 4ms
//{
//	vector<int> v;
//	unordered_map<int, int> hash;
//	for (int i = nums.size() - 1; i >= 0; hash[nums[i]] = i, i--)
//	{
//		if (hash.find(target - nums[i]) == hash.end())
//			continue;
//		v.push_back(i);
//		v.push_back(hash[target - nums[i]]);
//		return v;
//	}
//	return v;
//}

void Init(vector<int>& nums)
{
	//int A[] = { 1,2 };
	//int A[] = { 1,2,3,4 };
	//int A[] = { 1,2,3,4,5,6 };
	int A[] = { 1,2,3,4,5,6,7 };
	nums.clear();
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
	cout << endl;
}

void Init2(vector<int>& nums)
{
	//int A[] = { 1,2 };
	//int A[] = { 1,2,3,4 };
	//int A[] = { 1,2,3,4,5,6 };
	int A[] = { 1,1,0,4,0,6,7 };
	nums.clear();
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums;
	Init(nums);

	vector<int> rst = twoSum(nums, 9);
	cout << "twoSum = " << endl;
	for (int i : rst)
	{
		cout << i << " ";
	}
	cout << endl;
}
