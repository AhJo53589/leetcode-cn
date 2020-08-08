
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minInsertions(string s) {
		vector<int> data(s.size(), 0);
		for (int i = 0; i < s.size(); i++) {
			data[i] = s[i] - '(';
		}

		int ans = 0;
		while (blance(data)) {
			ans += ins(data);
		}
		return ans;
    }

	bool blance(vector<int>& s) {
		vector<int> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 0) {
				st.push_back(s[i]);
			}
			else {
				if (st.size() >= 2 && st[st.size() - 2] == 0 && st.back() == 1) {
					st.pop_back();
					st.pop_back();
				}
				else {
					st.push_back(s[i]);
				}
			}
		}
		swap(s, st);
		return !s.empty();
	}

	int ins(vector<int>& s) {
		int r = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			r += (s[i] == 1);
			if (s[i] == 0) {
				for (int j = 0; j < r; j++) {
					s.pop_back();
				}
				s.pop_back();
				return 2 - r;
			}
		}
		s.clear();
		return r / 2 + (r % 2) * 2;
	}
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s)
{
	int caseNo = 7;
	static int caseCnt = 0;
	if (caseNo != -1 && caseCnt++ != caseNo) return {};

	cout << s << endl;
	Solution sln;
	return sln.minInsertions(s);
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
