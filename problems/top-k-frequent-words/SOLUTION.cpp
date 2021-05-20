
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& w : words) {
            cnt[w]++;
        }

        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto& it : cnt) {
            pq.emplace(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& words, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.topKFrequent(words, k);
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
