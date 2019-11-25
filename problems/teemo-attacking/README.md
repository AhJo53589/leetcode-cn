# `（中等）` [495.teemo-attacking 提莫攻击](https://leetcode-cn.com/problems/teemo-attacking/)

### 题目描述
<p>在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄，他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。</p>

<p>你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。</p>

<p><strong>示例1:</strong></p>

<pre><strong>输入:</strong> [1,4], 2
<strong>输出:</strong> 4
<strong>原因:</strong> 在第 1 秒开始时，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持 2 秒钟，直到第 2 秒钟结束。
在第 4 秒开始时，提莫再次攻击艾希，使得艾希获得另外 2 秒的中毒时间。
所以最终输出 4 秒。
</pre>

<p><strong>示例2:</strong></p>

<pre><strong>输入:</strong> [1,2], 2
<strong>输出:</strong> 3
<strong>原因:</strong> 在第 1 秒开始时，提莫开始对艾希进行攻击并使其立即中毒。中毒状态会维持 2 秒钟，直到第 2 秒钟结束。
但是在第 2 秒开始时，提莫再次攻击了已经处于中毒状态的艾希。
由于中毒状态不可叠加，提莫在第 2 秒开始时的这次攻击会在第 3 秒钟结束。
所以最终输出 3。
</pre>

<p><strong>注意：</strong></p>

<ol>
	<li>你可以假定时间序列数组的总长度不超过 10000。</li>
	<li>你可以假定提莫攻击时间序列中的数字和提莫攻击的中毒持续时间都是非负整数，并且不超过 10,000,000。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
int findPoisonedDuration(vector<int>& timeSeries, int duration) 
{
	if (timeSeries.empty()) return 0;

	int ans = 0;
	for (size_t i = 1; i < timeSeries.size(); i++)
	{
		ans += min(timeSeries[i] - timeSeries[i - 1], duration);
	}
	return ans += duration;
}
```




