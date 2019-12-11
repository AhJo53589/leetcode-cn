


//////////////////////////////////////////////////////////////////////////
int maxSubarraySumCircular(vector<int>& A) 
{
	int sum = 0;
	int smax = INT_MIN;
	bool flag = true;
	int s1 = 0;
	int s2 = 0;
	int ans1 = 0;
	int ans2 = 0;
	for (auto n : A)
	{
		sum += n;
		smax = max(smax, n);
		if (n > 0) flag = false;
		s1 = (s1 > 0) ? s1 + n : n;
		ans1 = max(ans1, s1);
		s2 = (s2 < 0) ? s2 + n : n;
		ans2 = min(ans2, s2);
	}
	if (flag) return smax;
	return max(ans1, sum - ans2);
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A)
{
	return maxSubarraySumCircular(A);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/maximum-sum-circular-subarray/tests.txt";
}

