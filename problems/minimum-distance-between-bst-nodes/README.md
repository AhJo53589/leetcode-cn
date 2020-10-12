# `（简单）` [783.minimum-distance-between-bst-nodes 二叉搜索树节点最小距离](https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/)

### 题目描述
<p>给定一个二叉搜索树的根节点&nbsp;<code>root</code>，返回树中任意两节点的差的最小值。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入:</strong> root = [4,2,6,1,3,null,null]
<strong>输出:</strong> 1
<strong>解释:</strong>
注意，root是树节点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \    
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ol>
	<li>二叉树的大小范围在 <code>2</code> 到&nbsp;<code>100</code>。</li>
	<li>二叉树总是有效的，每个节点的值都是整数，且不重复。</li>
	<li>本题与 530：<a href="https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/">https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/</a> 相同</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
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




