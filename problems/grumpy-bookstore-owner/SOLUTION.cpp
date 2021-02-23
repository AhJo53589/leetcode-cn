
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0;
        int window = 0;
        for (int i = 0, j = 0; j < customers.size(); j++) {
            if (j - i == X) {
                window -= (grumpy[i] == 1) ? customers[i] : 0;
                i++;
            }
            window += (grumpy[j] == 1) ? customers[j] : 0;
            ans = max(ans, window);
        }

        for (int i = 0; i < customers.size(); i++) {
            ans += (grumpy[i] == 0) ? customers[i] : 0;
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& customers, vector<int>& grumpy, int X)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxSatisfied(customers, grumpy, X);
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
