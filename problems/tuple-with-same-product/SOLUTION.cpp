
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                dic[nums[i] * nums[j]]++;
            }
        }
        for (auto [k, v] : dic) {
            if (v < 2) continue;
            ans += combi(v, 2);
        }
        return ans * 8;
    }

    long long combi(int n, int m) {
        long long ans = 1;
        m = (m > n - m) ? n - m : m;
        for (int i = 0; i < m; i++) {
            ans *= n - i;
            ans /= i + 1;
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
    return sln.tupleSameProduct(nums);
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
