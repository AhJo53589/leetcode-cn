# `（中等）`  [3.longest-substring-without-repeating-characters 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

### 题目描述
<p>给定一个字符串，请你找出其中不含有重复字符的&nbsp;<strong>最长子串&nbsp;</strong>的长度。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入: </strong>"abcabcbb"
<strong>输出: </strong>3 
<strong>解释:</strong> 因为无重复字符的最长子串是 <code>"abc"，所以其</code>长度为 3。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>"bbbbb"
<strong>输出: </strong>1
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"b"</code>，所以其长度为 1。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入: </strong>"pwwkew"
<strong>输出: </strong>3
<strong>解释: </strong>因为无重复字符的最长子串是&nbsp;<code>"wke"</code>，所以其长度为 3。
&nbsp;    请注意，你的答案必须是 <strong>子串 </strong>的长度，<code>"pwke"</code>&nbsp;是一个<em>子序列，</em>不是子串。
</pre>


---
### 思路
```
脑子秀逗了非要两次循环用set。
可以用map一次循环搞定的。
```

### 答题
``` C++
int lengthOfLongestSubstring(string s)
{
	int len = 0;
	unordered_set<char> set;
	for (int i = 0; i < s.size(); i++)
	{
		int len_temp = 0;
		set.clear();
		for (int j = i; j < s.size(); j++)
		{
			if (!set.count(s[j]))
			{
				set.insert(s[j]);
				len_temp++;
				continue;
			}
			break;
		}
		len = max(len, len_temp);
	}
	return len;
}
```

### 其它
``` C++
int lengthOfLongestSubstring(string s) {
	int map[256]={0};
	int len=0;
	int index=0;
	for(int i=0;i<s.length();i++){
		if(map[s[i]]==0||map[s[i]]<index){
			len=len>(i-index+1)?len:(i-index+1);
		}
		else{
			index=map[s[i]];
		}
		map[s[i]]=i+1;
	}
	return len;
}
```

