
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        unordered_set<int> us;
        for (int i = 0; i < s.size() - k + 1; i++) {
            string temp = s.substr(i, k);
            us.insert(stoi(temp, nullptr, 2));
        }

        for (int i = 0; i < (1 << k); i++) {
            if (us.count(i) == 0) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << s << endl;
    cout << k << endl;
    Solution sln;
    return sln.hasAllCodes(s, k);
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
