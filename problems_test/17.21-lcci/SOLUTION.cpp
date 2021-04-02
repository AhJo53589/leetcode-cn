
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        vector<int> left(height.size(), 0);
        left.front() = height.front();
        for (int i = 1; i < height.size(); i++) {
            left[i] = max(height[i], left[i - 1]);
        }

        vector<int> right(height.size(), 0);
        right.back() = height.back();
        for (int i = (int)height.size() - 2; i >= 0; i--) {
            right[i] = max(height[i], right[i + 1]);
        }

        int ans = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int t = min(left[i - 1], right[i + 1]) - height[i];
            ans += (t < 0) ? 0 : t;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& height)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.trap(height);
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
