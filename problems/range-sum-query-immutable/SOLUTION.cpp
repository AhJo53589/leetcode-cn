
//////////////////////////////////////////////////////////////////////////
class NumArray 
{
public:
	NumArray(vector<int>& nums) : m_nums(nums)
	{
		partial_sum(m_nums.begin(), m_nums.end(), back_inserter(m_partial));
	}

	int sumRange(int i, int j)
	{
		return m_partial[j] - m_partial[i] + m_nums[i];
	}

private:
	vector<int> m_nums;
	vector<int> m_partial;
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int n, int m)
{
	return {};
}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<int> nums(tc.get<vector<int>>());
	NumArray na(nums);
	vector<vector<int>> params(tc.get<vector<vector<int>>>());
	string ans = "[null";
	for (auto p : params)
	{
		int t = na.sumRange(p[0], p[1]);
		ans += "," + to_string(t);
	}
	ans += "]";
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

