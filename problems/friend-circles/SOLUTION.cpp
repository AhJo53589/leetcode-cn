
//////////////////////////////////////////////////////////////////////////
//int findCircleNum(vector<vector<int>>& M)
//{
//	int iNum = 0;
//	unordered_set<int> visited;
//	queue<int> que;
//	for (int i = 0; i < M.size(); i++)
//	{
//		if (visited.count(i)) continue;
//		visited.insert(i);
//		iNum++;
//		for (int j = 0; j < M.size(); j++)
//		{
//			if (visited.count(j)) continue;
//			if (M[i][j] == 0) continue;
//			visited.insert(j);
//			que.push(j);
//		}
//		while (!que.empty())
//		{
//			int q = que.front();
//			que.pop();
//			for (int j = 0; j < M.size(); j++)
//			{
//				if (visited.count(j)) continue;
//				if (M[q][j] == 0) continue;
//				visited.insert(j);
//				que.push(j);
//			}
//		}
//		if (visited.size() == M.size()) return iNum;
//	}
//	return iNum;
//}

//////////////////////////////////////////////////////////////////////////
// ���鼯
int findroot(vector<int>& uf, int x)
{
    return (uf[x] == -1) ? x : (uf[x] = findroot(uf, uf[x]));
}

int findCircleNum(vector<vector<int>>& M)
{
    int ans = M.size();
    vector<int> uf(M.size(), -1);
    for (size_t i = 0; i < M.size(); i++)
    {
        for (size_t j = i + 1; j < M.size(); j++)
        {
            if (M[i][j] == 0) continue;
            int x = findroot(uf, i);
            int y = findroot(uf, j);
            if (x == y) continue;
            uf[y] = x;
            ans--;
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<vector<int>>& M)
{
	return findCircleNum(M);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

