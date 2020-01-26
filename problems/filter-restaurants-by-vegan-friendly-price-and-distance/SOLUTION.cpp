


//////////////////////////////////////////////////////////////////////////
vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance)
{
	vector<int> valid(restaurants.size(), 1);
	for (size_t i = 0; i < restaurants.size(); i++)
	{
		if (veganFriendly == 1)
		{
			valid[i] = restaurants[i][2];
		}
		if (maxPrice < restaurants[i][3])
		{
			valid[i] = 0;
		}
		if (maxDistance < restaurants[i][4])
		{
			valid[i] = 0;
		}
	}
	vector<vector<int>> s;
	for (size_t i = 0; i < restaurants.size(); i++)
	{
		if (valid[i] == 0) continue;
		s.push_back({ restaurants[i][1], restaurants[i][0] });
	}
	sort(s.rbegin(), s.rend());
	vector<int> ans;
	for (size_t i = 0; i < s.size(); i++)
	{
		ans.push_back(s[i][1]);
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance)
{
	return filterRestaurants(restaurants,veganFriendly,maxPrice,maxDistance);
}

//#define USE_SOLUTION_CUSTOM
//vector<int> _solution_custom(TestCases &tc)
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
	return "../../problems/filter-restaurants-by-vegan-friendly-price-and-distance/tests.txt";
}

