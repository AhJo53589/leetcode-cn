
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        score = { x, y };

        s += '-';
        int ans = 0;
        int left = -1;
        for (int i = 0; i < s.size(); i++) {
            left = (left == -1 && (s[i] == 'a' || s[i] == 'b')) ? i : left;
            if (left != -1 && s[i] != 'a' && s[i] != 'b') {
                if (i - left > 1) {
                    string n = s.substr(left, i - left);
                    ans += dfs(n);
                }
                left = -1;
            }
        }
        return ans;
    }

    int dfs(string& s) {
        if (cache.find(s) != cache.end()) return cache[s];
        int ans = 0;
        for (int i = 0; i + 1 < s.size();) {
            auto sc = getScore(s, i);
            if (sc[2] == 0) break;
            int cut_left = (sc[1] <= sc[2]) ? i : i + sc[1] - sc[2];
            int cut_len = min(sc[1], sc[2]) * 2;
            string n(s);
            n.erase(cut_left, cut_len);
            ans = max(ans, sc[0] + dfs(n));
            i += sc[1];
        }
        cache[s] = ans;
        return ans;
    }

    vector<int> getScore(string& s, int start) {
        int left = 0;
        int right = 0;
        int flag = 0;
        for (int i = start; i < s.size(); i++) {
            flag = (flag == 0 && s[i] == s[start]) ? 0 : 1;
            left += (flag == 0);
            right += (flag == 1 && s[i] != s[start]);
            if (flag == 1 && s[i] == s[start]) break;
        }
        int sc = min(left, right) * score[s[start] != 'a'];
        return { sc, left, right };
    }

private:
    vector<int> score;
    unordered_map<string, int> cache;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int x, int y)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    //cout << s << endl << x << ", " << y << endl;
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
