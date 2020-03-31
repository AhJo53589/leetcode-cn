
//////////////////////////////////////////////////////////////////////////
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Employee {
public:
    Employee(int _id, int _importance, vector<int> _subordinates)
        : id(_id), importance(_importance), subordinates(_subordinates)
    {
    }

    int id;
    int importance;
    vector<int> subordinates;
};

class Solution2 {
public:
    int getImportance(vector<Employee*> employees, int id)
    {
        unordered_map<int, Employee*> mp;
        for (auto p : employees)
        {
            if (p == nullptr) continue;
            mp[p->id] = p;
        }

        int ans = 0;
        queue<int> que;
        que.push(id);

        while (!que.empty())
        {
            ans += mp[que.front()]->importance;
            for (auto n : mp[que.front()]->subordinates)
            {
                que.push(n);
            }
            que.pop();
        }
        return ans;
    }
};

class Solution {
public:
    int dfs(unordered_map<int, Employee*>& mp, int id)
    {
        if (mp.count(id) == 0 || mp[id] == nullptr) return 0;
        int ans = mp[id]->importance;
        for (auto n : mp[id]->subordinates)
        {
            ans += dfs(mp, n);
        }
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id)
    {
        unordered_map<int, Employee*> mp;
        for (auto p : employees)
        {
            if (p == nullptr) continue;
            mp[p->id] = p;
        }

        return dfs(mp, id);
    }
};

//////////////////////////////////////////////////////////////////////////
//int _solution_run(vector<Employee*> employees, int id)
//{
//    //int caseNo = -1;
//    //static int caseCnt = 0;
//    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
//
//    Solution sln;
//    return sln.getImportance(employees, id);
//}

#define USE_SOLUTION_CUSTOM
int _solution_custom(TestCases& tc)
{
    vector<string> sp = tc.get<vector<string>>();
    int id = tc.get<int>();

    vector<Employee*> employees;
    for (int i = 0; i < sp.size(); i++)
    {
        TestCases stc(sp[i]);
        int _id = stc.get<int>();
        int _importance = stc.get<int>();
        vector<int> _subordinates = stc.get<vector<int>>();
        Employee* _employee = new Employee(_id, _importance, _subordinates);
        employees.push_back(_employee);
    }

    Solution sln;
    int ans = sln.getImportance(employees, id);

    for (int i = 0; i < employees.size(); i++)
    {
        delete(employees[i]);
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
