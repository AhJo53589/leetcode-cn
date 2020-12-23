# `（困难）` [1697.checking-existence-of-edge-length-limited-paths 检查边长度限制的路径是否存在](https://leetcode-cn.com/problems/checking-existence-of-edge-length-limited-paths/)

[contest](https://leetcode-cn.com/contest/weekly-contest-220/problems/checking-existence-of-edge-length-limited-paths/)

### 题目描述
<p>给你一个 <code>n</code>&nbsp;个点组成的无向图边集&nbsp;<code>edgeList</code>&nbsp;，其中&nbsp;<code>edgeList[i] = [u<sub>i</sub>, v<sub>i</sub>, dis<sub>i</sub>]</code>&nbsp;表示点&nbsp;<code>u<sub>i</sub></code> 和点&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条长度为&nbsp;<code>dis<sub>i</sub></code>&nbsp;的边。请注意，两个点之间可能有 <strong>超过一条边&nbsp;</strong>。</p>

<p>给你一个查询数组<code>queries</code>&nbsp;，其中&nbsp;<code>queries[j] = [p<sub>j</sub>, q<sub>j</sub>, limit<sub>j</sub>]</code>&nbsp;，你的任务是对于每个查询&nbsp;<code>queries[j]</code>&nbsp;，判断是否存在从&nbsp;<code>p<sub>j</sub></code>&nbsp;到&nbsp;<code>q<sub>j</sub></code><sub>&nbsp;</sub>的路径，且这条路径上的每一条边都 <strong>严格小于</strong>&nbsp;<code>limit<sub>j</sub></code>&nbsp;。</p>

<p>请你返回一个 <b>布尔数组</b><em>&nbsp;</em><code>answer</code><em>&nbsp;</em>，其中<em>&nbsp;</em><code>answer.length == queries.length</code>&nbsp;，当&nbsp;<code>queries[j]</code>&nbsp;的查询结果为&nbsp;<code>true</code>&nbsp;时，&nbsp;<code>answer</code> 第<em>&nbsp;</em><code>j</code>&nbsp;个值为<em>&nbsp;</em><code>true</code><em>&nbsp;</em>，否则为&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 267px; height: 262px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/12/19/h.png" alt="">
<pre><b>输入：</b>n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
<b>输出：</b>[false,true]
<b>解释：</b>上图为给定的输入数据。注意到 0 和 1 之间有两条重边，分别为 2 和 16 。
对于第一个查询，0 和 1 之间没有小于 2 的边，所以我们返回 false 。
对于第二个查询，有一条路径（0 -&gt; 1 -&gt; 2）两条边都小于 5 ，所以这个查询我们返回 true 。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 390px; height: 358px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/12/19/q.png" alt="">
<pre><b>输入：</b>n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
<b>输出：</b>[true,false]
<b>解释：</b>上图为给定数据。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= edgeList.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edgeList[i].length == 3</code></li>
	<li><code>queries[j].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub>, p<sub>j</sub>, q<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>p<sub>j</sub> != q<sub>j</sub></code></li>
	<li><code>1 &lt;= dis<sub>i</sub>, limit<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
	<li>两个点之间可能有 <strong>多条</strong>&nbsp;边。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

    }
};
```




