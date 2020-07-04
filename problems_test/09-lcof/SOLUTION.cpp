
//////////////////////////////////////////////////////////////////////////
class CQueue {
public:
	CQueue() {
	}

	void appendTail(int value) {
		st[0].push(value);
	}

	int deleteHead() {
		if (st[0].empty() && st[1].empty()) return -1;
		if (st[1].empty()) {
			while (!st[0].empty()) {
				st[1].push(st[0].top());
				st[0].pop();
			}
		}
		int t = st[1].top();
		st[1].pop();
		return t;
	}

private:
	stack<int> st[2];
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
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

	CQueue *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "CQueue")
		{
			obj = new CQueue();
			ans.push_back("null");
		}
		else if (sf[i] == "appendTail")
		{
			TestCases stc(sp[i]);
			int value = stc.get<int>();
			obj->appendTail(value);
			ans.push_back("null");
		}
		else if (sf[i] == "deleteHead")
		{
			TestCases stc(sp[i]);
			int r = obj->deleteHead();
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
