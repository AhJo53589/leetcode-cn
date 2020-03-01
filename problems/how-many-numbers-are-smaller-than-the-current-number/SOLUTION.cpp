
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
	{
		map<int, int> count;
		for (auto& n : nums)
		{
			count[n]++;
		}
		int t = 0;
		for (auto& p : count)
		{
			int temp = p.second;
			p.second = t;
			t += temp;
		}
		for (auto& n : nums)
		{
			n = count[n];
		}
		return nums;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.smallerNumbersThanCurrent(nums);
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
