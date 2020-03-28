
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int distributeCandies(vector<int>& candies) 
    {
        unordered_set<int> kind;
        for (auto c : candies)
        {
            kind.insert(c);
        }
        return min(candies.size() / 2, kind.size());
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& candies)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.distributeCandies(candies);
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
