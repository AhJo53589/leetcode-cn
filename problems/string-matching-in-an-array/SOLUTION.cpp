
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> ans;
        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                for (int k = 0; k + words[i].size() <= words[j].size(); k++)
                {
                    if (memcmp(&words[i][0], &words[j][k], words[i].size()) != 0) continue;
                    ans.push_back(words[i]);
                    j = words.size();
                    break;
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& words)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(words);
    Solution sln;
    return sln.stringMatching(words);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
