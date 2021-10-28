
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {	
        s = filterOut(s);

        set<string> ans;
        vector<int> use(s.size(), 1);

        for (int k = 0; k < s.size(); k++) {
            for (int i = 0; i < s.size(); i++) {
                use[i] = (i >= k) ? 1 : 0;
            }

            do {
                if (valid(s, use)) {
                    string a;
                    for (size_t i = 0; i < s.size(); i++) {
                        if (!use[i]) continue;
                        a += s[i];
                    }
                    ans.insert(a);

                    k = s.size();
                }
            } while (next_permutation(use.begin(), use.end()));
        }
        if (ans.empty()) return { "" };
        return vector<string>(ans.begin(), ans.end());
    }

    string filterOut(string& s) {
        vector<bool> filter(s.size(), false);
        int left = 0;
        int right = count(s.begin(), s.end(), ')');
        for (int i = 0; i < s.size(); i++) {
            left += (s[i] == '(');
            right -= (s[i] == ')');
            
            filter[i] = (s[i] == '(' && right == 0) || (s[i] == ')' && left == 0);
        }

        string ns;
        for (int i = 0; i < s.size(); i++) {
            if (filter[i]) continue;
            ns += s[i];
        }
        return ns;
    }

    bool valid(string& s, vector<int>& use) {
        int st = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (use[i] == 0) continue;
            st += (s[i] == '(');
            st -= (s[i] == ')');
            if (st < 0) return false;
        }
        return (st == 0);
    }
};


//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.removeInvalidParentheses(s);
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
