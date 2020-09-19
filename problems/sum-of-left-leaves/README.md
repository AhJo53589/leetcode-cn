# `（简单）` [404.sum-of-left-leaves 左叶子之和](https://leetcode-cn.com/problems/sum-of-left-leaves/)

### 题目描述
<p>计算给定二叉树的所有左叶子之和。</p>

<p><strong>示例：</strong></p>

<pre>    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24</pre>

<p>&nbsp;</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum = root->left->val;
        }
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```




