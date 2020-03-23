# `（中等）` [1382.balance-a-binary-search-tree 将二叉搜索树变平衡](https://leetcode-cn.com/problems/balance-a-binary-search-tree/)

[contest](https://leetcode-cn.com/contest/weekly-contest-180/problems/balance-a-binary-search-tree/)

### 题目描述
<p>给你一棵二叉搜索树，请你返回一棵&nbsp;<strong>平衡后</strong>&nbsp;的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。</p>

<p>如果一颗二叉搜索树中，任何节点两棵子树的高度差不超过 1 ，我们就称这棵二叉搜索树是&nbsp;<strong>平衡的</strong> 。</p>

<p>如果有多种构造方法，请你返回任意一种。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/15/1515_ex1.png" style="height: 248px; width: 250px;"><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/15/1515_ex1_out.png" style="height: 200px; width: 200px;"></strong></p>

<pre><strong>输入：</strong>root = [1,null,2,null,3,null,4,null,null]
<strong>输出：</strong>[2,1,3,null,null,null,4]
<strong>解释：</strong>这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树节点的数目在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>10^4</code>&nbsp;之间。</li>
	<li>树节点的值互不相同，且在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>10^5</code> 之间。</li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/balance-a-binary-search-tree/solution/5179-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) 
    {
        if (start > end) return nullptr;

        TreeNode* root = nullptr;
        int mid = start + (end - start) / 2;
        root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        return root;
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr) return {};

        vector<int> ret;
        vector<int> left = inorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());

        ret.push_back(root->val);

        vector<int> right = inorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<int> num = inorderTraversal(root);
        TreeNode* node = sortedArrayToBSTHelper(num, 0, num.size() - 1);
        return node;
    }
};
```




