// 108.SortedArrayToBST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

TreeNode* sortedArrayToBST(vector<int>& nums, size_t _First, size_t _Last)
{
	if (_Last <= _First) return NULL;

	size_t _Mid = _First + (_Last - _First) / 2;
	TreeNode *pNode = new TreeNode(nums[_Mid]);
	TreeNode *pLeft = sortedArrayToBST(nums, _First, _Mid);
	TreeNode *pRight = sortedArrayToBST(nums, _Mid + 1, _Last);
	pNode->left = pLeft;
	pNode->right = pRight;
	return pNode;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	size_t _First = 0;
	size_t _Last = nums.size();
	if (_Last == 0) return NULL;

	return sortedArrayToBST(nums, _First, _Last);
}

void Init(vector<int>& nums)
{
	//int A[] = { 1,2 };
	//int A[] = { 1,2,3,4 };
	//int A[] = { 1,2,3,4,5,6 };
	int A[] = { -10,-3,0,5,9 };
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
	TreeNode *root = NULL;
	root = sortedArrayToBST(nums);
	DrawTreeNode(root);
}
