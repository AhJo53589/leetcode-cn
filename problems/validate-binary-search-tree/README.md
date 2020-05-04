# `（中等）` [98.validate-binary-search-tree 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)

### 题目描述
<p>给定一个二叉树，判断其是否是一个有效的二叉搜索树。</p>

<p>假设一个二叉搜索树具有如下特征：</p>

<ul>
	<li>节点的左子树只包含<strong>小于</strong>当前节点的数。</li>
	<li>节点的右子树只包含<strong>大于</strong>当前节点的数。</li>
	<li>所有左子树和右子树自身必须也是二叉搜索树。</li>
</ul>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong>
    2
   / \
  1   3
<strong>输出:</strong> true
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:
</strong>    5
   / \
  1   4
&nbsp;    / \
&nbsp;   3   6
<strong>输出:</strong> false
<strong>解释:</strong> 输入为: [5,1,4,null,null,3,6]。
&nbsp;    根节点的值为 5 ，但是其右子节点值为 4 。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/validate-binary-search-tree/solution/validate-binary-search-tree-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int val = 0;
        bool flag = false;
        return Inorder(root, val, flag);
    }

    bool Inorder(TreeNode* root, int& val, bool& flag) {
        if (root == nullptr) return true;

        if (!Inorder(root->left, val, flag)) return false;

        if (flag && !(val < root->val)) return false;
        val = root->val;
        flag = true;

        if (!Inorder(root->right, val, flag)) return false;
        return true;
    }
};

```


### 其它
``` C++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

    bool dfs(TreeNode* root, long long min, long long max) {
        if (root == NULL) return true;
        if (root->val <= min || root->val >= max) return false;
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
};
```


