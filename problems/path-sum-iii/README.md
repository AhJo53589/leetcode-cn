# `（简单）` [437.path-sum-iii 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)

### 题目描述
<p>给定一个二叉树，它的每个结点都存放着一个整数值。</p>

<p>找出路径和等于给定数值的路径总数。</p>

<p>路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。</p>

<p>二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。</p>

<p><strong>示例：</strong></p>

<pre>root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    <strong>5</strong>   <strong>-3</strong>
   <strong>/</strong> <strong>\</strong>    <strong>\</strong>
  <strong>3</strong>   <strong>2</strong>   <strong>11</strong>
 / \   <strong>\</strong>
3  -2   <strong>1</strong>

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/path-sum-iii/solution/path-sum-iii-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    void dfs(TreeNode* root, int ps, int sum, unordered_map<int, int>& vi, int& ans)
    {
        if (root == nullptr) return;
        root->val += ps;
        ans += vi[root->val - sum];
        vi[root->val]++;
        dfs(root->left, root->val, sum, vi, ans);
        dfs(root->right, root->val, sum, vi, ans);
        vi[root->val]--;
    }

    int pathSum(TreeNode* root, int sum) 
    {
        int ans = 0;
        unordered_map<int, int> vi;
        vi[0] = 1;
        dfs(root, 0, sum, vi, ans);
        return ans;
    }
};
```




