# `（困难）` [1719.number-of-ways-to-reconstruct-a-tree 重构一棵树的方案数](https://leetcode-cn.com/problems/number-of-ways-to-reconstruct-a-tree/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-43/problems/number-of-ways-to-reconstruct-a-tree/)

### 题目描述
<p>给你一个数组&nbsp;<code>pairs</code> ，其中&nbsp;<code>pairs[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;，并且满足：</p>

<ul>
	<li><code>pairs</code>&nbsp;中没有重复元素</li>
	<li><code>x<sub>i</sub> &lt; y<sub>i</sub></code></li>
</ul>

<p>令&nbsp;<code>ways</code>&nbsp;为满足下面条件的有根树的方案数：</p>

<ul>
	<li>树所包含的所有节点值都在 <code>pairs</code>&nbsp;中。</li>
	<li>一个数对&nbsp;<code>[x<sub>i</sub>, y<sub>i</sub>]</code> 出现在&nbsp;<code>pairs</code>&nbsp;中&nbsp;<strong>当且仅当</strong><strong>&nbsp;</strong><code>x<sub>i</sub></code>&nbsp;是&nbsp;<code>y<sub>i</sub></code>&nbsp;的祖先或者&nbsp;<code>y<sub>i</sub></code>&nbsp;是&nbsp;<code>x<sub>i</sub></code><sub>&nbsp;</sub>的祖先。</li>
	<li><strong>注意：</strong>构造出来的树不一定是二叉树。</li>
</ul>

<p>两棵树被视为不同的方案当存在至少一个节点在两棵树中有不同的父节点。</p>

<p>请你返回：</p>

<ul>
	<li>如果&nbsp;<code>ways == 0</code>&nbsp;，返回&nbsp;<code>0</code>&nbsp;。</li>
	<li>如果&nbsp;<code>ways == 1</code>&nbsp;，返回 <code>1</code>&nbsp;。</li>
	<li>如果&nbsp;<code>ways &gt; 1</code>&nbsp;，返回&nbsp;<code>2</code>&nbsp;。</li>
</ul>

<p>一棵 <strong>有根树</strong>&nbsp;指的是只有一个根节点的树，所有边都是从根往外的方向。</p>

<p>我们称从根到一个节点路径上的任意一个节点（除去节点本身）都是该节点的 <strong>祖先</strong>&nbsp;。根节点没有祖先。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 208px; height: 221px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/09/trees2.png">
<pre><b>输入：</b>pairs = [[1,2],[2,3]]
<b>输出：</b>1
<b>解释：</b>如上图所示，有且只有一个符合规定的有根树。
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 234px; height: 241px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/09/tree.png" alt="">
<pre><b>输入：</b>pairs = [[1,2],[2,3],[1,3]]
<b>输出：</b>2
<b>解释：</b>有多个符合规定的有根树，其中三个如上图所示。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>pairs = [[1,2],[2,3],[2,4],[1,5]]
<b>输出：</b>0
<b>解释：</b>没有符合规定的有根树。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pairs.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x<sub>i </sub>&lt; y<sub>i</sub> &lt;= 500</code></li>
	<li><code>pairs</code>&nbsp;中的元素互不相同。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {

    }
};
```




