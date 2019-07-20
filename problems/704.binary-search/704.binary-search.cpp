// 704.binary-search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


//int lowerBound(vector<int> &nums, int target, int low, int high)
//{
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		if (nums[mid] < target) low = mid + 1;
//		else high = mid;
//	}
//	return low;
//}

int lowerBound(vector<int> &nums, int target, int low, int high)
{
	if (low >= high) return low;
	int mid = low + (high - low) / 2;
	if (nums[mid] < target) return lowerBound(nums, target, mid + 1, high);
	else return lowerBound(nums, target, low, mid);
}

int search(vector<int>& nums, int target)
{
	int i = lowerBound(nums, target, 0, nums.size());
	if (i == nums.size()) return -1;
	return (nums[i] == target) ? i : -1;
}

int main()
{
	vector<string> strInput;
	vector<int> target;
	vector<int> answer;
	strInput.push_back("[-1,0,3,5,9,12]");
	target.push_back(9);
	answer.push_back(4);

	strInput.push_back("[-1,0,3,5,9,12]");
	target.push_back(2);
	answer.push_back(-1);

	strInput.push_back("[-1,0,3,5,9,12]");
	target.push_back(13);
	answer.push_back(-1);

	for (int i = 0; i < strInput.size(); i++)
	{
		cout << endl << "////////////////////////////////////" << endl;
		cout << "Input: " << endl;
		vector<int> nums = StringToVectorInt(strInput[i]);
		printVectorInt(nums);

		int f = search(nums, target[i]);
		cout << "Find value = " << target[i] << endl;
		cout << "Index = " << f << endl;
		cout << "Answer = " << answer[i] << endl;
	}
}
