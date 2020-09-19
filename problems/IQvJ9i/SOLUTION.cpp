
//////////////////////////////////////////////////////////////////////////
class BlackBox {
public:
    BlackBox(int n, int m) {

    }
    
    int open(int index, int direction) {

    }
    
    void close(int index) {

    }
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

	BlackBox *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "BlackBox")
		{
			TestCases stc(sp[i]);
			int n = stc.get<int>();
			int m = stc.get<int>();
			obj = new BlackBox(n, m);
			ans.push_back("null");
		}
		else if (sf[i] == "open")
		{
			TestCases stc(sp[i]);
			int index = stc.get<int>();
			int direction = stc.get<int>();
			int r = obj->open(index, direction);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "close")
		{
			TestCases stc(sp[i]);
			int index = stc.get<int>();
			obj->close(index);
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
