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



bool canWinNim(int n)
{
	return n % 4 != 0;
}


int main()
{
	vector<int> N;
	vector<int> A;

	N.push_back(4);
	A.push_back(1);


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << N[i] << " = " << A[i] << endl;
		bool ans = canWinNim(N[i]);
		cout << "my answer = " << ans << endl;
	}
}



//int main()
//{
//	vector<TreeNode *> N;
//	TreeNode *pHead;
//	vector<pair<TreeNode *, TreeNode *>> K;
//	vector<int> A;
//
//	StringToTreeNode(&pHead, "3,5,1,6,2,0,8,null,null,7,4");
//	N.push_back(pHead);
//	K.push_back(make_pair(FindTreeNode(pHead, 5), FindTreeNode(pHead, 1)));
//	A.push_back(3);
//	pHead = nullptr;
//
//	StringToTreeNode(&pHead, "3,5,1,6,2,0,8,null,null,7,4");
//	N.push_back(pHead);
//	K.push_back(make_pair(FindTreeNode(pHead, 5), FindTreeNode(pHead, 4)));
//	A.push_back(5);
//	pHead = nullptr;
//
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		printTreeNode(N[i]);
//		cout << "lowest Common Ancestor = " << A[i] << endl;
//		TreeNode *pNode = lowestCommonAncestor(N[i], K[i].first, K[i].second);
//		cout << "my answer = " << pNode->val << endl;
//	}
//}

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

