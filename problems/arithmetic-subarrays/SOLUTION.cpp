
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for (int i = 0; i < l.size(); i++) {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans[i] = check(temp);
        }
        return ans;
    }

    bool check(vector<int>& temp) {
        sort(temp.begin(), temp.end());
        for (int i = 2; i < temp.size(); i++) {
            if (temp[i] - temp[i - 1] != temp[1] - temp[0]) return false;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<bool> _solution_run(vector<int>& nums, vector<int>& l, vector<int>& r)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    
    printVectorT(nums);
    printVectorT(l);
    printVectorT(r);

    Solution sln;
    return sln.checkArithmeticSubarrays(nums, l, r);
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
