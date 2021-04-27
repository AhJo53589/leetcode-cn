# `（简单）` [938.range-sum-of-bst 二叉搜索树的范围和](https://leetcode-cn.com/problems/range-sum-of-bst/)

### 题目描述
<p>给定二叉搜索树的根结点&nbsp;<code>root</code>，返回值位于范围 <em><code>[low, high]</code></em> 之间的所有结点的值的和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 400px; height: 222px;" src="https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg" alt="">
<pre><strong>输入：</strong>root = [10,5,15,3,7,null,18], low = 7, high = 15
<strong>输出：</strong>32
</pre>

<p><strong>示例 2：</strong></p>
<img style="width: 400px; height: 335px;" src="https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg" alt="">
<pre><strong>输入：</strong>root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
<strong>输出：</strong>23
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 2 * 10<sup>4</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= low &lt;= high &lt;= 10<sup>5</sup></code></li>
	<li>所有 <code>Node.val</code> <strong>互不相同</strong></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return ans;
        if (root->val >= low) {
            rangeSumBST(root->left, low, high);
        }

        if (root->val >= low && root->val <= high) {
            ans += root->val;
        }

        if (root->val <= high) {
            rangeSumBST(root->right, low, high);
        }
        return ans;
    }

private:
    int ans = 0;
};
```




