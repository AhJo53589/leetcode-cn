
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        dq.push_back({ nums[0], 0 });

        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            while (!dq.empty() && i - dq.front().second > k) {
                dq.pop_front();
            }
            ans = dq.front().first + nums[i];
            while (!dq.empty() && dq.back().first <= ans) {
                dq.pop_back();
            }
            dq.push_back({ ans, i });
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	printVectorT(nums);
	cout << k << endl;
	Solution sln;
	return sln.maxResult(nums, k);
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
