
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int compress(vector<char>& chars) 
    {
        if (chars.empty()) return 0;
        
        size_t j = 0;
        int cnt = 0;
        for (size_t i = 1; i <= chars.size(); i++)
        {
            cnt++;
            if (i == chars.size() || chars[i] != chars[j])
            {
                j++;
                if (cnt != 1)
                {
                    string scnt = to_string(cnt);
                    for (auto c : scnt)
                    {
                        chars[j++] = c;
                    }
                }

                if (i == chars.size()) break;
                chars[j] = chars[i];
                cnt = 0;
            }
        }

        return j;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<char>& chars)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(chars);
    Solution sln;
    return sln.compress(chars);
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
