
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	vector<int> getClose(int num)
	{
		for (int a = pow(num, 0.5) + 1; a >= 1; a--)
		{
			int b = num / a;
			if (a * b == num) return { a, b };
		}
		return {};
	}

    vector<int> closestDivisors(int num) 
	{
		auto a = getClose(num + 1);
		auto b = getClose(num + 2);
		if (a.empty()) return b;
		if (b.empty()) return a;	
		return abs(a[0] - a[1]) <= abs(b[0] - b[1]) ? a : b;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int num)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.closestDivisors(num);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
