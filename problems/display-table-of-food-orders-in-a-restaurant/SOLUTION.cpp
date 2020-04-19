
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) 
    {
        set<string> foodList;
        map<int, map<string, int>> tableList;

        for (auto& o : orders)
        {
            foodList.insert(o[2]);
            tableList[stoi(o[1])][o[2]]++;
        }

        vector<vector<string>> ans;
        vector<string> title = { "Table" };
        for (auto& s : foodList)
        {
            title.push_back(s);
        }
        ans.push_back(title);
        for (auto& p : tableList)
        {
            vector<string> t = { to_string(p.first) };
            for (auto& s : foodList)
            {
                t.push_back(to_string(p.second[s]));
            }
            ans.push_back(t);
        }

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(vector<vector<string>>& orders)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorVectorT(orders);
    Solution sln;
    return sln.displayTable(orders);
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
