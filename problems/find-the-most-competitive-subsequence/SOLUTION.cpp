
//////////////////////////////////////////////////////////////////////////
class Solution2 {   // tle
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int right = -1;
        vector<int> ans;
        for (int i = 0; i < nums.size() && ans.size() != k; i++) {
            for (int j = right + 1; j <= nums.size() - (k - ans.size()); j++) {
                pq.push({ nums[j], j });
                right = j;
            }
            while (!pq.empty() && pq.top()[1] < i) {
                pq.pop();
            }
            ans.push_back(pq.top()[0]);
            i = pq.top()[1];
        }
        return ans;
    }
};

class Solution { // ac
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n - k + 1; ++i)
            pq.emplace(nums[i], i);
        vector<int> ans;
        int l = 0;
        for (int i = 0; i < k; ++i) {
            while (pq.top().second < l)
                pq.pop();
            auto [num, idx] = pq.top();
            pq.pop();
            l = idx + 1;
            ans.emplace_back(num);
            if (i < k - 1)
                pq.emplace(nums[n - k + i + 1], n - k + i + 1);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorT(nums);
    //cout << k << endl;
    Solution sln;
    return sln.mostCompetitive(nums, k);
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
