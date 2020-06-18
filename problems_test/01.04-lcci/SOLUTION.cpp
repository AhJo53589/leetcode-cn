
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> bits;
        for (char c : s) {
            bits.flip(c);
        }
        return bits.none() || bits.count() == 1;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(string s)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.canPermutePalindrome(s);
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
