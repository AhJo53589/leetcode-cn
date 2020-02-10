# `（中等）` [1344.angle-between-hands-of-a-clock 时钟指针的夹角](https://leetcode-cn.com/problems/angle-between-hands-of-a-clock/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-19/problems/angle-between-hands-of-a-clock/)

### 题目描述
<p>给你两个数&nbsp;<code>hour</code>&nbsp;和&nbsp;<code>minutes</code>&nbsp;。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/08/sample_1_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 12, minutes = 30
<strong>输出：</strong>165
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/08/sample_2_1673.png" style="height: 225px; width: 230px;"></p>

<pre><strong>输入：</strong>hour = 3, minutes = 30
<strong>输出；</strong>75
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/08/sample_3_1673.png" style="height: 231px; width: 230px;"></strong></p>

<pre><strong>输入：</strong>hour = 3, minutes = 15
<strong>输出：</strong>7.5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>hour = 4, minutes = 50
<strong>输出：</strong>155
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>hour = 12, minutes = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hour &lt;= 12</code></li>
	<li><code>0 &lt;= minutes &lt;= 59</code></li>
	<li>与标准答案误差在&nbsp;<code>10^-5</code>&nbsp;以内的结果都被视为正确结果。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
double angleClock(int hour, int minutes) 
{
    double c1 = 30 * hour + 0.5 * minutes;
    double c2 = 6 * minutes;
    double ans = abs(c1 - c2);
    return ans < 180.0 ? ans : 360 - ans;
}
```




