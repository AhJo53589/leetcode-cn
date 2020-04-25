
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dic;
        for (int i = 0; i < order.size(); i++) {
            dic[order[i]] = i;
        }

        auto f = [&dic](const string& a, const string& b) {
            for (int i = 0; i < a.size(); i++) {
                if (i == b.size()) return false;
                if (dic[a[i]] > dic[b[i]]) return false;
                if (dic[a[i]] < dic[b[i]]) return true;
            }
            return a.size() != b.size();
        };

        for (int i = 1; i < words.size(); i++) {
            if (f(words[i], words[i - 1])) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& words, string order)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isAlienSorted(words, order);
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
