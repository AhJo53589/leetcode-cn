
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	vector<vector<string>> test(vector<vector<string>>& a)
	//vector<vector<char>> test(vector<vector<char>>& a)
	//int test(vector<string>& a)
	{
		return a;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(vector<vector<string>>& a)
//vector<vector<char>> _solution_run(vector<vector<char>>& a)
//int _solution_run(vector<string>& a)
{
	//int caseNo = 5;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
	
	printVectorVectorT(a);
	//for (auto& vt : a)
	//{
	//	for (auto& t : vt)
	//	{
	//		cout << t << endl;
	//	}
	//}
	//		
	//for (auto& t : a)
	//{
	//	cout << t << endl;
	//}

	Solution sln;
	return sln.test(a);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
