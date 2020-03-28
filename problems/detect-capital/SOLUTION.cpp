
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() < 2) return true;
        bool flag_first = isupper(word[0]);
        cout << boolalpha << flag_first << endl;
        bool flag_second = isupper(word[1]);
        cout << boolalpha << flag_second << endl;
        if (!flag_first && flag_second)
        {
            cout << "false here: 0";
            return false;
        }
        for (int i = 2; i < word.size(); i++)
        {
            cout << "[" << i << "] = " << word[i] << "\t" << boolalpha << isupper(word[i]) << endl;
            if (flag_second != isupper(word[i]))
            {
                cout << "false here: " << i;
                return false;
            }
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() < 2) return true;
        bool flag_first = isupper(word[0]);
        bool flag_second = isupper(word[1]);
        if (!flag_first && flag_second) return false;

        for (int i = 2; i < word.size(); i++)
        {
            bool flag_cur = isupper(word[i]);
            if (flag_second != flag_cur) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string word)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << word << endl;
    Solution sln;
    return sln.detectCapitalUse(word);
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
