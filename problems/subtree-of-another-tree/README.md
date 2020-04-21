# `（简单）` [572.subtree-of-another-tree 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/)

### 题目描述
<p>给定两个非空二叉树 <strong>s</strong> 和 <strong>t</strong>，检验&nbsp;<strong>s</strong> 中是否包含和 <strong>t</strong> 具有相同结构和节点值的子树。<strong>s</strong> 的一个子树包括 <strong>s</strong> 的一个节点和这个节点的所有子孙。<strong>s</strong> 也可以看做它自身的一棵子树。</p>

<p><strong>示例 1:</strong><br>
给定的树 s:</p>

<pre>     3
    / \
   4   5
  / \
 1   2
</pre>

<p>给定的树 t：</p>

<pre>   4 
  / \
 1   2
</pre>

<p>返回 <strong>true</strong>，因为 t 与 s 的一个子树拥有相同的结构和节点值。</p>

<p><strong>示例 2:</strong><br>
给定的树 s：</p>

<pre>     3
    / \
   4   5
  / \
 1   2
    /
   0
</pre>

<p>给定的树 t：</p>

<pre>   4
  / \
 1   2
</pre>

<p>返回 <strong>false</strong>。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/subtree-of-another-tree/solution/subtree-of-another-tree-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        while (s != nullptr) {
            if (dfs(s, t)) return true;
            return (isSubtree(s->left, t) || isSubtree(s->right, t));
        }
        return false;
    }

    bool dfs(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        if (s->val != t->val) return false;
        return (dfs(s->left, t->left) && dfs(s->right, t->right));
    }
};


```




