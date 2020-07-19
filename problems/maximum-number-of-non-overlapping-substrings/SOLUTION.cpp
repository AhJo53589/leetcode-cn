
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> subs(26);
        for (int i = 0; i < subs.size(); i++) {
            subs[i].push_back(INT_MAX);
            char c = 'a' + i;
            if (s.find(c) == string::npos) continue;
            subs[i].push_back(s.find_first_of(c));
            subs[i].push_back(s.find_last_of(c));
            subs[i][0] = subs[i][2] - subs[i][1] + 1;
        }

        for (int i = 0; i < subs.size(); i++) {
            if (subs[i].size() == 1) continue;
            subs[i] = getFullSub(subs, s, subs[i][1], subs[i][2]);
        }

        sort(subs.begin(), subs.end());

        vector<string> ans;
        vector<bool> vi(s.size(), false);
        for (auto sub : subs) {
            if (sub.size() == 1) break;

            bool check = true;
            for (int j = sub[1]; j <= sub[2] && check; j++) {
                check = !vi[j];
            }
            if (!check) continue;

            for (int j = sub[1]; j <= sub[2]; j++) {
                vi[j] = true;
            }
            ans.push_back(s.substr(sub[1], sub[0]));
        }
        return ans;
    }

    vector<int> getFullSub(vector<vector<int>>& subs, string& s, int left, int right) {
        for (int j = left + 1; j < right; j++) {
            int n = s[j] - 'a';
            if (left <= subs[n][1] && right >= subs[n][2]) continue;
            left = min(left, subs[n][1]);
            right = max(right, subs[n][2]);
            j = left;
        }
        return { right - left + 1, left, right };
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << s << endl;
    for (int i = 0; i < s.size(); i++) {
        cout << setw(3) << i << ",";
    }
    cout << endl;
    for (int i = 0; i < s.size(); i++) {
        cout << setw(3) << s[i] << ",";
    }
    cout << endl << "-----------------------------------------------------" << endl;

    Solution sln;
    return sln.maxNumOfSubstrings(s);
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
