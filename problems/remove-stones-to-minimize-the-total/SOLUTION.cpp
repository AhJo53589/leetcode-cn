
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        auto pq = priority_queue{ less<int>{}, piles };
        while (!pq.empty() && k-- > 0) {
            auto q = pq.top();
            pq.pop();

            q -= q / 2;
            pq.push(q);
        }

        int ans = 0;
        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();

            ans += q;
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& piles, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.minStoneSum(piles, k);
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
