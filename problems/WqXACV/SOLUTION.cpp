
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        unordered_map<int, int> cnt;
        for (auto q : questions) {
            cnt[q]++;
        }

        vector<int> xx;
        for (auto [n, c] : cnt) {
            xx.push_back(c);
        }
        sort(xx.rbegin(), xx.rend());

        int n = questions.size() / 2;
        for (int i = 0; i < xx.size(); i++) {
            n -= xx[i];
            if (n <= 0) return i + 1;
        }
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& questions)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.halfQuestions(questions);
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
