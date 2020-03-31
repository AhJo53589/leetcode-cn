
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (n == 0) break;
            if (flowerbed[i] == 1) continue;
            if (i > 0 && flowerbed[i - 1] == 1) continue;
            if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1) continue;
            i++;
            n--;
        }
        return n == 0;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<int>& flowerbed, int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.canPlaceFlowers(flowerbed, n);
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
