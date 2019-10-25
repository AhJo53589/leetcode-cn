// 705.design-hashset.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class MyHashSet {
	vector<bool> set;
public:
	/** Initialize your data structure here. */
	//map<int,int> set;
	MyHashSet() {
		set = vector<bool>(1000001, false);
	}

	void add(int key) {
		set[key] = true;
	}

	void remove(int key) {
		set[key] = false;
	}

	/** Returns true if this set did not already contain the specified element */
	bool contains(int key) {
		return set[key];
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    std::cout << "Hello World!\n"; 
}
