
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A)
	{
		int sum = accumulate(A.begin(), A.end(), 0);
		if (sum % 3 != 0) return false;
		int avg = sum / 3;
		sum = 0;
		int ans = 0;
		for (auto& n : A)
		{
			sum += n;
			ans += (avg == sum);
			sum = (avg == sum) ? 0 : sum;
		}
		return ans >= 3;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& A)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.canThreePartsEqualSum(A);
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
