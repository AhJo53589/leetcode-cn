


//////////////////////////////////////////////////////////////////////////
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
	unordered_map<string, int> restIndex;
	unordered_set<string> restList2;
	for (int i = 0; i < list1.size(); i++)
	{
		restIndex[list1[i]] = i;
	}
	for (int i = 0; i < list2.size(); i++)
	{
		if (!restIndex.count(list2[i])) continue;
		restList2.insert(list2[i]);
		restIndex[list2[i]] += i;
	}

	int rIndex = INT_MAX;
	vector<string> rst;
	for (auto r : restIndex)
	{
		if (!restList2.count(r.first)) continue;
		if (r.second == rIndex)
		{
			rst.push_back(r.first);
		}
		else if (r.second < rIndex)
		{
			rIndex = r.second;
			rst.clear();
			rst.push_back(r.first);
		}
	}
	return rst;
}


//////////////////////////////////////////////////////////////////////////
vector<string> _solution_run(vector<string>& list1, vector<string>& list2)
{
	return findRestaurant(list1,list2);
}

//#define USE_SOLUTION_CUSTOM
//vector<string> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

