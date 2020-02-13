


//////////////////////////////////////////////////////////////////////////
string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) 
{
	unordered_map<string, string> rr;
	for (auto vs : regions)
	{
		for (size_t i = 1; i < vs.size(); i++)
		{
			rr[vs[i]] = vs[0];
		}
	}

	unordered_set<string> rs;
	string temp = region1;
	while (true)
	{
		rs.insert(temp);
		if (rr.count(temp) == 0) break;
		temp = rr[temp];
	}
	temp = region2;
	while (true)
	{
		if (rs.count(temp)) break;
		//if (rr.count(temp) == 0) break;
		temp = rr[temp];
	}
	return temp;
}

//////////////////////////////////////////////////////////////////////////
string _solution_run(vector<vector<string>>& regions, string region1, string region2)
{
	return findSmallestRegion(regions,region1,region2);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

