
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
	MinStack *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MinStack")
		{
			obj = new MinStack();
			ans += "null";
		}
		else if (sf[i] == "push")
		{
			obj->push(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "pop")
		{
			obj->pop();
			ans += "null";
		}
		else if (sf[i] == "top")
		{
			int r = obj->top();
			ans += to_string(r);
		}
		else if (sf[i] == "getMin")
		{
			int r = obj->getMin();
			ans += to_string(r);
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
	return "../../problems/min-stack/tests.txt";
}

