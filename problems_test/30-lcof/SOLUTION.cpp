
//////////////////////////////////////////////////////////////////////////
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (mindata.empty() || x <= mindata.top()) {
            mindata.push(x);
        }
        data.push(x);
    }
    
    void pop() {
        if (data.empty() || mindata.empty()) return;
        if (data.top() == mindata.top()) {
            mindata.pop();
        }
        data.pop();
    }
    
    int top() {
        if (data.empty()) return -1;
        return data.top();
    }
    
    int min() {
        if (mindata.empty()) return -1;
        return mindata.top();
    }

private:
    stack<int> data;
    stack<int> mindata;
};


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
		else if (sf[i] == "min")
		{
			TestCases stc(sp[i]);
			int r = obj->min();
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
