# `（简单）` [559.maximum-depth-of-n-ary-tree N叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/)

### 题目描述
<p>给定一个 N 叉树，找到其最大深度。</p>

<p>最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。</p>

<p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>

<p>&nbsp;</p>

<p><img style="width: 100%; max-width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>

<p>&nbsp;</p>

<p>我们应返回其最大深度，3。</p>

<p><strong>说明:</strong></p>

<ol>
	<li>树的深度不会超过&nbsp;<code>1000</code>。</li>
	<li>树的节点总不会超过&nbsp;<code>5000</code>。</li>
</ol>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int maxDepth(Node* root) 
    {
        if (root == nullptr) return 0;
        int ans = 0;
        queue<Node*> que;
        que.push(root);

        while (!que.empty())
        {
            int len = que.size();
            while (len-- > 0)
            {
                auto q = que.front();
                que.pop();
                if (q == nullptr) continue;
                
                for (auto& c : q->children)
                {
                    que.push(c);
                }
            }
            ans++;
        }
        return ans;
    }
};
```




