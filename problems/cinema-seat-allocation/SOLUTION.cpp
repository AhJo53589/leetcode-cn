
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        int ans = 0;
        sort(reservedSeats.begin(), reservedSeats.end());
        int r = 0;
        for (int i = 0; i < n;)
        {
            int bitA = 0;
            int bitB = 0;
            int bitC = 0;
            while (r < reservedSeats.size() && reservedSeats[r][0] == i + 1)
            {
                int b = reservedSeats[r][1];
                r++;
                if (b >= 2 && b < 6)
                {
                    bitA |= (1 << (b - 2));
                }
                if (b >= 4 && b < 8)
                {
                    bitB |= (1 << (b - 4));
                }
                if (b >= 6 && b < 10)
                {
                    bitC |= (1 << (b - 6));
                }
            }
            int cntA = 2 - (bitA != 0) - (bitC != 0);
            int cntB = 1 - (bitB != 0);
            ans += max(cntA, cntB);

            if (r >= reservedSeats.size())
            {
                ans += (n - 1 - i) * 2;
                break;
            }

            int next = reservedSeats[r][0] - 1;
            ans += (next - i - 1) * 2;
            i = next;
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
