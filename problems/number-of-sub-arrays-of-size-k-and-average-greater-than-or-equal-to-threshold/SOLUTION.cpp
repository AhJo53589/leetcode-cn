
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
	{
		int ans = 0;
		int sum = k * threshold;

		vector<int> a;
		partial_sum(arr.begin(), arr.end(), back_inserter(a));
		for (auto i = 0; i < a.size() - k + 1; i++)
		{
			if (i == 0 && a[i + k - 1] < sum) continue;
			if (i != 0 && a[i + k - 1] - a[i - 1] < sum) continue;
			ans++;
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& arr, int k, int threshold)
{
	//int caseNo = 1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numOfSubarrays(arr, k, threshold);
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
