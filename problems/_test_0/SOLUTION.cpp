


//////////////////////////////////////////////////////////////////////////
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


//////////////////////////////////////////////////////////////////////////
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
	MyStack *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyStack")
		{
			obj = new MyStack();
			ans += "null";
		}
		else if (sf[i] == "push")
		{
			obj->push(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "top")
		{
			int r = obj->top();
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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/_test_0/tests.txt";
}

