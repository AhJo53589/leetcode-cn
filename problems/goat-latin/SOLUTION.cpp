
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string ans;
        int cnt = 1;

        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            if (v.find(word[0]) == v.end()) {
                rotate(word.begin(), word.begin() + 1, word.end());
            }
            word += "ma" + string(cnt++, 'a');
            ans += word + " ";
        }

        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string sentence)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.toGoatLatin(sentence);
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
