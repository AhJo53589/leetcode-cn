
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int test(vector<char>& a)
	//int test(vector<string>& a)
	{
		return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<char>& a)
//int _solution_run(vector<string>& a)
{
	//int caseNo = 5;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
	
	printVectorT(a);
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
