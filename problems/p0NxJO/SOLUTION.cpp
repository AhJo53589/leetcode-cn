
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int magicTower(vector<int>& nums) {
        int ans = 0;
        long long sum = 1;
        long long last = 0;
        priority_queue<long long> pq;
        for (auto n : nums) {
            sum += n;
            if (n < 0) {
                pq.push(-n);
            }

            if (sum <= 0) {
                while (sum <= 0 && !pq.empty()) {
                    sum += pq.top();
                    last -= pq.top();
                    pq.pop();
                    ans++;
                }
            }
        }
        return sum + last > 0 ? ans : -1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& nums)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.magicTower(nums);
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
