# `（简单）` [637.average-of-levels-in-binary-tree 二叉树的层平均值](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/)

### 题目描述
<p>给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
    3
   / \
  9  20
    /  \
   15   7
<strong>输出：</strong>[3, 14.5, 11]
<strong>解释：</strong>
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点值的范围在32位有符号整数范围内。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
        }

        while (!que.empty()) {
            int cnt = 0;
            double avg = 0;
            for (int len = que.size(); len > 0; len--) {
                auto q = que.front();
                que.pop();

                avg += q->val;
                cnt++;
                if (q->left != nullptr) {
                    que.push(q->left);
                }
                if (q->right != nullptr) {
                    que.push(q->right);
                }
            }
            ans.push_back(avg / (double)cnt);
        }
        return ans;
    }
};
```




