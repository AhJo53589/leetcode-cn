# `（简单）`  [771.jewels-and-stones 宝石与石头](https://leetcode-cn.com/problems/jewels-and-stones/)

### 题目描述
<p>&nbsp;给定字符串<code>J</code>&nbsp;代表石头中宝石的类型，和字符串&nbsp;<code>S</code>代表你拥有的石头。&nbsp;<code>S</code>&nbsp;中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。</p>

<p><code>J</code>&nbsp;中的字母不重复，<code>J</code>&nbsp;和&nbsp;<code>S</code>中的所有字符都是字母。字母区分大小写，因此<code>"a"</code>和<code>"A"</code>是不同类型的石头。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> J = "aA", S = "aAAbbbb"
<strong>输出:</strong> 3
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> J = "z", S = "ZZ"
<strong>输出:</strong> 0
</pre>

<p><strong>注意:</strong></p>

<ul>
	<li><code>S</code>&nbsp;和&nbsp;<code>J</code>&nbsp;最多含有50个字母。</li>
	<li>&nbsp;<code>J</code>&nbsp;中的字符不重复。</li>
</ul>


---
### 思路
```
```

### 答题
``` C++
int numJewelsInStones(string J, string S) 
{
	unordered_set<char> s;
	for (auto c : J) s.insert(c);
	int i = 0;
	for (auto c : S) if (s.count(c)) i++;
	return i;
}
```

