# `（中等）` [199.binary-tree-right-side-view 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/)

### 题目描述
<p>给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>&nbsp;[1,2,3,null,5,null,4]
<strong>输出:</strong>&nbsp;[1, 3, 4]
<strong>解释:
</strong>
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/binary-tree-right-side-view-by-ikaruga/)

### 答题
``` C++
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                auto q = que.front();
                que.pop();
                if (i == len - 1) {
                    ans.push_back(q->val);
                }
                if (q->left != nullptr) {
                    que.push(q->left);
                }
                if (q->right != nullptr) {
                    que.push(q->right);
                }
            }
        }

        return ans;
    }
```




