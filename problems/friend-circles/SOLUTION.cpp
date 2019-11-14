
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
vector<int> Tree;
int findRoot(int x) {
	if (Tree[x] == -1) return x;
	int tmp = findRoot(Tree[x]);
	Tree[x] = tmp;
	return tmp;
}

int findCircleNum(vector<vector<int>>& M) {
	Tree.resize(M.size(), -1);
	for (int i = 0; i < M.size(); i++) {
		for (int j = i + 1; j < M.size(); j++) {
			if (M[i][j] == 1) {
				int a = findRoot(i);
				int b = findRoot(j);
				if (a != b) Tree[a] = b;
			}
		}
	}
	int ans = 0;
	for (auto i : Tree) {
		if (i == -1) ans++;
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
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/friend-circles/tests.txt";
}

