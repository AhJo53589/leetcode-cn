
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reformat(string s) 
    {
        vector<char> vc_a;
        vector<char> vc_b;
        for (auto c : s)
        {
            if (isalpha(c))
            {
                vc_a.push_back(c);
            }
            if (isdigit(c))
            {
                vc_b.push_back(c);
            }
        }
        if (vc_a.size() < vc_b.size())
        {
            swap(vc_a, vc_b);
        }
        if (vc_a.size() - vc_b.size() > 1) return {};

        string ans = "";
        for (int i = 0; i < vc_a.size(); i++)
        {
            ans += vc_a[i];
            if (i >= vc_b.size()) continue;
            ans += vc_b[i];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
string _solution_run(string s)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.reformat(s);
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
