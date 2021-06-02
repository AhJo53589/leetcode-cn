
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> val(aliceValues.size());
        for (int i = 0; i < val.size(); i++) {
            val[i] = { aliceValues[i] + bobValues[i], i };
        }
        sort(val.rbegin(), val.rend());

        int ans = 0;
        for (int i = 0; i < val.size(); i++) {
            if (i % 2 == 0) {
                ans += aliceValues[val[i].second];
            }
            else {
                ans -= bobValues[val[i].second];
            }
        }
        return ans == 0 ? 0 : abs(ans) / ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& aliceValues, vector<int>& bobValues)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(aliceValues);
    printVectorT(bobValues);

    Solution sln;
    return sln.stoneGameVI(aliceValues, bobValues);
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
