# `（中等）` [677.map-sum-pairs 键值映射](https://leetcode-cn.com/problems/map-sum-pairs/)

### 题目描述
<p>实现一个 MapSum 类里的两个方法，<code>insert</code>&nbsp;和&nbsp;<code>sum</code>。</p>

<p>对于方法&nbsp;<code>insert</code>，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。</p>

<p>对于方法 <code>sum</code>，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。</p>

<p><strong>示例 1:</strong></p>

<pre>输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5
</pre>


---
### 思路
```
```



### 答题
``` C++
class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() : ans(0) {	}

	~MapSum()
	{
		for (auto n : next)
		{
			delete n.second;
		}
	}

	void insert(string key, int val)
	{
		MapSum* p = this;
		for (auto c : key)
		{
			if (p->next.count(c) == 0)
			{
				p->next[c] = new MapSum();
			}
			p = p->next[c];
		}
		p->ans = val;
	}

	int sum(string prefix)
	{
		MapSum* p = this;
		for (auto c : prefix)
		{
			if (p->next.count(c) == 0) return 0;
			p = p->next[c];
		}
		return calc(p);
	}

private:
	int calc(MapSum* p)
	{
		if (p == nullptr) return 0;
		int ans = p->ans;
		for (auto& n : p->next)
		{
			ans += calc(n.second);
		}
		return ans;
	}

	int ans;
	map<char, MapSum*> next;
};
```




