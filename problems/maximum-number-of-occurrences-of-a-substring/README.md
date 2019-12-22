# `（中等）` [5293.maximum-number-of-occurrences-of-a-substring 子串的最大出现次数](https://leetcode-cn.com/problems/maximum-number-of-occurrences-of-a-substring/)

[contest](https://leetcode-cn.com/contest/weekly-contest-168/problems/maximum-number-of-occurrences-of-a-substring/)

### 题目描述
<p>给你一个字符串&nbsp;<code>s</code> ，请你返回满足以下条件且出现次数最大的&nbsp;<strong>任意</strong>&nbsp;子串的出现次数：</p>

<ul>
	<li>子串中不同字母的数目必须小于等于 <code>maxLetters</code> 。</li>
	<li>子串的长度必须大于等于&nbsp;<code>minSize</code> 且小于等于&nbsp;<code>maxSize</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
<strong>输出：</strong>2
<strong>解释：</strong>子串 "aab" 在原字符串中出现了 2 次。
它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
<strong>输出：</strong>2
<strong>解释：</strong>子串 "aaa" 在原字符串中出现了 2 次，且它们有重叠部分。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= maxLetters &lt;= 26</code></li>
	<li><code>1 &lt;= minSize &lt;= maxSize &lt;= min(26, s.length)</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
{
	int ans = 0;
	unordered_map<string, int> cnts;
	vector<int> chars(26, 0);
	vector<int> tmpChars(26, 0);
	int curLetters = 0;
	string curStr = "";

	for (size_t i = 0; i < minSize - 1; i++)
	{
		curStr += s[i];
		curLetters += (chars[s[i] - 'a']++ == 0);
	}
	//cout << "curStr: " << curStr << endl;

	for (size_t i = minSize - 1; i < s.size(); i++)
	{
		tmpChars = chars;
		int tmpLetters = curLetters;
		string tmpStr = curStr;
		for (size_t j = 0; j < maxSize - minSize + 1; j++)
		{
			int k = i + j;
			if (k >= s.size()) break;
			tmpStr += s[k];
			tmpLetters += (tmpChars[s[k] - 'a']++ == 0);

			if (tmpLetters > maxLetters) break;
			cnts[tmpStr]++;
			//cout << tmpStr << ":\t" << cnts[tmpStr] << endl;
			ans = max(ans, cnts[tmpStr]);
		}

		if (curStr.size() == 0) continue;
		curLetters -= (--chars[curStr[0] - 'a'] == 0);
		curStr.erase(curStr.begin());

		curStr += s[i];
		curLetters += (chars[s[i] - 'a']++ == 0);
	}
	return ans;
}
```




