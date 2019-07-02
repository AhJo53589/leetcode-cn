// 119.pascals-triangle-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

#include "..\Common\Common.h"
using namespace std;

vector<int> getRow(int rowIndex) {
	if (rowIndex < 0)
		return vector<int>();
	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;
	for (int i = 1; i <= rowIndex; ++i)
		for (int j = i; j >= 1; --j) {
			res[j] += res[j - 1];
		}
	return res;
}

//// 根据组合数公式C(n,i)=n!/(i!*(n-i)!)直接由C(n,i)算C(n,i+1),后者是前者的(n-i)/(i+1)倍
//vector<int> getRow(int rowIndex)
//{
//	vector<int> res;
//	if (rowIndex < 0) return res;
//	res.push_back(1);
//	for (int i = 0; i < rowIndex; ++i)
//		res.push_back(static_cast<int>(double(res[i])*(rowIndex - i) / (i + 1))); //注意res[i]不进行类型转换会造成结果overflow 
//	return res;
//}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		vector<int> nums = getRow(i);
		printVectorInt(nums);
	}
}
