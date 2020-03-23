
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    string longestPrefix(string s) {
        int base = 131;
        vector<unsigned long long> p(100002, 0);
        p[0] = 1;
        vector<unsigned long long> hash(100002, 0);
        hash[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            hash[i] = hash[i - 1] * base + s[i - 1] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        for (int i = s.size() - 1; i >= 1; i--) {
            unsigned long long pre = hash[i];
            unsigned long long suf = hash[s.size()] - hash[s.size() - i] * p[i];
            if (pre == suf) {
                return s.substr(0, i);
            }
        }
        return "";
    }
};

class Solution
{
public:
    string longestPrefix(string s)
    {
        auto prefixEnd = s.end();
        auto suffixBegin = s.begin();
        for (int i = s.size() - 1; i > 0; --i)
        {
            --prefixEnd;
            ++suffixBegin;
            if (equal(s.begin(), prefixEnd, suffixBegin, s.end()))
            {
                return string(s.begin(), prefixEnd);
            }
        }

        return string();
    }
};


//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.longestPrefix(s);
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
