// 232.implement-queue-using-stacks.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

using namespace std;

class MyQueue
{
public:
	/** Initialize your data structure here. */
	MyQueue(){}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		m_in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		int i = peek();
		m_out.pop();
		return i;
	}

	/** Get the front element. */
	int peek()
	{
		TransferData();
		return m_out.top();
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return m_out.empty() && m_in.empty();
	}

	void TransferData()
	{
		if (!m_out.empty()) return;
		while (!m_in.empty())
		{
			m_out.push(m_in.top());
			m_in.pop();
		}
	}

private:
	stack<int> m_out;
	stack<int> m_in;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main()
{
	MyQueue* obj = new MyQueue();
	for (int i = 0; i < 2; i++)
	{
		obj->push(i);
		cout << "push " << i << endl;
	}
	cout << "pop " << obj->pop() << endl;
	cout << "peek " << obj->peek() << endl;
	cout << "pop " << obj->pop() << endl;
	cout << "empty " << obj->empty() << endl;
}
