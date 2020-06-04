
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        ans[0] = 0;
        if (num == 0) return ans;
        ans[1] = 1;
        if (num == 1) return ans;

        int k = 2;
        for (int i = k; i < ans.size(); i++) {
            k *= (i == k + k) ? 2 : 1;
            ans[i] = 1 + ans[i - k];
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int num)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.countBits(num);
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
