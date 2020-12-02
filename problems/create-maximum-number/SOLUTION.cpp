
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, 0);
        
        for (int s = max(0, k - (int)nums2.size()); s <= min(k, (int)nums1.size()); s++) {
            vector<int> temp;
            vector<int> temp1 = maxKsequence(nums1, s);
            vector<int> temp2 = maxKsequence(nums2, k - s);
            
            auto iter1 = temp1.begin();
            auto iter2 = temp2.begin();
            while (iter1 != temp1.end() || iter2 != temp2.end()){
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);
            }
            
            ans = lexicographical_compare(ans.begin(), ans.end(), temp.begin(), temp.end()) ? temp : ans;
        }
        return ans;
    }

    vector<int> maxKsequence(vector<int> v, int k) {
        if (v.size() <= k) return v;
        vector<int> ans;
        int pop = v.size() - k;
        for (int i = 0; i < v.size(); i++) {
            while (!ans.empty() && v[i] > ans.back() && pop-- > 0) {
                ans.pop_back();
            }
            ans.push_back(v[i]);
        }
        ans.resize(k);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums1, vector<int>& nums2, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxNumber(nums1, nums2, k);
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
