# `（中等）`  [5.longest-palindromic-substring 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

### 题目描述
<p>给定一个字符串 <code>s</code>，找到 <code>s</code> 中最长的回文子串。你可以假设&nbsp;<code>s</code> 的最大长度为 1000。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> "babad"
<strong>输出:</strong> "bab"
<strong>注意:</strong> "aba" 也是一个有效答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> "cbbd"
<strong>输出:</strong> "bb"
</pre>


---
### 思路
```
循环用来确定是否是回文字符串的中心位置。
使用findPalindrome来确定能扩张到哪里。
```

### 答题
``` C++
void findPalindrome(string s, int &low, int &high)
{
	while (s[low] == s[high])
	{
		low--;
		high++;
		if (low < 0 || high > s.size() - 1) break;
	}
	low++;
	high--;
}

string longestPalindrome(string s)
{
	if (s.size() == 1) return s;

	string ans;
	ans.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			int low = i - 1;
			int high = i;
			findPalindrome(s, low, high);
			if (high - low + 1 > ans.size())
			{
				ans = s.substr(low, high - low + 1);
			}
		}
		if ((i + 1 < s.size()) && s[i - 1] == s[i + 1])
		{
			int low = i - 1;
			int high = i + 1;
			findPalindrome(s, low, high);
			if (high - low + 1 > ans.size())
			{
				ans = s.substr(low, high - low + 1);
			}
		}
	}
	return ans;
}
```
