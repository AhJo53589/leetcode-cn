# `（困难）` [140.word-break-ii 单词拆分 II](https://leetcode-cn.com/problems/word-break-ii/)

### 题目描述
<p>给定一个<strong>非空</strong>字符串 <em>s</em> 和一个包含<strong>非空</strong>单词列表的字典 <em>wordDict</em>，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。</p>

<p><strong>说明：</strong></p>

<ul>
	<li>分隔时可以重复使用字典中的单词。</li>
	<li>你可以假设字典中没有重复的单词。</li>
</ul>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:
</strong>s = "<code>catsanddog</code>"
wordDict = <code>["cat", "cats", "and", "sand", "dog"]</code>
<strong>输出:
</strong><code>[
&nbsp; "cats and dog",
&nbsp; "cat sand dog"
]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:
</strong>s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
<strong>输出:
</strong>[
&nbsp; "pine apple pen apple",
&nbsp; "pineapple pen apple",
&nbsp; "pine applepen apple"
]
<strong>解释:</strong> 注意你可以重复使用字典中的单词。
</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre><strong>输入:
</strong>s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>输出:
</strong>[]
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/word-break-ii/solution/140-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		if (!wordBreak_valid(s, wordDict)) return {};

		size_t validEnd = 0;
		vector<vector<string>> dp(s.size() + 1, vector<string>());

		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return {};
			if (i != 0 && dp[i].empty()) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) != 0) continue;
				validEnd = max(validEnd, newEnd);
				if (i == 0)
				{
					dp[newEnd].push_back(word);
					continue;
				}
				for (auto& d : dp[i])
				{
					dp[newEnd].push_back(d + " " + word);
				}
			}
		}

		return dp.back();
	}

	bool wordBreak_valid(string& s, vector<string>& wordDict)
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




