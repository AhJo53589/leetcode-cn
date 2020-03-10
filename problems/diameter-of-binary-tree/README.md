# `（简单）` [543.diameter-of-binary-tree 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

### 题目描述
<p>给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。</p>

<p><strong>示例 :</strong><br>
给定二叉树</p>

<pre>          1
         / \
        2   3
       / \     
      4   5    
</pre>

<p>返回&nbsp;<strong>3</strong>, 它的长度是路径 [4,2,1,3] 或者&nbsp;[5,2,1,3]。</p>

<p><strong>注意：</strong>两结点之间的路径长度是以它们之间边的数目表示。</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/543-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root, int& ans)
    {
        if (root == nullptr) return 0;
        int left = diameterOfBinaryTree(root->left, ans);
        int right = diameterOfBinaryTree(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int ans = 0;
        diameterOfBinaryTree(root, ans);
        return ans;
    }
};
```




