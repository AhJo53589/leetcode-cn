
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numSplits(string s) {
        int ans = 0;

		vector<int> l_dic(26, 0);
		vector<int> r_dic(26, 0);
		int left = 0;
		int right = 0;

		for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
			right += (r_dic[c] == 0);
			r_dic[c]++;
		}

		for (int i = 0; i < s.size() - 1; i++) {
			int c = s[i] - 'a';
			left += (l_dic[c] == 0);
			l_dic[c]++;
			r_dic[c]--;
			right -= (r_dic[c] == 0);
			ans += (left == right);
		}

		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

	cout << s << endl;
	Solution sln;
	return sln.numSplits(s);
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
