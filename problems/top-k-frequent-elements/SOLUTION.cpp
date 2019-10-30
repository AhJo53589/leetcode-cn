
//vector<int> topKFrequent(vector<int>& nums, int k) {
//	unordered_map<int, int> m;
//	for (auto i : nums) {
//		m[i]++;
//	}
//	multimap<int, int, greater<int>> s;
//	for (auto i : m) {
//		s.insert(make_pair(i.second, i.first));
//	}
//	vector<int> res;
//	for (auto i : s) {
//		if (res.size() == k) break;
//		res.push_back(i.second);
//	}
//	return res;
//}

//////////////////////////////////////////////////////////////////////////
vector<int> topKFrequent(vector<int>& nums, int k)
{
	vector<int> res;
	unordered_map<int, int> m;
	for (auto n : nums) m[n]++;

	vector<pair<int, int>> freq;
	for (auto x : m) freq.push_back(x);
	sort(freq.begin(), freq.end(), [](auto a, auto b) { return a.second > b.second; });

	auto it = freq.begin();
	for (int i = 0; i < k; i++)
	{
		res.push_back(it->first);
		it++;
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int>& nums, int k)
{
	return topKFrequent(nums,k);
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
	return "../../problems/top-k-frequent-elements/tests.txt";
}

