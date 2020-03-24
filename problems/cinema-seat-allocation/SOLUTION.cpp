
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
    {
        unordered_map<int, int> rsCnt;
        for (auto& rs : reservedSeats)
        {
            if (rs[1] == 10 || rs[1] == 1) continue;
            rsCnt[rs[0]] |= 1 << ((rs[1] - 2) / 2);
        }
        int ans = 2 * n;
        for (auto& p : rsCnt)
        {
            cout << bitset<4>(p.second) << endl;
            ans -= 2;
            ans += ((p.second & 0b0011) == 0 || (p.second & 0b0110) == 0 || (p.second & 0b1100) == 0);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, vector<vector<int>>& reservedSeats)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxNumberOfFamilies(n, reservedSeats);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
