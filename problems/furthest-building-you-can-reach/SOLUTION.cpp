
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < heights.size(); i++) {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0) continue;
            pq.push(diff);
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            if (bricks < 0) return i - 1;
        }
        return heights.size() - 1;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& heights, int bricks, int ladders)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(heights);
    cout << bricks << ", " << ladders << endl;
    Solution sln;
    return sln.furthestBuilding(heights, bricks, ladders);
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
