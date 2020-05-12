# `（中等）` [102.binary-tree-level-order-traversal 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

### 题目描述
<p>给你一个二叉树，请你返回其按 <strong>层序遍历</strong> 得到的节点值。 （即逐层地，从左到右访问所有节点）。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong><br>
二叉树：<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回其层次遍历结果：</p>

<pre>[
  [3],
  [9,20],
  [15,7]
]
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/binary-tree-level-order-traversal-by-ikaruga/)

### 答题
``` C++
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que[2];
        int seq = 0;

        que[seq].push(root);
        while (!(que[0].empty() && que[1].empty())) {
            int seq_next = (seq + 1) % 2;
            vector<int> num;
            while (!que[seq].empty()) {
                TreeNode* pNode = que[seq].front();
                que[seq].pop();
                num.push_back(pNode->val);

                if (pNode->left != nullptr) {
                    que[seq_next].push(pNode->left);
                }
                if (pNode->right != nullptr) {
                    que[seq_next].push(pNode->right);
                }
            }
            ans.push_back(num);
            seq = seq_next;
        }
        return ans;
    }
```




