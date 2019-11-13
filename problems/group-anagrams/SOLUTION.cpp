


//////////////////////////////////////////////////////////////////////////
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> hashmap;
	for (auto s : strs) {
		string temp = s;
		sort(temp.begin(), temp.end());
		hashmap[temp].push_back(s);
	}
	int len = hashmap.size();
	vector<vector<string>> ans(len);
	int index = 0;
	for (auto i : hashmap) {
		ans[index] = i.second;
		++index;
	}
	return ans;
}


//////////////////////////////////////////////////////////////////////////
vector<vector<string>> _solution_run(vector<string>& strs)
{
	return groupAnagrams(strs);
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
	return "../../problems/group-anagrams/tests.txt";
}

