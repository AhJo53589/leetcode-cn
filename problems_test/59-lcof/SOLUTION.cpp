
//////////////////////////////////////////////////////////////////////////
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
		return qmax.empty() ? -1 : qmax.front();
    }
    
    void push_back(int value) {
		que.push(value);
		while (!qmax.empty() && qmax.back() < value)
		{
            qmax.pop_back();
		}
		qmax.push_back(value);
    }
    
    int pop_front() {
		if (que.empty()) return -1;
		auto q = que.front();
		if (!qmax.empty() && qmax.front() == q)
		{
			qmax.pop_front();
		}
		que.pop();
		return q;
    }
private:
	queue<int> que;
	deque<int> qmax;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

class AA
{
	AA(initializer_list<int> pp)
	{
		for (auto& p : pp)
		{

		}
	}
};

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	//printVectorT(sf);
	vector<string> sp = tc.get<vector<string>>();
	//printVectorT(sp);
	vector<string> ans;

	MaxQueue *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MaxQueue")
		{
			obj = new MaxQueue();
			ans.push_back("null");
		}
		else if (sf[i] == "max_value")
		{
			TestCases stc(sp[i]);
			int r = obj->max_value();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "push_back")
		{
			TestCases stc(sp[i]);
			int value = stc.get<int>();
			obj->push_back(value);
			ans.push_back("null");
		}
		else if (sf[i] == "pop_front")
		{
			TestCases stc(sp[i]);
			int r = obj->pop_front();
			ans.push_back(convert<string>(r));
		}
		//cout << sf[i] << "\t" << sp[i] << "\t" << ans.back() << "\t" << endl;
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
