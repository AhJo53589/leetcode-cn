# `（困难）` [5660.maximum-number-of-events-that-can-be-attended-ii 最多可以参加的会议数目 II](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-45/problems/maximum-number-of-events-that-can-be-attended-ii/)

### 题目描述
<div class="notranslate"><p>给你一个&nbsp;<code>events</code>&nbsp;数组，其中&nbsp;<code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>, value<sub>i</sub>]</code>&nbsp;，表示第&nbsp;<code>i</code>&nbsp;个会议在&nbsp;<code>startDay<sub>i</sub></code><sub>&nbsp;</sub>天开始，第&nbsp;<code>endDay<sub>i</sub></code>&nbsp;天结束，如果你参加这个会议，你能得到价值&nbsp;<code>value<sub>i</sub></code>&nbsp;。同时给你一个整数&nbsp;<code>k</code>&nbsp;表示你能参加的最多会议数目。</p>

<p>你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 <strong>完整</strong>&nbsp;地参加完这个会议。会议结束日期是包含在会议内的，也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。</p>

<p>请你返回能得到的会议价值&nbsp;<strong>最大和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 400px; height: 103px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/02/06/screenshot-2021-01-11-at-60048-pm.png" alt=""></p>

<pre><b>输入：</b>events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
<b>输出：</b>7
<strong>解释：</strong>选择绿色的活动会议 0 和 1，得到总价值和为 4 + 3 = 7 。</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 400px; height: 103px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/02/06/screenshot-2021-01-11-at-60150-pm.png" alt=""></p>

<pre><b>输入：</b>events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
<b>输出：</b>10
<b>解释：</b>参加会议 2 ，得到价值和为 10 。
你没法再参加别的会议了，因为跟会议 2 有重叠。你 <strong>不</strong>&nbsp;需要参加满 k 个会议。</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img style="width: 400px; height: 126px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/02/06/screenshot-2021-01-11-at-60703-pm.png" alt=""></strong></p>

<pre><b>输入：</b>events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
<b>输出：</b>9
<b>解释：</b>尽管会议互不重叠，你只能参加 3 个会议，所以选择价值最大的 3 个会议。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= events.length</code></li>
	<li><code>1 &lt;= k * events.length &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= startDay<sub>i</sub> &lt;= endDay<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= value<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
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
    int maxValue(vector<vector<int>>& events, int k) {

    }
};
```




