# `（困难）` [1665.minimum-initial-energy-to-finish-tasks 完成所有任务的最少初始能量](https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks/)

[contest](https://leetcode-cn.com/contest/weekly-contest-216/problems/minimum-initial-energy-to-finish-tasks/)

### 题目描述
<p>给你一个任务数组&nbsp;<code>tasks</code> ，其中&nbsp;<code>tasks[i] = [actual<sub>i</sub>, minimum<sub>i</sub>]</code>&nbsp;：</p>

<ul>
	<li><code>actual<sub>i</sub></code>&nbsp;是完成第 <code>i</code>&nbsp;个任务 <strong>需要耗费</strong>&nbsp;的实际能量。</li>
	<li><code>minimum<sub>i</sub></code>&nbsp;是开始第 <code>i</code>&nbsp;个任务前需要达到的最低能量。</li>
</ul>

<p>比方说，如果任务为&nbsp;<code>[10, 12]</code>&nbsp;且你当前的能量为&nbsp;<code>11</code>&nbsp;，那么你不能开始这个任务。如果你当前的能量为&nbsp;<code>13</code>&nbsp;，你可以完成这个任务，且完成它后剩余能量为 <code>3</code>&nbsp;。</p>

<p>你可以按照 <strong>任意顺序</strong>&nbsp;完成任务。</p>

<p>请你返回完成所有任务的 <strong>最少</strong>&nbsp;初始能量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>tasks = [[1,2],[2,4],[4,8]]
<b>输出：</b>8
<strong>解释：</strong>
一开始有 8 能量，我们按照如下顺序完成任务：
    - 完成第 3 个任务，剩余能量为 8 - 4 = 4 。
    - 完成第 2 个任务，剩余能量为 4 - 2 = 2 。
    - 完成第 1 个任务，剩余能量为 2 - 1 = 1 。
注意到尽管我们有能量剩余，但是如果一开始只有 7 能量是不能完成所有任务的，因为我们无法开始第 3 个任务。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
<b>输出：</b>32
<strong>解释：</strong>
一开始有 32 能量，我们按照如下顺序完成任务：
    - 完成第 1 个任务，剩余能量为 32 - 1 = 31 。
    - 完成第 2 个任务，剩余能量为 31 - 2 = 29 。
    - 完成第 3 个任务，剩余能量为 29 - 10 = 19 。
    - 完成第 4 个任务，剩余能量为 19 - 10 = 9 。
    - 完成第 5 个任务，剩余能量为 9 - 8 = 1 。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
<b>输出：</b>27
<strong>解释：</strong>
一开始有 27 能量，我们按照如下顺序完成任务：
    - 完成第 5 个任务，剩余能量为 27 - 5 = 22 。
    - 完成第 2 个任务，剩余能量为 22 - 2 = 20 。
    - 完成第 3 个任务，剩余能量为 20 - 3 = 17 。
    - 完成第 1 个任务，剩余能量为 17 - 1 = 16 。
    - 完成第 4 个任务，剩余能量为 16 - 4 = 12 。
    - 完成第 6 个任务，剩余能量为 12 - 6 = 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= actual<sub>​i</sub>&nbsp;&lt;= minimum<sub>i</sub>&nbsp;&lt;= 10<sup>4</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

    }
};
```




