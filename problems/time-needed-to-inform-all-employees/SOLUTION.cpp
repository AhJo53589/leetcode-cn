//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> v(n,0);
        for(int i=0;i<n;++i){
            int m=i;
            int t=0;
            while((m=manager[m])!=-1){
                t+=informTime[m];
                if(t<=v[m]) break;
                v[m]=t;
            }
        }
        return *max_element(v.begin(),v.end());
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(vector<vector<int>>& mana, vector<int>& informTime, int id, int time, int& ans)
    {
        if (mana[id].empty())
        {
            ans = max(ans, time);
            return;
        }
        time += informTime[id];
        for (auto& next : mana[id])
        {
            dfs(mana, informTime, next, time, ans);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>> mana(manager.size(), vector<int>());
        for (int i = 0; i < manager.size(); i++)
        {
            if (manager[i] == -1) continue;
            mana[manager[i]].push_back(i);
        }

        int ans = 0;
        dfs(mana, informTime, headID, 0, ans);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int headID, vector<int>& manager, vector<int>& informTime)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numOfMinutes(n, headID, manager, informTime);
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
