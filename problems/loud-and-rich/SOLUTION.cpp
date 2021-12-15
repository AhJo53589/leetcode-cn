
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for (auto& r : richer) {
            um[r[1]].push_back(r[0]);
        }

        vector<int> ans(quiet.size(), 0);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = check(i, quiet);
        }
        return ans;
    }

    int check(int n, vector<int>& quiet) {
        if (cache.find(n) != cache.end()) return cache[n];

        int x = n;
        for (auto& r : um[n]) {
            x = (quiet[x] > quiet[r]) ? r : x;
            int y = check(r, quiet);
            x = (quiet[x] > quiet[y]) ? y : x;
        }
        cache[n] = x;
        return x;
    }

private:
    unordered_map<int, vector<int>> um;
    unordered_map<int, bool> vi;
    unordered_map<int, int> cache;
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& richer, vector<int>& quiet)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.loudAndRich(richer, quiet);
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
