
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0;
        for (; i < costs.size() && coins > 0; i++) {
            coins -= costs[i];
        }
        return i - (coins < 0);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& costs, int coins)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxIceCream(costs, coins);
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
