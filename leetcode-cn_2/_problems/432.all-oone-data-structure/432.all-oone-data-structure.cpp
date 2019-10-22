// 432.all-oone-data-structure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


//class AllOne {
//private:
//	vector<pair<string, int>> vec;
//	unordered_map<string, int> mp;
//public:
//	/** Initialize your data structure here. */
//	AllOne() {
//
//	}
//
//	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
//	void inc(string key) {
//		if (mp.count(key)) {
//			int p = mp[key];
//			vec[p].second++;
//			while (p > 0 && vec[p].second > vec[p - 1].second) {
//				mp[vec[p - 1].first] = p;
//				swap(vec[p], vec[p - 1]);
//				p--;
//			}
//			mp[vec[p].first] = p;
//		}
//		else {
//			mp[key] = vec.size();
//			vec.push_back(make_pair(key, 1));
//		}
//	}
//
//	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
//	void dec(string key) {
//		if (!mp.count(key)) return;
//		int p = mp[key];
//		vec[p].second--;
//		while (p < vec.size() - 2 && vec[p].second < vec[p + 1].second) {
//			mp[vec[p + 1].first] = p;
//			swap(vec[p], vec[p + 1]);
//			p++;
//		}
//		if (vec[p].second == 0)
//		{
//			mp.erase(key);
//			vec.erase(vec.begin() + p);
//		}
//		else {
//			mp[key] = p;
//		}
//	}
//
//	/** Returns one of the keys with maximal value. */
//	string getMaxKey() {
//		if (vec.empty())return "";
//		return vec.front().first;
//	}
//
//	/** Returns one of the keys with Minimal value. */
//	string getMinKey() {
//		if (vec.empty()) return"";
//		return vec.back().first;
//	}
//};

class AllOne {
public:
	/** Initialize your data structure here. */
	AllOne() {
		addValMapHead(0, true);
		min_node = val_map[0];
		max_node = val_map[0];
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		cout << "inc " << key << endl;
		if (!key_map.count(key))
		{
			Node *n = new Node(key);
			key_map[key] = n;
			insertValMapNode(n, true);
		}
		else
		{
			Node *n = key_map[key];
			deleteValMapNode(n);
			(n->val)++;
			insertValMapNode(n, true);
			updateValMap(val_map[n->val - 1]);
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		cout << "dec " << key << endl;
		if (!key_map.count(key)) return;
		Node *n = key_map[key];
		if (n->val == 1)
		{
			key_map.erase(key);
			deleteValMapNode(n);
			updateValMap(val_map[n->val]);
			delete n;
		}
		else
		{
			deleteValMapNode(n);
			(n->val)--;
			insertValMapNode(n, false);
			updateValMap(val_map[n->val + 1]);
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (max_node == nullptr) return {};
		if (max_node->next == nullptr) return {};
		cout << "max_node->val " << max_node->val << endl;
		return max_node->next->str;
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (min_node == nullptr) return {};
		if (min_node->next == nullptr) return {};
		cout << "min_node->val " << min_node->val << endl;
		return min_node->next->str;
	}

private:
	struct Node
	{
		string str;
		int val;
		Node *pre;
		Node *next;
		Node *up;
		Node *down;
		Node(string k) : str(k), val(1), pre(nullptr), next(nullptr), up(nullptr), down(nullptr) { }
	};

private:
	void addValMapHead(int val, bool incFlag)
	{
		Node *pNew = new Node("");
		Node *pDown = nullptr;
		Node *pUp = nullptr;
		if (incFlag)
		{
			pDown = val_map[val - 1];
			pUp = (pDown == nullptr) ? nullptr : pDown->up;
		}
		else
		{
			pUp = val_map[val + 1];
			pDown = (pUp == nullptr) ? nullptr : pUp->down;
		}
		pNew->val = val;
		pNew->down = pDown;
		pNew->up = pUp;
		if (pDown != nullptr) pDown->up = pNew;
		if (pUp != nullptr) pUp->down = pNew;

		val_map[val] = pNew;

		if (val == 0) return;
		if (pUp == nullptr) max_node = pNew;
		if (pDown == val_map[0]) min_node = pNew;
	}

	void deleteValMapHead(int val)
	{
		if (!val_map.count(val)) return;

		Node *n = val_map[val];
		if (n->down != nullptr) n->down->up = n->up;
		if (n->up != nullptr) n->up->down = n->down;
		val_map.erase(n->val);

		if (max_node == n) max_node = (n->up != nullptr) ? n->up : n->down;
		if (min_node == n) min_node = (n->down != val_map[0]) ? n->down : n->up;

		delete n;
	}

	void insertValMapNode(Node *n, bool incFlag)
	{
		if (!val_map.count(n->val))
		{
			addValMapHead(n->val, incFlag);
		}

		Node *pValHead = val_map[n->val];
		n->pre = pValHead;
		n->next = pValHead->next;
		if (n->next != nullptr) n->next->pre = n;
		pValHead->next = n;
	}

	void deleteValMapNode(Node *n)
	{
		if (n == nullptr) return;

		n->pre->next = n->next;
		if (n->next != nullptr) n->next->pre = n->pre;
	}

	void updateValMap(Node *n)
	{
		if (n->next != nullptr) return;
		deleteValMapHead(n->val);
	}

private:
	unordered_map<string, Node *> key_map;
	unordered_map<int, Node *> val_map;
	Node *max_node;
	Node *min_node;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */


int main()
{
	AllOne *obj = new AllOne();
	// Test 01
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << endl << "///////////////////////////////////////" << endl;
	//	obj->inc("Hello");
	//	cout << "MaxKey = " << obj->getMaxKey() << endl;
	//	cout << "MinKey = " << obj->getMinKey() << endl;
	//}

	//for (int i = 0; i < 1; i++)
	//{
	//	cout << endl << "///////////////////////////////////////" << endl;
	//	obj->dec("Hello");
	//	cout << "MaxKey = " << obj->getMaxKey() << endl;
	//	cout << "MinKey = " << obj->getMinKey() << endl;
	//}

	//for (int i = 0; i < 4; i++)
	//{
	//	cout << endl << "///////////////////////////////////////" << endl;
	//	obj->inc("AhJo");
	//	cout << "MaxKey = " << obj->getMaxKey() << endl;
	//	cout << "MinKey = " << obj->getMinKey() << endl;
	//}

	//for (int i = 0; i < 4; i++)
	//{
	//	cout << endl << "///////////////////////////////////////" << endl;
	//	obj->dec("AhJo");
	//	cout << "MaxKey = " << obj->getMaxKey() << endl;
	//	cout << "MinKey = " << obj->getMinKey() << endl;
	//}

	// Test 02
	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("hello");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("goodbye");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("hello");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("goodbye");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("leet");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("code");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("leet");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->dec("hello");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("leet");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("code");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;

	cout << endl << "///////////////////////////////////////" << endl;
	obj->inc("code");
	cout << "MaxKey = " << obj->getMaxKey() << endl;
	cout << "MinKey = " << obj->getMinKey() << endl;
}