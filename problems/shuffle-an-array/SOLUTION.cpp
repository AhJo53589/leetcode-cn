


//////////////////////////////////////////////////////////////////////////
class Solution
{
public:
	Solution(vector<int>& nums) : m_nums(nums)
	{
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		return m_nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle()
	{
		vector<int> ans = m_nums;
		for (int i = 1; i < ans.size(); i++)
		{
			swap(ans[rand() % (i + 1)], ans[i]);
		}
		return ans;
	}

private:
	vector<int> m_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	Solution *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "Solution")
		{
			TestCases stc(sp[i]);
			vector<int> nums = stc.get<vector<int>>();
			obj = new Solution(nums);
			ans.push_back("null");
		}
		else if (sf[i] == "reset")
		{
			TestCases stc(sp[i]);
			vector<int> r = obj->reset();
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "shuffle")
		{
			TestCases stc(sp[i]);
			vector<int> r = obj->shuffle();
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
