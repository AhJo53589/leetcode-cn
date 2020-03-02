
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
	{
		nums2.push_back(INT_MAX);
		unordered_map<int, int> um;
		stack<int> st;
		for (auto& n : nums2)
		{
			while (!st.empty() && st.top() < n)
			{
				um[st.top()] = n;
				st.pop();
			}
			st.push(n);
		}

		vector<int> ans;
		for (auto& n : nums1)
		{
			ans.push_back(um[n]);
			ans.back() = (ans.back() == INT_MAX) ? -1 : ans.back();
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
