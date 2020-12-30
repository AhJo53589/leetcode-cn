
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto n : stones) {
            pq.push(n);
        }

        while (pq.size() > 1) {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            if (x == y) continue;
            pq.push(x - y);
        }

        return pq.empty() ? 0 : pq.top();
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& stones)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.lastStoneWeight(stones);
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
