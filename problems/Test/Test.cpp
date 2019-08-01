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
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;



bool isPalindrome(int x) 
{
	if (x < 0) return false;
	if (x < 10) return true;

	deque<int> d;
	while (x >= 1)
	{
		d.push_back(x % 10);
		x /= 10;
	}
	while (d.size() > 1)
	{
		int h = d.front();
		d.pop_front();
		int t = d.back();
		d.pop_back();
		if (h != t) return false;
	}
	return true;
}

bool isPalindrome(int x) {
	if (x < 0 || ((x % 10 == 0) && x != 0)) {
		return false;
	}
	int reverse = 0;
	while (x > reverse) {
		reverse = reverse * 10 + x % 10;
		x /= 10;
	}
	return x == reverse || x == reverse / 10;
}

int main()
{
	vector<int> N;
	N.push_back(121);
	N.push_back(-121);
	N.push_back(10);
	N.push_back(9);
	N.push_back(123454321);
	N.push_back(123321);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "/////////////////////////////////" << endl;
		cout << N[i] << endl;
		bool ans = isPalindrome(N[i]);
		cout << ans << endl;
	}
}

//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = nullptr;
//	StringToListNode(&pHead, "[1,5,5]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	StringToListNode(&pHead, "[1,3,4]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	StringToListNode(&pHead, "[2,6]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	StringToListNode(&pHead, "[1]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//
//	for (auto p : lists)
//	{
//		PrintLinkList(p);
//	}
//	pHead = mergeKLists(lists);
//	PrintLinkList(pHead);
//	cout << endl;
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

