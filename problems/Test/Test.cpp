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

//////////////////////////////////////////////////////////////////////////
int funDelete(TreeNode **ppNode)
{
	int res = (*ppNode)->val;
	if ((*ppNode)->left == nullptr || (*ppNode)->right == nullptr)
	{
		TreeNode *pChild = ((*ppNode)->left != nullptr) ? (*ppNode)->left : (*ppNode)->right;
		delete (*ppNode);
		*ppNode = pChild;
	}
	else
	{
		TreeNode **ppChild = &((*ppNode)->left->right);
		while ((*ppChild) != nullptr && (*ppChild)->right != nullptr) ppChild = &((*ppChild)->right);	
		if ((*ppChild) == nullptr)
		{
			ppChild = &((*ppNode)->right->left);
			while ((*ppChild) != nullptr && (*ppChild)->left != nullptr) ppChild = &((*ppChild)->left);
		}
		if ((*ppChild) == nullptr) ppChild = &((*ppNode)->right);
		(*ppNode)->val = funDelete(ppChild);
	}
	return res;
}

TreeNode* deleteNode(TreeNode* root, int key) //执行用时：28 ms
{
	TreeNode **ppNode = &root;
	while ((*ppNode) != nullptr)
	{
		if (key == (*ppNode)->val)
		{
			funDelete(ppNode);
			return root;
		}
		if (key < (*ppNode)->val) ppNode = &((*ppNode)->left);
		else ppNode = &((*ppNode)->right);
	}
	return root;
}


int main()
{
	vector<TreeNode *> N;
	vector<int> K;
	vector<TreeNode *> A;

	//N.push_back(StringToTreeNode("5,3,6,2,4,null,7"));
	//K.push_back(3);
	//A.push_back(StringToTreeNode("5,4,6,2,null,null,7"));

	//N.push_back(StringToTreeNode("5,3,6,2,4,null,7"));
	//K.push_back(5);
	//A.push_back(StringToTreeNode("4,3,6,2,null,null,7"));

	//N.push_back(StringToTreeNode("2,0,33,null,1,25,40,null,null,11,31,34,45,10,18,29,32,null,36,43,46"));
	//K.push_back(33);
	//A.push_back(StringToTreeNode("2,0,34,null,1,25,40,null,null,11,31,35,45,10,18,29,32,null,36,43,46"));

	//N.push_back(StringToTreeNode("2,0,33,null,1,25,40,null,null,11,31,34,45,10,18,29,32,null,36,43,46,4,null,12,24,26,30,null,null,35,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6"));
	//K.push_back(33);
	//A.push_back(StringToTreeNode("2,0,34,null,1,25,40,null,null,11,31,35,45,10,18,29,32,null,36,43,46,4,null,12,24,26,30,null,null,null,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6"));

	N.push_back(StringToTreeNode("1,0,15,null,null,4,35,3,8,25,49,2,null,5,12,22,27,47,null,null,null,null,7,11,13,19,24,26,31,40,48,6,null,9,null,null,14,17,21,23,null,null,null,30,33,39,42,null,null,null,null,null,10,null,null,16,18,20,null,null,null,28,null,32,34,36,null,41,44,null,null,null,null,null,null,null,null,null,29,null,null,null,null,null,37,null,null,43,46,null,null,null,38,null,null,45"));
	K.push_back(22);
	A.push_back(StringToTreeNode(""));

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		cout << N[i] << endl;
		//DrawTreeNode(N[i]);

		TreeNode *ans = deleteNode(N[i], K[i]);
		cout << "deleteNode = " << endl << A[i] << endl;
		cout << "My answer = " << endl << ans << endl;
		//DrawTreeNode(ans);

	}
}

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

