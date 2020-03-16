
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int magicalString(int n)
    {
        if (n < 1) return 0;
        
        int ans = 1;
        queue<int> que;
        que.push(2);
        int i = 3;
        int num = 2;
        //cout << 1 << "," << 2 << "," << 2 << ",";
        while (i < n)
        {
            num = (num == 1) ? 2 : 1;
            
            auto q = que.front();
            que.pop();

            if (q == 2)
            {
                que.push(num);
                i++;
                ans += (num == 1);
                //cout << num << ",";
            }
            if (i < n)
            {
                que.push(num);
                i++;
                ans += (num == 1);
                //cout << num << ",";
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.magicalString(n);
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
