# `（中等）` [429.n-ary-tree-level-order-traversal N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)

### 题目描述
<p>给定一个 N 叉树，返回其节点值的<em>层序遍历</em>。 (即从左到右，逐层遍历)。</p>

<p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>

<p>&nbsp;</p>

<p><img style="width: 100%; max-width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>

<p>&nbsp;</p>

<p>返回其层序遍历:</p>

<pre>[
     [1],
     [3,2,4],
     [5,6]
]
</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ol>
	<li>树的深度不会超过&nbsp;<code>1000</code>。</li>
	<li>树的节点总数不会超过&nbsp;<code>5000</code>。</li>
</ol>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        queue<Node*> queCurr;
        queue<Node*> queNext;
        queCurr.push(root);
        while (!queCurr.empty() || !queNext.empty())
        {
            vector<int> temp;
            while (!queCurr.empty())
            {
                auto q = queCurr.front();
                queCurr.pop();
                if (q == nullptr) continue;
                temp.push_back(q->val);
                for (auto c : q->children)
                {
                    queNext.push(c);
                }
            }
            if (!temp.empty())
            {
                ans.push_back(temp);
            }
            swap(queCurr, queNext);
        }
        return ans;
    }
};
```




