
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string temp;
        while (ss >> temp) {
            words.push_back(temp);
        }

        string ans = ""; 
        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i == 0) break;
            ans += " ";
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.reverseWords(s);
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
