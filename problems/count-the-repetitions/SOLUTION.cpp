
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        vector<int> repeatCnt(102, 0);
        vector<int> nextIdx(102, -1);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k)
        {
            int tag = 0;
            for (int i = 0; i < s1.size(); ++i) 
            {
                if (s1[i] == s2[j])
                {
                    ++j;
                    tag = 1;
                    if (j == s2.size())
                    {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            if (tag == 0) return 0;
            repeatCnt[k] = cnt;
            if (nextIdx[j] != -1)
            {
                int start = nextIdx[j];
                int interval = k - start;
                int repeat = (n1 - start) / interval;
                int patternCnt = (repeatCnt[k] - repeatCnt[start]) * repeat;
                int remainCnt = repeatCnt[start + (n1 - start) % interval];
                return (patternCnt + remainCnt) / n2;
            }
            else
            {
                nextIdx[j] = k;
            }

        }
        return repeatCnt[n1] / n2;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s1, int n1, string s2, int n2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getMaxRepetitions(s1, n1, s2, n2);
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
