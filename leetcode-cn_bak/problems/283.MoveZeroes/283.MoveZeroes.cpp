// 283.MoveZeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums)
{
	int iLen = nums.size();
	int j = 0;
	for (int i = 0; i < iLen; ++i)
	{
		if (nums[i] != 0)
		{
			if (i != j)
			{
				swap(nums[i], nums[j]);
			}
			++j;
		}
	}
}

void Init(vector<int>& nums)
{
	//int A[] = { 1,2 };
	int A[] = { 1,2,3,4 };
	//int A[] = { 1,2,3,4,5,6 };
	//int A[] = { 1,2,3,4,5,6,7 };
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
	Init2(nums);

	moveZeroes(nums);
	cout << "moveZeroes = " << endl;
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}
