


//////////////////////////////////////////////////////////////////////////
class RandomizedSet 
{
public:
	/** Initialize your data structure here. */
	RandomizedSet()
	{
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) 
	{
		if (m.count(val)) return false;
		nums.push_back(val);
		m[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) 
	{
		if (!m.count(val)) return false;
		int last = nums.back();
		m[last] = m[val];
		nums[m[val]] = last;
		nums.pop_back();
		m.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() 
	{
		return nums[rand() % nums.size()];
	}
private:
	vector<int> nums;
	unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
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

	RandomizedSet *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "RandomizedSet")
		{
			obj = new RandomizedSet();
			ans.push_back("null");
		}
		else if (sf[i] == "insert")
		{
			TestCases stc(sp[i]);
			int val = stc.get<int>();
			bool r = obj->insert(val);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "remove")
		{
			TestCases stc(sp[i]);
			int val = stc.get<int>();
			bool r = obj->remove(val);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "getRandom")
		{
			TestCases stc(sp[i]);
			int r = obj->getRandom();
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

