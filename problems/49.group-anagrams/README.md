# `（中等）`  [49.group-anagrams 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)

### 题目描述
<p>给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>["eat", "tea", "tan", "ate", "nat", "bat"]</code>,
<strong>输出:</strong>
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]</pre>

<p><strong>说明：</strong></p>

<ul>
	<li>所有输入均为小写字母。</li>
	<li>不考虑答案输出的顺序。</li>
</ul>


---
### 思路
```
```

### 答题
``` C++
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	unordered_map<string, vector<string>> hashmap;
	for (auto s : strs) {
		string temp = s;
		sort(temp.begin(), temp.end());
		hashmap[temp].push_back(s);
	}
	int len = hashmap.size();
	vector<vector<string>> ans(len);
	int index = 0;
	for (auto i : hashmap) {
		ans[index] = i.second;
		++index;
	}
	return ans;
}
```
