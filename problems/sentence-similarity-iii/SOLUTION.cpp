
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        vector<string> str1;
        vector<string> str2;
        string temp;
        while (ss1 >> temp) {
            str1.push_back(temp);
        }
        while(ss2 >> temp) {
            str2.push_back(temp);
        }
        
        if (str1.size() < str2.size()) {
            swap(str1, str2);
        }
        
        if (str2.empty()) return true;
        
        int ans = 0;
        int i = 0;
        int j = (int)str2.size() - 1;
        for (int ii = 0; i < str2.size() && str2[i] == str1[ii]; i++, ii++) {
            ans++;
        }
        for (int jj = (int)str1.size() - 1; j >= 0 && str2[j] == str1[jj]; j--, jj--) {
            ans++;
        }
        // cout << ans << endl;
        return ans >= str2.size();
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string sentence1, string sentence2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.areSentencesSimilar(sentence1, sentence2);
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
