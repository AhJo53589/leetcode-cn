# `（简单）` [538.convert-bst-to-greater-tree 把二叉搜索树转换为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)

### 题目描述
<p>给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。</p>

<p>&nbsp;</p>

<p><strong>例如：</strong></p>

<pre><strong>输入:</strong> 原始二叉搜索树:
              5
            /   \
           2     13

<strong>输出:</strong> 转换为累加树:
             18
            /   \
          20     13
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题和 1038:&nbsp;<a href="https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/">https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/</a> 相同</p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }

    int dfs(TreeNode* root, int add) {
        if (root == nullptr) return add;
        root->val += dfs(root->right, add);
        return dfs(root->left, root->val);
    }
};
```




