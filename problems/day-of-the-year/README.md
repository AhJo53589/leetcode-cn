# `（简单）` [1154.day-of-the-year 一年中的第几天](https://leetcode-cn.com/problems/day-of-the-year/)

### 题目描述
<p>给你一个字符串&nbsp;<code>date</code> ，按 <code>YYYY-MM-DD</code> 格式表示一个 <a href="https://baike.baidu.com/item/公元/17855">现行公元纪年法</a> 日期。请你计算并返回该日期是当年的第几天。</p>

<p>通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>date = "2019-01-09"
<strong>输出：</strong>9
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>date = "2019-02-10"
<strong>输出：</strong>41
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>date = "2003-03-01"
<strong>输出：</strong>60
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>date = "2004-03-01"
<strong>输出：</strong>61</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == '-'</code>，其他的&nbsp;<code>date[i]</code>&nbsp;都是数字</li>
	<li><code>date</code> 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int dayOfYear(string date) {
        tm t;
        strptime(date.c_str(), "%Y-%m-%d", &t);
        return t.tm_yday + 1;
    }
};
```




