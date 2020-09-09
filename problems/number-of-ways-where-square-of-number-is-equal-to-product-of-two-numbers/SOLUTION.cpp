
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> um1;
        unordered_map<long long, int> um2;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                long long t = (long long)nums1[i] * (long long)nums1[j];
                um1[t]++;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                long long t = (long long)nums2[i] * (long long)nums2[j];
                um2[t]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            long long t = (long long)nums1[i] * (long long)nums1[i];
            ans += um2[t];
        }
        for (int i = 0; i < nums2.size(); i++) {
            long long t = (long long)nums2[i] * (long long)nums2[i];
            ans += um1[t];
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums1, vector<int>& nums2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.numTriplets(nums1, nums2);
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
