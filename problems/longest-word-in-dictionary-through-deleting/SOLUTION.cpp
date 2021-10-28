
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });

        for (auto& w : dictionary) {
            for (int i = 0, j = 0; i < s.size(); i++) {
                j += (s[i] == w[j]);
                if (j == w.size()) return w;
            }
        }
        return "";
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s, vector<string>& dictionary)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findLongestWord(s, dictionary);
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
