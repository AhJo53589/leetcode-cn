
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int nextGreaterElement(int n) 
	{
		vector<int> dg;
		while (n != 0)
		{
			dg.push_back(n % 10);
			n /= 10;
		}
		reverse(dg.begin(), dg.end());
		if (!next_permutation(dg.begin(), dg.end())) return -1;
		
		long long ans = 0;
		for (auto& i : dg)
		{
			ans *= 10;
			ans += i;
		}
		return (ans > INT_MAX) ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.nextGreaterElement(n);
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
