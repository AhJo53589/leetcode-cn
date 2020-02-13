//////////////////////////////////////////////////////////////////////////
class MyHashSet {
	unsigned int hashMap[1000000 / 32 + 1];

public:
	/** Initialize your data structure here. */
	//map<int,int> set;
	MyHashSet() {
		memset(hashMap, 0, sizeof(hashMap));
	}

	void add(int key) {
		//cout << "��add��" << endl;
		//bitset<32> a = key;
		//cout << "[key] = " << a << endl;
		//cout << "[key] = " << key << ", " << "[key & 0x1F] = " << (key & 0x1F) << endl;
		//cout << "[key / 32] = " << (key / 32) << ", " << "[key % 32] = " << (key % 32) << endl;
		//cout << "hashMap[key / 32] |= ((unsigned int)1 << (key & 0x1F));" << endl << endl;
		hashMap[key / 32] |= ((unsigned int)1 << (key & 0x1F));
	}

	void remove(int key) {
		if ((hashMap[key / 32]) & ((unsigned int)1 << (key & 0x1F))) {
			hashMap[key / 32] &= ~((unsigned int)1 << (key & 0x1F));
		}

	}

	/** Returns true if this set did not already contain the specified element */
	bool contains(int key) {
		return hashMap[key / 32] & ((unsigned int)1 << (key & 0x1F));
	}
};


//////////////////////////////////////////////////////////////////////////
//class MyHashSet {
//	vector<bool> set;
//
//public:
//	/** Initialize your data structure here. */
//	//map<int,int> set;
//	MyHashSet() {
//		set = vector<bool>(1000001, false);
//	}
//
//	void add(int key) {
//		set[key] = true;
//	}
//
//	void remove(int key) {
//		set[key] = false;
//	}
//
//	/** Returns true if this set did not already contain the specified element */
//	bool contains(int key) {
//		return set[key];
//	}
//};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

////////////////////////////////////////////////////////////////////////
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
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

