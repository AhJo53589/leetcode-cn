


//////////////////////////////////////////////////////////////////////////
class MyHashSet {
	vector<bool> set;
public:
	/** Initialize your data structure here. */
	//map<int,int> set;
	MyHashSet() {
		set = vector<bool>(1000001, false);
	}

	void add(int key) {
		set[key] = true;
	}

	void remove(int key) {
		set[key] = false;
	}

	/** Returns true if this set did not already contain the specified element */
	bool contains(int key) {
		return set[key];
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

//////////////////////////////////////////////////////////////////////////
//void _solution_run(int x)
//{
//	return push(x);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<vector<int>> param = tc.get<vector<vector<int>>>();

	string ans = "[";
	MyHashSet *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyHashSet")
		{
			obj = new MyHashSet();
			ans += "null";
		}
		else if (sf[i] == "add")
		{
			obj->add(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "remove")
		{
			obj->remove(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "contains")
		{
			bool r = obj->contains(param[i][0]);
			ans += r ? "true" : "false";
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
	return "../../problems/design-hashset/tests.txt";
}

