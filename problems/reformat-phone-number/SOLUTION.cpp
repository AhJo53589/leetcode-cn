
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reformatNumber(string number) {
		string s;
		for (auto& c : number) {
			if (c == '-' || c == ' ') continue;
			s += c;
		}
		string ans;
		for (int i = 0; i < s.size();) {
			if (s.size() - i > 4) {
				ans += s.substr(i, 3);
				ans += "-";
				i += 3;
				continue;
			}

			if (s.size() - i == 2) {
				ans += s.substr(i, 2);
				i += 2;
			}
			else if (s.size() - i == 3) {
				ans += s.substr(i, 3);
				i += 3;
			}
			else {
				ans += s.substr(i, 2);
				ans += "-";
				i += 2;
			}
		}
		return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string number)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.reformatNumber(number);
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
