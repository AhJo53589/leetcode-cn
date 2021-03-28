
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numDifferentIntegers(string word) {
        word += "-";
        unordered_set<string> ans;
        string val = "-";
        for (auto c : word) {
            if (!isdigit(c)) {
                if (val == "-") continue;
                ans.insert(val);
                val = "-";
            }
            else {
                val = (val == "-") ? "0" : val;
                val = (val == "0") ? "" : val;
                val += c;
            }
        }
        return ans.size();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string word)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numDifferentIntegers(word);
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
