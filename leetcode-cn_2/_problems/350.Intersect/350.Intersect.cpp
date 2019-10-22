// 350.Intersect.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0;
	int j = 0;
	vector<int> nums;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
		{
			i++;
		}
		else if (nums1[i] > nums2[j])
		{
			j++;
		}
		else
		{
			nums.push_back(nums1[i]);
			i++;
			j++;
		}
	}
	return nums;
}

void Init(vector<int>& nums)
{
	//int A[] = { 1,2 };
	int A[] = { 1,2,1,4 };
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
	int A[] = { 1,1,3,4,5,6,7 };
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
	vector<int> nums1;
	vector<int> nums2;
	Init(nums1);
	Init2(nums2);

	nums = intersect(nums1, nums2);
	cout << "intersect = " << endl;
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;

}
