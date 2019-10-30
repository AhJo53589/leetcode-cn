# `（简单）` [345.reverse-vowels-of-a-string 反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)

### 题目描述
<p>编写一个函数，以字符串作为输入，反转该字符串中的元音字母。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>"hello"
<strong>输出: </strong>"holle"
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>"leetcode"
<strong>输出: </strong>"leotcede"</pre>

<p><strong>说明:</strong><br>
元音字母不包含字母"y"。</p>


---
### 思路
```
使用对撞指针，从两边向中间检查。  
交换两边的元音，实现逆序。  
```

### 答题
``` C++
string reverseVowels(string s)
{
	int low = 0;
	int high = s.size() - 1;
	while (low < high)
	{
		auto isVowel = [](char c) { unordered_set<char> list = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' }; return list.count(c); };
		while (low < high && !isVowel(s[low])) low++;
		while (low < high && !isVowel(s[high])) high--;
		swap(s[low++], s[high--]);
	}
	return s;
}
```

