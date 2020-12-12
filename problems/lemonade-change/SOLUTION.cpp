
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> own;
        for (auto& n : bills) {
            if (n == 5) {
                own[5]++;
                continue;
            }
            if (n == 10 && own[5] != 0) {
                own[5]--;
                own[10]++;
                continue;
            }
            if (n == 20 && own[5] != 0 && own[10] != 0) {
                own[5]--;
                own[10]--;
                own[20]++;
                continue;
            }
            if (n == 20 && own[5] >= 3) {
                own[5] -= 3;
                own[20]++;
                continue;
            }
            return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& bills)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.lemonadeChange(bills);
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
