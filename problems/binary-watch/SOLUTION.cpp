
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> ans;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 60; j++) 
            {
                if (count1(i) + count1(j) != num) continue;
                ans.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
            }
        }
        return ans;
    }

    int count1(int n)
    {
        int cnt = 0;
        while (n != 0)
        {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
};


//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(int num)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.readBinaryWatch(num);
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
