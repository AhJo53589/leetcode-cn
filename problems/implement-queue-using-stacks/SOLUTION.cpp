


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
//void _solution_run(int x)
//{
//	return push(x);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<vector<int>> param = tc.get<vector<vector<int>>>();

	string ans = "[";
	MyQueue *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyQueue")
		{
			obj = new MyQueue();
			ans += "null";
		}
		else if (sf[i] == "push")
		{
			obj->push(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "peek")
		{
			int r = obj->peek();
			ans += to_string(r);
		}
		else if (sf[i] == "pop")
		{
			int r = obj->pop();
			ans += to_string(r);
		}
		else if (sf[i] == "empty")
		{
			bool r = obj->empty();
			ans += r ? "true" : "false";
		}
		ans += ",";
	}
	ans.pop_back();
	ans += "]";
	return ans;
}
//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

