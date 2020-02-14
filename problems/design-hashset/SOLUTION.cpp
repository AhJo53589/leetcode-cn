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

	MyHashSet *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyHashSet")
		{
			obj = new MyHashSet();
			ans.push_back("null");
		}
		else if (sf[i] == "add")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			obj->add(key);
			ans.push_back("null");
		}
		else if (sf[i] == "remove")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			obj->remove(key);
			ans.push_back("null");
		}
		else if (sf[i] == "contains")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			bool r = obj->contains(key);
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

