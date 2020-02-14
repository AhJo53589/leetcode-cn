


//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	MyCircularQueue *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyCircularQueue")
		{
			TestCases stc(sp[i]);
			int k = stc.get<int>();
			obj = new MyCircularQueue(k);
			ans.push_back("null");
		}
		else if (sf[i] == "enQueue")
		{
			TestCases stc(sp[i]);
			int value = stc.get<int>();
			bool r = obj->enQueue(value);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "deQueue")
		{
			TestCases stc(sp[i]);
			bool r = obj->deQueue();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "Front")
		{
			TestCases stc(sp[i]);
			int r = obj->Front();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "Rear")
		{
			TestCases stc(sp[i]);
			int r = obj->Rear();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "isEmpty")
		{
			TestCases stc(sp[i]);
			bool r = obj->isEmpty();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "isFull")
		{
			TestCases stc(sp[i]);
			bool r = obj->isFull();
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

