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
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;



//////////////////////////////////////////////////////////////////////////
class LRUCache {
private:
	int cap;
	list<pair<int, int>> cache;
	unordered_map<int, list<pair<int, int>>::iterator> map;
public:
	LRUCache(int capacity) {
		this->cap = capacity;
	}

	int get(int key) {
		auto it = map.find(key);
		if (it == map.end()) return -1;
		pair<int, int> kv = *map[key];
		cache.erase(map[key]);
		cache.push_front(kv);
		map[key] = cache.begin();
		return kv.second; // value
	}

	void put(int key, int value) {

		auto it = map.find(key);
		if (it == map.end()) {
			if (cache.size() == cap) {
				auto lastPair = cache.back();
				int lastKey = lastPair.first;
				map.erase(lastKey);
				cache.pop_back();
			}
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
		else {
			cache.erase(map[key]);
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
	int capacity = 2;
	LRUCache* obj = new LRUCache(capacity);

	obj->put(1, 1);
	obj->put(2, 2);
	obj->get(1);
	obj->put(3, 3);
	obj->get(2);
	obj->put(4, 4);
	obj->get(1);
	obj->get(3);
	obj->get(4);
}


//int main()
//{
//	vector<TreeNode *> N;
//	vector<vector<vector<int>>> A;
//	TreeNode *pHead = nullptr;
//
//	StringToTreeNode(&pHead, "3,9,20,null,null,15,7");
//	N.push_back(pHead);
//	A.push_back({ {3}, { 20,9 }, { 15,7 } });
//	pHead = nullptr;
//
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		printTreeNode(N[i]);
//		cout << "zigzagLevelOrder = " << endl;
//		printVectorVectorInt(A[i]);
//		vector<vector<int>> ans = zigzagLevelOrder(N[i]);
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

