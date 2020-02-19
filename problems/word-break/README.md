# `（中等）` [139.word-break 单词拆分](https://leetcode-cn.com/problems/word-break/)

### 题目描述
<p>给定一个<strong>非空</strong>字符串 <em>s</em> 和一个包含<strong>非空</strong>单词列表的字典 <em>wordDict</em>，判定&nbsp;<em>s</em> 是否可以被空格拆分为一个或多个在字典中出现的单词。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>拆分时可以重复使用字典中的单词。</li>
	<li>你可以假设字典中没有重复的单词。</li>
</ul>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> s = "leetcode", wordDict = ["leet", "code"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> s = "applepenapple", wordDict = ["apple", "pen"]
<strong>输出:</strong> true
<strong>解释:</strong> 返回 true 因为 <code>"</code>applepenapple<code>"</code> 可以被拆分成 <code>"</code>apple pen apple<code>"</code>。
&nbsp;    注意你可以重复使用字典中的单词。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>输出:</strong> false
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/word-break/solution/139-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
	{
		size_t validEnd = 0;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return false;
			if (!dp[i]) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) == 0)
				{
					dp[newEnd] = true;
					validEnd = max(validEnd, newEnd);
				}
			}
		}
		return dp.back();
    }
};
```




