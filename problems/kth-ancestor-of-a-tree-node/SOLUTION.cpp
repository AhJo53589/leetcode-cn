
//////////////////////////////////////////////////////////////////////////
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {

    }
    
    int getKthAncestor(int node, int k) {

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
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

	TreeAncestor *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "TreeAncestor")
		{
			TestCases stc(sp[i]);
			int n = stc.get<int>();
			vector<int> parent = stc.get<vector<int>>();
			obj = new TreeAncestor(n, parent);
			ans.push_back("null");
		}
		else if (sf[i] == "getKthAncestor")
		{
			TestCases stc(sp[i]);
			int node = stc.get<int>();
			int k = stc.get<int>();
			int r = obj->getKthAncestor(node, k);
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
