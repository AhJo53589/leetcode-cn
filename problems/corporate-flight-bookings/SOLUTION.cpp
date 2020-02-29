
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
	{
		vector<int> ans(n + 1, 0);
		for (auto& b: bookings)
		{
			ans[b[0] - 1] += b[2];
			ans[b[1]] -= b[2];
		}
		for (int i = 1; i < n; i++)
		{
			ans[i] += ans[i - 1];
		}
		ans.pop_back();
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& bookings, int n)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};
	cout << convert<string>(bookings) << endl;

	Solution sln;
	return sln.corpFlightBookings(bookings, n);
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
