// 4.median-of-two-sorted-arrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	if (m > n) return findMedianSortedArrays(nums2, nums1);
	if (m + n == 1) return nums2[0];

	bool odd = (m + n) % 2 == 1;
	int i1 = 0;
	int i2 = 0;
	int iPrev2 = 0;
	int iPrev = 0;

	while (i1 + i2 < (m + n) / 2 + 1)
	{
		iPrev2 = iPrev;
		if (odd && i1 == m) return nums2[n - (m + n) / 2 - 1];
		else if (odd && i2 == n) return nums1[m - (m + n) / 2 - 1];
		else if (!odd && i1 == m) iPrev = nums2[i2++];
		else if (!odd && i2 == n) iPrev = nums1[i1++];
		else iPrev = (nums1[i1] < nums2[i2]) ? nums1[i1++] : nums2[i2++];
	}
	return odd ? iPrev : (double)(iPrev + iPrev2) / 2;
}

int main()
{
	vector<vector<vector<int>>> N;
	vector<double> answer;

	N.push_back({ { 1 }, {  } });
	answer.push_back(1);

	N.push_back({ { 1, 2 }, {  } });
	answer.push_back(1.5);

	N.push_back({ { 1 }, { 2 } });
	answer.push_back(1.5);

	N.push_back({ {  }, { 1, 2 } });
	answer.push_back(1.5);

	N.push_back({ { 1, 3 }, { 2 } });
	answer.push_back(2.0);

	N.push_back({ { 1, 2 }, { 3, 4 } });
	answer.push_back(2.5);

	N.push_back({ { 1, 3 }, { 2, 4 } });
	answer.push_back(2.5);

	N.push_back({ { 1, 3 }, { 2, 4, 5 } });
	answer.push_back(3.0);

	N.push_back({ { 1 }, { 2, 3, 4 } });
	answer.push_back(2.5);

	N.push_back({ { 2 }, { 1, 3, 5 } });
	answer.push_back(2.5);


	for (int i = 0; i < answer.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		for (auto i : N[i][0]) cout << i << ", ";
		cout << endl;
		for (auto i : N[i][1]) cout << i << ", ";
		cout << endl;
		double a = findMedianSortedArrays(N[i][0], N[i][1]);
		cout << "Find Median-Sorted-Arrays = " << a << endl;
		cout << "Answer = " << answer[i] << endl;
		if (a != answer[i])
		{
			return 0;
		}
	}
}
