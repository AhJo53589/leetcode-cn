
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> ans;
        int left = 1;
        int right = 2;
        while (right != left && left <= target / 2)
        {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target)
            {
                vector<int> temp(right - left + 1, 0);
                int i = left;
                generate(temp.begin(), temp.end(), [&i]() { return i++; });
                ans.push_back(move(temp));
            }
            left += (sum > target);
            right += (sum <= target);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int target)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findContinuousSequence(target);
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
