


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
//Solution(vector<int>& _solution_run(vector<int>& nums)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<vector<int>> param = tc.get<vector<vector<int>>>();

	string ans = "[";
	Solution *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "Solution")
		{
			obj = new Solution(param[i]);
			ans += "null";
		}
		else if (sf[i] == "reset")
		{
			vector<int> r = obj->reset();
			ans += VectorIntToString(r);
		}
		else if (sf[i] == "shuffle")
		{
			vector<int> r = obj->shuffle();
			ans += VectorIntToString(r);
		}
		ans += ",";
	}
	ans.pop_back();
	ans += "]";
	return ans;
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/shuffle-an-array/tests.txt";
}

