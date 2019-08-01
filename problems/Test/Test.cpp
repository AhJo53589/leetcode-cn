// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

void InOrder(TreeNode *root, int &k, int &val)
{
	if (k == 0) return;
	if (root == nullptr) return;
	if (root->left != nullptr) InOrder(root->left, k, val);
	if (k-- == 1) val = root->val;
	if (root->right != nullptr) InOrder(root->right, k, val);
}

int kthSmallest(TreeNode* root, int k) 
{
	int val;
	InOrder(root, k, val);
	return val;
}

int main()
{
	vector<TreeNode *> N;
	TreeNode *pHead;
	vector<int> K;

	StringToTreeNode(&pHead, "3,1,4,null,2");
	N.push_back(pHead);
	pHead = nullptr;
	K.push_back(1);

	StringToTreeNode(&pHead, "5,3,6,2,4,null,null,1");
	N.push_back(pHead);
	pHead = nullptr;
	K.push_back(3);
		
	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printTreeNode(N[i]);
		cout << "kth Smallest, k = " << K[i] << ", ans = ";
		cout << kthSmallest(N[i], K[i]) << endl;
	}
}

//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = nullptr;
//	StringToListNode(&pHead, "[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto p : lists)
//	{
//		PrintLinkList(p);
//		pHead = sortList(p);
//		PrintLinkList(pHead);
//		cout << endl;
//	}
//}

//int main()
//{
//	vector<int> N;
//	N.push_back(121);
//	N.push_back(-121);
//	N.push_back(10);
//	N.push_back(9);
//	N.push_back(123454321);
//	N.push_back(123321);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "/////////////////////////////////" << endl;
//		cout << N[i] << endl;
//		bool ans = isPalindrome(N[i]);
//		cout << ans << endl;
//	}
//}


//int main()
//{
//	vector<vector<int>> N;
//	N.push_back({ 1,2,3,4 });
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "/////////////////////////////////" << endl;
//		printVectorInt(N[i]);
//		vector<int> ans = productExceptSelf(N[i]);
//		printVectorInt(ans);
//	}
//}

//int main()
//{
//	vector<vector<int>> N;
//	vector<int> K;
//	//vector<double> A;
//
//	//N.push_back({ -1, 0, 1, 2, -1, -4 });
//	//K.push_back(1142);
//	//A.push_back(2);
//
//	//N.push_back({ -1, 2, 1, -4 });
//	//K.push_back(1);
//
//	//N.push_back({ 0, 2, 1 });
//	//K.push_back(3);
//
//	N.push_back({ 1, 1, 1, 1 });
//	K.push_back(0);
//
//	//N.push_back({ -1, 0, 1, 2, -1, -4 });
//	//N.push_back({ 0, 0, 1 });
//	//N.push_back({ 0, 0, 0 });
//	//N.push_back({ 0, 0, 0, 1 });
//	//N.push_back({  });
//	//N.push_back({ -2, -3, 0, 0, -2 });
//	//N.push_back({ -1, 0, 1, 0 });
//	//N.push_back({ 3, 0, -2, -1, 1, 2 });
//	//N.push_back({ 1, 1, -2 });
//	//N.push_back({ -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 });
//	//N.push_back({ -4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0 });
//
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "/////////////////////////////" << endl;
//		printVectorInt(N[i]);
//		sort(N[i].begin(), N[i].end());
//		printVectorInt(N[i]);
//		int a = threeSumClosest(N[i], K[i]);
//		cout << "target = " << K[i] << endl;
//		cout << "threeSum = " << a << endl;
//	}
//}

