# `（简单）` [589.n-ary-tree-preorder-traversal N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/)

### 题目描述
<p>给定一个 N 叉树，返回其节点值的<em>前序遍历</em>。</p>

<p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>

<p>&nbsp;</p>

<p><img style="width: 100%; max-width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>

<p>&nbsp;</p>

<p>返回其前序遍历: <code>[1,3,5,6,2,4]</code>。</p>

<p>&nbsp;</p>

<p><strong>说明:&nbsp;</strong>递归法很简单，你可以使用迭代法完成此题吗?</p>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    void preorder(Node* root, vector<int>& ans)
    {
        if (root == nullptr) return;
        ans.push_back(root->val);
        for (auto c : root->children)
        {
            preorder(c, ans);
        }
    }

    vector<int> preorder(Node* root) 
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
```




