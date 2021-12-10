
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        auto s = ""s;
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                s += tolower(ch);
            }
        }

        sort(begin(s), end(s));
        stable_sort(begin(words), end(words), [](auto&&a, auto&& b) {
            return size(a) < size(b); 
            });

        for (auto&& w : words) {
            auto ww = w;
            sort(begin(ww), end(ww));
            if (includes(begin(ww), end(ww), begin(s), end(s))) return w;
        }
        return {};
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
