
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bitset<26> broken;
        for (auto c : brokenLetters) {
            broken[c - 'a'] = 1;
        }

        int ans = 0;
        string temp;
        stringstream ss(text);
        while (ss >> temp) {
            int t = temp.size();
            for (auto c : temp) {
                if (broken.test(c - 'a')) break;
                t--;
            }
            ans += (t == 0);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string text, string brokenLetters)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.canBeTypedWords(text, brokenLetters);
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
