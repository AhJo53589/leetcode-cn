
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& op : operations) {
            int x = gem[op[0]] / 2;
            gem[op[0]] -= x;
            gem[op[1]] += x;
        }
        int _max = *max_element(gem.begin(), gem.end());
        int _min = *min_element(gem.begin(), gem.end());
        return _max - _min;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& gem, vector<vector<int>>& operations)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.giveGem(gem, operations);
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
