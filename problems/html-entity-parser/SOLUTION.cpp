
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string entityParser(string text) 
    {
        vector<string> words = { "&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;" };
        vector<char> chars = { '\"', '\'', '&', '>', '<', '/' };

        string ans = "";
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == '&')
            {
                bool flag = false;
                for (int j = 0; j < words.size(); j++)
                {
                    if (i + words[j].size() > text.size()) continue;
                    if (memcmp(&text[i], &words[j][0], words[j].size()) != 0) continue;
                    ans.push_back(chars[j]);
                    i += (words[j].size() - 1);
                    flag = true;
                    break;
                }
                if (flag) continue;
            }

            ans.push_back(text[i]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string text)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.entityParser(text);
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
