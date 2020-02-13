
//////////////////////////////////////////////////////////////////////////
int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) 
{
	int ans = parent.size();

	vector<int> cnt(parent.size(), 0);
	vector<int> del(parent.size(), 0);
	vector<int> visited(parent.size(), 0);
	vector<int> sum(parent.size(), 0);
	for (auto i = 0; i < parent.size(); i++)
	{
		if (parent[i] != -1)
		{
			cnt[parent[i]]++;
			del[parent[i]]++;
		}
	}

	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < parent.size(); i++)
		{
			if (cnt[i] > 0)
			{
				flag = true;
				continue;
			}
			if (visited[i]++ != 0) continue;

			sum[i] += value[i];
			if (parent[i] != -1)
			{
				cnt[parent[i]]--;
				sum[parent[i]] += sum[i];
			}

			if (sum[i] == 0)
			{
				ans -= del[i] + 1;
			}
			if (parent[i] != -1)
			{
				del[parent[i]] = (sum[i] == 0) ? del[parent[i]] - 1 : del[parent[i]] + del[i];
			}
		}
	}

	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(int nodes, vector<int>& parent, vector<int>& value)
{
	return deleteTreeNodes(nodes,parent,value);
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

