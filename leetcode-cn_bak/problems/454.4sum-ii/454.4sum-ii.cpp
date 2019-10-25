// 454.4sum-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	unordered_map<int, int> rec;
	int res = 0;
	for (int i = 0; i < C.size(); i++)
		for (int j = 0; j < D.size(); j++)
			rec[C[i] + D[j]]++;

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++) {
			if (rec.find(-A[i] - B[j]) != rec.end())
				res += rec[-A[i] - B[j]];
		}
	return res;
}

int main()
{
	vector<int> A = StringToVectorInt("[1,2]");
	vector<int> B = StringToVectorInt("[-2,-1]");
	vector<int> C = StringToVectorInt("[-1,2]");
	vector<int> D = StringToVectorInt("[0,2]");

	cout << fourSumCount(A, B, C, D) << endl;
}
