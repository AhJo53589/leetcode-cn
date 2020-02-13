
//////////////////////////////////////////////////////////////////////////
int getNextGroupSize(vector<vector<int>> &g)
{
    for (size_t i = 0; i < g.size(); i++)
    {         
        if (g[i].empty()) continue;
        return i;
    }
    return 0;
}

int getNext(vector<vector<int>> &g)
{
    int a = -1;
    for (size_t i = 0; i < g.size(); i++)
    {         
        if (g[i].empty()) continue;
        a = g[i].back();
        g[i].pop_back();
        break;
    }
    return a;
}

vector<vector<int>> groupThePeople(vector<int>& groupSizes)
{
    size_t N = groupSizes.size();
    vector<vector<int>> g(N + 1, vector<int>());
    for (int i = 0; i < N; i++)
    {
        g[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> ans;
    while (true)
    {
        int t = getNextGroupSize(g);
        if (t == 0) break;
        vector<int> temp;
        while (t--)
        {
            temp.push_back(getNext(g));
        }
        ans.push_back(temp);
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(vector<int>& groupSizes)
{
	return groupThePeople(groupSizes);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

