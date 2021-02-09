
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return GetMostDistinct(A, K) - GetMostDistinct(A, K - 1);
    }

    int GetMostDistinct(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ret = 0;
        while (right < A.size()) {
            ++mp[A[right++]];
            while (mp.size() > K) {
                --mp[A[left]];
                if (mp[A[left]] == 0) mp.erase(A[left]);
                ++left;
            }
            // 如果这里改成 ret = max(ret, right - left)，那么此函数就是 LeetCode 904 题的解。
            // 这里可以用动态规划的思想来理解 ret += right - left
            // right 增加一次，增加的数组个数可以用 right - left 来表示
            ret += right - left;
        }
        return ret;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& A, int K)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.subarraysWithKDistinct(A, K);
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
