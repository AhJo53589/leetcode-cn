# `（困难）` [1483.kth-ancestor-of-a-tree-node 树节点的第 K 个祖先](https://leetcode-cn.com/problems/kth-ancestor-of-a-tree-node/)

[contest](https://leetcode-cn.com/contest/weekly-contest-193/problems/kth-ancestor-of-a-tree-node/)

### 题目描述
<p>给你一棵树，树上有 <code>n</code> 个节点，按从 <code>0</code> 到 <code>n-1</code> 编号。树以父节点数组的形式给出，其中 <code>parent[i]</code> 是节点 <code>i</code> 的父节点。树的根节点是编号为 <code>0</code> 的节点。</p>

<p>请你设计并实现 <code>getKthAncestor</code><code>(int node, int k)</code> 函数，函数返回节点 <code>node</code> 的第 <code>k</code> 个祖先节点。如果不存在这样的祖先节点，返回 <code>-1</code> 。</p>

<p>树节点的第 <em><code>k</code> </em>个祖先节点是从该节点到根节点路径上的第 <code>k</code> 个节点。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><strong><img style="height: 262px; width: 396px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/14/1528_ex1.png" alt=""></strong></p>

<pre><strong>输入：</strong>
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

<strong>输出：</strong>
[null,1,0,-1]

<strong>解释：</strong>
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <=&nbsp;n <= 5*10^4</code></li>
	<li><code>parent[0] == -1</code> 表示编号为 <code>0</code> 的节点是根节点。</li>
	<li>对于所有的 <code>0 <&nbsp;i < n</code> ，<code>0 <= parent[i] < n</code> 总成立</li>
	<li><code>0 <= node < n</code></li>
	<li>至多查询 <code>5*10^4</code> 次</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {

    }
    
    int getKthAncestor(int node, int k) {

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
```




