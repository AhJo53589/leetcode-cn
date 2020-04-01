
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string fillWords(vector<string>& words, int bg, int ed, int maxWidth, bool lastLine = false)
    {
        string ans;
        int wordCount = ed - bg + 1;
        int spaceCount = maxWidth + 1 - wordCount;
        for (int i = bg; i <= ed; i++)
        {
            spaceCount -= words[i].size();
        }

        int t = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);
        spaceCount /= (wordCount == 1) ? 1 : (wordCount - 1);

        for (int i = bg; i < ed; i++)
        {
            ans += words[i];
            if (lastLine)
            {
                fill_n(back_inserter(ans), 1, ' ');
                continue;
            }
            fill_n(back_inserter(ans), spaceCount + 1 + ((i - bg) < t), ' ');
        }
        ans += words[ed];
        fill_n(back_inserter(ans), maxWidth - ans.size(), ' ');
        return ans;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> ans;
        int cnt = 0;
        int bg = 0;
        for (int i = 0; i < words.size(); i++)
        {
            cnt += words[i].size() + 1;

            if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth)
            {
                ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
                bg = i + 1;
                cnt = 0;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& words, int maxWidth)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(words);

    Solution sln;
    return sln.fullJustify(words, maxWidth);
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
