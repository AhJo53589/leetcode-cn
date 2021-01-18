
//////////////////////////////////////////////////////////////////////////
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) {
            swap(x, y);
        }
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }

    vector<int> data;
}; 


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string, int> mp;
        for (int i = 0; i < accounts.size(); i++) {
            int x = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                const auto& email = accounts[i][j];
                if (mp.find(email) != mp.end()) {
                    x = mp[email];
                    dsu.unionSet(x, i);
                }
                else {
                    mp[email] = x;
                }
            }
        }

        unordered_map<int, pair<string, set<string>>> temp;
        for (int i = 0; i < accounts.size(); i++) {
            int x = dsu.root(i);
            if (temp.find(x) == temp.end()) {
                temp[x] = {accounts[i][0], set<string>()};
            }
            for (int j = 1; j < accounts[i].size(); j++) {
                temp[x].second.insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for (auto& [k, p] : temp) {
            ans.push_back({p.first});
            for (auto& e : p.second) {
                ans.back().push_back(e);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(vector<vector<string>>& accounts)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.accountsMerge(accounts);
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
