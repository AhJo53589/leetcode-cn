
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);
        int maxcnt = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> fs;
        for (int i = 0; i < k; i++) {
            fs.insert(i);
        }

        for (int i = 0; i < arrival.size(); i++) {
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                fs.insert(pq.top().second);
                pq.pop();
            }

            int cur = getServer(i % k, fs);
            if (cur == -1) continue;
            maxcnt = max(maxcnt, ++cnt[cur]);
            pq.push({ arrival[i] + load[i], cur });
            fs.erase(cur);
        }

        vector<int> ans;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] != maxcnt) continue;
            ans.push_back(i);
        }
        return ans;
    }

    int getServer(int start, set<int>& fs) {
        auto it = fs.lower_bound(start);
        if (it != fs.end()) return *it;
        it = fs.lower_bound(0);
        if (it != fs.end()) return *it;
        return -1;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(int k, vector<int>& arrival, vector<int>& load)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.busiestServers(k, arrival, load);
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
