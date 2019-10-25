// 66.PlusOne.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	if (digits.size() == 0) return digits;

	int i = digits.size() - 1;
	int bUpFlag = 1;
	while (i >= 0 && bUpFlag > 0)
	{
		digits[i] += bUpFlag;
		bUpFlag--;
		if (digits[i] > 9)
		{
			bUpFlag += digits[i] / 10;
			digits[i] %= 10;
		}
		i--;
	}
	if (bUpFlag > 0)
	{
		digits.insert(digits.begin(), bUpFlag);
	}
	return digits;
}

void Init(vector<int>& nums)
{
	//int A[] = { 1,2 };
	int A[] = { 9,9,9,9 };
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
	Init(nums);

	nums = plusOne(nums);
	cout << "plusOne = " << endl;
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}
