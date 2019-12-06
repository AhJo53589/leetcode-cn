# `（困难）`  [432.all-oone-data-structure 全 O(1) 的数据结构](https://leetcode-cn.com/problems/all-oone-data-structure/)

### 题目描述
<p>实现一个数据结构支持以下操作：</p>

<ol>
	<li>Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。</li>
	<li>Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否者使一个存在的 key 值减一。如果这个 key 不存在，这个函数不做任何事情。key 保证不为空字符串。</li>
	<li>GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串<code>""</code>。</li>
	<li>GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串<code>""</code>。</li>
</ol>

<p>挑战：以 O(1) 的时间复杂度实现所有操作。</p>


---
### 思路
```
我用的上下左右链表来存数据。
用两个map来对应key和val。
相当麻烦，讲道理应该是O(1)了吧。
```

### 答题
``` C++
class AllOne {
public:
	/** Initialize your data structure here. */
	AllOne() {
		addValMapHead(0, true);
		min_node = val_map[0];
		max_node = val_map[0];
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		cout << "inc " << key << endl;
		if (!key_map.count(key))
		{
			Node *n = new Node(key);
			key_map[key] = n;
			insertValMapNode(n, true);
		}
		else
		{
			Node *n = key_map[key];
			deleteValMapNode(n);
			(n->val)++;
			insertValMapNode(n, true);
			updateValMap(val_map[n->val - 1]);
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		cout << "dec " << key << endl;
		if (!key_map.count(key)) return;
		Node *n = key_map[key];
		if (n->val == 1)
		{
			key_map.erase(key);
			deleteValMapNode(n);
			updateValMap(val_map[n->val]);
			delete n;
		}
		else
		{
			deleteValMapNode(n);
			(n->val)--;
			insertValMapNode(n, false);
			updateValMap(val_map[n->val + 1]);
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (max_node == nullptr) return {};
		if (max_node->next == nullptr) return {};
		cout << "max_node->val " << max_node->val << endl;
		return max_node->next->str;
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (min_node == nullptr) return {};
		if (min_node->next == nullptr) return {};
		cout << "min_node->val " << min_node->val << endl;
		return min_node->next->str;
	}

private:
	struct Node
	{
		string str;
		int val;
		Node *pre;
		Node *next;
		Node *up;
		Node *down;
		Node(string k) : str(k), val(1), pre(nullptr), next(nullptr), up(nullptr), down(nullptr) { }
	};

private:
	void addValMapHead(int val, bool incFlag)
	{
		Node *pNew = new Node("");
		Node *pDown = nullptr;
		Node *pUp = nullptr;
		if (incFlag)
		{
			pDown = val_map[val - 1];
			pUp = (pDown == nullptr) ? nullptr : pDown->up;
		}
		else
		{
			pUp = val_map[val + 1];
			pDown = (pUp == nullptr) ? nullptr : pUp->down;
		}
		pNew->val = val;
		pNew->down = pDown;
		pNew->up = pUp;
		if (pDown != nullptr) pDown->up = pNew;
		if (pUp != nullptr) pUp->down = pNew;

		val_map[val] = pNew;

		if (val == 0) return;
		if (pUp == nullptr) max_node = pNew;
		if (pDown == val_map[0]) min_node = pNew;
	}

	void deleteValMapHead(int val)
	{
		if (!val_map.count(val)) return;

		Node *n = val_map[val];
		if (n->down != nullptr) n->down->up = n->up;
		if (n->up != nullptr) n->up->down = n->down;
		val_map.erase(n->val);

		if (max_node == n) max_node = (n->up != nullptr) ? n->up : n->down;
		if (min_node == n) min_node = (n->down != val_map[0]) ? n->down : n->up;

		delete n;
	}

	void insertValMapNode(Node *n, bool incFlag)
	{
		if (!val_map.count(n->val))
		{
			addValMapHead(n->val, incFlag);
		}

		Node *pValHead = val_map[n->val];
		n->pre = pValHead;
		n->next = pValHead->next;
		if (n->next != nullptr) n->next->pre = n;
		pValHead->next = n;
	}

	void deleteValMapNode(Node *n)
	{
		if (n == nullptr) return;

		n->pre->next = n->next;
		if (n->next != nullptr) n->next->pre = n->pre;
	}

	void updateValMap(Node *n)
	{
		if (n->next != nullptr) return;
		deleteValMapHead(n->val);
	}

private:
	unordered_map<string, Node *> key_map;
	unordered_map<int, Node *> val_map;
	Node *max_node;
	Node *min_node;
};
```

### 其它
看到别人这简洁的代码，眼泪掉下来。
``` C++
class AllOne {
private:
	vector<pair<string, int>> vec;
	unordered_map<string, int> mp;
public:
	/** Initialize your data structure here. */
	AllOne() {

	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		if (mp.count(key)) {
			int p = mp[key];
			vec[p].second++;
			while (p > 0 && vec[p].second > vec[p - 1].second) {
				mp[vec[p - 1].first] = p;
				swap(vec[p], vec[p - 1]);
				p--;
			}
			mp[vec[p].first] = p;
		}
		else {
			mp[key] = vec.size();
			vec.push_back(make_pair(key, 1));
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (!mp.count(key)) return;
		int p = mp[key];
		vec[p].second--;
		while (p < vec.size() - 2 && vec[p].second < vec[p + 1].second) {
			mp[vec[p + 1].first] = p;
			swap(vec[p], vec[p + 1]);
			p++;
		}
		if (vec[p].second == 0)
		{
			mp.erase(key);
			vec.erase(vec.begin() + p);
		}
		else {
			mp[key] = p;
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (vec.empty())return "";
		return vec.front().first;
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (vec.empty()) return"";
		return vec.back().first;
	}
};
```

