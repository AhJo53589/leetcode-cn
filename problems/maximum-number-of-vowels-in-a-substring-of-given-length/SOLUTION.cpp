
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> us({ 'a', 'e', 'i', 'o', 'u' });
        
        int ans = 0;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (j < s.size()) {
            while (j < s.size() && j - i < k) {
                cnt += (us.count(s[j]) != 0);
                j++;
            }
            ans = max(ans, cnt);

            while (true) {
                cnt -= (us.count(s[i]) != 0);
                i++;
                if (i == j || us.count(s[i]) != 0) break;
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int k)
{
    //int caseNo = 5;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << s << endl;
    cout << k << endl;
    Solution sln;
    return sln.maxVowels(s, k);
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
