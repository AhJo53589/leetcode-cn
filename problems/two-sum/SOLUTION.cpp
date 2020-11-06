
//////////////////////////////////////////////////////////////////////////
//class Solution 
//{
//public:
//	vector<int> twoSum(vector<int>& nums, int target)	// 4ms
//	{
//		vector<int> v;
//		unordered_map<int, int> hash;
//		for (int i = nums.size() - 1; i >= 0; hash[nums[i]] = i, i--)
//		{
//			if (hash.find(target - nums[i]) == hash.end())
//				continue;
//			v.push_back(i);
//			v.push_back(hash[target - nums[i]]);
//			return v;
//		}
//		return v;
//	}
//};


//////////////////////////////////////////////////////////////////////////
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> sum;
        vector<int> rst;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum.find(target - nums[i]) != sum.end())
            {
                rst.push_back(sum[target - nums[i]]);
                rst.push_back(i);
                break;
            }
            else
            {
                sum[nums[i]] = i;
            }
        }
        return rst;
    }
};


//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.twoSum(nums, target);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
