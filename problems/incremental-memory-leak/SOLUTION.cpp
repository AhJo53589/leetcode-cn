
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        long long sec = 1;
        while (sec <= memory1 || sec <= memory2) {
            int& m = (memory1 >= memory2) ? memory1 : memory2;
            m -= sec;
            sec++;
        }
        return { (int)sec, memory1, memory2 };
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int memory1, int memory2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.memLeak(memory1, memory2);
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
