
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto n : nums) {
            string s = to_string(n);
            reverse(s.begin(), s.end());
            int r = stoi(s);
            cnt[n - r]++;
        }
        
        long long ans = 0;
        const long long mod = 1e9 + 7;
        for (auto [f, s] : cnt) {
            if (s < 2) continue;
            ans += 1LL * s * (s - 1) / 2;
            ans %= mod;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.countNicePairs(nums);
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
