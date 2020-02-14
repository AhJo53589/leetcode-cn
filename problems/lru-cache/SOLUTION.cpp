
//////////////////////////////////////////////////////////////////////////
//class LRUCache {
//public:
//	LRUCache(int capacity) {
//		cap = capacity;
//	}
//
//	int get(int key) {
//		auto it = m.find(key);
//
//		if (it == m.end())
//			return -1;
//
//		// 剪切 l 的 it->second 到 l.begin ，相当于erase + push_front
//		l.splice(l.begin(), l, it->second);
//
//		return it->second->second;
//	}
//
//	void put(int key, int value) {
//		auto it = m.find(key);
//
//		if (it != m.end())
//			l.erase(it->second);
//
//		l.push_front(make_pair(key, value));
//
//		m[key] = l.begin();
//
//		if (m.size() > cap) {
//			int k = l.rbegin()->first;
//			l.pop_back();
//			m.erase(k);
//		}
//	}
//
//private:
//	int cap;
//	list<pair<int, int>> l;
//	unordered_map<int, list<pair<int, int>>::iterator> m;
//};

//////////////////////////////////////////////////////////////////////////
class LRUCache {
private:
	int cap;
	list<pair<int, int>> cache;
	unordered_map<int, list<pair<int, int>>::iterator> map;
public:
	LRUCache(int capacity) {
		this->cap = capacity;
	}

	int get(int key) {
		auto it = map.find(key);
		if (it == map.end()) return -1;
		pair<int, int> kv = *map[key];
		cache.erase(map[key]);
		cache.push_front(kv);
		map[key] = cache.begin();
		return kv.second; // value
	}

	void put(int key, int value) {

		auto it = map.find(key);
		if (it == map.end()) {
			if (cache.size() == cap) {
				auto lastPair = cache.back();
				int lastKey = lastPair.first;
				map.erase(lastKey);
				cache.pop_back();
			}
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
		else {
			cache.erase(map[key]);
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
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

	LRUCache *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "LRUCache")
		{
			TestCases stc(sp[i]);
			int capacity = stc.get<int>();
			obj = new LRUCache(capacity);
			ans.push_back("null");
		}
		else if (sf[i] == "get")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			int r = obj->get(key);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "put")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			int value = stc.get<int>();
			obj->put(key, value);
			ans.push_back("null");
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

