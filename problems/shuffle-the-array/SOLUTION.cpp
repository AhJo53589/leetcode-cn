
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<vector<int>> temp(2, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int t = (i / (nums.size() / 2));
            temp[t].push_back(nums[i]);
        }
        for (int t = 0; t < 2; t++) {
            for (int i = 0; i < temp[t].size(); i++) {
                nums[i * 2] = temp[0][i];
                nums[i * 2 + 1] = temp[1][i];
            }
        }

        return nums;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(nums);
    Solution sln;
    return sln.shuffle(nums, n);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
