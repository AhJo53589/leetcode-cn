
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> st;
        for (auto n : nums2) {
            while (!st.empty() && st.back() < n) {
                mp[st.back()] = n;
                st.pop_back();
            }
            st.push_back(n);
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = (mp.find(nums1[i]) == mp.end()) ? -1 : mp[nums1[i]];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums1, vector<int>& nums2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.nextGreaterElement(nums1, nums2);
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
