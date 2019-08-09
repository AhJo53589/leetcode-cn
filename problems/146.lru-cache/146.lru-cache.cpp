// 146.lru-cache.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//class LRUCache {
//public:
//	LRUCache(int capacity) {
//		cap = capacity;
//	}
//
//	int get(int key) {
//		auto it = m.find(key);
//
//		if (it == m.end())
//			return -1;
//
//		// 剪切 l 的 it->second 到 l.begin ，相当于erase + push_front
//		l.splice(l.begin(), l, it->second);
//
//		return it->second->second;
//	}
//
//	void put(int key, int value) {
//		auto it = m.find(key);
//
//		if (it != m.end())
//			l.erase(it->second);
//
//		l.push_front(make_pair(key, value));
//
//		m[key] = l.begin();
//
//		if (m.size() > cap) {
//			int k = l.rbegin()->first;
//			l.pop_back();
//			m.erase(k);
//		}
//	}
//
//private:
//	int cap;
//	list<pair<int, int>> l;
//	unordered_map<int, list<pair<int, int>>::iterator> m;
//};

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
