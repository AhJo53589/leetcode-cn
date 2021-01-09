
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        s += '-';
        unordered_map<string, int> cache;
        int ans = 0;
        int left = -1;
        for (int i = 0; i < s.size(); i++) {
            left = (left == -1 && (s[i] == 'a' || s[i] == 'b')) ? i : left;
            if (left != -1 && s[i] != 'a' && s[i] != 'b') {
                if (i - left > 1) {
                    string n = s.substr(left, i - left);
                    ans += dfs(n, x, y, cache);
                }
                left = -1;
            }
        }
        return ans;
    }

    int dfs(string& s, int x, int y, unordered_map<string, int>& cache) {
        if (cache.find(s) != cache.end()) return cache[s];
        bool flag = false;
        string target[2] = { "ab", "ba" };
        int score[2] = { x, y };
        int ans = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            for (int t = 0; t < 2; t++) {
                if (s[i] == target[t][0] && s[i + 1] == target[t][1]) {
                    s.erase(i, 2);
                    ans = max(ans, dfs(s, x, y, cache) + score[t]);
                    s.insert(i, target[t]);
                    flag = true;
                }
            }
        }
        cache[s] = ans;
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int x, int y)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    cout << s << endl << x << ", " << y << endl;
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
