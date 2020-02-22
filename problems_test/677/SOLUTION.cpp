
//////////////////////////////////////////////////////////////////////////
class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() {

	}

	void insert(string key, int val) {

	}

	int sum(string prefix) {

	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
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

	MapSum *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MapSum")
		{
			obj = new MapSum();
			ans.push_back("null");
		}
		else if (sf[i] == "insert")
		{
			TestCases stc(sp[i]);
			string key = stc.get<string>();
			int val = stc.get<int>();
			obj->insert(key, val);
			ans.push_back("null");
		}
		else if (sf[i] == "sum")
		{
			TestCases stc(sp[i]);
			string prefix = stc.get<string>();
			int r = obj->sum(prefix);
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
