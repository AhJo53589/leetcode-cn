
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt_1(26, 0);
        vector<int> cnt_2(26, 0);

        for (auto &c : s1) {
            cnt_1[c - 'a']++;
        }

        for (int i = 0, j = 0; j < s2.size(); i++) {
            while (j - i < s1.size() && j < s2.size()) {
                cnt_2[s2[j] - 'a']++;
                j++;
            }

            if (j - i != s1.size()) break;
            if (cnt_1 == cnt_2) return true;

            cnt_2[s2[i] - 'a']--;
        }

        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s1, string s2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.checkInclusion(s1, s2);
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
