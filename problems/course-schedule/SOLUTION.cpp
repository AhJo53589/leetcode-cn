


//////////////////////////////////////////////////////////////////////////
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
	vector<int> inDegree(numCourses, 0);
	vector<vector<int>> lst(numCourses, vector<int>());
	for (auto v : prerequisites)
	{
		inDegree[v[0]]++;
		lst[v[1]].push_back(v[0]);
	}

	queue<int> que;
	for (auto i = 0; i < inDegree.size(); i++)
	{
		if (inDegree[i] == 0)
		{
			que.push(i);
		}
	}

	vector<int> ans;
	while (!que.empty())
	{
		auto q = que.front();
		que.pop();
		ans.push_back(q);

		for (auto l : lst[q])
		{
			if (--inDegree[l] == 0)
			{
				que.push(l);
			}
		}
	}

	return ans.size() == numCourses;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int numCourses, vector<vector<int>>& prerequisites)
{
	return canFinish(numCourses,prerequisites);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

