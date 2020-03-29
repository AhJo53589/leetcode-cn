
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numTeams(vector<int>& rating) 
    {
        if (rating.size() < 3) return 0;
        int ans = 0;
        for (int i = 0; i < rating.size(); i++)
        {
            for (int j = i + 1; j < rating.size(); j++)
            {
                for (int k = j + 1; k < rating.size(); k++)
                {
                    if ((rating[i] < rating[j] && rating[j] < rating[k])
                        || (rating[i] > rating[j] && rating[j] > rating[k]))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& rating)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numTeams(rating);
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
