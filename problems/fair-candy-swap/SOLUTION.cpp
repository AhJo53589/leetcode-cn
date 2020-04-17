
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
    {
        long long sumA = accumulate(A.begin(), A.end(), 0);
        long long sumB = accumulate(B.begin(), B.end(), 0);
        int diff = (sumA - sumB) / 2;
        
        unordered_map<int, int> mp;
        for (int i = 0; i < A.size(); i++)
        {
            mp[A[i] - diff] = i;
        }
        for (int j = 0; j < B.size(); j++)
        {
            if (mp.count(B[j]) == 0) continue;
            return { A[mp[B[j]]], B[j] };
        }
        return {};
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& A, vector<int>& B)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.fairCandySwap(A, B);
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
