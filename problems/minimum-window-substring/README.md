# `（困难）` [76.minimum-window-substring 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)

### 题目描述
<p>给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入: S</strong> = "ADOBECODEBANC", <strong>T</strong> = "ABC"
<strong>输出:</strong> "BANC"</pre>

<p><strong>说明：</strong></p>

<ul>
	<li>如果 S 中不存这样的子串，则返回空字符串 <code>""</code>。</li>
	<li>如果 S 中存在这样的子串，我们保证它是唯一的答案。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-window-substring/solution/76-by-ikaruga/)

### 答题
``` C++
string minWindow(string s, string t) 
{
	if (s.size() < t.size()) return "";
	if (t.size() == 1 && s.find(t[0]) != string::npos) return t;

	deque<size_t> _window;
	unordered_map<char, int> _map;
	string ans;
	size_t ans_len = UINT_MAX;
	bool bMapFlag = false;

	for (auto c : t)
	{
		_map[c]--;
	}

	auto f_check_map = [&_map, &bMapFlag]()
	{
		if (bMapFlag) return true;
		for (auto m : _map)
		{
			if (m.second < 0) return false;
		}
		bMapFlag = true;
		return true;
	};

	for (size_t i = 0; i < s.size(); i++)
	{
		if (_map.count(s[i]) == 0) continue;
		_window.push_back(i);
		_map[s[i]]++;
		while (_map[s[_window.front()]] > 0)
		{
			auto j = _window.front();
			_window.pop_front();
			_map[s[j]]--;
		}
		if (f_check_map())
		{
			auto k = (_window.size() > 1) ? _window.back() - _window.front() + 1 : UINT_MAX;
			if (k < ans_len)
			{
				ans = s.substr(_window.front(), k);
				ans_len = k;
			}
		}
	}
	return ans;
}
```

