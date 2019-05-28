// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

#include "..\Common\TreeNode.h"
using namespace std;


bool isPowerOfThree(int n) 
{

}

void initVectorInt(vector<int> &nums)
{
	//int A[] = { 1,2,3,1 };
	//int A[] = { 2,7,9,3,1 };
	//int A[] = { 2,4,8,9,9,3 };
	int A[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
	cout << endl;
}

void printfVectorInt(vector<int> &nums)
{
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//vector<int> nums;
	//initVectorInt(nums);
	//Solution* obj = new Solution(nums);
	//vector<int> param_2 = obj->shuffle();
	//printfVectorInt(param_2);
	//vector<int> param_1 = obj->reset();
	//printfVectorInt(param_1);

	cout << endl << countPrimes(100) << endl;
}
