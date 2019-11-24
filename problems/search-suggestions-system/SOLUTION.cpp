
//////////////////////////////////////////////////////////////////////////
size_t find(vector<string>& p, size_t pos, char c, size_t lo, size_t hi)
{
	while (lo < hi)
	{
		size_t md = lo + (hi - lo) / 2;
		if (p[md][pos] < c)
		{
			lo = md + 1;
		}
		else
		{
			hi = md;
		}
	}
	return lo;
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
{
    sort(products.begin(), products.end());

    vector<vector<string>> ans(searchWord.size(), vector<string>());
	size_t lo = 0;
	size_t hi = products.size();
    for (size_t i = 0; i < ans.size(); i++)
    {            
		lo = find(products, i, searchWord[i], lo, hi);
		hi = find(products, i, searchWord[i] + 1, lo, hi);
		for (size_t j = lo; j < hi; j++)
		{
			if (ans[i].size() == 3) break;
			ans[i].push_back(products[j]);
		}
	}
    return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(vector<string>& products, string searchWord)
{
	return suggestedProducts(products,searchWord);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<string>> _solution_custom(TestCases &tc)
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
	return "../../problems/search-suggestions-system/tests.txt";
}

