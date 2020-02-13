


//////////////////////////////////////////////////////////////////////////
vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
{
    vector<int> ans;
    vector<int> vi(mat.size(), 0);
    int minSum = INT_MAX;
    for (int j = 0; j < mat[0].size(); j++)
    {
        if (ans.size() == k) break;
        for (int i = 0; i < mat.size(); i++)
        {
            if (ans.size() == k) break;
            if (vi[i] == 1) continue;
            if (mat[i][j] != 0) continue;
            ans.push_back(i);
            vi[i] = 1;
        }
    }
    int ii = 0;
    while (ans.size() != k)
    {
        while (vi[ii] == 1) ii++;
        ans.push_back(ii);
        vi[ii] = 1;
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& mat, int k)
{
	return kWeakestRows(mat,k);
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

