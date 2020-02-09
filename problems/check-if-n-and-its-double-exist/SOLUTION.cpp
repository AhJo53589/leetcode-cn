
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
	{
		set<int> s;
		for (auto n : arr)
		{
			if (s.count(n * 2) != 0) return true;
			if ((n % 2 == 0) && s.count(n / 2) != 0) return true;
			s.insert(n);
		}
		return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& arr)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.checkIfExist(arr);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
