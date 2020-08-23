
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int start = rounds.front();
        while (start != rounds.back()) {
            ans.push_back(start);
            start++;
            start = (start > n) ? start % n : start;
        }
        ans.push_back(start);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int n, vector<int>& rounds)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.mostVisited(n, rounds);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
