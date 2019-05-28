// 204.CountPrimes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


int countPrimes(int n) 
{
	if (n < 3) return 0;

	vector<bool> primeFlag(n);
	primeFlag[2] = true;
	for (long long i = 3; i < n; i += 2)
	{
		primeFlag[i] = true; // 所有奇数标为true，偶数为false
	}
	for (long long i = 3; i < n; i++)
	{
		if (primeFlag[i])
		{
			int cnt = 2;
			while (cnt * i < n)
			{
				// 把i的倍数标为false（因为它们是合数）
				primeFlag[cnt * i] = false;
				cnt++;
			}
		}
	}

	int cnt = 1;
	for (long long i = 3; i < n; i += 2)
	{
		if (primeFlag[i])
		{
			//cout << cnt << ' ' << i << endl;
			cnt++;
		}
	}
	return cnt;
}

//int countPrimes(int k)
//{
//	if (k < 3)
//	{
//		return 0;
//	}
//
//	vector<bool> arr(k);
//
//	for (int i = 0; i < k; i++)
//	{
//		arr[i] = true;
//	}
//
//	int m = sqrt(k);
//
//	for (int i = 3; i <= m; i += 2)
//	{
//		if (arr[i])
//		{
//			int step = i + i;
//			for (int j = i + step; j < k; j += step)
//			{
//				arr[j] = false;
//			}
//		}
//	}
//
//	int sum = 1;
//	for (int i = 3; i < k; i += 2)
//	{
//		if (arr[i])
//		{
//			sum++;
//		}
//	}
//
//	return sum;
//}

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
