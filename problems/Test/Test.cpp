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
int getTreeHeight(TreeNode *pNode)
{
	if (pNode == nullptr) return 0;
	int l = getTreeHeight(pNode->left);
	int r = getTreeHeight(pNode->right);
	if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
	return max(l, r) + 1;
}

bool isBalanced(TreeNode* root) 
{
	return getTreeHeight(root) != -1;
}


int main()
{
	vector<TreeNode *> N;
	vector<int> K;
	vector<bool> A;

	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
	//K.push_back(3);
	A.push_back(true);

	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
	//K.push_back(3);
	A.push_back(false);

	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
	//K.push_back(3);
	A.push_back(false);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		cout << N[i] << endl;
		//DrawTreeNode(N[i]);

		bool ans = isBalanced(N[i]);
		cout << checkAnswer<bool>(ans, A[i]) << endl;
		//DrawTreeNode(ans);

	}
}


//int main()
//{
//	vector<vector<int>> N;
//	vector<int> K;
//	vector<int> T;
//	vector<bool> A;
//
//	//N.push_back({ 1,2,3,1 });
//	//K.push_back(3);
//	//T.push_back(0);
//	//A.push_back(true);
//
//	//N.push_back({ 1,0,1,1 });
//	//K.push_back(1);
//	//T.push_back(2);
//	//A.push_back(true);
//
//	N.push_back({ 1,5,9,1,5,9 });
//	K.push_back(2);
//	T.push_back(3);
//	A.push_back(false);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "/////////////////////////////" << endl;
//		for (int j = 0; j < N.size(); j++)
//		{
//			int ans = containsNearbyAlmostDuplicate(N[i], K[i], T[i]);
//			//cout << checkAnswer<bool>(ans, A[i]) << endl;
//			string check = (ans == A[i]) ? "" : "\t\tWRONG!";
//			cout << ans << "\t <== " << A[i] << check << endl;
//		}
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

