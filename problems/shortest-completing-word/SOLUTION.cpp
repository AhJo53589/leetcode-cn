
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        vector<int> letter(26, 0);
        int cnt = 0;
        for (auto c : licensePlate)
        {
            c = isupper(c) ? tolower(c) : c;
            if (islower(c))
            {
                letter[c - 'a']++;
                cnt++;
            }
        }

        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
        for (auto w : words)
        {
            auto letter_t = letter;
            int cnt_t = cnt;
            for (auto c : w)
            {
                if (letter_t[c - 'a']-- <= 0) continue;
                if (--cnt_t == 0) return w;
            }
        }
        return {};
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        vector<int> letter(26, 0);
        int cnt = 0;
        for (auto c : licensePlate)
        {
            c = isupper(c) ? tolower(c) : c;
            if (islower(c))
            {
                letter[c - 'a']++;
                cnt++;
            }
        }

        string ans = "";
        int minSize = INT_MAX;
        for (auto w : words)
        {
            if (minSize <= w.size()) continue;

            auto letter_t = letter;
            int cnt_t = cnt;
            for (auto c : w)
            {
                if (letter_t[c - 'a']-- <= 0) continue;
                if (--cnt_t == 0)
                {
                    if (minSize > w.size())
                    {
                        minSize = w.size();
                        ans = w;
                    }
                }
            }
        }
        return ans;
    }
};
//////////////////////////////////////////////////////////////////////////
string _solution_run(string licensePlate, vector<string>& words)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << licensePlate << endl;
    Solution sln;
    return sln.shortestCompletingWord(licensePlate, words);
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
