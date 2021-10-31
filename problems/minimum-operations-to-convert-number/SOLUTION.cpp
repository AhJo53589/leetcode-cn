
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans = 0;

        unordered_set<int> vi;
        vi.insert(start);

        vector<int> vn(3 * nums.size(), 0);
        queue<int> que;
        que.push(start);
        while (!que.empty()) {
            ans++;
            for (int len = (int)que.size() - 1; ~len; len--) {
                auto q = que.front();
                que.pop();

                calc(q, nums, vn);

                for (auto& n : vn) {
                    if (n == goal) return ans;
                    if (n < 0 || n > 1000) continue;
                    if (vi.find(n) == vi.end()) {
                        vi.insert(n);
                        que.push(n);
                    }
                }
            }
        }
        return -1;
    }

    void calc(int q, vector<int>& nums, vector<int>& vn) {
        for (int i = 0; i < nums.size(); i++) {
            vn[i * 3 + 0] = q + nums[i];
            vn[i * 3 + 1] = q - nums[i];
            vn[i * 3 + 2] = q ^ nums[i];
        }
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums, int start, int goal)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minimumOperations(nums, start, goal);
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
