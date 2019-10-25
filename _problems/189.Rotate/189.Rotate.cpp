// 189.Rotate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <vector>
using namespace std;

void swap(int &a, int &b)
{
	if (a == b) return;
	a ^= b;
	b ^= a;
	a ^= b;
}

void rotate(vector<int>& nums, int k)	// 28ms
{
	k = k % nums.size();

	int iLen = nums.size();
	while (k > 0 && iLen > 1 && iLen != k)
	{
		for (int i = iLen - 1; i > k - 1; i--)
		{
			swap(nums[i], nums[i - k]);
		}

		int tmp = k;
		k = k - iLen % k;
		iLen = tmp;
	}
}

//void rotate(vector<int>& nums, int k)	// 12ms
//{
//	k = k >= nums.size() ? k - nums.size() : k;
//	if (k)
//	{
//		reverse(nums.begin(), nums.end() - k);
//		reverse(nums.end() - k, nums.end());
//		reverse(nums.begin(), nums.end());
//	}
//}

void Init(vector<int>& nums)
{
	//int A[] = { 1,2 };
	//int A[] = { 1,2,3,4 };
	//int A[] = { 1,2,3,4,5,6 };
	int A[] = { 1,2,3,4,5,6,7 };
	//int A[] = { 1,2,3,4,5,6,7,8 };
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

	for (int k = 3; k < 4; k++)
	{
		Init(nums);
		cout << "k = " << k << endl;
		rotate(nums, k);
		for (auto i : nums)
		{
			cout << i << " ";
		}
		cout << endl << endl;
	}
}
