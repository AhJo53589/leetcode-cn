
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findComplement(int num) {
        uint hibit = 0;
        uint n = num;
        while (n != 0) {
            hibit = n;
            n &= (n - 1);
        }
        return num ^ ((hibit << 1) - 1);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int num)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findComplement(num);
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
