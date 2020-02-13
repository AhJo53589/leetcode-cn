
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
	vector<int> res(arr.size(), 0);

	res[0] = arr[0];
	for (size_t i = 1; i < arr.size(); i++)
	{
		res[i] = res[i - 1] ^ arr[i];
	}

	vector<int> ans;
	for (size_t i = 0; i < queries.size(); i++)
	{
		auto& qu = queries[i];
		int left = (qu[0] == 0) ? 0 : res[qu[0] - 1];
		int r = (left == 0) ? res[qu[1]] : res[qu[1]] ^ left;
		ans.push_back(r);
	}
	return ans;
}

//vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
//{
//	vector<int> ans;
//	for (size_t i = 0; i < queries.size(); i++)
//	{
//		auto& qu = queries[i];
//		int t = arr[qu[0]];
//		for (size_t j = qu[0] + 1; j <= qu[1]; j++)
//		{
//			t ^= arr[j];
//		}
//		ans.push_back(t);
//	}
//
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
//vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
//{
//	vector<vector<int>> res(arr.size(), vector<int>(arr.size(), 0));
//
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		res[i][i] = arr[i];
//		for (size_t j = i + 1; j < arr.size(); j++)
//		{
//			res[i][j] = res[i][j - 1] ^ arr[j];
//		}
//	}
//
//	vector<int> ans;
//	for (size_t i = 0; i < queries.size(); i++)
//	{
//		ans.push_back(res[queries[i][0]][queries[i][1]]);
//	}
//
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& arr, vector<vector<int>>& queries)
{
	return xorQueries(arr,queries);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

