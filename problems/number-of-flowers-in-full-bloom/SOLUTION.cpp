
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> op(flowers.size());
        vector<int> cl(flowers.size());
        for (int i = 0; i < flowers.size(); i++) {
            op[i] = flowers[i][0];
            cl[i] = flowers[i][1];
        }
        sort(op.begin(), op.end());
        sort(cl.begin(), cl.end());

        vector<int> ans(persons);
        for (int& t : ans) {
            int a = upper_bound(op.begin(), op.end(), t) - op.begin();
            int b = upper_bound(cl.begin(), cl.end(), t - 1) - cl.begin();
            t = a - b;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& flowers, vector<int>& persons)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.fullBloomFlowers(flowers, persons);
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
