# `（简单）` [374.guess-number-higher-or-lower 猜数字大小](https://leetcode-cn.com/problems/guess-number-higher-or-lower/)

### 题目描述
<p>我们正在玩一个猜数字游戏。 游戏规则如下：<br>
我从&nbsp;<strong>1</strong>&nbsp;到&nbsp;<em><strong>n</strong></em>&nbsp;选择一个数字。 你需要猜我选择了哪个数字。<br>
每次你猜错了，我会告诉你这个数字是大了还是小了。<br>
你调用一个预先定义好的接口&nbsp;<code>guess(int num)</code>，它会返回 3 个可能的结果（<code>-1</code>，<code>1</code>&nbsp;或 <code>0</code>）：</p>

<pre>-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！
</pre>

<p><strong>示例 :</strong></p>

<pre><strong>输入: </strong>n = 10, pick = 6
<strong>输出: </strong>6</pre>


---
### 思路
```
这道题中
-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！

-1是被猜的数字比较小，即我猜的数字大了。  

被坑了好久
```

### 答题
``` C++
int guessNumber(int n) 
{
	int low = 0;
	int high = n;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		int guessResult = guess(mid);
		if (guessResult == 0) return mid;
		else if (guessResult == 1) low = mid + 1;
		else high = mid;
	}
	return low;
}
```
