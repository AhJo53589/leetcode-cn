
//////////////////////////////////////////////////////////////////////////
class MinStack
{
private:
	//自定义双链表，保存当前节点值+当前节点以前的最小值（含当前节点）
	struct Node
	{
		int val;
		Node *next;
		Node *pre;
		//当前节点前（含当前）的最小值
		int curMin;

		Node(int v)
		{
			val = v;
		}
	};

public:
	/** initialize your data structure here. */
	MinStack() : head(NULL), cur(NULL)
	{
		head = new Node(0);
	}

	void push(int x)
	{
		if (cur == NULL)
		{
			cur = new Node(x);
			head->next = cur;
			cur->pre = head;
			cur->curMin = x;
		}
		else
		{
			cur->next = new Node(x);
			cur->next->pre = cur;
			cur = cur->next;
			cur->curMin = min(cur->pre->curMin, x);
		}
	}

	void pop()
	{
		cur->pre->next = NULL;
		cur = cur->pre;
		if (cur == head)
			cur = NULL;
	}

	int top()
	{
		return cur->val;
	}

	int getMin()
	{
		return cur->curMin;
	}

private:
	Node *head;
	Node *cur;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
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

	MinStack *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MinStack")
		{
			obj = new MinStack();
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
			obj->pop();
			ans.push_back("null");
		}
		else if (sf[i] == "top")
		{
			TestCases stc(sp[i]);
			int r = obj->top();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "getMin")
		{
			TestCases stc(sp[i]);
			int r = obj->getMin();
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

