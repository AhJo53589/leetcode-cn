
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1;
        string w2;
        for (auto& s : word1) {
            w1 += s;
        }
        for (auto& s : word2) {
            w2 += s;
        }
        return w1 == w2;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& word1, vector<string>& word2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.arrayStringsAreEqual(word1, word2);
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
