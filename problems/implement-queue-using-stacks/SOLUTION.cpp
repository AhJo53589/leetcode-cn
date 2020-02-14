


//////////////////////////////////////////////////////////////////////////
class MyQueue
{
public:
	/** Initialize your data structure here. */
	MyQueue() {}

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

	MyQueue *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyQueue")
		{
			obj = new MyQueue();
			ans.push_back("null");
		}
		else if (sf[i] == "push")
		{
			TestCases stc(sp[i]);
			int x = stc.get<int>();
			obj->push(x);
			ans.push_back("null");
		}
		else if (sf[i] == "pop")
		{
			TestCases stc(sp[i]);
			int r = obj->pop();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "peek")
		{
			TestCases stc(sp[i]);
			int r = obj->peek();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "empty")
		{
			TestCases stc(sp[i]);
			bool r = obj->empty();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "TransferData")
		{
			TestCases stc(sp[i]);
			obj->TransferData();
			ans.push_back("null");
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

