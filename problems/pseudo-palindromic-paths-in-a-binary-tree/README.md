# `（中等）` [5418.pseudo-palindromic-paths-in-a-binary-tree 二叉树中的伪回文路径](https://leetcode-cn.com/problems/pseudo-palindromic-paths-in-a-binary-tree/)

[contest](https://leetcode-cn.com/contest/weekly-contest-190/problems/pseudo-palindromic-paths-in-a-binary-tree/)

### 题目描述
<p>给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「<strong>伪回文</strong>」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。</p>

<p>请你返回从根到叶子节点的所有路径中&nbsp;<strong>伪回文&nbsp;</strong>路径的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/23/palindromic_paths_1.png" style="height: 201px; width: 300px;"></p>

<pre><strong>输入：</strong>root = [2,3,1,3,1,null,1]
<strong>输出：</strong>2 
<strong>解释：</strong>上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
     在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/23/palindromic_paths_2.png" style="height: 314px; width: 300px;"></strong></p>

<pre><strong>输入：</strong>root = [2,1,1,1,3,null,null,null,null,null,1]
<strong>输出：</strong>1 
<strong>解释：</strong>上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
     这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [9]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定二叉树的节点数目在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>10^5</code>&nbsp;之间。</li>
	<li>节点值在&nbsp;<code>1</code> 到&nbsp;<code>9</code>&nbsp;之间。</li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/pseudo-palindromic-paths-in-a-binary-tree/solution/pseudo-palindromic-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> vals;
        int ans = 0;
        dfs(root, vals, ans);
        return ans;
    }

    void dfs(TreeNode* root, unordered_map<int, int>& vals, int& ans) {
        if (root == nullptr) return;
        vals[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            ans += check(vals);
        }
        dfs(root->left, vals, ans);
        dfs(root->right, vals, ans);

        vals[root->val]--;
    }

    bool check(unordered_map<int, int>& vals) {
        bool singleFlag = false;
        for (auto it = vals.begin(); it != vals.end(); it++) {
            if (it->second % 2 == 0) continue;
            if (singleFlag) return false;
            singleFlag = true;
        }
        return true;
    }
};
```




