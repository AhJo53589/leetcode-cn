# `（简单）` [687.longest-univalue-path 最长同值路径](https://leetcode-cn.com/problems/longest-univalue-path/)

### 题目描述
<p>给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。</p>

<p><strong>注意</strong>：两个节点之间的路径长度由它们之间的边数表示。</p>

<p><strong>示例 1:</strong></p>

<p>输入:</p>

<pre>              5
             / \
            4   5
           / \   \
          1   1   5
</pre>

<p>输出:</p>

<pre>2
</pre>

<p><strong>示例 2:</strong></p>

<p>输入:</p>

<pre>              1
             / \
            4   5
           / \   \
          4   4   5
</pre>

<p>输出:</p>

<pre>2
</pre>

<p><strong>注意:</strong> 给定的二叉树不超过10000个结点。&nbsp;树的高度不超过1000。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/longest-univalue-path/solution/687-by-ikaruga/)

### 答题
``` C++
int help(TreeNode* node, int &ans)
{
    if (node == nullptr) return 0;

    int l = help(node->left, ans);
    int r = help(node->right, ans);

    int samel = 0;
    int samer = 0;
    if (node->left != nullptr && node->val == node->left->val)
    {
        samel = l + 1;
    }
    if (node->right != nullptr && node->val == node->right->val)
    {
        samer = r + 1;
    }
    ans = max(ans, samel + samer);
    return max(samel, samer);
}

int longestUnivaluePath(TreeNode* root)
{
    int ans = 0;
    help(root, ans);
    return ans;
}
```




