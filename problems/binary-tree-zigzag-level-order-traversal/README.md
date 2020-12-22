# `（中等）` [103.binary-tree-zigzag-level-order-traversal 二叉树的锯齿形层序遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

### 题目描述
<p>给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。</p>

<p>例如：<br>
给定二叉树&nbsp;<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回锯齿形层序遍历如下：</p>

<pre>[
  [3],
  [20,9],
  [15,7]
]
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/binary-tree-zigzag-by-ikaruga-rj7x/)

### 答题
``` C++
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st[2];
        if (root != nullptr) {
            st[0].push(root);
        }

        vector<vector<int>> ans;
        int i = 0;
        int j = 1;
        while (!st[0].empty() || !st[1].empty()) {
            vector<int> lv;
            while (!st[i].empty()) {
                auto node = st[i].top();
                st[i].pop();

                lv.push_back(node->val);

                if (node->left != nullptr && i == 0) {
                    st[j].push(node->left);
                }
                if (node->right != nullptr) {
                    st[j].push(node->right);
                }
                if (node->left != nullptr && i == 1) {
                    st[j].push(node->left);                    
                }          
            }
            ans.emplace_back(lv);
            swap(i, j);
        }

        return ans;
    }
};
```




