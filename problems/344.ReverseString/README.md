# `（简单）`  [344.ReverseString 反转字符串](https://leetcode-cn.com/problems/reverse-string/)

### 题目描述
<p>编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 <code>char[]</code> 的形式给出。</p>

<p>不要给另外的数组分配额外的空间，你必须<strong><a href="https://baike.baidu.com/item/原地算法">原地</a>修改输入数组</strong>、使用 O(1) 的额外空间解决这一问题。</p>

<p>你可以假设数组中的所有字符都是 <a href="https://baike.baidu.com/item/ASCII">ASCII</a> 码表中的可打印字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>["h","e","l","l","o"]
<strong>输出：</strong>["o","l","l","e","h"]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>["H","a","n","n","a","h"]
<strong>输出：</strong>["h","a","n","n","a","H"]</pre>





---
### 思路
```

```


### 答题
``` C++
void reverseString(vector<char>& s)
 {
	int iLen = s.size();
	for (int i = 0; i < iLen/2; i++)
	{
		swap(s[i], s[iLen-i-1]);
	}
}
``` 

### 其它
这道题真的简单，我用手机写的。  
手机写代码感觉很神奇。