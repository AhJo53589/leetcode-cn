
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            tk[t[0]].push_back(t[1]);
            vi[t[0]].push_back(false);
        }
        for (auto& t : tk) {
            sort(t.second.begin(), t.second.end());
        }
        ans.push_back("JFK");
        dfs(tickets.size() + 1);
        return ans;
    }

    bool dfs(int len) {
        if (ans.size() == len) return true;
        for (int i = 0; i < tk[ans.back()].size(); i++) {
            if (vi[ans.back()][i]) continue;
            vi[ans.back()][i] = true;
            ans.push_back(tk[ans.back()][i]);
            if (dfs(len)) return true;
            ans.pop_back();
            vi[ans.back()][i] = false;
        }
        return false;
    }

private:
    unordered_map<string, vector<string>> tk;
    unordered_map<string, vector<bool>> vi;
    vector<string> ans;
};

//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<vector<string>>& tickets)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.findItinerary(tickets);
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
