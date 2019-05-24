// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "..\Common\TreeNode.h"
using namespace std;


int rob(vector<int>& nums) 
{

}

void initVectorInt(vector<int> &nums)
{
	//int A[] = { 1,2,3,1 };
	//int A[] = { 2,7,9,3,1 };
	//int A[] = { 2,4,8,9,9,3 };
	int A[] = { 1,3,1,3,100 };
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
	initVectorInt(nums);
	cout << endl << rob(nums) << endl;
}
