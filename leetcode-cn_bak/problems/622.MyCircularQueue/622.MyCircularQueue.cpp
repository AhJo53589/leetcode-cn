// 622.MyCircularQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <random>

using namespace std;



class MyCircularQueue
{
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k)
	{
		m_size = k > 0 ? k : 0;
		m_pData = new int[k];
		m_head = -1;
		m_tail = -1;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value)
	{
		if (isFull()) return false;

		if (isEmpty())
		{
			m_head = 0;
			m_tail = 0;
			m_pData[m_tail] = value;
		}
		else
		{
			m_tail = (m_tail + 1) % m_size;
			m_pData[m_tail] = value;
		}
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue()
	{
		if (isEmpty()) return false;

		if (m_tail == m_head)
		{
			m_head = -1;
			m_tail = -1;
		}
		else
		{
			m_head = (m_head + 1) % m_size;
		}
		return true;
	}

	/** Get the front item from the queue. */
	int Front()
	{
		if (isEmpty()) return -1;
		return m_pData[m_head];
	}

	/** Get the last item from the queue. */
	int Rear()
	{
		if (isEmpty()) return -1;
		return m_pData[m_tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty()
	{
		return m_head == -1;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull()
	{
		return (m_size == 0 || ((m_tail + 1) % m_size) == m_head);
	}

private:
	int *m_pData;
	int m_head;
	int m_tail;
	int m_size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
	int k = 5;
	MyCircularQueue* obj = new MyCircularQueue(k);

	bool param_5 = obj->isEmpty();
	cout << "isEmpty = " << param_5 << " || ";
	bool param_6 = obj->isFull();
	cout << "isFull = " << param_6 << endl;

	for (int i = 0; i < 6; i++)
	{
		bool param_1 = obj->enQueue(i);
		cout << "enQueue " << i << " result = " << param_1 << " || ";
		int param_4 = obj->Rear();
		cout << "Rear = " << param_4 << endl;
	}

	param_5 = obj->isEmpty();
	cout << "isEmpty = " << param_5 << " || ";
	param_6 = obj->isFull();
	cout << "isFull = " << param_6 << endl;

	for (int i = 0; i < 6; i++)
	{
		int param_3 = obj->Front();
		cout << "Front = " << param_3 << " || ";
		bool param_2 = obj->deQueue();
		cout << "deQueue result = " << param_2 << endl;
	}
}
