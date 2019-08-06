# `（中等）`  [146.lru-cache LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)

### 题目描述
<p>运用你所掌握的数据结构，设计和实现一个&nbsp; <a href="https://baike.baidu.com/item/LRU">LRU (最近最少使用) 缓存机制</a>。它应该支持以下操作： 获取数据 <code>get</code> 和 写入数据 <code>put</code> 。</p>

<p>获取数据 <code>get(key)</code> - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。<br>
写入数据 <code>put(key, value)</code> - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。</p>

<p><strong>进阶:</strong></p>

<p>你是否可以在&nbsp;<strong>O(1)</strong> 时间复杂度内完成这两种操作？</p>

<p><strong>示例:</strong></p>

<pre>LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
</pre>


---
### 思路
```
```

### 答题
``` C++
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
```

### 其它
``` C++
class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);

		if (it == m.end())
			return -1;

		// 剪切 l 的 it->second 到 l.begin ，相当于erase + push_front
		l.splice(l.begin(), l, it->second);

		return it->second->second;
	}

	void put(int key, int value) {
		auto it = m.find(key);

		if (it != m.end())
			l.erase(it->second);

		l.push_front(make_pair(key, value));

		m[key] = l.begin();

		if (m.size() > cap) {
			int k = l.rbegin()->first;
			l.pop_back();
			m.erase(k);
		}
	}

private:
	int cap;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
};
```

