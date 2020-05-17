
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        for (auto& f : favoriteCompanies) {
            sort(f.begin(), f.end());
        }

        map<int, vector<int>> mapSizeIndex;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            mapSizeIndex[favoriteCompanies[i].size()].push_back(i);
        }

        vector<int> ans;
        for (auto it = mapSizeIndex.rbegin(); it != mapSizeIndex.rend(); it++) {
            for (auto& p : it->second) {
                if (it != mapSizeIndex.rbegin() && checkIncludes(favoriteCompanies, ans, p)) continue;
                ans.push_back(p);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    bool checkIncludes(vector<vector<string>>& fc, vector<int>& ans, int p) {
        for (auto i : ans) {
            if (includes(fc[i].begin(), fc[i].end(), fc[p].begin(), fc[p].end())) return true;
        }
        return false;
    }    
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<string>>& favoriteCompanies)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    //printVectorVectorT(favoriteCompanies);
    Solution sln;
    return sln.peopleIndexes(favoriteCompanies);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
