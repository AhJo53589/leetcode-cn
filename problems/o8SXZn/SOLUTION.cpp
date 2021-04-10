
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int t = 0;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < bucket.size(); i++) {
            if (vat[i] == 0) continue;
            if (bucket[i] == 0) {
                t++;
                bucket[i] += bucket[i] + 1;
            }
            pq.push({ (vat[i] - 1) / bucket[i] + 1, bucket[i], i });
        }

        int ans = INT_MAX;
        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();
            if (t >= ans) break;
            ans = min(ans, q[0] + t);

            int i = q[2];
            int nb = q[1] + 1;
            pq.push({ (vat[i] - 1) / nb + 1, nb, i });
            t++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& bucket, vector<int>& vat)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(bucket);
    printVectorT(vat);
    Solution sln;
    return sln.storeWater(bucket, vat);
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
