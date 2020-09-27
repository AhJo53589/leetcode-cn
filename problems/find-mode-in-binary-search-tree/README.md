# `（简单）` [501.find-mode-in-binary-search-tree 二叉搜索树中的众数](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/)

### 题目描述
<p>给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。</p>

<p>假定 BST 有如下定义：</p>

<ul>
	<li>结点左子树中所含结点的值小于等于当前结点的值</li>
	<li>结点右子树中所含结点的值大于等于当前结点的值</li>
	<li>左子树和右子树都是二叉搜索树</li>
</ul>

<p>例如：<br>
给定 BST <code>[1,null,2,2]</code>,</p>

<pre>   1
    \
     2
    /
   2
</pre>

<p><code>返回[2]</code>.</p>

<p><strong>提示</strong>：如果众数超过1个，不需考虑输出顺序</p>

<p><strong>进阶：</strong>你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）</p>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/solution/find-mode-in-binary-search-tree-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cnt = (root->val == val) ? cnt + 1 : 1;
        if (cnt == maxcnt) {
            ans.push_back(root->val);
        }
        else if (cnt > maxcnt) {
            maxcnt = cnt;
            ans = vector<int>(1, root->val);
        }
        val = root->val;
        inorder(root->right);
    }

private:
    int val = INT_MIN;
    int cnt = 0;
    int maxcnt = 0;
    vector<int> ans;
};
```




