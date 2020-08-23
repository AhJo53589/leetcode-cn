# `（简单）` [5495.most-visited-sector-in-a-circular-track 圆形赛道上经过次数最多的扇区](https://leetcode-cn.com/problems/most-visited-sector-in-a-circular-track/)

[contest](https://leetcode-cn.com/contest/weekly-contest-203/problems/most-visited-sector-in-a-circular-track/)

### 题目描述
<p>给你一个整数 <code>n</code> 和一个整数数组 <code>rounds</code> 。有一条圆形赛道由 <code>n</code> 个扇区组成，扇区编号从 <code>1</code> 到 <code>n</code> 。现将在这条赛道上举办一场马拉松比赛，该马拉松全程由 <code>m</code> 个阶段组成。其中，第 <code>i</code> 个阶段将会从扇区 <code>rounds[i - 1]</code> 开始，到扇区 <code>rounds[i]</code> 结束。举例来说，第 <code>1</code> 阶段从&nbsp;<code>rounds[0]</code>&nbsp;开始，到&nbsp;<code>rounds[1]</code>&nbsp;结束。</p>

<p>请你以数组形式返回经过次数最多的那几个扇区，按扇区编号 <strong>升序</strong> 排列。</p>

<p>注意，赛道按扇区编号升序逆时针形成一个圆（请参见第一个示例）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 341px; width: 433px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/22/3rd45e.jpg" alt=""></p>

<pre><strong>输入：</strong>n = 4, rounds = [1,3,1,2]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>本场马拉松比赛从扇区 1 开始。经过各个扇区的次序如下所示：
1 --> 2 --> 3（阶段 1 结束）--> 4 --> 1（阶段 2 结束）--> 2（阶段 3 结束，即本场马拉松结束）
其中，扇区 1 和 2 都经过了两次，它们是经过次数最多的两个扇区。扇区 3 和 4 都只经过了一次。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2, rounds = [2,1,2,1,2,1,2,1,2]
<strong>输出：</strong>[2]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 7, rounds = [1,3,5,7]
<strong>输出：</strong>[1,2,3,4,5,6,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 100</code></li>
	<li><code>1 <= m <= 100</code></li>
	<li><code>rounds.length == m + 1</code></li>
	<li><code>1 <= rounds[i] <= n</code></li>
	<li><code>rounds[i] != rounds[i + 1]</code> ，其中 <code>0 <= i < m</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/most-visited-sector-in-a-circular-track/solution/most-visited-sector-by-ikaruga/)

### 答题
``` C++
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int start = rounds.front();
        while (start != rounds.back()) {
            ans.push_back(start);
            start++;
            start = (start > n) ? start % n : start;
        }
        ans.push_back(start);
        sort(ans.begin(), ans.end());
        return ans;
    }
```




