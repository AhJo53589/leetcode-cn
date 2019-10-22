// 122.MaxProfit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)	// 4ms
{
	if (prices.size() < 2)return 0;
	int hold = -prices[0], unhold = 0;
	for (int i = 1; i < prices.size(); ++i) {
		int tmp = hold;
		hold = max(hold, unhold - prices[i]);
		unhold = max(unhold, tmp + prices[i]);
	}
	return unhold;
}

//
//int maxProfit(vector<int>& prices) // 8ms
//{
//	int len = prices.size();
//	if (len <= 1)
//		return 0;
//	int res = 0;
//	for (int i = 0; i < len - 1; i++)
//		if (prices[i + 1] - prices[i] > 0)
//			res += prices[i + 1] - prices[i];
//	return res;
//}

//int maxProfit(vector<int>& prices)	// 12ms
//{
//	if (prices.size() < 2) return 0;
//
//	int iLen = prices.size();
//	int iMaxValue = 0;
//	int high = prices[iLen - 1];
//	int low = high;
//	int j = iLen - 2;
//	while (j >= 0)
//	{
//		if (high < prices[j])
//		{
//			if (low < high)
//			{
//				iMaxValue += high - low;
//			}
//			high = prices[j];
//			low = high;
//		}
//		else
//		{
//			if (prices[j] < low)
//			{
//				low = prices[j];
//			}
//			else
//			{
//				iMaxValue += high - low;
//				high = prices[j];
//				low = high;
//			}
//		}
//		j--;
//	}
//	if (low < high)
//	{
//		iMaxValue += high - low;
//	}
//	return iMaxValue;
//}

int main()
{
	int A[] = { 7,1,5,3,6,4 };
	//int A[] = { 7,6,4,3,1 };
	//int A[] = { 1,2,3,4,5 };
	//int A[] = { 2,1,2,0,1 };
	vector<int> prices;
	for (int i : A)
	{
		prices.push_back(i);
		cout << i << " ";
	}

	int maxValue = maxProfit(prices);
	cout << endl << maxValue << endl;

}
