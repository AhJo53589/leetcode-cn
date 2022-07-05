
//////////////////////////////////////////////////////////////////////////
class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        if (check(start, end)) {
            ss.insert(-start);
            se.insert(end);
            return true;
        }
        return false;
    }

    bool check(int start, int end) {
        auto before = ss.upper_bound(-end);
        if (before == ss.end()) return true;
        auto p1 = -(*before);
        if (p1 >= start) return false;
        auto after = se.upper_bound(p1);
        auto p2 = *after;
        if (p2 > start) return false;
        return true;
    }

private:
    set<int> ss;
    set<int> se;
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

	MyCalendar *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyCalendar")
		{
			obj = new MyCalendar();
			ans.push_back("null");
		}
		else if (sf[i] == "book")
		{
			TestCases stc(sp[i]);
			int start = stc.get<int>();
			int end = stc.get<int>();
			bool r = obj->book(start, end);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "check")
		{
			TestCases stc(sp[i]);
			int start = stc.get<int>();
			int end = stc.get<int>();
			bool r = obj->check(start, end);
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
