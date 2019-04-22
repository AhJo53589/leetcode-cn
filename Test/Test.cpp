// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)	// 32ms
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return 1;

	int iNewLen = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] != nums[iNewLen])
		{
			++iNewLen;
			if (iNewLen != i)
			{
				nums[iNewLen] = nums[i];
			}
		}
	}
	return iNewLen + 1;
}

//int removeDuplicates(vector<int>& nums)		// 20ms
//{
//	if (nums.size() == 0) return 0;
//	auto i = 0;
//	auto j = 0;
//	while (j < nums.size()) 
//	{
//		if (nums[i] == nums[j])
//			j++;
//		else
//			nums[++i] = nums[j];
//	}
//	return i + 1;
//}
//
int main()
{
	int A[] = { 0,0,0,1,1,2,3,3,4,5 };
	vector<int> nums(&A[0], &A[10]);
	int len = removeDuplicates(nums);
	for (int i = 0; i < len; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl << len << endl;
}
