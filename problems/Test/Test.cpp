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
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;



//////////////////////////////////////////////////////////////////////////
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
	if (preorder.size() != inorder.size() || inorder.size() == 0) return nullptr;

	int val = preorder[0];
	bool f = false;
	vector<int> left_inorder;
	vector<int> right_inorder;
	for (auto n : inorder)
	{
		if (n == val) { f = true; continue; }

		if (!f) left_inorder.push_back(n);
		else right_inorder.push_back(n);
	}
	vector<int> left_preorder;
	vector<int> right_preorder;
	for (auto n : preorder)
	{
		if (n == val) continue;
		if (left_inorder.size() > left_preorder.size()) left_preorder.push_back(n);
		else if (right_inorder.size() > right_preorder.size()) right_preorder.push_back(n);
	}

	TreeNode *root = new TreeNode(val);
	root->left = buildTree(left_preorder, left_inorder);
	root->right = buildTree(right_preorder, right_inorder);
	return root;
}

int main()
{
	vector<pair<vector<int>, vector<int>>> N;
	vector<string> A;

	N.push_back({ {3,9,20,15,7}, {9,3,15,20,7} });
	A.push_back("3,9,20,null,null,15,7");

	for (size_t i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printVectorInt(N[i].first);
		printVectorInt(N[i].second);
		TreeNode *pNode = buildTree(N[i].first, N[i].second);
		cout << "buildTree = " << endl;
		cout << A[i] << endl;
		cout << "my answer = " << endl;
		printTreeNode(pNode);
	}
}

//int main()
//{
//	vector<TreeNode *> N;
//	vector<vector<vector<int>>> A;
//	TreeNode *pHead = nullptr;
//
//	StringToTreeNode(&pHead, "3,9,20,null,null,15,7");
//	N.push_back(pHead);
//	A.push_back({ {3}, { 9,20 }, { 15,7 } });
//	pHead = nullptr;
//
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		printTreeNode(N[i]);
//		cout << "levelOrder = " << endl;
//		printVectorVectorInt(A[i]);
//		vector<vector<int>> ans = levelOrder(N[i]);
//		cout << "my answer = " << endl;
//		printVectorVectorInt(ans);
//	}
//}

//int main()
//{
//	vector<vector<vector<int>>> N;
//	vector<vector<vector<int>>> A;
//
//	N.push_back({ { 1,3 }, { 2,6 }, { 8,10 }, { 15,18 } });
//	A.push_back({ { 1,6 }, { 8,10 }, { 15,18 } });
//
//	N.push_back({ { 1,4 }, { 4,5 } });
//	A.push_back({ { 1,5 } });
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "/////////////////////////////////" << endl;
//		printVectorVectorInt(N[i]);
//		vector<vector<int>> ans = merge(N[i]);
//		cout << "merge = " << endl;
//		printVectorVectorInt(A[i]);
//		cout << "my answer = " << endl;
//		printVectorVectorInt(ans);
//	}
//}

// int main()
// {
// 	vector<int> N;
// 	vector<int> A;
// 
// 	N.push_back(4);
// 	A.push_back(1);
// 
// 
// 	for (int i = 0; i < N.size(); i++)
// 	{
// 		cout << endl << "/////////////////////////////////" << endl;
// 		cout << N[i] << " = " << A[i] << endl;
// 		bool ans = canWinNim(N[i]);
// 		cout << "my answer = " << ans << endl;
// 	}
// }


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

