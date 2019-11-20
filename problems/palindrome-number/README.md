# `（简单）` [9.palindrome-number 回文数](https://leetcode-cn.com/problems/palindrome-number/)

### 题目描述
<p>判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 121
<strong>输出:</strong> true
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> -121
<strong>输出:</strong> false
<strong>解释:</strong> 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> false
<strong>解释:</strong> 从右向左读, 为 01 。因此它不是一个回文数。
</pre>

<p><strong>进阶:</strong></p>

<p>你能不将整数转为字符串来解决这个问题吗？</p>

---
### 思路
```
使用了双端队列。
```

### 答题
``` C++
bool isPalindrome(int x) 
{
	if (x < 0) return false;
	if (x < 10) return true;

	deque<int> d;
	while (x >= 1)
	{
		d.push_back(x % 10);
		x /= 10;
	}
	while (d.size() > 1)
	{
		int h = d.front();
		d.pop_front();
		int t = d.back();
		d.pop_back();
		if (h != t) return false;
	}
	return true;
}
```

### 其它
使用数字实现堆栈效果。
``` C++
bool isPalindrome(int x) {
	if (x < 0 || ((x % 10 == 0) && x != 0)) {
		return false;
	}
	int reverse = 0;
	while (x > reverse) {
		reverse = reverse * 10 + x % 10;
		x /= 10;
	}
	return x == reverse || x == reverse / 10;
}
```

