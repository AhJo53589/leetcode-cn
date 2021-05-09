# `（困难）` [5753.largest-color-value-in-a-directed-graph 有向图中最大颜色值](https://leetcode-cn.com/problems/largest-color-value-in-a-directed-graph/)

[contest](https://leetcode-cn.com/contest/weekly-contest-240/problems/largest-color-value-in-a-directed-graph/)

### 题目描述
<div class="notranslate"><p>给你一个&nbsp;<strong>有向图</strong>&nbsp;，它含有&nbsp;<code>n</code>&nbsp;个节点和 <code>m</code>&nbsp;条边。节点编号从&nbsp;<code>0</code> 到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>给你一个字符串&nbsp;<code>colors</code> ，其中&nbsp;<code>colors[i]</code>&nbsp;是小写英文字母，表示图中第 <code>i</code>&nbsp;个节点的 <b>颜色</b>&nbsp;（下标从 <strong>0</strong>&nbsp;开始）。同时给你一个二维数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[j] = [a<sub>j</sub>, b<sub>j</sub>]</code>&nbsp;表示从节点&nbsp;<code>a<sub>j</sub></code>&nbsp;到节点&nbsp;<code>b<sub>j</sub></code><sub>&nbsp;</sub>有一条&nbsp;<strong>有向边</strong>&nbsp;。</p>

<p>图中一条有效 <strong>路径</strong>&nbsp;是一个点序列&nbsp;<code>x<sub>1</sub> -&gt; x<sub>2</sub> -&gt; x<sub>3</sub> -&gt; ... -&gt; x<sub>k</sub></code>&nbsp;，对于所有&nbsp;<code>1 &lt;= i &lt; k</code>&nbsp;，从&nbsp;<code>x<sub>i</sub></code> 到&nbsp;<code>x<sub>i+1</sub></code>&nbsp;在图中有一条有向边。路径的 <strong>颜色值</strong>&nbsp;是路径中 <strong>出现次数最多</strong> 颜色的节点数目。</p>

<p>请你返回给定图中有效路径里面的&nbsp;<strong>最大颜色值</strong><strong>&nbsp;。</strong>如果图中含有环，请返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 400px; height: 182px;" src="https://assets.leetcode.com/uploads/2021/04/21/leet1.png" alt=""></p>

<pre><b>输入：</b>colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
<b>输出：</b>3
<b>解释：</b>路径 0 -&gt; 2 -&gt; 3 -&gt; 4 含有 3 个颜色为 <code>"a" 的节点（上图中的红色节点）。</code>
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 85px; height: 85px;" src="https://assets.leetcode.com/uploads/2021/04/21/leet2.png" alt=""></p>

<pre><b>输入：</b>colors = "a", edges = [[0,0]]
<b>输出：</b>-1
<b>解释：</b>从 0 到 0 有一个环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == colors.length</code></li>
	<li><code>m == edges.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>colors</code>&nbsp;只含有小写英文字母。</li>
	<li><code>0 &lt;= a<sub>j</sub>, b<sub>j</sub>&nbsp;&lt; n</code></li>
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
    int largestPathValue(string colors, vector<vector<int>>& edges) {

    }
};
```




