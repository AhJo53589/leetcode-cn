# `（中等）` [515.find-largest-value-in-each-tree-row 在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)

### 题目描述
<p>给定一棵二叉树的根节点&nbsp;<code>root</code> ，请找出该二叉树中每一层的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例1：</strong></p>

<p><img style="height: 172px; width: 300px;" src="https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg" alt=""></p>

<pre><strong>输入: </strong>root = [1,3,2,5,3,null,9]
<strong>输出: </strong>[1,3,9]
</pre>

<p><strong>示例2：</strong></p>

<pre><strong>输入: </strong>root = [1,2,3]
<strong>输出: </strong>[1,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树的节点个数的范围是 <code>[0,10<sup>4</sup>]</code></li>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= Node.val &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }

    void dfs(TreeNode* node, vector<int>& ans, int h) {
        if (node == nullptr) return;
        if (ans.size() == h) {
            ans.push_back(node->val);
        }
        ans[h] = max(ans[h], node->val);

        dfs(node->left, ans, h + 1);
        dfs(node->right, ans, h + 1);
    }
};
```




