
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int w1 = 0;
        int w2 = 0;
        while (w1 < word1.size() && w2 < word2.size()) {
            int i = 0;
            while (w1 + i < word1.size() && w2 + i < word2.size() && word1[w1 + i] == word2[w2 + i]) {
                i++;
            }
            
            bool select_word1 = true;
            if (w1 + i < word1.size() && w2 + i < word2.size()) {
                select_word1 = (word1[w1 + i] >= word2[w2 + i]);
            }
            else {
                select_word1 = (w1 + i < word1.size());
            }
            
            string& str = select_word1 ? word1 : word2;
            int& idx = select_word1 ? w1 : w2;
            ans.push_back(str[idx]);
            idx++;
        }
        
        ans += word1.substr(w1);
        ans += word2.substr(w2);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string word1, string word2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.largestMerge(word1, word2);
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
