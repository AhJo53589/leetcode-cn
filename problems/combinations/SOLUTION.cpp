
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp(k);
        for (int x = 0; x < (1 << n); x++) {
            if (hammingWeight(x) != k) continue;
            int idx = 0;
            for (int i = 0; i < n && idx != temp.size(); i++) {
                if (x & (1 << i)) {
                    temp[idx++] = i + 1;
                }
            }
            ans.push_back({ temp.begin(), temp.begin() + k });
        }
        return ans;
    }

    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            n &= (n - 1);
            sum++;
        }
        return sum;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int n, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.combine(n, k);
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
