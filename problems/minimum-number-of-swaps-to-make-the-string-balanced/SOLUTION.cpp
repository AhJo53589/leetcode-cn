
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSwaps(string s) {
        vector<int> v;
        for (auto c : s) {
            int x = (c == '[') ? 1 : -1;
            if (!v.empty() && v.back() * 2 + x == 1) {
                v.pop_back();
                continue;
            }
            v.push_back(x);
        }
        int ans = v.size() / 2;
        return ans - ans / 2;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minSwaps(s);
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
