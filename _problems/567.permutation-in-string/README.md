# `（中等）`  [567.permutation-in-string 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

### 题目描述
<p>给定两个字符串&nbsp;<strong>s1</strong>&nbsp;和&nbsp;<strong>s2</strong>，写一个函数来判断 <strong>s2</strong> 是否包含 <strong>s1&nbsp;</strong>的排列。</p>

<p>换句话说，第一个字符串的排列之一是第二个字符串的子串。</p>

<p><strong>示例1:</strong></p>

<pre><strong>输入: </strong>s1 = "ab" s2 = "eidbaooo"
<strong>输出: </strong>True
<strong>解释:</strong> s2 包含 s1 的排列之一 ("ba").
</pre>

<p>&nbsp;</p>

<p><strong>示例2:</strong></p>

<pre><strong>输入: </strong>s1= "ab" s2 = "eidboaoo"
<strong>输出:</strong> False
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ol>
	<li>输入的字符串只包含小写字母</li>
	<li>两个字符串的长度都在 [1, 10,000] 之间</li>
</ol>


---
### 思路
```
```

### 答题
``` C++
bool checkInclusion(string s1, string s2)
{
	int cc_s1[26] = { 0 };
	for (auto &c : s1)
	{
		cc_s1[c - 'a']++;
	}

	int cc_s2[26] = { 0 };
	size_t left = 0;
	for (size_t i = 0; i < s2.size(); i++)
	{
		int t = s2[i] - 'a';
		cc_s2[t]++;
		if (cc_s2[t] == cc_s1[t])
		{
			bool bFlag = true;
			for (size_t j = 0; j < 26; j++)
			{
				if (cc_s2[j] != cc_s1[j])
				{
					bFlag = false;
					break;
				}
			}
			if (bFlag) return true;
		}
		else if (cc_s2[t] > cc_s1[t])
		{
			for (size_t j = left; j <= i; j++)
			{
				int t2 = s2[j] - 'a';
				cc_s2[t2]--;
				left++;
				if (s2[j] == s2[i]) break;
			}
		}
	}
	return false;
}
```

