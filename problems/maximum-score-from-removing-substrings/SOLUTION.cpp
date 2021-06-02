
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int ans = 0;
        ans += calc(s, 'a', 'b', x);
        ans += calc(s, 'b', 'a', y);
        return ans;
    }

    int calc(string& s, char first, char second, int sc) {
        int score = 0;
        string st;
        for (auto c : s) {
            if (!st.empty() && st.back() == first && c == second) {
                score += sc;
                st.pop_back();
                continue;
            }
            st += c;
        }
        s = st;
        return score;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int x, int y)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    if (s.size() < 50) {
        cout << s << endl << "x = " << x << ", y = " << y << endl;
    }

    Solution sln;
    return sln.maximumGain(s, x, y);
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
