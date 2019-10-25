// 225.implement-stack-using-queues.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

class MyStack
{
public:
	/** Initialize your data structure here. */
	MyStack()
		: m_topMark(true)
	{

	}

	/** Push element x onto stack. */
	void push(int x)
	{
		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;
		queue<int> *pBase = m_topMark ? &m_dataB : &m_dataA;
		if (!pTop->empty())
		{
			pBase->push(pTop->front());
			pTop->pop();
		}
		pTop->push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		int i = top();

		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;

		pTop->pop();
		return i;
	}

	/** Get the top element. */
	int top()
	{
		queue<int> *pTop = m_topMark ? &m_dataA : &m_dataB;
		queue<int> *pBase = m_topMark ? &m_dataB : &m_dataA;

		if (!pTop->empty()) return pTop->front();

		for (int i = 0; i < pBase->size() - 1; i++)
		{
			pTop->push(pBase->front());
			pBase->pop();
		}
		m_topMark = !m_topMark;

		return pBase->front();
	}

	/** Returns whether the stack is empty. */
	bool empty()
	{
		return m_dataA.empty() && m_dataB.empty();
	}

private:
	queue<int> m_dataA;
	queue<int> m_dataB;
	bool m_topMark;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */




 //class MyStack {
 //public:
 //	/** Initialize your data structure here. */
 //	MyStack() {
 //	}
 //
 //	/** Push element x onto stack. */
 //	void push(int x) {
 //		q.push(x);
 //		for (int i = 0; i < q.size() - 1; i++)
 //		{
 //			q.push(q.front());
 //			q.pop();
 //		}
 //	}
 //
 //	/** Removes the element on top of the stack and returns that element. */
 //	int pop() {
 //		int ret = q.front();
 //		q.pop();
 //		return ret;
 //	}
 //
 //	/** Get the top element. */
 //	int top() {
 //		return q.front();
 //	}
 //
 //	/** Returns whether the stack is empty. */
 //	bool empty() {
 //		return q.empty();
 //	}
 //private:
 //	queue<int> q;
 //};

 /**
  * Your MyStack object will be instantiated and called as such:
  * MyStack* obj = new MyStack();
  * obj->push(x);
  * int param_2 = obj->pop();
  * int param_3 = obj->top();
  * bool param_4 = obj->empty();
  */




int main()
{
	MyStack* obj = new MyStack();
	for (int i = 0; i < 5; i++)
	{
		obj->push(i);
		cout << "push " << i << endl;
	}
	cout << "pop " << obj->pop() << endl;
	cout << "top " << obj->top() << endl;
	cout << "pop " << obj->pop() << endl;
	cout << "pop " << obj->pop() << endl;
	cout << "pop " << obj->pop() << endl;
	cout << "empty " << obj->empty() << endl;

}
