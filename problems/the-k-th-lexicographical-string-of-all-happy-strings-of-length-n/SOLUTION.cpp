
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string getHappyString(int n, int k) 
    {
        string s(n, 'a');
        for (int i = 1; i < n; i += 2)
        {
            s[i] = 'b';
        }
        k -= 1;

        bool flag = true;
        while (k-- > 0)
        {
            for (int i = s.size() - 1; i >= 0; i--)
            {
                flag = false;
                if (s[i] == 'd') break;

                s[i]++;
                s[i] += (i > 0 && s[i - 1] == s[i]);
                flag = !(s[i] == 'd');
                if (!flag) continue;

                for (int j = i + 1; j < s.size(); j++)
                {
                    s[j] = s[j - 1] == 'a' ? 'b' : 'a';
                }
                break;
            }
        }

        return flag ? s : "";
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(int n, int k)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << n << "," << k << endl;
    Solution sln;
    return sln.getHappyString(n, k);
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
