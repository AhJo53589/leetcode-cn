# `（困难）` [5775.minimum-skips-to-arrive-at-meeting-on-time 准时抵达会议现场的最小跳过休息次数](https://leetcode-cn.com/problems/minimum-skips-to-arrive-at-meeting-on-time/)

[contest](https://leetcode-cn.com/contest/weekly-contest-243/problems/minimum-skips-to-arrive-at-meeting-on-time/)

### 题目描述
<div class="notranslate"><p>给你一个整数 <code>hoursBefore</code> ，表示你要前往会议所剩下的可用小时数。要想成功抵达会议现场，你必须途经 <code>n</code> 条道路。道路的长度用一个长度为 <code>n</code> 的整数数组 <code>dist</code> 表示，其中 <code>dist[i]</code> 表示第 <code>i</code> 条道路的长度（单位：<strong>千米</strong>）。另给你一个整数 <code>speed</code> ，表示你在道路上前进的速度（单位：<strong>千米每小时</strong>）。</p>

<p>当你通过第 <code>i</code> 条路之后，就必须休息并等待，直到 <strong>下一个整数小时</strong> 才能开始继续通过下一条道路。注意：你不需要在通过最后一条道路后休息，因为那时你已经抵达会议现场。</p>

<ul>
	<li>例如，如果你通过一条道路用去 <code>1.4</code> 小时，那你必须停下来等待，到&nbsp;<code>2</code> 小时才可以继续通过下一条道路。如果通过一条道路恰好用去 <code>2</code> 小时，就无需等待，可以直接继续。</li>
</ul>

<p>然而，为了能准时到达，你可以选择 <strong>跳过</strong> 一些路的休息时间，这意味着你不必等待下一个整数小时。注意，这意味着与不跳过任何休息时间相比，你可能在不同时刻到达接下来的道路。</p>

<ul>
	<li>例如，假设通过第 <code>1</code> 条道路用去 <code>1.4</code> 小时，且通过第 <code>2</code> 条道路用去 <code>0.6</code> 小时。跳过第 <code>1</code> 条道路的休息时间意味着你将会在恰好&nbsp;<code>2</code> 小时完成通过第 <code>2</code> 条道路，且你能够立即开始通过第 <code>3</code> 条道路。</li>
</ul>

<p>返回准时抵达会议现场所需要的 <strong>最小跳过次数</strong> ，如果 <strong>无法准时参会</strong> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>dist = [1,3,2], speed = 4, hoursBefore = 2
<strong>输出：</strong>1
<strong>解释：</strong>
不跳过任何休息时间，你将用 (1/4 + 3/4) + (3/4 + 1/4) + (2/4) = 2.5 小时才能抵达会议现场。
可以跳过第 1 次休息时间，共用 ((1/4 + <strong>0</strong>) + (3/4 + 0)) + (2/4) = 1.5 小时抵达会议现场。
注意，第 2 次休息时间缩短为 0 ，由于跳过第 1 次休息时间，你是在整数小时处完成通过第 2 条道路。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>dist = [7,3,5,5], speed = 2, hoursBefore = 10
<strong>输出：</strong>2
<strong>解释：</strong>
不跳过任何休息时间，你将用 (7/2 + 1/2) + (3/2 + 1/2) + (5/2 + 1/2) + (5/2) = 11.5 小时才能抵达会议现场。
可以跳过第 1 次和第 3 次休息时间，共用 ((7/2 + <strong>0</strong>) + (3/2 + 0)) + ((5/2 + <strong>0</strong>) + (5/2)) = 10 小时抵达会议现场。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>dist = [7,3,5,5], speed = 1, hoursBefore = 10
<strong>输出：</strong>-1
<strong>解释：</strong>即使跳过所有的休息时间，也无法准时参加会议。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == dist.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= dist[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= speed &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= hoursBefore &lt;= 10<sup>7</sup></code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {

    }
};
```




