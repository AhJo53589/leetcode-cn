// 719.find-k-th-smallest-pair-distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//寻找距离不超过distance的个数（nums已经按照升序排序）
int findDistaceShort(vector<int>& nums, int distance) {
	//rightIndex代表的是在index左边且与nums[index]的距离不超过distanc的下标
	int numsSize = nums.size(), res = 0, rightIndex = numsSize - 1;
	for (int index = numsSize - 2; index >= 0; --index) {
		//修正index左边与与nums[index]的距离不超过distanc的下标
		while (rightIndex > index && nums[rightIndex] - nums[index] > distance) {
			--rightIndex;
		}
		res += (rightIndex - index);//则以index为一端，距离不超过distance的个数就是rightIndex - index
	}
	return res;
}

int smallestDistancePair(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());//按照升序排序
	//二分搜索的三个指针，left初始化为0，right初始化为最大的距离
	int left = 0, right = nums.back() - nums[0], mid;
	while (left < right) {
		mid = (left + right) / 2;
		int shortDisMid = findDistaceShort(nums, mid);//获取距离大小不超过k的距离对的个数
		//缩小[left, right]区间
		if (shortDisMid < k) {
			//<= mid的距离对个数小于k，则第k小的距离必定不会出现在[left, mid]
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int main()
{
	vector<vector<int>> N;
	vector<int> K;
	vector<double> A;

	//N.push_back({ 1,3,1 });
	//K.push_back(1);
	//A.push_back(0);

	//N.push_back({ 1,3,1 });
	//K.push_back(2);
	//A.push_back(2);

	N.push_back({ 95, 29, 47, 58, 80, 65, 26, 7, 69, 0, 1, 53, 61, 46, 66, 30, 78, 25, 1, 62, 5, 1, 78, 60, 81, 100, 52, 33, 9, 52, 7, 74, 94, 93, 47, 68, 80, 81, 50, 31, 9, 96, 8, 8, 64, 4, 40, 22, 50, 93 });
	K.push_back(1142);
	A.push_back(2);

	for (int i = 0; i < A.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		printVectorT(N[i]);
		int a = smallestDistancePair(N[i], K[i]);
		cout << "Find Smallest-Distance-Pair( " << K[i] << " ) = " << a << endl;
		cout << "Answer = " << A[i] << endl;
		if (a != A[i])
		{
			return 0;
		}
	}
}
