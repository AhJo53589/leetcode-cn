# `（简单）` [530.minimum-absolute-difference-in-bst 二叉搜索树的最小绝对差](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/)

### 题目描述
<p>给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>

   1
    \
     3
    /
   2

<strong>输出：</strong>
1

<strong>解释：
</strong>最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中至少有 2 个节点。</li>
	<li>本题与 783 <a href="https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/">https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/</a> 相同</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        inordered(root);
        return ans;
    }

    void inordered(TreeNode* root) {
        if (root == nullptr) return;
        inordered(root->left);
        if (val != -1) {
            ans = min(ans, root->val - val);
        }
        val = root->val;
        inordered(root->right);
    }

private:
    int ans = INT_MAX;
    int val = -1;
};
```




