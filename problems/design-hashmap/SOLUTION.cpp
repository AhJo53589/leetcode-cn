


//////////////////////////////////////////////////////////////////////////
struct Node {
	int nkey;
	int nval;
	Node* next;
	Node(int key, int val) : nkey(key), nval(val), next(nullptr) {}
};

int len = 1000;
class MyHashMap {
public:
	vector <Node*> arr;
	/** Initialize your data structure here. */
	MyHashMap() {
		arr = vector<Node*>(len, new Node(-1, -1));
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int temp = key % len;
		Node* h = arr[temp];
		Node* prev = nullptr;
		while (h) {
			if (h->nkey == key) {
				h->nval = value;
				return;
			}
			prev = h;
			h = h->next;
		}
		Node* node = new Node(key, value);
		prev->next = node;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int temp = key % len;
		Node* h = arr[temp];
		while (h) {
			if (h->nkey == key)    return h->nval;
			h = h->next;
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int temp = key % len;
		Node* h = arr[temp];
		while (h) {
			if (h->nkey == key) {
				h->nval = -1;
			}
			h = h->next;
		}
	}
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	MyHashMap *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyHashMap")
		{
			obj = new MyHashMap();
			ans.push_back("null");
		}
		else if (sf[i] == "put")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			int value = stc.get<int>();
			obj->put(key, value);
			ans.push_back("null");
		}
		else if (sf[i] == "get")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			int r = obj->get(key);
			ans.push_back(convert<string>(r));
		}
		else if (sf[i] == "remove")
		{
			TestCases stc(sp[i]);
			int key = stc.get<int>();
			obj->remove(key);
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
