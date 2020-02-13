


//////////////////////////////////////////////////////////////////////////
vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto &c : colsum)
    {
        cnt0 += (c == 0);
        cnt1 += (c == 1);
        cnt2 += (c == 2);
    }
    if (upper + lower != cnt1 + cnt2 * 2) return {};
    if (upper > colsum.size() - cnt0) return {};
    if (lower > colsum.size() - cnt0) return {};

    vector<vector<int>> ans(2, vector<int>());
    for (auto &c : colsum)
    {
        if (c == 0)
        {
            ans[0].push_back(0);
            ans[1].push_back(0);
        }
        else if (c == 2)
        {
            ans[0].push_back(1);
            ans[1].push_back(1);
            cnt2--;
            upper--;
            lower--;
        }
        else
        {
            if (upper > cnt2)
            {
                ans[0].push_back(1);
                ans[1].push_back(0);
                upper--;
            }
            else if (lower > cnt2)
            {
                ans[0].push_back(0);
                ans[1].push_back(1);
                lower--;
            }
            else 
            {
                return {};
            }
        }
    }
    return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int upper, int lower, vector<int>& colsum)
{
	return reconstructMatrix(upper,lower,colsum);
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

